#include "exper.h"

Exper::Exper(int w, int h, QObject *parent)
    :GameUnit("exper", 0, 0, 1, w, h, QPixmap(":/rec/resources/exp.png"), parent)
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


Exper::~Exper()
{
    cout << "Exper destroyed!!!" << endl;
}
