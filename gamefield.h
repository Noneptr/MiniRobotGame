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

const int count_dead_obj = 100;

class GameField : public QGraphicsScene
{
    Q_OBJECT

private:
    QVector<QVector<Cell*>> _cells; // матрица ячеек
    QTimer _timer;
    QVector<QString> nrobots = {"rstd", "rbul", "rhp"};
    QVector<QString> nresources = {"hp", "exp", "dmg"};
    int _count = 0;
public:
    GameField(qreal x, qreal y, qreal width, qreal height,
              int size_cell, int interval, QObject *parent = nullptr);
public slots:
    void createRobot();
    void createResource();
    void playGame();
    void playStepGame();
    void stopGame();
    void setIntervalGame(int interval);
};

#endif // GAMEFIELD_H
