#ifndef EXPER_H
#define EXPER_H

#include "gameunit.h"

//класс - ресурс для повышения опыта

class Exper: public GameUnit
{
    Q_OBJECT
public:
    Exper(QObject *parent = nullptr);
    void setExp(int e);
};

#endif // EXPER_H
