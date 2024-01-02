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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_3;
    QChartView *graphicsView;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QPushButton *a;
    QWidget *formLayoutWidget;
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
    QLabel *atmosCheckLabel;
    QCheckBox *useAtmosCorrection;
    QLabel *temperatureLabel_2;
    QLineEdit *temperature;
    QLabel *airPressureInHgLabel;
    QLineEdit *inHg;
    QLabel *altitudeLabel;
    QLineEdit *altitude;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 801, 551));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(horizontalLayoutWidget);
        groupBox_3->setObjectName("groupBox_3");
        graphicsView = new QChartView(groupBox_3);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 20, 391, 391));

        horizontalLayout_2->addWidget(groupBox_3);

        groupBox = new QGroupBox(horizontalLayoutWidget);
        groupBox->setObjectName("groupBox");
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 0, 397, 549));
        groupBox_2->setAlignment(Qt::AlignCenter);
        a = new QPushButton(groupBox_2);
        a->setObjectName("a");
        a->setGeometry(QRect(60, 520, 261, 23));
        formLayoutWidget = new QWidget(groupBox_2);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 20, 391, 491));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setLabelAlignment(Qt::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout_2->setHorizontalSpacing(6);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        bcLabel = new QLabel(formLayoutWidget);
        bcLabel->setObjectName("bcLabel");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, bcLabel);

        bc = new QLineEdit(formLayoutWidget);
        bc->setObjectName("bc");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, bc);

        bcFormLabel = new QLabel(formLayoutWidget);
        bcFormLabel->setObjectName("bcFormLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, bcFormLabel);

        coeffSelector = new QHBoxLayout();
        coeffSelector->setSpacing(0);
        coeffSelector->setObjectName("coeffSelector");
        g1Selected = new QRadioButton(formLayoutWidget);
        g1Selected->setObjectName("g1Selected");

        coeffSelector->addWidget(g1Selected);

        g7Selected = new QRadioButton(formLayoutWidget);
        g7Selected->setObjectName("g7Selected");

        coeffSelector->addWidget(g7Selected);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, coeffSelector);

        veloLabel = new QLabel(formLayoutWidget);
        veloLabel->setObjectName("veloLabel");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, veloLabel);

        velo = new QLineEdit(formLayoutWidget);
        velo->setObjectName("velo");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, velo);

        shLabel = new QLabel(formLayoutWidget);
        shLabel->setObjectName("shLabel");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, shLabel);

        sh = new QLineEdit(formLayoutWidget);
        sh->setObjectName("sh");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, sh);

        bulletLengthLabel = new QLabel(formLayoutWidget);
        bulletLengthLabel->setObjectName("bulletLengthLabel");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, bulletLengthLabel);

        length = new QLineEdit(formLayoutWidget);
        length->setObjectName("length");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, length);

        bulletGrainsLabel = new QLabel(formLayoutWidget);
        bulletGrainsLabel->setObjectName("bulletGrainsLabel");

        formLayout_2->setWidget(5, QFormLayout::LabelRole, bulletGrainsLabel);

        grains = new QLineEdit(formLayoutWidget);
        grains->setObjectName("grains");

        formLayout_2->setWidget(5, QFormLayout::FieldRole, grains);

        caliberLabel = new QLabel(formLayoutWidget);
        caliberLabel->setObjectName("caliberLabel");

        formLayout_2->setWidget(6, QFormLayout::LabelRole, caliberLabel);

        caliber = new QLineEdit(formLayoutWidget);
        caliber->setObjectName("caliber");

        formLayout_2->setWidget(6, QFormLayout::FieldRole, caliber);

        atmosCheckLabel = new QLabel(formLayoutWidget);
        atmosCheckLabel->setObjectName("atmosCheckLabel");

        formLayout_2->setWidget(7, QFormLayout::LabelRole, atmosCheckLabel);

        useAtmosCorrection = new QCheckBox(formLayoutWidget);
        useAtmosCorrection->setObjectName("useAtmosCorrection");
        useAtmosCorrection->setChecked(true);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, useAtmosCorrection);

        temperatureLabel_2 = new QLabel(formLayoutWidget);
        temperatureLabel_2->setObjectName("temperatureLabel_2");

        formLayout_2->setWidget(8, QFormLayout::LabelRole, temperatureLabel_2);

        temperature = new QLineEdit(formLayoutWidget);
        temperature->setObjectName("temperature");

        formLayout_2->setWidget(8, QFormLayout::FieldRole, temperature);

        airPressureInHgLabel = new QLabel(formLayoutWidget);
        airPressureInHgLabel->setObjectName("airPressureInHgLabel");

        formLayout_2->setWidget(9, QFormLayout::LabelRole, airPressureInHgLabel);

        inHg = new QLineEdit(formLayoutWidget);
        inHg->setObjectName("inHg");

        formLayout_2->setWidget(9, QFormLayout::FieldRole, inHg);

        altitudeLabel = new QLabel(formLayoutWidget);
        altitudeLabel->setObjectName("altitudeLabel");

        formLayout_2->setWidget(10, QFormLayout::LabelRole, altitudeLabel);

        altitude = new QLineEdit(formLayoutWidget);
        altitude->setObjectName("altitude");

        formLayout_2->setWidget(10, QFormLayout::FieldRole, altitude);


        horizontalLayout_2->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, temperatureLabel_2, &QLabel::setHidden);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, temperature, &QLineEdit::setHidden);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, airPressureInHgLabel, &QLabel::setHidden);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, inHg, &QLineEdit::setHidden);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, altitudeLabel, &QLabel::setHidden);
        QObject::connect(useAtmosCorrection, &QCheckBox::toggled, altitude, &QLineEdit::setHidden);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Ballistics Visualization", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ballistics Visualization", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Parameters", nullptr));
        a->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
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
        atmosCheckLabel->setText(QCoreApplication::translate("MainWindow", "Use Atmosphere Correction?", nullptr));
        useAtmosCorrection->setText(QCoreApplication::translate("MainWindow", "Yes", nullptr));
        temperatureLabel_2->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        airPressureInHgLabel->setText(QCoreApplication::translate("MainWindow", "Air Pressure (inHg)", nullptr));
        altitudeLabel->setText(QCoreApplication::translate("MainWindow", "Altitude", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
