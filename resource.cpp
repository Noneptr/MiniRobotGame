#include "resource.h"

Resource::Resource(int Damage, int Health, int Exp, const QString &Name, int Width, int Height, const QPixmap &pixmap, QObject *parent)
    :GameObject(Name, Width, Height, pixmap, parent), _damage(Damage), _health(Health), _exp(Exp)
{
}


void Resource::setDamage(int d)
{
    _damage = d;
}


int Resource::damage() const
{
    return _damage;
}


void Resource::setHealth(int h)
{
    _health = h;
}


int Resource::health() const
{
    return _health;
}


void Resource::setExp(int e)
{
    _exp = e;
}


int Resource::exp() const
{
    return _exp;
}

Resource::~Resource()
{
}
