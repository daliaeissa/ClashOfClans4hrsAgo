#ifndef BULLET_H
#define BULLET_H
#include<QGraphicsPixmapItem>
#include<QObject>
#include<QPixmap>

 class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(int a);
    int angle;
    double x_move = -5.0;
    double y_move;

public slots:
    void move();
};


#endif // BULLET_H

