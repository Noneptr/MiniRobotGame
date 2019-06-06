#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int win_w = 704;
    int win_h = 630;
    this->setGeometry(this->x(), this->y(), win_w, win_h);
    this->setMaximumWidth(win_w);
    this->setMaximumHeight(win_h);
    this->setMinimumWidth(win_w);
    this->setMinimumHeight(win_h);
    ui->graphicsView->setGeometry(0, 0, 702, 502);
    int interval = 100;
    scene = new GameField(ui->graphicsView->x() - 1, ui->graphicsView->y() - 1,
                                          ui->graphicsView->width(), ui->graphicsView->height(),
                                            size_cell, interval, this);
    ui->sb_interval->setValue(interval);

    ui->graphicsView->setScene(scene);

    ui->label_rstd->setFrameShadow(QFrame::Sunken);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}


void MainWindow::on_graphicsView_clicked(QMouseEvent *event)
{
    QPointF p = event->pos();
    int i = static_cast<int>(p.y() / size_cell);
    int j = static_cast<int>(p.x() / size_cell);
    if (type_object == "robot")
    {
        scene->createRobot(name_object, i, j);
    }
    else
    {
        scene->createResource(name_object, i, j);
    }
}


void MainWindow::work_with_label_obj_clicked(int index)
{
    ui->label_rstd->setFrameShadow(QFrame::Raised);
    ui->label_rdmg->setFrameShadow(QFrame::Raised);
    ui->label_rhp->setFrameShadow(QFrame::Raised);
    ui->label_hp->setFrameShadow(QFrame::Raised);
    ui->label_dmg->setFrameShadow(QFrame::Raised);
    ui->label_exp->setFrameShadow(QFrame::Raised);

    if (index == 1)
    {
        name_object = "robot1";
        ui->label_rstd->setFrameShadow(QFrame::Sunken);
        type_object = "robot";
    }
    else if (index == 2)
    {
        name_object = "robot2";
        ui->label_rdmg->setFrameShadow(QFrame::Sunken);
        type_object = "robot";
    }
    else if (index == 3)
    {
        name_object = "robot3";
        ui->label_rhp->setFrameShadow(QFrame::Sunken);
        type_object = "robot";
    }
    else if (index == 4)
    {
        name_object = "healther";
        ui->label_hp->setFrameShadow(QFrame::Sunken);
        type_object = "rec";
    }
    else if (index == 5)
    {
        name_object = "damager";
        ui->label_dmg->setFrameShadow(QFrame::Sunken);
        type_object = "rec";
    }
    else if (index == 6)
    {
        name_object = "exper";
        ui->label_exp->setFrameShadow(QFrame::Sunken);
        type_object = "rec";
    }
}


void MainWindow::on_label_rstd_clicked()
{
    if (name_object != "robot1")
    {
        work_with_label_obj_clicked(1);
    }
}


void MainWindow::on_label_rdmg_clicked()
{
    if (name_object != "robot2")
    {
        work_with_label_obj_clicked(2);
    }
}


void MainWindow::on_label_rhp_clicked()
{
    if (name_object != "robot3")
    {
        work_with_label_obj_clicked(3);
    }
}


void MainWindow::on_label_hp_clicked()
{
    if (name_object != "healther")
    {
        work_with_label_obj_clicked(4);
    }
}


void MainWindow::on_label_dmg_clicked()
{
    if (name_object != "damager")
    {
        work_with_label_obj_clicked(5);
    }
}


void MainWindow::on_label_exp_clicked()
{
    if (name_object != "exper")
    {
        work_with_label_obj_clicked(6);
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
