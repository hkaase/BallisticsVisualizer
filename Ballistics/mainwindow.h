#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "ui_mainwindow.h" // Include the UI header

using namespace QtCharts; // Use the QtCharts namespace to easily access chart classes

// Struct for trajectory data
struct TrajectoryPoint {
    double range;
    double path;
    double windage;
    // Add other fields if necessary
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
	void updateTrajectoryChart(const QVector<TrajectoryPoint>);
    void computeBallistics();
	QVector<TrajectoryPoint> trajectoryData;


private slots:
    void on_calcButton_clicked(); // Slot for handling button click
};
#endif // MAINWINDOW_H
