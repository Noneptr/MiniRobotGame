#include "robotbullet.h"

RobotBullet::RobotBullet(int Width, int Height, QVector<QVector<Cell *>> *gamefield,
                         int PosI, int PosJ, QObject *parent)
  :Robot("robot2", 1, 1, 1, Width, Height, ":/rec/", gamefield, PosI, PosJ, parent)
{
}

RobotBullet::~RobotBullet()
{
}
