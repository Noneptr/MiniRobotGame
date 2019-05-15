#include "healther.h"

Healther::Healther(QObject *parent)
    :GameUnit("healther", 0, 1, 0, 50, 50, QPixmap(":/recs/resources/hp.png"), parent)
{
}
