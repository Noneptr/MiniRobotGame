#include "robot.h"

Robot::Robot(const QString &Name, int Damage, int Health, int Exp, int Width, int Height, const QPixmap &pixmap, QObject *parent)
    :GameUnit(Name, Damage, Health, Exp, Width, Height, pixmap, parent)
{
}
