#include "gamefield.h"

GameField::GameField(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    :QGraphicsScene(x, y, width, height, parent)
{
    int size_cell = 50;
    int m = int(width/ size_cell);
    int n = int(height/size_cell);
    for (int i = 0; i < m; i++)
    {
        QVector<Cell*> v;
        for (int j = 0; j < n; j++)
        {
            Cell* cell = new Cell(size_cell, size_cell, QPixmap(":/recs/resources/cell.png"), nullptr, this);
            v.push_back(cell);
            this->addItem(cell);
            cell->setPos(i * size_cell, j * size_cell);
        }
        cells.push_back(v);
    }
}
