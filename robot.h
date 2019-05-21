#ifndef ROBOT_H
#define ROBOT_H

#include "gameunit.h"
#include "cell.h"
#include <iostream>

//класс - интерфейс для создания роботов

enum RobotDirect {RDDown, RDUp, RDLeft, RDRight};
enum RobotError {NotRightGameFieldError, NotPointGameFieldError};

class Robot: public GameUnit
{
    Q_OBJECT
protected:
    int _ii, _jj; // индексы текущей клетки
    RobotDirect _direct;  // направление робота
    QVector<QVector<Cell *>> *_gamefield = nullptr; // указатель на игровое поле
    QString _filedir;

protected:
    bool collection(int index, RobotDirect d);
    bool hit(int index, RobotDirect d);

public:
    Robot(const QString &Name, int Damage, int Health, int Exp,
          int Width, int Height, const QString &filedir,
          QVector<QVector<Cell*>>* gamefield,
          int PosI = 0,int PosJ = 0, QObject *parent = nullptr);

    void setGameField(QVector<QVector<Cell*>>* gamefield);
    QVector<QVector<Cell*>>* gameField() const;

    void setPosI(int p);
    int posI() const;
    void setPosJ(int p);
    int posJ() const;

    QString fileDir() const;
    void setFileDir(const QString &filedir);

    RobotDirect direct() const;
    void setDirect(RobotDirect d);

    virtual void move();

    virtual void collect();

    virtual void attack();

    virtual ~Robot();
};

#endif // ROBOT_H
