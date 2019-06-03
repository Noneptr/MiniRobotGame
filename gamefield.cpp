#include "gamefield.h"

GameField::GameField(qreal x, qreal y, qreal width, qreal height,
                     int size_cell, int interval, QObject *parent)
    :QGraphicsScene(x, y, width, height, parent)
{
    try
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
    catch(...)
    {
        qDebug() << "Cell new ERROR" << endl;
    }
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

void GameField::createRobot()
{
    try
    {
        if (_ticks % 6 == 0)
        {
            int si = rand() % _cells.size();
            int sj = rand() % _cells[0].size();

            if (_cells[si][sj]->MyObject() == nullptr)
            {
                int s = rand() % nrobots.size();
                QString &name = nrobots[s];

                Robot* robot;

                if (name == "rstd")
                {
                    robot = new RobotStandart(50, 50, &_cells, si, sj, this);
                    robot->setNameResources({"exper", "healther", "damager"});
                    robot->setNameEnemys({"robot2", "robot3"});
                }
                else if (name == "rbul")
                {
                    robot = new RobotBullet(50, 50, &_cells, si, sj, this);
                    robot->setNameResources({"exper", "healther", "damager"});
                    robot->setNameEnemys({"robot1", "robot3"});
                }
                else
                {
                    robot = new RobotHealthy(50, 50, &_cells, si, sj, this);
                    robot->setNameResources({"exper", "healther", "damager"});
                    robot->setNameEnemys({"robot1", "robot2"});
                }

                addItem(robot);
                addItem(robot->damageBar());
                addItem(robot->healthBar());
                addItem(robot->expBar());

                connect(robot, &Robot::deaded, this, &GameField::removeItem);
                connect(robot, &Robot::deleteBar, this, &GameField::removeItem);
                connect(robot, &Robot::deaded, robot, &Robot::deleteLater);
                connect(&_timer, &QTimer::timeout, robot, &Robot::action);
                auto f = [this, robot]()->void{
                    disconnect(robot, &Robot::deaded, this, &GameField::removeItem);
                    disconnect(robot, &Robot::deleteBar, this, &GameField::removeItem);
                    disconnect(robot, &Robot::deaded, robot, &Robot::deleteLater);
                    disconnect(&_timer, &QTimer::timeout, robot, &Robot::action);};

                connect(robot, &Robot::destroyed, f);
            }
        }
    }
    catch(...)
    {
        qDebug() << "Robot new ERROR!!!" << endl;
    }
}


void GameField::createResource()
{
    try
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

                GameUnit* rec;

                if (name == "exp")
                {
                    rec = new Exper(50, 50,this);
                }
                else if (name == "hp")
                {
                    rec = new Healther(50, 50,this);
                }
                else
                {
                    rec = new Damager(50, 50,this);
                }

                addItem(rec);
                cell->setMyObject(rec);
                rec->setPos(sj * size_cell, si * size_cell);

                connect(rec, &GameUnit::deaded, this, &GameField::removeItem);
                connect(rec, &GameUnit::deaded, rec, &GameUnit::deleteLater);

                auto f = [this, rec]()->void{
                    disconnect(rec, &GameUnit::deaded, this, &GameField::removeItem);
                    disconnect(rec, &GameUnit::deaded, rec, &GameUnit::deleteLater);};

                connect(rec, &GameUnit::destroyed, f);
            }
        }
    }
    catch(...)
    {
        qDebug() << "Resource new ERROR!!!" << endl;
    }
}


GameField::~GameField()
{
}
