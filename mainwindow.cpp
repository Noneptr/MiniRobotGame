#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int win_w = 704;
    int win_h = 600;
    this->setGeometry(this->x(), this->y(), win_w, win_h);
    this->setMaximumWidth(win_w);
    this->setMaximumHeight(win_h);
    this->setMinimumWidth(win_w);
    this->setMinimumHeight(win_h);
    ui->graphicsView->setGeometry(0, 0, 702, 502);
    scene = new GameField(ui->graphicsView->x() - 1, ui->graphicsView->y() - 1,
                                          ui->graphicsView->width(), ui->graphicsView->height(), this);

    ui->graphicsView->setScene(scene);

    QGraphicsPixmapItem *r = new RobotStandart(50, 50, scene->cells(), 0, 0, this);
    scene->addItem(r);
    robot = static_cast<RobotStandart*>(r);
    connect(robot, &RobotStandart::deaded, scene, &QGraphicsScene::removeItem);
    scene->addItem(robot->damageBar());
    scene->addItem(robot->healthBar());
    scene->addItem(robot->expBar());
    robot->setNameResources({"exper", "healther", "damager"});
    robot->setNameEnemys({"robot2", "robot3"});

    QGraphicsPixmapItem *r2 = new RobotBullet(50, 50, scene->cells(), 8, 12, this);
    robot2 = static_cast<RobotBullet*>(r2);
    scene->addItem(r2);
    connect(robot2, &RobotBullet::deaded, scene, &QGraphicsScene::removeItem);
    scene->addItem(robot2->damageBar());
    scene->addItem(robot2->healthBar());
    scene->addItem(robot2->expBar());
    robot2->setNameResources({"exper", "healther", "damager"});
    robot2->setNameEnemys({"robot1", "robot3"});

    QGraphicsPixmapItem *r3 = new RobotHealthy(50, 50, scene->cells(), 5, 6, this);
    robot3 = static_cast<RobotHealthy*>(r3);
    scene->addItem(r3);
    connect(robot3, &RobotHealthy::deaded, scene, &QGraphicsScene::removeItem);
    scene->addItem(robot3->damageBar());
    scene->addItem(robot3->healthBar());
    scene->addItem(robot3->expBar());
    robot3->setNameResources({"exper", "healther", "damager"});
    robot3->setNameEnemys({"robot1", "robot2"});

    QGraphicsPixmapItem *h = new Healther(50, 50,this);
    Healther *hp = static_cast<Healther*>(h);
    scene->addItem(h);
    (*scene->cells())[4][4]->setMyObject(hp);
    hp->setPos(200, 200);
    connect(hp, &Healther::deaded, scene, &QGraphicsScene::removeItem);


    QGraphicsPixmapItem *d = new Damager(50, 50,this);
    Damager *dmg = static_cast<Damager*>(d);
    scene->addItem(d);
    (*scene->cells())[7][8]->setMyObject(dmg);
    dmg->setPos(400, 350);
    connect(dmg, &Damager::deaded, scene, &QGraphicsScene::removeItem);

    QGraphicsPixmapItem *e = new Exper(50, 50,this);
    Exper *ex = static_cast<Exper*>(e);
    scene->addItem(e);
    (*scene->cells())[0][13]->setMyObject(ex);
    ex->setPos(650, 0);
    connect(ex, &Exper::deaded, scene, &QGraphicsScene::removeItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    robot->setDirect(RDLeft);
    robot->move();
}

void MainWindow::on_pushButton_2_clicked()
{
    robot->setDirect(RDDown);
    robot->move();
}

void MainWindow::on_pushButton_3_clicked()
{
    robot->setDirect(RDUp);
    robot->move();
}

void MainWindow::on_pushButton_4_clicked()
{
    robot->setDirect(RDRight);
    robot->move();
}

void MainWindow::on_pushButton_5_clicked()
{
    robot->collect();
}

void MainWindow::on_pushButton_6_clicked()
{
    robot->attack();
}

void MainWindow::on_pushButton_7_clicked()
{
    if (robot->health() > 0)
    {
        robot->action();
    }

    if (robot3->health() > 0)
    {
        robot3->action();
    }

    if (robot2->health() > 0)
    {
        robot2->action();
    }
}
