#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#include "gameobject.h"

class GameUnit: public GameObject
{
    Q_OBJECT
protected:
    int _damage;
    int _health;
    int _exp;
public:
    GameUnit(const QString &Name, int Damage, int Health, int Exp, int Width, int Height, const QPixmap &pixmap, QObject *parent = nullptr);

    virtual void setDamage(int d);
    int damage() const;
    virtual void setHealth(int h);
    int health() const;
    virtual void setExp(int e);
    int exp() const;

    virtual ~GameUnit();
};

#endif // GAMEUNIT_H
