#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#include "gameobject.h"

class GameUnit: public GameObject
{
    Q_OBJECT
protected:
    QString _name;
    int _damage;
    int _health;
    int _exp;
public:
    GameUnit(const QString &Name, int Damage, int Health, int Exp, int Width, int Height, const QPixmap &pixmap, QObject *parent = nullptr);

    void setName(const QString &n);
    QString name() const;
    virtual void setDamage(int d);
    int damage() const;
    virtual void setHealth(int h);
    int health() const;
    virtual void setExp(int e);
    int exp() const;

    virtual ~GameUnit();
signals:
    void deaded(QGraphicsItem*);
    void changeHealth();
    void changeDamage();
    void changeExp();
};

#endif // GAMEUNIT_H
