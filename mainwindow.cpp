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
    int interval = 100;
    scene = new GameField(ui->graphicsView->x() - 1, ui->graphicsView->y() - 1,
                                          ui->graphicsView->width(), ui->graphicsView->height(),
                                            50, interval, this);
    ui->sb_interval->setValue(interval);

    ui->graphicsView->setScene(scene);

//    connect(ui->label_rstd, SIGNAL(clicked()), this, SLOT(on_label_rstd_clicked()));
//    connect(ui->label_rdmg, SIGNAL(clicked()), this, SLOT(on_label_rdmg_clicked()));
//    connect(ui->label_rhp, SIGNAL(clicked()), this, SLOT(on_label_rhp_clicked()));
    ui->label_rstd->setFrameShadow(QFrame::Sunken);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}


void MainWindow::on_label_rstd_clicked()
{
    if (name_robot != "robot1")
    {
        name_robot = "robot1";
        ui->label_rstd->setFrameShadow(QFrame::Sunken);
        ui->label_rdmg->setFrameShadow(QFrame::Raised);
        ui->label_rhp->setFrameShadow(QFrame::Raised);
    }
}


void MainWindow::on_label_rdmg_clicked()
{
    if (name_robot != "robot2")
    {
        name_robot = "robot2";
        ui->label_rstd->setFrameShadow(QFrame::Raised);
        ui->label_rdmg->setFrameShadow(QFrame::Sunken);
        ui->label_rhp->setFrameShadow(QFrame::Raised);
    }
}


void MainWindow::on_label_rhp_clicked()
{
    if (name_robot != "robot3")
    {
        name_robot = "robot3";
        ui->label_rstd->setFrameShadow(QFrame::Raised);
        ui->label_rdmg->setFrameShadow(QFrame::Raised);
        ui->label_rhp->setFrameShadow(QFrame::Sunken);
    }
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

void MainWindow::on_bt_clear_game_clicked()
{
    scene->clearCells();
}
