#include "damager.h"

Damager::Damager(int w, int h, QObject *parent)
    :GameUnit("damager", 1, 0, 0, w, h, QPixmap(":/rec/resources/dmg.png"), parent)
{
}


void Damager::setDamage(int d)
{
    if (d > 0)
    {
        _damage = d;
    }
    else
    {
        _damage = 1;
    }
}


Damager::~Damager()
{
    cout << "Damager destroyed!!!" << endl;
}
