#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#include "gameobject.h"
#include <QDebug>

class GameUnit: public GameObject
{
    Q_OBJECT

protected:
    QString _name; // название игровой единицы
    int _damage; // значение урона игровой единицы
    int _health; // значение здоровья игровой единицы
    int _exp; // значение опыта игровой единицы
public:
    GameUnit(const QString &Name, int Damage, int Health, int Exp, int Width,
             int Height, const QPixmap &pixmap, QObject *parent = nullptr);

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
    void changedHealth();
    void changedDamage();
    void changedExp();
};

#endif // GAMEUNIT_H
