#ifndef GAMEFIELD_H
#define GAMEFIELD_H


#include <QGraphicsScene>
#include <QTimer>
#include <ctime>

#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include "robotstandart.h"
#include "robotbullet.h"
#include "robothealthy.h"
#include "exper.h"
#include "damager.h"
#include "healther.h"


// класс - игровое поле, позволяет запускать и управлять симуляцией

class GameField : public QGraphicsScene
{
    Q_OBJECT

private:
    QVector<QVector<Cell*>> _cells; // матрица ячеек
    QTimer _timer;
    QVector<QString> nrobots = {"robot1", "robot2", "robot3"};
    QVector<QString> nresources = {"healther", "exper", "damager"};
    int _ticks = 0;

public:
    GameField(qreal x, qreal y, qreal width, qreal height,
              int size_cell, int interval, QObject *parent = nullptr);

public slots:
    void playGame();                                // запустить симуляцию
    void playStepGame();                            // запустить один шаг симуляции
    void stopGame();                                // остановить симуляцию
    void setIntervalGame(int interval);             // установить интервал таймера симуляции
    void removeItemRobot(Robot *r);                 // слот отчиски Robot с игрового поля и отчиска занимаемой им памяти
    void removeItemGameUnit(GameUnit *obj);         // слот отчиски GameUnit с игрового поля и отчиска занимаемой им памяти
    void clearCells();                              // отчистить ячейки игрового поля

    void createRobot(const QString &name_robot, int i, int j);    // создать опред. робота на опред. ячейке
    void createResource(const QString &name_rec, int i, int j);   // создать опред. ресурса на опред. ячейке
    void createRobot();                                         // создать на случайной ячейке случайного нового робота
    void createResource();                                      // создать на случайной ячейке случайный новый ресурс

public:
    ~GameField();
};

#endif // GAMEFIELD_H
