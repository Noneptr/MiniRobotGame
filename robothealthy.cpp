#include "robothealthy.h"

RobotHealthy::RobotHealthy(int Width, int Height, QVector<QVector<Cell *>> *gamefield,
                           int PosI, int PosJ, QObject *parent)
    :Robot("robot3", 1, 15, 10, Width, Height, ":/rec/", gamefield, PosI, PosJ, parent)
{
}
