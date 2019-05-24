#ifndef DAMAGER_H
#define DAMAGER_H

#include "gameunit.h"

//класс - ресурс для повышения урона

class Damager: public GameUnit
{
    Q_OBJECT
public:
    Damager(int w, int h, QObject *parent = nullptr);
    void setDamage(int d);
};

#endif // DAMAGER_H
