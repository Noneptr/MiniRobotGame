#ifndef ROBOT_H
#define ROBOT_H

#include "gameunit.h"
#include "gamefield.h"

//класс - интерфейс для создания роботов

enum DirectRobot {up, down, left, right};

class Robot: public GameUnit
{
    Q_OBJECT
protected:
    int _ii, _jj; // индексы текущей клетки
    QVector<QVector<Cell *>> *_gamefield; // указатель на игровое поле
public:
    Robot(const QString &Name, int Damage, int Health, int Exp, int Width, int Height, const QPixmap &pixmap, QObject *parent = nullptr);
    ~Robot();
};

#endif // ROBOT_H
