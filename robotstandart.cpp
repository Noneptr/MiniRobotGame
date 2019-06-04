#include "robotstandart.h"

RobotStandart::RobotStandart(int Width, int Height, QVector<QVector<Cell *>> *gamefield,
             int PosI, int PosJ, QObject *parent)
    :Robot("robot1", 1, 1, 1, Width, Height, ":/rec/", gamefield, PosI, PosJ, parent)
{
}

RobotStandart::~RobotStandart()
{
}
