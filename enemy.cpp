#include "enemy.h"
#include "Fence.h"
#include<QGraphicsScene>
#include<QGraphicsView>

void Enemy::hit_fence(){
    Fence::decHealth();
}

void Enemy::move_right(){
    setPos(x()+5,y());
    QList<QGraphicsItem*> colliding_items2 = collidingItems();
    for(int i=0;i<colliding_items2.size();i++)
    {
        if(typeid(*(colliding_items2[i])) == typeid(Fence))
        {
            setPos(125,y());
            //QTimer * timer = new QTimer();
           /* if(Fence::getHealth() > 0 && !Fence::is_hit){
                fence1->decHealth();
                Fence::set_hit();
            }*/
            return;

        }
        //Fence::is_hit = false;
    }
}
void Enemy::move_left(){
    setPos(x()-5,y());
    QList<QGraphicsItem*> colliding_items2 = collidingItems();
    for(int i=0;i<colliding_items2.size();i++)
    {
        if(typeid(*(colliding_items2[i])) == typeid(Fence))
        {
            setPos(450,y());
            return;
        }
    }
}
void Enemy::move_up(){
    setPos(x(),y()-5);
    QList<QGraphicsItem*> colliding_items2 = collidingItems();
    for(int i=0;i<colliding_items2.size();i++)
    {
        if(typeid(*(colliding_items2[i])) == typeid(Fence))
        {
            setPos(x(),450);
            return;
        }
    }
}
void Enemy::move_down(){
    setPos(x(),y()+5);
    QList<QGraphicsItem*> colliding_items2 = collidingItems();
    for(int i=0;i<colliding_items2.size();i++)
    {
        if(typeid(*(colliding_items2[i])) == typeid(Fence))
        {
            setPos(x(),25);
            return;
        }
    }
}

Fence* arr[24];

void setFenceObject(Fence*& obj){

        arr[0] = obj;

}


Enemy::Enemy() {

    setRect(0, 0, 25, 25);
    int x1, random_number_y1, x2, random_number_x3, y3, y4;
    // Left and Right columns
    x1 = 0;
    x2 = 550;
    random_number_y1 = rand() % (501);
    // Up and Down
    random_number_x3 = rand() % (251) + 150;
    y3 = 0;
    y4 = 450;

    //Left and right
    int arr_1[4] = {x1, random_number_y1, x2, random_number_y1};
    //Up and Down
    int arr_2[4] = {y3, random_number_x3, y4, random_number_x3};
    // Randomizes the choice either arr[0] or arr[2]
    int final_random = rand()%2;
    final_random *= 2;
    // Decides which array to access
    int arr_decider = rand() % 2;
    arr_decider = arr_decider * 2 + 4;
    if(arr_decider == 4){
        setPos(arr_1[final_random], arr_1[final_random+1]);
    }
    else{
        setPos(arr_2[final_random+1], arr_2[final_random]);
    }

    // Decide which way to move
    if(arr_decider == 4 && final_random == 0){
        // move right
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this,SLOT (move_right()));
        timer->start(50);
    }
    if(arr_decider == 4 && final_random == 2){
        // move left
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this,SLOT (move_left()));
        timer->start(50);
    }
    if(arr_decider == 6 && final_random == 0){
        // move down
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this,SLOT (move_down()));
        timer->start(50);
    }
    if(arr_decider == 6 && final_random == 2){
        // move up
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this,SLOT (move_up()));
        timer->start(50);
    }





    //Handling collision with fence

   /* setPos(x(),y()-10);
    if(pos().y()+100<0){
        //scene()->removeItem(this);
        delete this;
    }*/

}
