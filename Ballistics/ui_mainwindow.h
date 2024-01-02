/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <openglshotvisualizer.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *ballisticsForm;
    QLabel *bcLabel;
    QLabel *bcFormLabel;
    QHBoxLayout *coeffSelector;
    QRadioButton *g1Selected;
    QRadioButton *g7Selected;
    QLabel *veloLabel;
    QLabel *shLabel;
    QLabel *bulletLengthLabel;
    QLabel *bulletGrainsLabel;
    QLabel *caliberLabel;
    QLabel *shotAngleLabel;
    QLabel *windSpeedLabel;
    QLabel *windAngleLabel;
    QLabel *twistRateLabel;
    QLabel *zeroDistanceLabel;
    QLabel *temperatureLabel_2;
    QLabel *airPressureInHgLabel;
    QLabel *atmosCheckLabel;
    QCheckBox *useAtmosCorrection;
    QLabel *altitudeLabel;
    QLineEdit *altitude;
    QLabel *humidityLabel;
    QLineEdit *humidity;
    QSpinBox *velo;
    QDoubleSpinBox *length;
    QDoubleSpinBox *sh;
    QDoubleSpinBox *bc;
    QDoubleSpinBox *grains;
    QDoubleSpinBox *caliber;
    QDoubleSpinBox *angle;
    QDoubleSpinBox *windSpeed;
    QDoubleSpinBox *windAngle;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *twistRate;
    QLabel *twistInLabel;
    QDoubleSpinBox *zero;
    QDoubleSpinBox *temperature;
    QDoubleSpinBox *inHg;
    QPushButton *calcButton;
    QVBoxLayout *verticalLayout_3;
    OpenGLShotVisualizer *shotVisualizer;
    QChartView *trajectoryChart;
    QFormLayout *chartForm;
    QLabel *viewTypeLabel;
    QLabel *testLabel;
    QSpinBox *stepSize;
    QLabel *maxYardsLabel;
    QSpinBox *maxYards;
    QPushButton *toggleViewButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1323, 603);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 1321, 581));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        ballisticsForm = new QFormLayout();
        ballisticsForm->setObjectName("ballisticsForm");
        ballisticsForm->setLabelAlignment(Qt::AlignCenter);
        ballisticsForm->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        ballisticsForm->setHorizontalSpacing(6);
        bcLabel = new QLabel(horizontalLayoutWidget);
        bcLabel->setObjectName("bcLabel");

        ballisticsForm->setWidget(0, QFormLayout::LabelRole, bcLabel);

        bcFormLabel = new QLabel(horizontalLayoutWidget);
        bcFormLabel->setObjectName("bcFormLabel");

        ballisticsForm->setWidget(1, QFormLayout::LabelRole, bcFormLabel);

        coeffSelector = new QHBoxLayout();
        coeffSelector->setSpacing(0);
        coeffSelector->setObjectName("coeffSelector");
        g1Selected = new QRadioButton(horizontalLayoutWidget);
        g1Selected->setObjectName("g1Selected");

        coeffSelector->addWidget(g1Selected);

        g7Selected = new QRadioButton(horizontalLayoutWidget);
        g7Selected->setObjectName("g7Selected");
        g7Selected->setEnabled(false);
        g7Selected->setChecked(true);

        coeffSelector->addWidget(g7Selected);


        ballisticsForm->setLayout(1, QFormLayout::FieldRole, coeffSelector);

        veloLabel = new QLabel(horizontalLayoutWidget);
        veloLabel->setObjectName("veloLabel");

        ballisticsForm->setWidget(2, QFormLayout::LabelRole, veloLabel);

        shLabel = new QLabel(horizontalLayoutWidget);
        shLabel->setObjectName("shLabel");

        ballisticsForm->setWidget(4, QFormLayout::LabelRole, shLabel);

        bulletLengthLabel = new QLabel(horizontalLayoutWidget);
        bulletLengthLabel->setObjectName("bulletLengthLabel");

        ballisticsForm->setWidget(6, QFormLayout::LabelRole, bulletLengthLabel);

        bulletGrainsLabel = new QLabel(horizontalLayoutWidget);
        bulletGrainsLabel->setObjectName("bulletGrainsLabel");

        ballisticsForm->setWidget(8, QFormLayout::LabelRole, bulletGrainsLabel);

        caliberLabel = new QLabel(horizontalLayoutWidget);
        caliberLabel->setObjectName("caliberLabel");

        ballisticsForm->setWidget(9, QFormLayout::LabelRole, caliberLabel);

        shotAngleLabel = new QLabel(horizontalLayoutWidget);
        shotAngleLabel->setObjectName("shotAngleLabel");

        ballisticsForm->setWidget(10, QFormLayout::LabelRole, shotAngleLabel);

        windSpeedLabel = new QLabel(horizontalLayoutWidget);
        windSpeedLabel->setObjectName("windSpeedLabel");

        ballisticsForm->setWidget(11, QFormLayout::LabelRole, windSpeedLabel);

        windAngleLabel = new QLabel(horizontalLayoutWidget);
        windAngleLabel->setObjectName("windAngleLabel");

        ballisticsForm->setWidget(12, QFormLayout::LabelRole, windAngleLabel);

        twistRateLabel = new QLabel(horizontalLayoutWidget);
        twistRateLabel->setObjectName("twistRateLabel");

        ballisticsForm->setWidget(13, QFormLayout::LabelRole, twistRateLabel);

        zeroDistanceLabel = new QLabel(horizontalLayoutWidget);
        zeroDistanceLabel->setObjectName("zeroDistanceLabel");

        ballisticsForm->setWidget(14, QFormLayout::LabelRole, zeroDistanceLabel);

        temperatureLabel_2 = new QLabel(horizontalLayoutWidget);
        temperatureLabel_2->setObjectName("temperatureLabel_2");
        temperatureLabel_2->setEnabled(true);
        temperatureLabel_2->setProperty("setHidden", QVariant(true));

        ballisticsForm->setWidget(15, QFormLayout::LabelRole, temperatureLabel_2);

        airPressureInHgLabel = new QLabel(horizontalLayoutWidget);
        airPressureInHgLabel->setObjectName("airPressureInHgLabel");
        airPressureInHgLabel->setEnabled(true);

        ballisticsForm->setWidget(16, QFormLayout::LabelRole, airPressureInHgLabel);

        atmosCheckLabel = new QLabel(horizontalLayoutWidget);
        atmosCheckLabel->setObjectName("atmosCheckLabel");

        ballisticsForm->setWidget(17, QFormLayout::LabelRole, atmosCheckLabel);

        useAtmosCorrection = new QCheckBox(horizontalLayoutWidget);
        useAtmosCorrection->setObjectName("useAtmosCorrection");
        useAtmosCorrection->setEnabled(true);
        useAtmosCorrection->setChecked(false);

        ballisticsForm->setWidget(17, QFormLayout::FieldRole, useAtmosCorrection);

        altitudeLabel = new QLabel(horizontalLayoutWidget);
        altitudeLabel->setObjectName("altitudeLabel");
        altitudeLabel->setEnabled(false);

        ballisticsForm->setWidget(20, QFormLayout::LabelRole, altitudeLabel);

        altitude = new QLineEdit(horizontalLayoutWidget);
        altitude->setObjectName("altitude");
        altitude->setEnabled(false);

        ballisticsForm->setWidget(20, QFormLayout::FieldRole, altitude);

        humidityLabel = new QLabel(horizontalLayoutWidget);
        humidityLabel->setObjectName("humidityLabel");
        humidityLabel->setEnabled(false);

        ballisticsForm->setWidget(21, QFormLayout::LabelRole, humidityLabel);

        humidity = new QLineEdit(horizontalLayoutWidget);
        humidity->setObjectName("humidity");
        humidity->setEnabled(false);

        ballisticsForm->setWidget(21, QFormLayout::FieldRole, humidity);

        velo = new QSpinBox(horizontalLayoutWidget);
        velo->setObjectName("velo");
        velo->setMinimum(100);
        velo->setMaximum(5000);
        velo->setValue(2800);

        ballisticsForm->setWidget(2, QFormLayout::FieldRole, velo);

        length = new QDoubleSpinBox(horizontalLayoutWidget);
        length->setObjectName("length");
        length->setMinimum(0.100000000000000);
        length->setMaximum(5.000000000000000);
        length->setValue(1.200000000000000);

        ballisticsForm->setWidget(6, QFormLayout::FieldRole, length);

        sh = new QDoubleSpinBox(horizontalLayoutWidget);
        sh->setObjectName("sh");
        sh->setMaximum(5.000000000000000);
        sh->setValue(1.500000000000000);

        ballisticsForm->setWidget(4, QFormLayout::FieldRole, sh);

        bc = new QDoubleSpinBox(horizontalLayoutWidget);
        bc->setObjectName("bc");
        bc->setMinimum(0.100000000000000);
        bc->setMaximum(1.000000000000000);
        bc->setValue(0.300000000000000);

        ballisticsForm->setWidget(0, QFormLayout::FieldRole, bc);

        grains = new QDoubleSpinBox(horizontalLayoutWidget);
        grains->setObjectName("grains");
        grains->setMinimum(10.000000000000000);
        grains->setMaximum(500.000000000000000);
        grains->setValue(168.000000000000000);

        ballisticsForm->setWidget(8, QFormLayout::FieldRole, grains);

        caliber = new QDoubleSpinBox(horizontalLayoutWidget);
        caliber->setObjectName("caliber");
        caliber->setDecimals(3);
        caliber->setMinimum(0.100000000000000);
        caliber->setMaximum(5.000000000000000);
        caliber->setValue(0.308000000000000);

        ballisticsForm->setWidget(9, QFormLayout::FieldRole, caliber);

        angle = new QDoubleSpinBox(horizontalLayoutWidget);
        angle->setObjectName("angle");
        angle->setMinimum(-360.000000000000000);
        angle->setMaximum(360.000000000000000);

        ballisticsForm->setWidget(10, QFormLayout::FieldRole, angle);

        windSpeed = new QDoubleSpinBox(horizontalLayoutWidget);
        windSpeed->setObjectName("windSpeed");
        windSpeed->setMaximum(100.000000000000000);

        ballisticsForm->setWidget(11, QFormLayout::FieldRole, windSpeed);

        windAngle = new QDoubleSpinBox(horizontalLayoutWidget);
        windAngle->setObjectName("windAngle");
        windAngle->setMinimum(-360.000000000000000);
        windAngle->setMaximum(360.000000000000000);

        ballisticsForm->setWidget(12, QFormLayout::FieldRole, windAngle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        twistRate = new QDoubleSpinBox(horizontalLayoutWidget);
        twistRate->setObjectName("twistRate");
        twistRate->setMinimum(0.100000000000000);
        twistRate->setMaximum(30.000000000000000);
        twistRate->setValue(8.000000000000000);

        horizontalLayout->addWidget(twistRate);

        twistInLabel = new QLabel(horizontalLayoutWidget);
        twistInLabel->setObjectName("twistInLabel");

        horizontalLayout->addWidget(twistInLabel);


        ballisticsForm->setLayout(13, QFormLayout::FieldRole, horizontalLayout);

        zero = new QDoubleSpinBox(horizontalLayoutWidget);
        zero->setObjectName("zero");
        zero->setMaximum(1000.000000000000000);
        zero->setValue(100.000000000000000);

        ballisticsForm->setWidget(14, QFormLayout::FieldRole, zero);

        temperature = new QDoubleSpinBox(horizontalLayoutWidget);
        temperature->setObjectName("temperature");
        temperature->setMinimum(-100.000000000000000);
        temperature->setMaximum(150.000000000000000);

        ballisticsForm->setWidget(15, QFormLayout::FieldRole, temperature);

        inHg = new QDoubleSpinBox(horizontalLayoutWidget);
        inHg->setObjectName("inHg");
        inHg->setMaximum(250.000000000000000);
        inHg->setValue(29.920000000000002);

        ballisticsForm->setWidget(16, QFormLayout::FieldRole, inHg);


        verticalLayout->addLayout(ballisticsForm);

        calcButton = new QPushButton(horizontalLayoutWidget);
        calcButton->setObjectName("calcButton");

        verticalLayout->addWidget(calcButton);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        shotVisualizer = new OpenGLShotVisualizer(horizontalLayoutWidget);
        shotVisualizer->setObjectName("shotVisualizer");

        verticalLayout_3->addWidget(shotVisualizer);

        trajectoryChart = new QChartView(horizontalLayoutWidget);
        trajectoryChart->setObjectName("trajectoryChart");

        verticalLayout_3->addWidget(trajectoryChart);

        chartForm = new QFormLayout();
        chartForm->setObjectName("chartForm");
        viewTypeLabel = new QLabel(horizontalLayoutWidget);
        viewTypeLabel->setObjectName("viewTypeLabel");

        chartForm->setWidget(1, QFormLayout::LabelRole, viewTypeLabel);

        testLabel = new QLabel(horizontalLayoutWidget);
        testLabel->setObjectName("testLabel");

        chartForm->setWidget(2, QFormLayout::LabelRole, testLabel);

        stepSize = new QSpinBox(horizontalLayoutWidget);
        stepSize->setObjectName("stepSize");
        stepSize->setMinimum(1);
        stepSize->setMaximum(100);
        stepSize->setValue(50);

        chartForm->setWidget(2, QFormLayout::FieldRole, stepSize);

        maxYardsLabel = new QLabel(horizontalLayoutWidget);
        maxYardsLabel->setObjectName("maxYardsLabel");

        chartForm->setWidget(3, QFormLayout::LabelRole, maxYardsLabel);

        maxYards = new QSpinBox(horizontalLayoutWidget);
        maxYards->setObjectName("maxYards");
        maxYards->setMinimum(50);
        maxYards->setMaximum(2000);
        maxYards->setValue(500);

        chartForm->setWidget(3, QFormLayout::FieldRole, maxYards);

        toggleViewButton = new QPushButton(horizontalLayoutWidget);
        toggleViewButton->setObjectName("toggleViewButton");

        chartForm->setWidget(1, QFormLayout::FieldRole, toggleViewButton);


        verticalLayout_3->addLayout(chartForm);


        horizontalLayout_2->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, altitudeLabel, &QLabel::setEnabled);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, altitude, &QLineEdit::setEnabled);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, humidity, &QLineEdit::setEnabled);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, humidityLabel, &QLabel::setEnabled);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Ballistics Calculator", nullptr));
        bcLabel->setText(QCoreApplication::translate("MainWindow", "BC", nullptr));
        bcFormLabel->setText(QCoreApplication::translate("MainWindow", "G1 or G7?", nullptr));
        g1Selected->setText(QCoreApplication::translate("MainWindow", "G1", nullptr));
        g7Selected->setText(QCoreApplication::translate("MainWindow", "G7", nullptr));
        veloLabel->setText(QCoreApplication::translate("MainWindow", "Initial Velocity", nullptr));
        shLabel->setText(QCoreApplication::translate("MainWindow", "Sight Height", nullptr));
        bulletLengthLabel->setText(QCoreApplication::translate("MainWindow", "Bullet Length", nullptr));
        bulletGrainsLabel->setText(QCoreApplication::translate("MainWindow", "Bullet Grains", nullptr));
        caliberLabel->setText(QCoreApplication::translate("MainWindow", "Caliber", nullptr));
        shotAngleLabel->setText(QCoreApplication::translate("MainWindow", "Shot Angle", nullptr));
        windSpeedLabel->setText(QCoreApplication::translate("MainWindow", "Wind Speed", nullptr));
        windAngleLabel->setText(QCoreApplication::translate("MainWindow", "Wind Angle", nullptr));
        twistRateLabel->setText(QCoreApplication::translate("MainWindow", "Twist Rate", nullptr));
        zeroDistanceLabel->setText(QCoreApplication::translate("MainWindow", "Zero Distance", nullptr));
        temperatureLabel_2->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        airPressureInHgLabel->setText(QCoreApplication::translate("MainWindow", "Air Pressure (inHg)", nullptr));
        atmosCheckLabel->setText(QCoreApplication::translate("MainWindow", "Use Atmosphere Correction?", nullptr));
        useAtmosCorrection->setText(QCoreApplication::translate("MainWindow", "Yes", nullptr));
        altitudeLabel->setText(QCoreApplication::translate("MainWindow", "Altitude", nullptr));
        humidityLabel->setText(QCoreApplication::translate("MainWindow", "Humidity", nullptr));
        twistInLabel->setText(QCoreApplication::translate("MainWindow", ": in", nullptr));
        calcButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        viewTypeLabel->setText(QString());
        testLabel->setText(QCoreApplication::translate("MainWindow", "Step Size", nullptr));
        maxYardsLabel->setText(QCoreApplication::translate("MainWindow", "Max Yards", nullptr));
        toggleViewButton->setText(QCoreApplication::translate("MainWindow", "Toggle 3D", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
