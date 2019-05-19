#include "damager.h"

Damager::Damager(QObject *parent)
    :GameUnit("damager", 1, 0, 0, 50, 50, QPixmap(":/recs/resources/dmg.png"), parent)
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
