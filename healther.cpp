#include "healther.h"

Healther::Healther(QObject *parent)
    :GameUnit("healther", 0, 1, 0, 50, 50, QPixmap(":/recs/resources/hp.png"), parent)
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
