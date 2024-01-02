#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ballistics.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
	connect(ui->calcButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calcButton_clicked() {
    computeBallistics();
    updateTrajectoryChart();
}

void MainWindow::computeBallistics() {
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
    double inHg = ui->atmosPressureInHg->text().toDouble();
    double altitude = ui->altitude->text().toDouble(); // If needed
    double caliber = ui->caliber->text().toDouble();
    double bulletGrains = ui->grains->text().toDouble();
    double bulletLength = ui->bulletLength->text().toDouble();
    double twistDenominator = ui->twistRate->text().toDouble(); // Assuming twistRate is the twist denominator
    
    // Determine which drag coefficient model is selected
    int dragModel;
    if (ui->g1Selected->isChecked()) {
        dragModel = G1;
    } else if (ui->g7Selected->isChecked()) {
        dragModel = G7;
    } else {
        // Handle the case where no drag model is selected or default to one
        dragModel = G7;
    }
    
    // If the atmosphere correction checkbox is checked, correct the BC
    if (ui->useAtmosCorrection->isChecked()) {
        bc = Ballistics::atmosphere_correction(bc, altitude, inHg, temp, humidity);
    }
    
    // Perform ballistic calculations
    Ballistics* solution;
    double zeroangle = Ballistics::zero_angle(dragModel, bc, v, sh, zero, angle);
    int k = Ballistics::solve(&solution, dragModel, bc, v, sh, angle, zeroangle, windspeed, windangle);

    // Store results in a member variable for later use in chart updating
    QVector<TrajectoryPoint> trajectoryData;
    for (int s = 0; s <= k; s += 100) {
        TrajectoryPoint point;
        point.range = Ballistics::get_range(solution, s);
        point.path = Ballistics::get_path(solution, s);
        point.windage = Ballistics::get_windage(solution, s);
        trajectoryData.push_back(point);
    }
    
    Ballistics::free(solution);
    
    // Now that we have the trajectory data, update the chart
    updateTrajectoryChart(trajectoryData);
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
