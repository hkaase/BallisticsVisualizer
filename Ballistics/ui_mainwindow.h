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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QLabel *bcLabel;
    QLineEdit *bc;
    QLabel *bcFormLabel;
    QHBoxLayout *coeffSelector;
    QRadioButton *g1Selected;
    QRadioButton *g7Selected;
    QLabel *veloLabel;
    QLineEdit *velo;
    QLabel *shLabel;
    QLineEdit *sh;
    QLabel *bulletLengthLabel;
    QLineEdit *length;
    QLabel *bulletGrainsLabel;
    QLineEdit *grains;
    QLabel *caliberLabel;
    QLineEdit *caliber;
    QLabel *shotAngleLabel;
    QLineEdit *angle;
    QLabel *windSpeedLabel;
    QLineEdit *windSpeed;
    QLabel *windAngleLabel;
    QLineEdit *windAngle;
    QLabel *twistRateLabel;
    QLineEdit *twistRate;
    QLabel *zeroDistanceLabel;
    QLineEdit *zero;
    QLabel *atmosCheckLabel;
    QCheckBox *useAtmosCorrection;
    QLabel *airPressureInHgLabel;
    QLineEdit *inHg;
    QLabel *altitudeLabel;
    QLineEdit *altitude;
    QLabel *humidityLabel;
    QLineEdit *humidity;
    QLabel *temperatureLabel_2;
    QLineEdit *temperature;
    QPushButton *calcButton;
    QChartView *trajectoryChart;
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
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 1321, 578));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setLabelAlignment(Qt::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout_2->setHorizontalSpacing(6);
        bcLabel = new QLabel(horizontalLayoutWidget);
        bcLabel->setObjectName("bcLabel");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, bcLabel);

        bc = new QLineEdit(horizontalLayoutWidget);
        bc->setObjectName("bc");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, bc);

        bcFormLabel = new QLabel(horizontalLayoutWidget);
        bcFormLabel->setObjectName("bcFormLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, bcFormLabel);

        coeffSelector = new QHBoxLayout();
        coeffSelector->setSpacing(0);
        coeffSelector->setObjectName("coeffSelector");
        g1Selected = new QRadioButton(horizontalLayoutWidget);
        g1Selected->setObjectName("g1Selected");

        coeffSelector->addWidget(g1Selected);

        g7Selected = new QRadioButton(horizontalLayoutWidget);
        g7Selected->setObjectName("g7Selected");

        coeffSelector->addWidget(g7Selected);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, coeffSelector);

        veloLabel = new QLabel(horizontalLayoutWidget);
        veloLabel->setObjectName("veloLabel");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, veloLabel);

        velo = new QLineEdit(horizontalLayoutWidget);
        velo->setObjectName("velo");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, velo);

        shLabel = new QLabel(horizontalLayoutWidget);
        shLabel->setObjectName("shLabel");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, shLabel);

        sh = new QLineEdit(horizontalLayoutWidget);
        sh->setObjectName("sh");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, sh);

        bulletLengthLabel = new QLabel(horizontalLayoutWidget);
        bulletLengthLabel->setObjectName("bulletLengthLabel");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, bulletLengthLabel);

        length = new QLineEdit(horizontalLayoutWidget);
        length->setObjectName("length");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, length);

        bulletGrainsLabel = new QLabel(horizontalLayoutWidget);
        bulletGrainsLabel->setObjectName("bulletGrainsLabel");

        formLayout_2->setWidget(5, QFormLayout::LabelRole, bulletGrainsLabel);

        grains = new QLineEdit(horizontalLayoutWidget);
        grains->setObjectName("grains");

        formLayout_2->setWidget(5, QFormLayout::FieldRole, grains);

        caliberLabel = new QLabel(horizontalLayoutWidget);
        caliberLabel->setObjectName("caliberLabel");

        formLayout_2->setWidget(6, QFormLayout::LabelRole, caliberLabel);

        caliber = new QLineEdit(horizontalLayoutWidget);
        caliber->setObjectName("caliber");

        formLayout_2->setWidget(6, QFormLayout::FieldRole, caliber);

        shotAngleLabel = new QLabel(horizontalLayoutWidget);
        shotAngleLabel->setObjectName("shotAngleLabel");

        formLayout_2->setWidget(7, QFormLayout::LabelRole, shotAngleLabel);

        angle = new QLineEdit(horizontalLayoutWidget);
        angle->setObjectName("angle");

        formLayout_2->setWidget(7, QFormLayout::FieldRole, angle);

        windSpeedLabel = new QLabel(horizontalLayoutWidget);
        windSpeedLabel->setObjectName("windSpeedLabel");

        formLayout_2->setWidget(8, QFormLayout::LabelRole, windSpeedLabel);

        windSpeed = new QLineEdit(horizontalLayoutWidget);
        windSpeed->setObjectName("windSpeed");

        formLayout_2->setWidget(8, QFormLayout::FieldRole, windSpeed);

        windAngleLabel = new QLabel(horizontalLayoutWidget);
        windAngleLabel->setObjectName("windAngleLabel");

        formLayout_2->setWidget(9, QFormLayout::LabelRole, windAngleLabel);

        windAngle = new QLineEdit(horizontalLayoutWidget);
        windAngle->setObjectName("windAngle");

        formLayout_2->setWidget(9, QFormLayout::FieldRole, windAngle);

        twistRateLabel = new QLabel(horizontalLayoutWidget);
        twistRateLabel->setObjectName("twistRateLabel");

        formLayout_2->setWidget(10, QFormLayout::LabelRole, twistRateLabel);

        twistRate = new QLineEdit(horizontalLayoutWidget);
        twistRate->setObjectName("twistRate");

        formLayout_2->setWidget(10, QFormLayout::FieldRole, twistRate);

        zeroDistanceLabel = new QLabel(horizontalLayoutWidget);
        zeroDistanceLabel->setObjectName("zeroDistanceLabel");

        formLayout_2->setWidget(11, QFormLayout::LabelRole, zeroDistanceLabel);

        zero = new QLineEdit(horizontalLayoutWidget);
        zero->setObjectName("zero");

        formLayout_2->setWidget(11, QFormLayout::FieldRole, zero);

        atmosCheckLabel = new QLabel(horizontalLayoutWidget);
        atmosCheckLabel->setObjectName("atmosCheckLabel");

        formLayout_2->setWidget(13, QFormLayout::LabelRole, atmosCheckLabel);

        useAtmosCorrection = new QCheckBox(horizontalLayoutWidget);
        useAtmosCorrection->setObjectName("useAtmosCorrection");
        useAtmosCorrection->setEnabled(true);
        useAtmosCorrection->setChecked(false);

        formLayout_2->setWidget(13, QFormLayout::FieldRole, useAtmosCorrection);

        airPressureInHgLabel = new QLabel(horizontalLayoutWidget);
        airPressureInHgLabel->setObjectName("airPressureInHgLabel");
        airPressureInHgLabel->setEnabled(false);

        formLayout_2->setWidget(15, QFormLayout::LabelRole, airPressureInHgLabel);

        inHg = new QLineEdit(horizontalLayoutWidget);
        inHg->setObjectName("inHg");
        inHg->setEnabled(false);

        formLayout_2->setWidget(15, QFormLayout::FieldRole, inHg);

        altitudeLabel = new QLabel(horizontalLayoutWidget);
        altitudeLabel->setObjectName("altitudeLabel");
        altitudeLabel->setEnabled(false);

        formLayout_2->setWidget(16, QFormLayout::LabelRole, altitudeLabel);

        altitude = new QLineEdit(horizontalLayoutWidget);
        altitude->setObjectName("altitude");
        altitude->setEnabled(false);

        formLayout_2->setWidget(16, QFormLayout::FieldRole, altitude);

        humidityLabel = new QLabel(horizontalLayoutWidget);
        humidityLabel->setObjectName("humidityLabel");
        humidityLabel->setEnabled(false);

        formLayout_2->setWidget(17, QFormLayout::LabelRole, humidityLabel);

        humidity = new QLineEdit(horizontalLayoutWidget);
        humidity->setObjectName("humidity");
        humidity->setEnabled(false);

        formLayout_2->setWidget(17, QFormLayout::FieldRole, humidity);

        temperatureLabel_2 = new QLabel(horizontalLayoutWidget);
        temperatureLabel_2->setObjectName("temperatureLabel_2");
        temperatureLabel_2->setEnabled(true);
        temperatureLabel_2->setProperty("setHidden", QVariant(true));

        formLayout_2->setWidget(12, QFormLayout::LabelRole, temperatureLabel_2);

        temperature = new QLineEdit(horizontalLayoutWidget);
        temperature->setObjectName("temperature");
        temperature->setEnabled(true);
        temperature->setProperty("setHidden", QVariant(true));

        formLayout_2->setWidget(12, QFormLayout::FieldRole, temperature);


        verticalLayout->addLayout(formLayout_2);

        calcButton = new QPushButton(horizontalLayoutWidget);
        calcButton->setObjectName("calcButton");

        verticalLayout->addWidget(calcButton);


        horizontalLayout_2->addLayout(verticalLayout);

        trajectoryChart = new QChartView(horizontalLayoutWidget);
        trajectoryChart->setObjectName("trajectoryChart");

        horizontalLayout_2->addWidget(trajectoryChart);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, temperatureLabel_2, &QLabel::setEnabled);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, temperature, &QLineEdit::setEnabled);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, airPressureInHgLabel, &QLabel::setEnabled);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, inHg, &QLineEdit::setEnabled);
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
        bc->setText(QString());
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
        atmosCheckLabel->setText(QCoreApplication::translate("MainWindow", "Use Atmosphere Correction?", nullptr));
        useAtmosCorrection->setText(QCoreApplication::translate("MainWindow", "Yes", nullptr));
        airPressureInHgLabel->setText(QCoreApplication::translate("MainWindow", "Air Pressure (inHg)", nullptr));
        altitudeLabel->setText(QCoreApplication::translate("MainWindow", "Altitude", nullptr));
        humidityLabel->setText(QCoreApplication::translate("MainWindow", "Humidity", nullptr));
        temperatureLabel_2->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        temperature->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        calcButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
