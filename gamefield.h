#ifndef GAMEFIELD_H
#define GAMEFIELD_H


#include <QGraphicsScene>
#include <QTimer>
#include <ctime>
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
    QVector<QString> nrobots = {"rstd", "rbul", "rhp"};
    QVector<QString> nresources = {"hp", "exp", "dmg"};
    int _ticks = 0;

    Robot* robot = nullptr;
    GameUnit* rec = nullptr;
public:
    GameField(qreal x, qreal y, qreal width, qreal height,
              int size_cell, int interval, QObject *parent = nullptr);
public slots:
    void createRobot();                             // создать на случайной ячейке случайного нового робота
    void createResource();                          // создать на случайной ячейке случайный новый ресурс
    void playGame();                                // запустить симуляцию
    void playStepGame();                            // запустить один шаг симуляции
    void stopGame();                                // остановить симуляцию
    void setIntervalGame(int interval);             // установить интервал таймера симуляции
    void removeItemRobot(Robot *r);                 // слот отчиски Robot с игрового поля и отчиска занимаемой им памяти
    void removeItemGameUnit(GameUnit *obj);         // слот отчиски GameUnit с игрового поля и отчиска занимаемой им памяти

public:
    ~GameField();
};

#endif // GAMEFIELD_H
