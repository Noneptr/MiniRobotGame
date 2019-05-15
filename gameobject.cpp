#include "gameobject.h"

GameObject::GameObject(int Width, int Height, const QPixmap &pixmap, QObject *parent)
    :QGraphicsPixmapItem(pixmap), QObject(parent)
{
    setWidth(Width);
    setHeight(Height);
}


void GameObject::setWidth(int w)
{
    if (w > 0)
    {
        _width = w;
    }
    else
    {
        throw SizeError;
    }
}


void GameObject::setHeight(int h)
{
    if (h > 0)
    {
        _height = h;
    }
    else
    {
        throw SizeError;
    }
}


int GameObject::width() const
{
    return _width;
}


int GameObject::height() const
{
    return _height;
}

GameObject::~GameObject()
{
}
