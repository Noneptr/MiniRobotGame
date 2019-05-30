#include "cell.h"

Cell::Cell(int Width, int Height, int ii, int jj, const QPixmap &pixmap, GameUnit *MyObj, QObject *parent)
    :GameObject(Width, Height, pixmap, parent), my_obj(MyObj), _i(ii), _j(jj)
{
}


void Cell::setI(int ii)
{
    _i = ii;
}


void Cell::setJ(int jj)
{
    _j = jj;
}


int Cell::i() const
{
    return _i;
}


int Cell::j() const
{
    return _j;
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
    my_obj = nullptr;
    qDebug() << "Cell {" << i() << "; " << j() << "} destroyed!!!" << endl;
}
