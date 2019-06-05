#include "gamefield.h"

GameField::GameField(qreal x, qreal y, qreal width, qreal height,
                     int size_cell, int interval, QObject *parent)
    :QGraphicsScene(x, y, width, height, parent)
{
    int n = int(width/size_cell);
    int m = int(height/size_cell);
    for (int i = 0; i < m; i++)
    {
        QVector<Cell*> v;
        for (int j = 0; j < n; j++)
        {
            Cell* cell = new Cell(size_cell, size_cell, i, j, QPixmap(":/rec/resources/cell.png"), nullptr, this);
            v.push_back(cell);
            this->addItem(cell);
            cell->setPos(j * size_cell, i * size_cell);
        }
        _cells.push_back(v);
    }

    _timer.setInterval(interval);
    srand(static_cast<unsigned long>(time(nullptr)));
    connect(&_timer, &QTimer::timeout, [this]()->void{if(_ticks > 1000){_ticks = 1;}else{_ticks++;}});
    connect(&_timer, &QTimer::timeout, this, &GameField::createResource);
    connect(&_timer, &QTimer::timeout, this, &GameField::createRobot);
}


void GameField::playGame()
{
    if (_timer.isSingleShot())
    {
        _timer.setSingleShot(false);
    }

    _timer.start();
}


void GameField::playStepGame()
{
    if (!_timer.isSingleShot())
    {
        _timer.setSingleShot(true);
    }

    _timer.start();
}


void GameField::stopGame()
{
    _timer.stop();
}

void GameField::setIntervalGame(int interval)
{
    _timer.stop();
    _timer.setInterval(interval);
}


void GameField::removeItemRobot(Robot *r)
{
    this->removeItem(r);
    this->removeItem(r->healthBar());
    this->removeItem(r->damageBar());
    this->removeItem(r->expBar());
    disconnect(&_timer, &QTimer::timeout, r, &Robot::action);
    delete r;
    r = nullptr;
}

void GameField::removeItemGameUnit(GameUnit *obj)
{
    this->removeItem(obj);
    delete obj;
    obj = nullptr;
}


void GameField::createRobot()
{
    if (_ticks % 6 == 0)
    {
        int si = rand() % _cells.size();
        int sj = rand() % _cells[0].size();

        Cell *cell = _cells[si][sj];

        if (cell->MyObject() == nullptr)
        {
            int size_cell = cell->width();

            int s = rand() % nrobots.size();
            QString &name = nrobots[s];

            if (name == "rstd")
            {
                robot = new RobotStandart(size_cell, size_cell, &_cells, si, sj, this);
                robot->setNameResources({"exper", "healther", "damager"});
                robot->setNameEnemys({"robot2", "robot3"});
            }
            else if (name == "rbul")
            {
                robot = new RobotBullet(size_cell, size_cell, &_cells, si, sj, this);
                robot->setNameResources({"exper", "healther", "damager"});
                robot->setNameEnemys({"robot1", "robot3"});
            }
            else
            {
                robot = new RobotHealthy(size_cell, size_cell, &_cells, si, sj, this);
                robot->setNameResources({"exper", "healther", "damager"});
                robot->setNameEnemys({"robot1", "robot2"});
            }

            addItem(robot);
            addItem(robot->damageBar());
            addItem(robot->healthBar());
            addItem(robot->expBar());

            connect(&_timer, &QTimer::timeout, robot, &Robot::action);
            connect(robot, &Robot::deaded, this, &GameField::removeItemRobot);
            robot = nullptr;
        }
    }
}


void GameField::createResource()
{
    if (_ticks % 4 == 0)
    {
        int si = rand() % _cells.size();
        int sj = rand() % _cells[0].size();

        Cell *cell = _cells[si][sj];
        if (cell->MyObject() == nullptr)
        {
            int size_cell = cell->width();

            int s = rand() % nresources.size();
            QString &name = nresources[s];
            if (name == "exp")
            {
                rec = new Exper(size_cell, size_cell,this);
            }
            else if (name == "hp")
            {
                rec = new Healther(size_cell, size_cell,this);
            }
            else
            {
                rec = new Damager(size_cell, size_cell,this);
            }

            addItem(rec);
            cell->setMyObject(rec);
            rec->setPos(sj * size_cell, si * size_cell);

            connect(rec, &GameUnit::deaded, this, &GameField::removeItemGameUnit);
            rec = nullptr;
        }
    }
}


GameField::~GameField()
{
    delete rec;
    rec = nullptr;

    delete robot;
    robot = nullptr;
}
