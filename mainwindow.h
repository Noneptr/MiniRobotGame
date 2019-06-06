#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamefield.h"
#include "clickablelabel.h"

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

    void on_label_hp_clicked();

    void on_label_dmg_clicked();

    void on_label_exp_clicked();

    void work_with_label_obj_clicked(int index);    // соответсвенные лейблы кнопки {1, 2, 3, 4, 5, 6}

private:
    Ui::MainWindow *ui;
    GameField *scene;
    QString name_object = "robot1";                 // {robot1, robot2, robot3, healther, damager, exper}
    QString type_object = "robot";                  // {robot, rec}
    int size_cell = 50;
};

#endif // MAINWINDOW_H
