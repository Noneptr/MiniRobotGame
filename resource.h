#ifndef RESOURCE_H
#define RESOURCE_H

#include "gameobject.h"

class Resource: public GameObject
{
    Q_OBJECT

private:
    int _damage;
    int _health;
    int _exp;
public:
    Resource(int Damage, int Health, int Exp, const QString &Name, int Width, int Height, const QPixmap &pixmap, QObject *parent = nullptr);

    void setDamage(int d);
    int damage() const;
    void setHealth(int h);
    int health() const;
    void setExp(int e);
    int exp() const;

public:
    ~Resource();
};

#endif // RESOURCE_H
