#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QObject>


class Cell: public QLabel
{
    Q_OBJECT
public:
    explicit Cell(QWidget *parent = nullptr);
    ~Cell();
};

#endif // CELL_H
