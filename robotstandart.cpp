#include "robotstandart.h"

RobotStandart::RobotStandart(int Width, int Height, QVector<QVector<Cell *>> *gamefield,
             int PosI, int PosJ, QObject *parent)
    :Robot("robot1", 3, 4, 3, Width, Height, ":/rec/", gamefield, PosI, PosJ, parent)
{
}

RobotStandart::~RobotStandart()
{
    qDebug() << "RobotStandart destroyed!!!" << endl;
}
