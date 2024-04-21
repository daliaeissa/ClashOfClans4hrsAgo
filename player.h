#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsItem>
#include<QGraphicsRectItem>
#include<QObject>
#include "Enemy.h"
#include"fence.h"

class Player:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player();
    Fence* obj;
public slots:
    void createEnemy();
    void settingFences();

};

#endif // PLAYER_H
