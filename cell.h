#ifndef CELL_H
#define CELL_H

#include "gameunit.h"

// ячейка, плитка игрового поля

class Cell: public GameObject
{
    Q_OBJECT
private:
    GameUnit *my_obj;
    int _i, _j; // индексы ячейки
public:
    Cell(int Width, int Height, int ii, int jj, const QPixmap &pixmap,
         GameUnit *MyObj = nullptr, QObject *parent = nullptr);

    void setI(int ii);
    void setJ(int jj);
    int i() const;
    int j() const;

    void setMyObject(GameUnit *MyObj);
    GameUnit *MyObject() const;
    ~Cell();
};

#endif // CELL_H
