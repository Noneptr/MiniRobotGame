#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamefield.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bt_play_game_clicked();

    void on_bt_play_step_clicked();

    void on_bt_stop_game_clicked();

    void on_sb_interval_valueChanged(int arg1);

    void on_bt_clear_game_clicked();

    void on_label_rstd_clicked();

    void on_label_rdmg_clicked();

    void on_label_rhp_clicked();

    void on_graphicsView_clicked(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    GameField *scene;
    QString name_robot = "robot1";
    int size_cell = 50;
};

#endif // MAINWINDOW_H
