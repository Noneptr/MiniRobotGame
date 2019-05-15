#include "gameunit.h"

GameUnit::GameUnit(const QString &Name, int Damage, int Health, int Exp, int Width, int Height, const QPixmap &pixmap, QObject *parent)
    :GameObject(Name, Width, Height, pixmap, parent), _damage(Damage), _health(Health), _exp(Exp)
{
}


void GameUnit::setDamage(int d)
{
    _damage = d;
}


int GameUnit::damage() const
{
    return _damage;
}


void GameUnit::setHealth(int h)
{
    _health = h;
}


int GameUnit::health() const
{
    return _health;
}


void GameUnit::setExp(int e)
{
    _exp = e;
}


int GameUnit::exp() const
{
    return _exp;
}


GameUnit::~GameUnit()
{
}
