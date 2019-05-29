#ifndef ROBOTSTANDART_H
#define ROBOTSTANDART_H

#include "robot.h"

//класс RobotStandart реализация потомок интерфейса Robot

class RobotStandart: public Robot
{
public:
    RobotStandart(int Width, int Height, QVector<QVector<Cell *>> *gamefield,
                  int PosI, int PosJ, QObject *parent = nullptr);
};

#endif // ROBOTSTANDART_H
