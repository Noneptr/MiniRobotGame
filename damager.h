#ifndef DAMAGER_H
#define DAMAGER_H

#include "gameunit.h"

//класс - ресурс для повышения урона

class Damager: public GameUnit
{
    Q_OBJECT
public:
    Damager(QObject *parent = nullptr);
};

#endif // DAMAGER_H
