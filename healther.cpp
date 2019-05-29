#include "healther.h"

Healther::Healther(int w, int h, QObject *parent)
    :GameUnit("healther", 0, 1, 0, w, h, QPixmap(":/rec/resources/hp.png"), parent)
{
}


void Healther::setHealth(int h)
{
    if (h > 0)
    {
        _health = h;
    }
    else
    {
        _health = 1;
    }
}

Healther::~Healther()
{
    qDebug() << "Healther destroyed!!!" << endl;
}
