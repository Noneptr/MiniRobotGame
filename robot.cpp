#include "robot.h"

Robot::Robot(const QString &Name, int Damage, int Health, int Exp,
             int Width, int Height, const QString &filedir,
             QVector<QVector<Cell *>> *gamefield,
             int PosI, int PosJ, QObject *parent)
    :GameUnit(Name, Damage, Health, Exp, Width, Height, QPixmap(), parent), _ii(0), _jj(0),
      _direct(RDDown), _filedir(filedir)
{
    setGameField(gamefield);
    setPosI(PosI);
    setPosJ(PosJ);
    setPixmap(fileDir() + name() + "/state/" + QString::number(direct())+ ".png");
}


void Robot::setPosI(int p)
{
    if (_gamefield != nullptr)
    {
        if ((p >= 0) && (p < _gamefield->size()))
        {
            if ((*_gamefield)[p][posJ()]->MyObject() == nullptr)
            {
                (*_gamefield)[_ii][posJ()]->setMyObject(nullptr);
                _ii = p;
                (*_gamefield)[_ii][posJ()]->setMyObject(this);
                int d = (*_gamefield)[0][0]->width();
                this->setPos(x(), _ii * d);
            }
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
        if ((p >= 0) && (p < (*_gamefield)[0].size()))
        {
            if ((*_gamefield)[posI()][p]->MyObject() == nullptr)
            {
                (*_gamefield)[posI()][_jj]->setMyObject(nullptr);
                _jj = p;
                (*_gamefield)[posI()][_jj]->setMyObject(this);
                int d = (*_gamefield)[0][0]->width();
                this->setPos(_jj * d, y());
            }
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


QString Robot::fileDir() const
{
    return _filedir;
}


void Robot::setFileDir(const QString &filedir)
{
    _filedir = filedir;
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


RobotDirect Robot::direct() const
{
    return _direct;
}


void Robot::setDirect(RobotDirect d)
{
    _direct = d;
}


void Robot::move()
{
    if (direct() == RDUp)
    {
        setPosI(posI() - 1);
    }
    else if (direct() == RDDown)
    {
        setPosI(posI() + 1);
    }
    else if (direct() == RDLeft)
    {
        setPosJ(posJ() - 1);
    }
    else if (direct() == RDRight)
    {
        setPosJ(posJ() + 1);
    }

    setPixmap(QPixmap(fileDir() + name() + "/state/" + QString::number(direct())+ ".png"));
}


void Robot::collect()
{
}


Robot::~Robot()
{
}
