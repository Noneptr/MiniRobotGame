#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QGraphicsPixmapItem>


enum GameObjectError {SizeError};

class GameObject : public QGraphicsPixmapItem, public QObject
{
    Q_OBJECT
private:
    int _width, _height;
public:
    GameObject(int Width, int Height, const QPixmap &pixmap, QObject *parent = nullptr);
    void setWidth(int w);
    void setHeight(int h);
    int width() const;
    int height() const;

    ~GameObject();
};

#endif // GAMEOBJECT_H
