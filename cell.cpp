#include "cell.h"

Cell::Cell(int Width, int Height, const QPixmap &pixmap, GameObject *MyObj, QObject *parent)
    :GameObject("Cell", Width, Height, pixmap, parent), my_obj(MyObj)
{
}

void Cell::setMyObject(GameUnit *MyObj)
{
    my_obj = MyObj;
}


GameUnit* Cell::MyObject() const
{
    return my_obj;
}

Cell::~Cell()
{
}
