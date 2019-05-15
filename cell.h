#ifndef CELL_H
#define CELL_H

#include "gameunit.h"

// ячейка, плитка игрового поля

class Cell: public GameObject
{
    Q_OBJECT
private:
    GameUnit *my_obj;
public:
    Cell(int Width, int Height, const QPixmap &pixmap, GameObject *MyObj = nullptr, QObject *parent = nullptr);
    void setMyObject(GameUnit *MyObj);
    GameUnit *MyObject() const;

    ~Cell();
};

#endif // CELL_H
