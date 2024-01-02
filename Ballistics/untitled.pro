QT       += core gui charts opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

INCLUDEPATH += /usr/local/include

FORMS += \
    mainwindow.ui

# LIBS += -L/usr/local/lib -lballistics
# Distinguish between native and WASM builds

unix:!wasm {
    LIBS += -L/usr/local/lib -lballistics
    INCLUDEPATH += /usr/local/include
}

wasm {
    LIBS += -L/usr/local/lib/wasm -lballistics
    INCLUDEPATH += /usr/local/include/wasm
}



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    openglshotvisualizer.cpp

HEADERS += \
    TrajectoryPoint.h \
    mainwindow.h \
    openglshotvisualizer.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



