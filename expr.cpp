#include "expr.h"


ExpR::ExpR(QObject *parent)
    :Resource(0, 0, 1, "ExpResource", 50, 50, QPixmap(":/recs/resources/exp.png"), parent)
{
}


ExpR::~ExpR()
{
}
