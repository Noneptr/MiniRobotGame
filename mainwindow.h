#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamefield.h"
#include "healther.h"
#include "damager.h"
#include "exper.h"
#include "robotstandart.h"
#include "robothealthy.h"
#include "robotbullet.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    GameField *scene;
    RobotStandart* robot;
    RobotHealthy* robot3;
    RobotBullet* robot2;
};

#endif // MAINWINDOW_H
