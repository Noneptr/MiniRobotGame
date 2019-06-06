#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    ClickableLabel(QWidget *parent = nullptr);
    ClickableLabel(const QString &text = "", QWidget *parent = nullptr);
    ~ClickableLabel();

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked();
};

#endif // CLICKABLELABEL_H
