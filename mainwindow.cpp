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

    QGraphicsPixmapItem *r = new Robot("robot1", 1, 1, 1, 50, 50,
    ":/rec/", scene->cells(), 0, 0, this);
    scene->addItem(r);
    robot = static_cast<Robot*>(r);
    scene->addItem(robot->damageBar());
    scene->addItem(robot->healthBar());
    scene->addItem(robot->expBar());

    QGraphicsPixmapItem *r2 = new Robot("robot2", 10, 10, 10, 50, 50,
                                            ":/rec/", scene->cells(), 6, 12, this);
    Robot *rb2 = static_cast<Robot*>(r2);
    scene->addItem(r2);
    connect(rb2, &Robot::deaded, scene, &QGraphicsScene::removeItem);
    scene->addItem(rb2->damageBar());
    scene->addItem(rb2->healthBar());
    scene->addItem(rb2->expBar());

    QGraphicsPixmapItem *h = new Healther(this);
    Healther *hp = static_cast<Healther*>(h);
    scene->addItem(h);
    (*scene->cells())[4][4]->setMyObject(hp);
    hp->setPos(200, 200);
    connect(hp, &Healther::deaded, scene, &QGraphicsScene::removeItem);


    QGraphicsPixmapItem *d = new Damager(this);
    Damager *dmg = static_cast<Damager*>(d);
    scene->addItem(d);
    (*scene->cells())[7][8]->setMyObject(dmg);
    dmg->setPos(400, 350);
    connect(dmg, &Damager::deaded, scene, &QGraphicsScene::removeItem);

    QGraphicsPixmapItem *e = new Exper(this);
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
