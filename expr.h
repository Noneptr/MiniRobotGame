#ifndef EXPR_H
#define EXPR_H

#include "resource.h"

class ExpR: public Resource
{
    Q_OBJECT
public:
    ExpR(QObject *parent = nullptr);
    ~ExpR();
};

#endif // EXPR_H
