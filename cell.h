#ifndef CELL_H
#define CELL_H

#include "gameobject.h"

// ячейка, плитка игрового поля

class Cell: public GameObject
{
    Q_OBJECT
private:
    GameObject *my_obj;
public:
    Cell(int Width, int Height, const QPixmap &pixmap, GameObject *MyObj = nullptr, QObject *parent = nullptr);
    void setMyObject(GameObject *MyObj);
    GameObject* MyObject() const;

    ~Cell();
};

#endif // CELL_H
