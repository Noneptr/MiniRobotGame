#ifndef ROBOTBULLET_H
#define ROBOTBULLET_H

#include "robot.h"

//класс RobotBullet реализация потомок интерфейса Robot

class RobotBullet: public Robot
{
public:
    RobotBullet(int Width, int Height, QVector<QVector<Cell *>> *gamefield,
                int PosI, int PosJ, QObject *parent = nullptr);
    ~RobotBullet();
};

#endif // ROBOTBULLET_H
