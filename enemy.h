#ifndef ENEMY_H
#define ENEMY_H
#include<QGraphicsItem>
#include<QGraphicsRectItem>
#include<QObject>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QTimer>
#include<QList>
#include"Fence.h"

class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy(Fence** arr);
    Fence** arr;
    static int health_1;
    static int health_2;
    static int health_3;
    static int health_4;
    int health_arr[4] = {health_1, health_2, health_3, health_4};
    int enemy_health = 3;
    bool clanCollision = false;

public slots:
    void move_right();
    void move_left();
    void move_up();
    void move_down();
    void goToClanRight();
    void goToClanLeft();
    void goToClanUp();
    void goToClanDown();
    //void decHealth(int i);
    //void hit_fence();
    //void display();
    void hit(int i);
    //void updateHealthDisplay();


    //void setFenceObject(Fence*& obj);
};

#endif // ENEMY_H
