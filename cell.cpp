#include "cell.h"

Cell::Cell(const QString &Name, int Width, int Height, const QPixmap &pixmap, GameObject *MyObj, QGraphicsItem *parent)
    :GameObject(Name, Width, Height, pixmap, parent), my_obj(MyObj)
{
}

void Cell::setMyObject(GameObject *MyObj)
{
    my_obj = MyObj;
}
GameObject* Cell::MyObject() const
{
    return my_obj;
}

Cell::~Cell()
{
}
