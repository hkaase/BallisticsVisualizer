#ifndef BALLISTICSINTERFACE_H
#define BALLISTICSINTERFACE_H

#include <QObject>
#include "Ballistics.h" // Include your ballistics library header

class BallisticsInterface : public QObject
{
    Q_OBJECT

public:
    explicit BallisticsInterface(QObject *parent = nullptr);
    ~BallisticsInterface();

    // Q_INVOKABLE methods can be called from QML
    Q_INVOKABLE void calculateTrajectory(double bc, double v, double sh, double angle, double zero, double windspeed, double windangle, double temp, double inHg);

signals:
    void trajectoryCalculated(const QVariantList &range, const QVariantList &path, const QVariantList &windage);

private:
    Ballistics *ballisticsSolution;
    void freeBallisticsSolution();
};

#endif // BALLISTICSINTERFACE_H
