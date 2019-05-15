#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QObject>
#include <QGraphicsScene>
#include "cell.h"

class GameField : public QGraphicsScene
{
    Q_OBJECT
private:
    QVector<QVector<Cell*>> cells; // матрица ячеек
public:
    GameField(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
};

#endif // GAMEFIELD_H
