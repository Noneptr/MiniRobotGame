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
    scene = new GameField(ui->graphicsView->x() - 1, ui->graphicsView->y() - 1,
                                          ui->graphicsView->width(), ui->graphicsView->height(), this);

    ui->graphicsView->setScene(scene);

    QGraphicsPixmapItem *r = new Robot("robot1", 1, 1, 1, 50, 50,
    ":/rec/", scene->cells(), 0, 0, this);
    scene->addItem(r);
    robot = static_cast<Robot*>(r);
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
