#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamefield.h"

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

private:
    Ui::MainWindow *ui;
    GameField *scene;
};

#endif // MAINWINDOW_H
