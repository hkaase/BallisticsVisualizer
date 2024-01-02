#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QtCharts>

#include "ui_mainwindow.h"
#include "TrajectoryPoint.h"




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
    void toggleView();
	bool validateInputs();
    void updateTrajectoryChart(const QVector<TrajectoryPoint>&);
    void computeBallistics();
	QVector<TrajectoryPoint> trajectoryData;
    bool is3D;


private slots:
    void on_calcButton_clicked(); // Slot for handling button click
};
#endif // MAINWINDOW_H
