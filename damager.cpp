#include "damager.h"

DamageR::DamageR(QObject *parent)
    :Resource(1, 0, 0, "DamageResource", 50, 50, QPixmap(":/recs/resources/dmg.png"), parent)
{
}


DamageR::~DamageR()
{
}
