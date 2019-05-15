#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QGraphicsPixmapItem>


enum GameObjectError {SizeError};

class GameObject : public QGraphicsPixmapItem, public QObject
{
    Q_OBJECT
private:
    QString _name;
    int _width, _height;
public:
    GameObject(const QString &Name, int Width, int Height, const QPixmap &pixmap, QObject *parent = nullptr);
    void setName(const QString &n);
    QString name() const;
    void setWidth(int w);
    void setHeight(int h);
    int width() const;
    int height() const;

    ~GameObject();
};

#endif // GAMEOBJECT_H
