#ifndef ENEMY_H
#define ENEMY_H
#include<QGraphicsItem>
#include<QGraphicsRectItem>
#include<QObject>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QList>
#include"Fence.h"

class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy();

public slots:
    void move_right();
    void move_left();
    void move_up();
    void move_down();
    void hit_fence();
    void setFenceObject(Fence*& obj);
};

#endif // ENEMY_H
