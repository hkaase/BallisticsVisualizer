QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

INCLUDEPATH += $$PWD/lib/ballistics/include


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    $$PWD/lib/ballistics/angle.c \
    $$PWD/lib/ballistics/atmosphere.c \
    $$PWD/lib/ballistics/ballistics.c \
    $$PWD/lib/ballistics/pbr.c

HEADERS += \
    mainwindow.h \
    $$PWD/lib/ballistics/include/angle.h \
    $$PWD/lib/ballistics/include/atmosphere.h \
    $$PWD/lib/ballistics/include/ballistics.h \
    $$PWD/lib/ballistics/include/constants.h \
    $$PWD/lib/ballistics/include/drag.h \
    $$PWD/lib/ballistics/include/pbr.h \
    $$PWD/lib/ballistics/include/windage.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
