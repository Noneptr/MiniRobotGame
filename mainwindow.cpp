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
    int interval = 50;
    scene = new GameField(ui->graphicsView->x() - 1, ui->graphicsView->y() - 1,
                                          ui->graphicsView->width(), ui->graphicsView->height(),
                                            50, interval, this);
    ui->sb_interval->setValue(interval);

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

void MainWindow::on_bt_play_game_clicked()
{
    scene->playGame();
}

void MainWindow::on_bt_play_step_clicked()
{
    scene->playStepGame();
}

void MainWindow::on_bt_stop_game_clicked()
{
    scene->stopGame();
}

void MainWindow::on_sb_interval_valueChanged(int arg1)
{
    scene->setIntervalGame(arg1);
}
