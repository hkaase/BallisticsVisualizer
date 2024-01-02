#include "mainwindow.h"
#include <ballistics/ballistics.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
    connect(ui->calcButton, &QPushButton::clicked, this, &MainWindow::on_calcButton_clicked);
    connect(ui->bc, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->g1Selected, &QRadioButton::toggled, this, &MainWindow::computeBallistics);
    connect(ui->velo, &QSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->sh, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->angle, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->zero, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->windSpeed, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->windAngle, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->temperature, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    // Skipping inHg, altitude, and humidity based on requirements
    connect(ui->caliber, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->grains, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->length, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->twistRate, &QDoubleSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->maxYards, &QSpinBox::valueChanged, this, &MainWindow::computeBallistics);
    connect(ui->stepSize, &QSpinBox::valueChanged, this, &MainWindow::computeBallistics);
	connect(ui->toggleViewButton, &QPushButton::clicked, this, &MainWindow::toggleView);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleView() {
    if (ui->trajectoryChart->isHidden()) {
        ui->trajectoryChart->show();
        ui->shotVisualizer->hide();
        is3D = false;
    } else {
        ui->trajectoryChart->hide();
        ui->shotVisualizer->show();
        is3D = true;
    }
}

bool MainWindow::validateInputs() {
    bool valid = true;
    valid &= !ui->bc->text().isEmpty() && ui->bc->value() > 0;
    valid &= !ui->velo->text().isEmpty() && ui->velo->value() > 750;
    valid &= !ui->sh->text().isEmpty() && ui->sh->value() > 0;
    valid &= !ui->angle->text().isEmpty() && ui->angle->value() >= 0;
    valid &= !ui->zero->text().isEmpty() && ui->zero->value() > 0;
    valid &= !ui->windSpeed->text().isEmpty() && ui->windSpeed->value() >= 0;
    valid &= !ui->windAngle->text().isEmpty() && ui->windAngle->value() >= 0;
    valid &= !ui->temperature->text().isEmpty(); // Temp could be below 0, so no need to check for > 0
    // Skipping altitude, and humidity based on requirements
	valid &= !ui->inHg->text().isEmpty();
    valid &= !ui->caliber->text().isEmpty() && ui->caliber->value() > 0;
    valid &= !ui->grains->text().isEmpty() && ui->grains->value() > 0;
    valid &= !ui->length->text().isEmpty() && ui->length->value() > 0;
    valid &= !ui->twistRate->text().isEmpty() && ui->twistRate->value() > 0;
    valid &= !ui->maxYards->text().isEmpty();
    valid &= !ui->stepSize->text().isEmpty() && ui->stepSize->value() <= ui->maxYards->value();
    
    return valid;
}

void MainWindow::on_calcButton_clicked() {
    computeBallistics();
}

void MainWindow::computeBallistics() {
	if (validateInputs()) {
		// Clear previous data
		trajectoryData.clear();

		// Retrieve input values from UI elements
        double bc = ui->bc->value();
        double v = ui->velo->value();
        double sh = ui->sh->value();
        double angle = ui->angle->value();
        double zero = ui->zero->value();
        double windspeed = ui->windSpeed->value();
        double windangle = ui->windAngle->value();
        double temp = ui->temperature->value();
        double inHg = ui->inHg->value();
        double altitude = ui->altitude->text().toDouble(); // If needed
        double humidity = ui->humidity->text().toDouble();
        double caliber = ui->caliber->value();
        double bulletGrains = ui->grains->value();
        double bulletLength = ui->length->value();
        double twistDenominator = ui->twistRate->value(); // Assuming twistRate is the twist denominator
        int maxYards = ui->maxYards->text().toInt();
        int stepSize = ui->stepSize->text().toInt();
		
		// Determine which drag coefficient model is selected
		DragFunction dragModel;
		if (ui->g1Selected->isChecked()) {
			dragModel = (DragFunction)G1;
		} else if (ui->g7Selected->isChecked()) {
			dragModel = (DragFunction)G7;
		} else {
			// Handle the case where no drag model is selected or default to one
			dragModel = (DragFunction)G7;
		}
		
		// If the atmosphere correction checkbox is checked, correct the BC
		if (ui->useAtmosCorrection->isChecked()) {
			bc = atmosphere_correction(bc, altitude, inHg, temp, humidity);
		}
		
		// Perform ballistic calculations
		Ballistics* solution;
		double zeroangle = zero_angle(dragModel, bc, v, sh, zero, angle);
		Ballistics_solve_modified_vertDeflect(&solution, dragModel, bc, v, sh, angle, zeroangle, windspeed, windangle, caliber, bulletLength, temp, inHg, twistDenominator, v, bulletGrains, 1);

		// Store results in a member variable for later use in chart updating
		QVector<TrajectoryPoint> trajectoryData;
        for (int s = 0; s <= maxYards; s += stepSize) {
			TrajectoryPoint point;
			point.range = Ballistics_get_range(solution, s);
			point.path = Ballistics_get_path(solution, s);
			point.windage = Ballistics_get_windage(solution, s);
			trajectoryData.push_back(point);
		}
		
		Ballistics_free(solution);
		
		// Now that we have the trajectory data, update the chart
		updateTrajectoryChart(trajectoryData);	
    }
}


void MainWindow::updateTrajectoryChart(const QVector<TrajectoryPoint>& trajectoryData) {
    // Create a new line series to hold the trajectory data
    QLineSeries *series = new QLineSeries();
    
    // Add the calculated trajectory points to the series
    for (const TrajectoryPoint &point : trajectoryData) {
        series->append(point.range, point.path);
    }
    if (!is3D) {
        // Create a chart or use the existing one
        QChart *chart = ui->trajectoryChart->chart();
        if (!chart) { // If there's no chart yet, create one
            chart = new QChart();
            ui->trajectoryChart->setChart(chart);
            chart->legend()->hide();
            chart->setTitle("Bullet Trajectory");
        } else { // If a chart already exists, remove the old series
            chart->removeAllSeries();
        }

        // Add the new series to the chart
        chart->addSeries(series);

        // Optionally, create default axes or customize them as needed
        chart->createDefaultAxes();
        chart->axes(Qt::Horizontal).first()->setTitleText("Range (yards)");
        chart->axes(Qt::Vertical).first()->setTitleText("Path (inches)");

        // The chart view widget takes ownership of the chart, so no need to delete the chart
        ui->trajectoryChart->setRenderHint(QPainter::Antialiasing);
    }

    else {
        // Create or configure the 3D visualizer
        if (!ui->shotVisualizer) {
            ui->shotVisualizer = new OpenGLShotVisualizer(this);
            // Add ui->shotVisualizer to your layout or replace a placeholder widget
            // For example:
            // ui->placeholderWidget->layout()->addWidget(ui->shotVisualizer);
        }

        // Update the 3D visualizer with trajectory data
        QVector<TrajectoryPoint> trajectoryData; // Populate this with your data
        ui->shotVisualizer->setTrajectoryData(trajectoryData);
    }
}
