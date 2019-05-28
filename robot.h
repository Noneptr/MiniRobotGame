#ifndef ROBOT_H
#define ROBOT_H

#include "gameunit.h"
#include "cell.h"
#include <iostream>
#include <QGraphicsTextItem>
#include "algorithm_help_robot.h"

//класс - интерфейс для создания роботов

enum RobotDirect {RDDown, RDUp, RDLeft, RDRight};
enum RobotError {NotRightGameFieldError, NotPointGameFieldError,
                 QVectorSizeError, NotNamesResourcesError, NotNamesEnemysError};

class Robot: public GameUnit
{
    Q_OBJECT
protected:
    int _ii, _jj; // индексы текущей клетки
    RobotDirect _direct;  // направление робота
    QVector<QVector<Cell *>> *_gamefield = nullptr; // указатель на игровое поле
    QString _filedir;

    QGraphicsTextItem _health_bar; // отображение жизней робота
    QGraphicsTextItem _damage_bar; // отображение урона робота
    QGraphicsTextItem _exp_bar; // отображение опыта робота

    QVector<QString> _name_recs = {"exper", "healther", "damager"};
    QVector<QString> _name_enemys = {"robot2", "robot3"};


protected slots:
    void changeHealthBar();
    void changeDamageBar();
    void changeExpBar();

protected:
    bool collection(int index, RobotDirect d); // сбор ресурса
    bool hit(int index, RobotDirect d); // атака

protected:
    Cell* _target; // текущая цель робота

public:
    Robot(const QString &Name, int Damage, int Health, int Exp,
          int Width, int Height, const QString &filedir,
          QVector<QVector<Cell*>>* gamefield,
          int PosI = 0,int PosJ = 0, QObject *parent = nullptr);

    void setGameField(QVector<QVector<Cell*>>* gamefield);
    QVector<QVector<Cell*>>* gameField() const;

    void setPosI(int p); // установить робота в позицию в столбце
    int posI() const;
    void setPosJ(int p); // установить робота в позицию в строке
    int posJ() const;

    QString fileDir() const; // установить название директории с картинками
    void setFileDir(const QString &filedir);

    void setNameResources(const QVector<QString> &nameRecs); // установить имена собираемых ресурсов
    QVector<QString> nameResources() const;

    void setNameEnemys(const QVector<QString> &nameEnemys); // установить имена атакуемых врагов
    QVector<QString> nameEnemys() const;

    RobotDirect direct() const;
    void setDirect(RobotDirect d);

    void move(); // сделать шаг

    void collect(); // собрать ресурс

    void attack(); // атаковать противника

    void action(); // построение стратегии совершения действий

    void setHealth(int h);
    void setDamage(int d);
    void setExp(int e);

    void findNearestTarget(); // поиск ближайшей цели волновым алгоритмом


    QGraphicsTextItem *healthBar();
    QGraphicsTextItem *damageBar();
    QGraphicsTextItem *expBar();

    virtual ~Robot();
};

#endif // ROBOT_H
