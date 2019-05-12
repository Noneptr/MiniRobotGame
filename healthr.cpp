#include "healthr.h"

HealthR::HealthR(QObject *parent)
    :Resource(0, 1, 0, "HealthResource", 50, 50, QPixmap(":/recs/resources/hp.png"), parent)
{
}


HealthR::~HealthR()
{
}
