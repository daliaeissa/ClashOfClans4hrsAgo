#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsItem>
#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QObject>
#include "Enemy.h"
#include"fence.h"

class Player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsScene* scene, Fence** arr);
    Fence** arr;
    int angle=0;
public slots:
    void createEnemy();
    void keyPressEvent(QKeyEvent * event) override;
};

#endif // PLAYER_H
