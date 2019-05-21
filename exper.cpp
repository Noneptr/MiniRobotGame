#include "exper.h"

Exper::Exper(QObject *parent)
    :GameUnit("exper", 0, 0, 1, 50, 50, QPixmap(":/rec/resources/exp.png"), parent)
{
}


void Exper::setExp(int e)
{
    if (e > 0)
    {
        _exp = e;
    }
    else
    {
        _exp = 1;
    }
}
