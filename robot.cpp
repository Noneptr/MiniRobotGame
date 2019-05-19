#include "robot.h"

Robot::Robot(const QString &Name, int Damage, int Health, int Exp,
             int Width, int Height, const QPixmap &pixmap, QVector<QVector<Cell *> > *gamefield,
             int PosI, int PosJ, QObject *parent)
    :GameUnit(Name, Damage, Health, Exp, Width, Height, pixmap, parent)
{
    setGameField(gamefield);
    setPosI(PosI);
    setPosJ(PosJ);
}


void Robot::setPosI(int p)
{
    if (_gamefield != nullptr)
    {
        if ((p >= 0) && (p <= _gamefield->size()))
        {
            _ii = p;
        }
    }
    else
    {
        throw NotPointGameFieldError;
    }
}


int Robot::posI() const
{
    return _ii;
}


void Robot::setPosJ(int p)
{    if (_gamefield != nullptr)
    {
        if ((p >= 0) && (p <= (*_gamefield)[0].size()))
        {
            _jj = p;
        }
    }
    else
    {
        throw NotPointGameFieldError;
    }
}


int Robot::posJ() const
{
    return _jj;
}


void Robot::setGameField(QVector<QVector<Cell*>>* gamefield)
{
    if (gamefield != nullptr)
    {
        if (gamefield->size() > 0)
        {
            if ((*gamefield)[0].size() > 0)
            {
                _gamefield = gamefield;
            }
            else
            {
                throw NotRightGameFieldError;
            }
        }
        else
        {
            throw NotRightGameFieldError;
        }
    }
    else
    {
        throw NotRightGameFieldError;
    }
}


QVector<QVector<Cell*>>* Robot::gameField() const
{
    return _gamefield;
}


void Robot::move(RobotDirect direct)
{
    int d = (*_gamefield)[0][0]->width();
    if (direct == RDUp)
    {
        int i = posI() - 1;
        setPosI(i);
        if (i == posI())
        {
            if ((*_gamefield)[posI()][posJ()]->MyObject() == nullptr)
            {
                (*_gamefield)[posI() + 1][posJ()]->setMyObject(nullptr);
                (*_gamefield)[posI()][posJ()]->setMyObject(this);
                this->setPos(x(), y() - d);
            }
        }
    }
    else if (direct == RDDown)
    {
        int i = posI() + 1;
        setPosI(i);
        if (i == posI())
        {
            if ((*_gamefield)[posI()][posJ()]->MyObject() == nullptr)
            {
                (*_gamefield)[posI() - 1][posJ()]->setMyObject(nullptr);
                (*_gamefield)[posI()][posJ()]->setMyObject(this);
                this->setPos(x(), y() + d);
            }
        }
    }
    else if (direct == RDLeft)
    {
        int j = posJ() - 1;
        setPosJ(j);
        if (j == posJ())
        {
            if ((*_gamefield)[posI()][posJ()]->MyObject() == nullptr)
            {
                (*_gamefield)[posI()][posJ() + 1]->setMyObject(nullptr);
                (*_gamefield)[posI()][posJ()]->setMyObject(this);
                this->setPos(x() - d, y());
            }
        }
    }
    else if (direct == RDRight)
    {
        int j = posJ() + 1;
        setPosJ(j);
        if (j == posJ())
        {
            if ((*_gamefield)[posI()][posJ()]->MyObject() == nullptr)
            {
                (*_gamefield)[posI()][posJ() - 1]->setMyObject(nullptr);
                (*_gamefield)[posI()][posJ()]->setMyObject(this);
                this->setPos(x() + d, y());
            }
        }
    }
}


Robot::~Robot()
{
}
