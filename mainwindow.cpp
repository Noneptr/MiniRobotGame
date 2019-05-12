#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(0, 0, ui->graphicsView->width(), ui->graphicsView->height(), this);
    QPixmap r(":/recs/robot1/robot1down.png");
    QPixmap c(":/recs/resources/cell.png");
    QGraphicsItem *robot = new QGraphicsPixmapItem(r);
    QGraphicsItem *cell = new QGraphicsPixmapItem(c);
    scene->addItem(cell);
    scene->addItem(robot);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
