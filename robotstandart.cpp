#include "robotstandart.h"

RobotStandart::RobotStandart(int Width, int Height, QVector<QVector<Cell *>> *gamefield,
             int PosI, int PosJ, QObject *parent)
    :Robot("robot1", 2, 3, 2, Width, Height, ":/rec/", gamefield, PosI, PosJ, parent)
{
}

RobotStandart::~RobotStandart()
{
    cout << "RobotStandart destroyed!!!" << endl;
}
