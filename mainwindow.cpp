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

    QGraphicsPixmapItem *r = new Robot("robot1", 1, 2, 4, 50, 50,
    ":/rec/", scene->cells(), 0, 0, this);
    scene->addItem(r);
    robot = static_cast<Robot*>(r);
    connect(robot, &Robot::deaded, scene, &QGraphicsScene::removeItem);
    scene->addItem(robot->damageBar());
    scene->addItem(robot->healthBar());
    scene->addItem(robot->expBar());
    robot->setNameResources({"exper", "healther", "damager"});
    robot->setNameEnemys({"robot2", "robot3"});

    QGraphicsPixmapItem *r2 = new Robot("robot2", 1, 2, 4, 50, 50,
                                            ":/rec/", scene->cells(), 6, 12, this);
    robot2 = static_cast<Robot*>(r2);
    scene->addItem(r2);
    connect(robot2, &Robot::deaded, scene, &QGraphicsScene::removeItem);
    scene->addItem(robot2->damageBar());
    scene->addItem(robot2->healthBar());
    scene->addItem(robot2->expBar());
    robot2->setNameResources({"exper", "healther", "damager"});
    robot2->setNameEnemys({"robot1", "robot3"});

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

//    std::cout << std::endl;
//    for (int i = 0; i < scene->cells()->size(); i++)
//    {
//        for (int j = 0; j < (*scene->cells())[0].size(); j++)
//        {
//            Cell* cell = (*scene->cells())[i][j];
//            GameUnit* obj = cell->MyObject();

//            if (obj == nullptr)
//            {
//                std::cout << "* ";
//            }
//            else
//            {
//                if (obj->name() == "robot1")
//                {
//                    std::cout << "R ";
//                }
//                else if (obj->name() == "robot2")
//                {
//                    std::cout << "r ";
//                }
//                else if (obj->name() == "healther")
//                {
//                    std::cout << "+ ";
//                }
//                else if (obj->name() == "damager")
//                {
//                    std::cout << "# ";
//                }
//                else if (obj->name() == "exper")
//                {
//                    std::cout << "@ ";
//                }
//            }
//        }
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
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
    if (robot2->health() > 0)
    {
        robot2->action();
    }
    if (robot->health() > 0)
    {
        robot->action();
    }
}
