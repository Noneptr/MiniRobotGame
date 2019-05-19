#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    GameField *scene = new GameField(ui->graphicsView->x() - 1, ui->graphicsView->y() - 1,
                                          ui->graphicsView->width(), ui->graphicsView->height(), this);

    ui->graphicsView->setScene(scene);

    QGraphicsPixmapItem *robot = new Robot("robot", 1, 1, 1, 50, 50,
    QPixmap(":/recs/robot1/robot1down.png"), scene->cells(), 0, 0, this);
    scene->addItem(robot);
    robot->setPos(0, 0);
    static_cast<Robot*>(robot)->move(RDRight);
    static_cast<Robot*>(robot)->move(RDRight);
    static_cast<Robot*>(robot)->move(RDRight);
    static_cast<Robot*>(robot)->move(RDRight);
    static_cast<Robot*>(robot)->move(RDDown);
    static_cast<Robot*>(robot)->move(RDDown);
    static_cast<Robot*>(robot)->move(RDDown);
    static_cast<Robot*>(robot)->move(RDDown);
    static_cast<Robot*>(robot)->move(RDLeft);
    static_cast<Robot*>(robot)->move(RDLeft);
    static_cast<Robot*>(robot)->move(RDLeft);
    static_cast<Robot*>(robot)->move(RDLeft);
    static_cast<Robot*>(robot)->move(RDUp);
}

MainWindow::~MainWindow()
{
    delete ui;
}
