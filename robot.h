#ifndef ROBOT_H
#define ROBOT_H

#include "gameunit.h"
#include "cell.h"
#include <QGraphicsTextItem>
#include "algorithm_help_robot.h"
#include <iostream>

//класс - интерфейс для создания роботов

enum RobotDirect {RDDown, RDUp, RDLeft, RDRight}; // перечислимы тип направлений движения робота

enum RobotError {NotRightGameFieldError, NotPointGameFieldError,
                 QVectorSizeError, NotNamesResourcesError, NotNamesEnemysError}; // перечислимый тип ошибок класа робот

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


    //========================методы взаимодействия с игровым полем и его объектами====================================
protected:
    bool collection(int index, RobotDirect d); // сбор ресурса
    bool hit(int index, RobotDirect d); // атака
    //=================================================================================================================


protected:
    Cell* _target; // текущая цель робота

public:
    Robot(const QString &Name, int Damage, int Health, int Exp,
          int Width, int Height, const QString &filedir,
          QVector<QVector<Cell*>>* gamefield,
          int PosI = 0,int PosJ = 0, QObject *parent = nullptr);

    //===================================методы доступа к полям========================================================

    void setGameField(QVector<QVector<Cell*>>* gamefield);
    QVector<QVector<Cell*>>* gameField() const;

    void setPosIJ(int pi, int pj); // установить позицию робота в поле
    int posI() const;
    int posJ() const;

    QString fileDir() const; // установить название директории с картинками
    void setFileDir(const QString &filedir);

    void setNameResources(const QVector<QString> &nameRecs); // установить имена собираемых ресурсов
    QVector<QString> nameResources() const;

    void setNameEnemys(const QVector<QString> &nameEnemys); // установить имена атакуемых врагов
    QVector<QString> nameEnemys() const;

    RobotDirect direct() const;
    void setDirect(RobotDirect d);

    void setHealth(int h);
    void setDamage(int d);
    void setExp(int e);

    QGraphicsTextItem *healthBar();
    QGraphicsTextItem *damageBar();
    QGraphicsTextItem *expBar();
    //========================================================================================================

    //================методы взаимодействия с игровым полем и его игровыми объектами==========================

    void move(); // сделать шаг

    void collect(); // собрать ресурс

    void attack(); // атаковать противника

    void action(); // принятие решения о том какое действие выполнить на текущем шаге

    void findNearestTarget(); // поиск ближайшей цели волновым алгоритмом
    //========================================================================================================

    virtual ~Robot();
};

#endif // ROBOT_H
