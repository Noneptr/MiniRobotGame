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
    _timer.setInterval(interval);
}

void GameField::createRobot()
{
    if (_ticks % 6 == 0)
    {
        int si = rand() % _cells.size();
        int sj = rand() % _cells[0].size();

        if (_cells[si][sj]->MyObject() == nullptr)
        {
            int s = rand() % nrobots.size();
            QString &name = nrobots[s];

            if (name == "rstd")
            {
                QGraphicsPixmapItem *r = new RobotStandart(50, 50, &_cells, si, sj, this);
                addItem(r);
                RobotStandart *robot = static_cast<RobotStandart*>(r);
                connect(robot, &RobotStandart::deaded, this, &QGraphicsScene::removeItem);
                connect(robot, &RobotStandart::deaded, robot, &RobotStandart::deleteLater);
                addItem(robot->damageBar());
                addItem(robot->healthBar());
                addItem(robot->expBar());
                robot->setNameResources({"exper", "healther", "damager"});
                robot->setNameEnemys({"robot2", "robot3"});
                connect(&_timer, &QTimer::timeout, robot, &RobotStandart::action);

                auto f = [this, robot]()->void{
                    disconnect(robot, &RobotStandart::deaded, this, &QGraphicsScene::removeItem);
                    disconnect(robot, &RobotStandart::deaded, robot, &RobotStandart::deleteLater);
                    disconnect(&_timer, &QTimer::timeout, robot, &RobotStandart::action);};

                connect(robot, &RobotStandart::destroyed, f);
            }
            else if (name == "rbul")
            {
                QGraphicsPixmapItem *r = new RobotBullet(50, 50, &_cells, si, sj, this);
                RobotBullet* robot = static_cast<RobotBullet*>(r);
                addItem(r);
                connect(robot, &RobotBullet::deaded, this, &QGraphicsScene::removeItem);
                connect(robot, &RobotBullet::deaded, robot, &RobotBullet::deleteLater);
                addItem(robot->damageBar());
                addItem(robot->healthBar());
                addItem(robot->expBar());
                robot->setNameResources({"exper", "healther", "damager"});
                robot->setNameEnemys({"robot1", "robot3"});
                connect(&_timer, &QTimer::timeout, robot, &RobotBullet::action);

                auto f = [this, robot]()->void{
                    disconnect(robot, &RobotBullet::deaded, this, &QGraphicsScene::removeItem);
                    disconnect(robot, &RobotBullet::deaded, robot, &RobotBullet::deleteLater);
                    disconnect(&_timer, &QTimer::timeout, robot, &RobotBullet::action);};

                connect(robot, &RobotBullet::destroyed, f);
            }
            else
            {
                QGraphicsPixmapItem *r = new RobotHealthy(50, 50, &_cells, si, sj, this);
                RobotHealthy* robot = static_cast<RobotHealthy*>(r);
                addItem(r);
                connect(robot, &RobotHealthy::deaded, this, &QGraphicsScene::removeItem);
                connect(robot, &RobotHealthy::deaded, robot, &RobotHealthy::deleteLater);
                addItem(robot->damageBar());
                addItem(robot->healthBar());
                addItem(robot->expBar());
                robot->setNameResources({"exper", "healther", "damager"});
                robot->setNameEnemys({"robot1", "robot2"});
                connect(&_timer, &QTimer::timeout, robot, &RobotHealthy::action);

                auto f = [this, robot]()->void{
                    disconnect(robot, &RobotHealthy::deaded, this, &QGraphicsScene::removeItem);
                    disconnect(robot, &RobotHealthy::deaded, robot, &RobotHealthy::deleteLater);
                    disconnect(&_timer, &QTimer::timeout, robot, &RobotHealthy::action);};

                connect(robot, &RobotHealthy::destroyed, f);
            }
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
                QGraphicsPixmapItem *e = new Exper(50, 50,this);
                Exper *ex = static_cast<Exper*>(e);
                addItem(e);
                cell->setMyObject(ex);
                ex->setPos(sj * size_cell, si * size_cell);
                connect(ex, &Exper::deaded, this, &QGraphicsScene::removeItem);
                connect(ex, &Exper::deaded, ex, &Exper::deleteLater);

                auto f = [this, ex]()->void{
                    disconnect(ex, &Exper::deaded, this, &QGraphicsScene::removeItem);
                    disconnect(ex, &Exper::deaded, ex, &Exper::deleteLater);};

                connect(ex, &Exper::destroyed, f);
            }
            else if (name == "hp")
            {
                QGraphicsPixmapItem *h = new Healther(50, 50,this);
                Healther *hp = static_cast<Healther*>(h);
                addItem(h);
                cell->setMyObject(hp);
                hp->setPos(sj * size_cell, si * size_cell);
                connect(hp, &Healther::deaded, this, &QGraphicsScene::removeItem);
                connect(hp, &Healther::deaded, hp, &Healther::deleteLater);

                auto f = [this, hp]()->void{
                    disconnect(hp, &Healther::deaded, this, &QGraphicsScene::removeItem);
                    disconnect(hp, &Healther::deaded, hp, &Healther::deleteLater);};

                connect(hp, &Healther::destroyed, f);
            }
            else
            {
                QGraphicsPixmapItem *d = new Damager(50, 50,this);
                Damager *dmg = static_cast<Damager*>(d);
                addItem(d);
                cell->setMyObject(dmg);
                dmg->setPos(sj * size_cell, si * size_cell);
                connect(dmg, &Damager::deaded, this, &QGraphicsScene::removeItem);
                connect(dmg, &Damager::deaded, dmg, &Damager::deleteLater);

                auto f = [this, dmg]()->void{
                    disconnect(dmg, &Damager::deaded, this, &QGraphicsScene::removeItem);
                    disconnect(dmg, &Damager::deaded, dmg, &Damager::deleteLater);};

                connect(dmg, &Damager::destroyed, f);
            }
        }
    }
}
