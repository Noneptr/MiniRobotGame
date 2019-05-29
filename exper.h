#ifndef EXPER_H
#define EXPER_H

#include "gameunit.h"

//класс - ресурс для повышения опыта

class Exper: public GameUnit
{
    Q_OBJECT
public:
    Exper(int w, int h, QObject *parent = nullptr);
    void setExp(int e);
    ~Exper();
};

#endif // EXPER_H
