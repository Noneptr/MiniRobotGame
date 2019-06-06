#include "gamefieldview.h"

GameFieldView::GameFieldView(QWidget *parent)
    :QGraphicsView (parent)
{
}


GameFieldView::GameFieldView(QGraphicsScene *scene, QWidget *parent)
    :QGraphicsView (scene, parent)
{
}


GameFieldView::~GameFieldView()
{
}


void GameFieldView::mousePressEvent(QMouseEvent *event)
{
    emit clicked(event);
}
