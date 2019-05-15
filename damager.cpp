#include "damager.h"

Damager::Damager(QObject *parent)
    :GameUnit("damager", 1, 0, 0, 50, 50, QPixmap(":/recs/resources/dmg.png"), parent)
{
}
