#include "mainwindow.h"
#include <ballistics/ballistics.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
    connect(ui->calcButton, &QPushButton::clicked, this, &MainWindow::on_calcButton_clicked);
	connect(ui->bc, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    connect(ui->velo, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    connect(ui->sh, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    connect(ui->angle, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    connect(ui->zero, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    connect(ui->windSpeed, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    connect(ui->windAngle, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    connect(ui->temperature, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    // Skipping inHg, altitude, and humidity based on requirements
    connect(ui->caliber, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    connect(ui->grains, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    connect(ui->length, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);
    connect(ui->twistRate, &QLineEdit::textChanged, this, &MainWindow::computeBallistics);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::validateInputs() {
    bool valid = true;
    valid &= !ui->bc->text().isEmpty() && ui->bc->text().toDouble() > 0;
    valid &= !ui->velo->text().isEmpty() && ui->velo->text().toDouble() > 0;
    valid &= !ui->sh->text().isEmpty() && ui->sh->text().toDouble() > 0;
    valid &= !ui->angle->text().isEmpty() && ui->angle->text().toDouble() >= 0;
    valid &= !ui->zero->text().isEmpty() && ui->zero->text().toDouble() > 0;
    valid &= !ui->windSpeed->text().isEmpty() && ui->windSpeed->text().toDouble() >= 0;
    valid &= !ui->windAngle->text().isEmpty() && ui->windAngle->text().toDouble() >= 0;
    valid &= !ui->temperature->text().isEmpty(); // Temp could be below 0, so no need to check for > 0
    // Skipping altitude, and humidity based on requirements
	valid &= !ui->inHg->text().isEmpty();
    valid &= !ui->caliber->text().isEmpty() && ui->caliber->text().toDouble() > 0;
    valid &= !ui->grains->text().isEmpty() && ui->grains->text().toDouble() > 0;
    valid &= !ui->length->text().isEmpty() && ui->length->text().toDouble() > 0;
    valid &= !ui->twistRate->text().isEmpty() && ui->twistRate->text().toDouble() > 0;
    
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
		double bc = ui->bc->text().toDouble();
		double v = ui->velo->text().toDouble();
		double sh = ui->sh->text().toDouble();
		double angle = ui->angle->text().toDouble();
		double zero = ui->zero->text().toDouble();
		double windspeed = ui->windSpeed->text().toDouble();
		double windangle = ui->windAngle->text().toDouble();
		double temp = ui->temperature->text().toDouble();
		double inHg = ui->inHg->text().toDouble();
		double altitude = ui->altitude->text().toDouble(); // If needed
		double humidity = ui->humidity->text().toDouble();
		double caliber = ui->caliber->text().toDouble();
		double bulletGrains = ui->grains->text().toDouble();
		double bulletLength = ui->length->text().toDouble();
		double twistDenominator = ui->twistRate->text().toDouble(); // Assuming twistRate is the twist denominator
		
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
		for (int s = 0; s <= 1000; s += 1) {
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
