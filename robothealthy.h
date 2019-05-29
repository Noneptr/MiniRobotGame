#ifndef ROBOTHEALTHY_H
#define ROBOTHEALTHY_H

#include "robot.h"

//класс RobotHealthy реализация потомок интерфейса Robot

class RobotHealthy: public Robot
{
public:
    RobotHealthy(int Width, int Height, QVector<QVector<Cell *>> *gamefield,
                 int PosI, int PosJ, QObject *parent = nullptr);

    ~RobotHealthy();
};

#endif // ROBOTHEALTHY_H
