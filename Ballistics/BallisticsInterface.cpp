#include "BallisticsInterface.h"
#include <QVariantList>

BallisticsInterface::BallisticsInterface(QObject *parent)
    : QObject(parent), ballisticsSolution(nullptr)
{
}

BallisticsInterface::~BallisticsInterface()
{
    freeBallisticsSolution();
}

void BallisticsInterface::calculateTrajectory(double bc, double v, double sh, double angle, double zero, double windspeed, double windangle, double temp, double inHg)
{
    freeBallisticsSolution(); // Free previous solution if any

    // Here you'll call the functions from your Ballistics library to calculate the trajectory
    // For example, using Ballistics_solve function
    int maxRange = Ballistics_solve(&ballisticsSolution, /* your parameters */);

    QVariantList rangeList;
    QVariantList pathList;
    QVariantList windageList;

    for (int i = 0; i <= maxRange; i += 100) { // Adjust step size as needed
        rangeList.append(Ballistics_get_range(ballisticsSolution, i));
        pathList.append(Ballistics_get_path(ballisticsSolution, i));
        windageList.append(Ballistics_get_windage(ballisticsSolution, i));
    }

    emit trajectoryCalculated(rangeList, pathList, windageList);
}

void BallisticsInterface::freeBallisticsSolution()
{
    if (ballisticsSolution != nullptr) {
        Ballistics_free(ballisticsSolution);
        ballisticsSolution = nullptr;
    }
}
