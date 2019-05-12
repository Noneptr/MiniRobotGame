#ifndef HEALTHR_H
#define HEALTHR_H

#include "resource.h"

class HealthR: public Resource
{
    Q_OBJECT
public:
    HealthR(QObject *parent = nullptr);
    ~HealthR();
};

#endif // HEALTHR_H
