#include "robotbullet.h"

RobotBullet::RobotBullet(int Width, int Height, QVector<QVector<Cell *>> *gamefield,
                         int PosI, int PosJ, QObject *parent)
  :Robot("robot2", 6, 2, 6, Width, Height, ":/rec/", gamefield, PosI, PosJ, parent)
{
}

RobotBullet::~RobotBullet()
{
}
