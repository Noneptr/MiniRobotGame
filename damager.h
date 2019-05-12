#ifndef DAMAGER_H
#define DAMAGER_H

#include "resource.h"

class DamageR: public Resource
{
    Q_OBJECT
public:
    DamageR(QObject *parent = nullptr);
    ~DamageR();
};

#endif // DAMAGER_H
