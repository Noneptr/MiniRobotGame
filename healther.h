#ifndef HEALTHER_H
#define HEALTHER_H

#include "gameunit.h"

//класс - ресурс для повышения здоровья

class Healther: public GameUnit
{
    Q_OBJECT
public:
    Healther(QObject *parent = nullptr);
    void setHealth(int h);
    ~Healther();
};

#endif // HEALTHER_H
