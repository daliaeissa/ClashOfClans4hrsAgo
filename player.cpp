#include "player.h"
#include<QGraphicsScene>
#include "Fence.h"

Fence *fence1 = new Fence(150, 50);



/*void Player::settingFences(){

    scene()->addItem(fence1);

}*/

Player::Player() {
    fence1->setRect(150,50,50,50);
}





void Player::createEnemy(){
    Enemy* enemy = new Enemy();
    //for(int i=0;i<24;i++){
        //enemy->setFenceObject(obj);
     //}
    //fence1->setRect(150, 50, 50, 50);
    scene()->addItem(enemy);

}
