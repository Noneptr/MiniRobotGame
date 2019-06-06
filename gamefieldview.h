#ifndef GAMEFIELDVIEW_H
#define GAMEFIELDVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>

class GameFieldView : public QGraphicsView
{
    Q_OBJECT
public:
    GameFieldView(QWidget *parent = nullptr);
    GameFieldView(QGraphicsScene *scene, QWidget *parent = nullptr);
    ~GameFieldView();

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked(QMouseEvent*);
};

#endif // GAMEFIELDVIEW_H
