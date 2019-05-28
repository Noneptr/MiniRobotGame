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

    connect(this, &Robot::changedHealth, this, &Robot::changeHealthBar);
    connect(this, &Robot::changedDamage, this, &Robot::changeDamageBar);
    connect(this, &Robot::changedExp, this, &Robot::changeExpBar);

    setDamage(Damage);
    setHealth(Health);
    setExp(Exp);

    _target = (*_gamefield)[posI() + 1][posJ()];
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
        if (gamefield->size() > 1)
        {
            if ((*gamefield)[0].size() > 1)
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


void Robot::setNameResources(const QVector<QString> &nameRecs)
{
    if (nameRecs.size() > 0)
    {
        _name_recs = nameRecs;
    }
    else
    {
        throw NotNamesResourcesError;
    }
}


QVector<QString> Robot::nameResources() const
{
    return _name_recs;
}


void Robot::setNameEnemys(const QVector<QString> &nameEnemys)
{
    if (nameEnemys.size() > 0)
    {
        _name_enemys = nameEnemys;
    }
    else
    {
        throw NotNamesEnemysError;
    }
}


QVector<QString> Robot::nameEnemys() const
{
    return _name_enemys;
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
    changeDamageBar();
    changeHealthBar();
    changeExpBar();
}


bool Robot::collection(int index, RobotDirect d)
{
    Cell* cell;


    if ((d == RDUp) || (d == RDDown))
    {
        cell = (*_gamefield)[index][posJ()];
    }
    else
    {
        cell = (*_gamefield)[posI()][index];
    }


    GameUnit *obj = cell->MyObject();
    if (obj != nullptr)
    {
        for (QString &r : _name_recs)
        {
            if (r == obj->name())
            {
                setHealth(health() + obj->health());
                setDamage(damage() + obj->damage());
                setExp(exp() + obj->exp());
                setPixmap(QPixmap(fileDir() + name() + "/alt_attack/" + QString::number(d) + ".png"));
                cell->setMyObject(nullptr);
                emit obj->deaded(obj);
                return true;
            }
        }
    }

    return false;
}

bool Robot::hit(int index, RobotDirect d)
{
    Cell* cell;


    if ((d == RDUp) || (d == RDDown))
    {
        cell = (*_gamefield)[index][posJ()];
    }
    else
    {
        cell = (*_gamefield)[posI()][index];
    }


    GameUnit *obj = cell->MyObject();
    if (obj != nullptr)
    {
        bool _flag = false;
        for (QString &r : _name_recs)
        {
            if (r == obj->name())
            {
                _flag = true;
                break;
            }
        }


        if ((!_flag) && (obj->name() != name()))
        {
            setPixmap(QPixmap(fileDir() + name() + "/attack/" + QString::number(d) + ".png"));
            Robot * robot = static_cast<Robot*>(obj);
            robot->setPixmap(QPixmap(robot->fileDir() + robot->name() + "/hpdown/"
                                     + QString::number(robot->direct()) + ".png"));
            robot->setHealth(robot->health() - damage());
            return true;
        }
    }

    return false;
}


void Robot::collect()
{
    int i1 = posI() - 1;
    int i2 = posI() + 1;
    int j1 = posJ() - 1;
    int j2 = posJ() + 1;
    bool flag = false;


    if ((i1 >= 0) && (!flag))
    {
        flag = collection(i1, RDUp);
    }


    if ((i2 < _gamefield->size())  && (!flag))
    {
        flag = collection(i2, RDDown);
    }


    if ((j1 >= 0) && (!flag))
    {
        flag = collection(j1, RDLeft);
    }


    if ((j2 < (*_gamefield)[0].size()) && (!flag))
    {
        flag = collection(j2, RDRight);
    }
}


void Robot::attack()
{
    int i1 = posI() - 1;
    int i2 = posI() + 1;
    int j1 = posJ() - 1;
    int j2 = posJ() + 1;
    bool flag = false;


    if ((i1 >= 0) && (!flag))
    {
        flag = hit(i1, RDUp);
    }


    if ((i2 < _gamefield->size())  && (!flag))
    {
        flag = hit(i2, RDDown);
    }


    if ((j1 >= 0) && (!flag))
    {
        flag = hit(j1, RDLeft);
    }


    if ((j2 < (*_gamefield)[0].size()) && (!flag))
    {
        flag = hit(j2, RDRight);
    }
}


void Robot::action()
{
    if (_target->MyObject() == nullptr)
    {
        findNearestTarget(); // поиск ближайшей цели волновым алгоритмом
    }

    if (_target->MyObject() != nullptr)
    {
        if (_target->MyObject()->name() != name())
        {
            bool p1 = abs(posI() - _target->i()) > 1;
            bool p2 = abs(posJ() - _target->j()) > 1;
            bool p3 = abs(posI() - _target->i()) == 1;
            bool p4 = abs(posJ() - _target->j()) == 1;
            if (p1 || p2 || (p3 && p4))
            {
                int c = qrand() % 2;

                if (c == 0)
                {
                    if (posI() < _target->i())
                    {
                        setDirect(RDDown);
                    }
                    else if (posI() > _target->i())
                    {
                        setDirect(RDUp);
                    }
                    else if (posJ() < _target->j())
                    {
                        setDirect(RDRight);
                    }
                    else if (posJ() > _target->j())
                    {
                        setDirect(RDLeft);
                    }
                }
                else
                {
                    if (posJ() < _target->j())
                    {
                        setDirect(RDRight);
                    }
                    else if (posJ() > _target->j())
                    {
                        setDirect(RDLeft);
                    }
                    else if (posI() < _target->i())
                    {
                        setDirect(RDDown);
                    }
                    else if (posI() > _target->i())
                    {
                        setDirect(RDUp);
                    }
                }

                move();
            }
            else
            {
                attack();
                collect();
            }
        }
    }
}


void Robot::setHealth(int h)
{
    _health = h;
    int max_h = int(exp() * 1.5);

    if (max_h > 99)
    {
        max_h = 99;
    }

    if (_health > max_h)
    {
        _health = max_h;
    }

    if (_health <= 0)
    {
        /*полное уничтожение робота*/
        emit deaded(healthBar());
        emit deaded(damageBar());
        emit deaded(expBar());
        emit deaded(this);
        (*_gamefield)[_ii][_jj]->setMyObject(nullptr);
    }

    emit changedHealth();
}


void Robot::setDamage(int d)
{
    _damage = d;
    int max_d = int(exp() * 1.2);

    if (max_d > 99)
    {
        max_d = 99;
    }

    if (_damage > max_d)
    {
        _damage = max_d;
    }

    emit changedDamage();
}


void Robot::setExp(int e)
{
    if (e > 99)
    {
        _exp = 99;
    }
    else
    {
        _exp = e;
    }

    emit changedExp();
}


void Robot::changeHealthBar()
{
    int cwidth = (*_gamefield)[0][0]->width();
    _health_bar.setPos(_jj * cwidth, _ii * cwidth);
    _health_bar.setHtml("<p><font size=\"" + QString::number(width() / 16)
                        + "\" color=\"green\" face=\"Comic Sans\">"
                                + QString::number(health()) + "</font></p>");
}


void Robot::changeDamageBar()
{
    int cwidth = (*_gamefield)[0][0]->width();
    int ot = 2 * width() / 3;
    _damage_bar.setPos(_jj * cwidth + ot, _ii * cwidth );
    _damage_bar.setHtml(QString("<p><font size=\"" + QString::number(width() / 16)
                                + "\" color=\"red\" face=\"Comic Sans\">"
                                + QString::number(damage()) + "</font></p>"));
}


void Robot::changeExpBar()
{
    int cwidth = (*_gamefield)[0][0]->width();
    int ot = 2 * width() / 3;
    _exp_bar.setPos(_jj * cwidth + ot, _ii * cwidth + ot );
    _exp_bar.setHtml(QString("<p><font size=\"" + QString::number(width() / 16)
                             + "\" color=\"yellow\" face=\"Comic Sans\">"
                             + QString::number(exp()) + "</font></p>"));
}

void Robot::findNearestTarget()
{
    QPair<int, int> target(-1, -1);
    QPair<int, int> finder(posI(), posJ()); // текущее положение робота

    int m = _gamefield->size();
    int n = (*_gamefield)[0].size();

    QVector<QString> name_targets; // список названий целей
    for (QString &e: _name_recs)
    {
        name_targets.push_back(e);
    }

    for (QString &e: _name_enemys)
    {
        name_targets.push_back(e);
    }

    Queue front; // очередь просматриваемых точек
    front.push(finder);
    QVector<QPair<int, int>> visited; // список просмотренных точек
    visited.push_back(finder);

    while (!front.empty())
    {
        QPair<int, int> current = front.front();
        front.pop();

        Cell *cell = (*_gamefield)[current.first][current.second];
        GameUnit *obj = cell->MyObject();

        if (obj != nullptr)
        {
            if (obj->name() != name())
            {
                bool flag = false;
                for (const QString &e: name_targets)
                {
                    if (e == obj->name())
                    {
                        target = current;
                        flag = true;
                        break;
                    }
                }

                if (flag)
                {
                    break;
                }
            }
        }

        for (QPair<int, int> &next: neighbours(current, m, n))
        {
            if (!in_vector(next, visited))
            {
                front.push(next);
                visited.push_back(next);
            }
        }
    }

    if (target == QPair<int, int>(-1, -1))
    {
        _target = (*_gamefield)[posI()][posJ()];
    }
    else
    {
        _target = (*_gamefield)[target.first][target.second];
    }
}


QGraphicsTextItem *Robot::healthBar()
{
    return &_health_bar;
}


QGraphicsTextItem *Robot::damageBar()
{
    return &_damage_bar;
}


QGraphicsTextItem *Robot::expBar()
{
    return &_exp_bar;
}


Robot::~Robot()
{
}
