#ifndef ROBOT_H
#define ROBOT_H

#include "gameunit.h"
#include "gamefield.h"

//класс - интерфейс для создания роботов

enum RobotDirect {up, down, left, right};
enum RobotError {NotRightGameFieldError, NotPointGameFieldError};

class Robot: public GameUnit
{
    Q_OBJECT
protected:
    int _ii, _jj; // индексы текущей клетки
    QVector<QVector<Cell *>> *_gamefield = nullptr; // указатель на игровое поле
public:
    Robot(const QString &Name, int Damage, int Health, int Exp,
          int Width, int Height, const QPixmap &pixmap, QVector<QVector<Cell*>>* gamefield,
          int PosI = 0,int PosJ = 0, QObject *parent = nullptr);

    void setGameField(QVector<QVector<Cell*>>* gamefield);
    QVector<QVector<Cell*>>* gameField() const;

    void setPosI(int p);
    int posI() const;
    void setPosJ(int p);
    int posJ() const;

    virtual void move(RobotDirect direct);

    virtual ~Robot();
};

#endif // ROBOT_H
