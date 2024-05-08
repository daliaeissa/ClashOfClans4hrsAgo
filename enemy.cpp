#include "enemy.h"
#include "Fence.h"
#include "Bullet.h"
#include "worker.h"
#include"player.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QThread>
#include<QDebug>
#include<QPixmap>
#include<QGraphicsPixmapItem>
#include"clan.h"

/*void Enemy::hit_fence(){
    Fence::decHealth();
}*/

/*void Enemy::decHealth(int i) {
    health_arr[i]--;
}*/

int Enemy::health_1 = 200;
int Enemy::health_2 = 200;
int Enemy::health_3 = 200;
int Enemy::health_4 = 200;

void Enemy::hit(int i){
    //arr[i]->setHealth(100)
    if (health_arr[i] > 150){
        health_arr[i]-=5;
    }
    else if(health_arr[i] <= 150){
        health_arr[i]--;
    }
}

void Enemy::goToClanRight(){
    if(x()<=225 && y()<=300){
        setPos(x()+5,y()+5);
    }
    if(x()<=225 && y()>300){
        setPos(x()+5,y()-5);
    }
    QList<QGraphicsItem*> colliding_itemsClan = collidingItems();
    for(int i = 0; i < colliding_itemsClan.size(); i++){
        if(typeid(*(colliding_itemsClan[i])) == typeid(Clan))
        {
            clanCollision = true;
            setPos(x(),y());
        }
    }
}
void Enemy::goToClanLeft(){
    if(x()>=300 && y()<=300){
        setPos(x()-5,y()+5);
    }
    if(x()>300 && y()>300){
        setPos(x()-5,y()-5);
    }
    QList<QGraphicsItem*> colliding_itemsClan = collidingItems();
    for(int i = 0; i < colliding_itemsClan.size(); i++){
        if(typeid(*(colliding_itemsClan[i])) == typeid(Clan))
        {
            clanCollision = true;
            setPos(x(),y());
        }
    }
}
void Enemy::goToClanUp(){
    if(x()<=225 && y()>=300){
        setPos(x()+1,y()-1);
    }
    if(x()>=275 && y()>300){
        setPos(x()-1,y()-1);
    }
    if(x()>225 && x()<275 && y()>300){
        setPos(x(),y()-5);
    }
    QList<QGraphicsItem*> colliding_itemsClan = collidingItems();
    for(int i = 0; i < colliding_itemsClan.size(); i++){
        if(typeid(*(colliding_itemsClan[i])) == typeid(Clan))
        {
            clanCollision = true;
            setPos(x(),y());
        }
    }
}
void Enemy::goToClanDown(){
    if(x()<=225 && y()<=300){
        setPos(x()+1,y()+1);
    }
    if(x()>275 && y()<300){
        setPos(x()-1,y()+1);
    }
    if(x()>225 && x()<275 && y()<300){
        setPos(x(),y()+5);
    }
    QList<QGraphicsItem*> colliding_itemsClan = collidingItems();
    for(int i = 0; i < colliding_itemsClan.size(); i++){
        if(typeid(*(colliding_itemsClan[i])) == typeid(Clan))
        {
            clanCollision = true;
            setPos(x(),y());
        }
    }
}

bool is_hit = false;
QGraphicsTextItem* health = nullptr; // Declare health outside the loop


// Inside Enemy::move_right() function
void Enemy::move_right() {
    // if(x() != 225){
        setPos(x() + 5, y());
    // }

    QList<QGraphicsItem*> colliding_items2 = collidingItems();

    // if(/*health_arr[0] <= 0*/Player::Right){
    //     if(x()<250-x() && y()<300-y()){
    //         setPos(x()+1, y()+10);
    //     }
    // }

    for(int i = 0; i < colliding_items2.size(); i++) {
        // if(typeid(*(colliding_items2[i])) == typeid(Bullet)) {
        //     if(enemy_health > 0){
        //         enemy_health--;
        //     }
        //     if(enemy_health == 0){
        //         scene()->removeItem(this);
        //         delete this;
        //         break;
        //     }
        // }

        if(typeid(*(colliding_items2[i])) == typeid(Fence)) {
            setPos(125, y());
            is_hit = true;
            if(health_arr[0] && health_arr[0] > 0) { // Check if arr[0] exists and health is positive
                hit(0);
                if (!health) { // Check if health is null
                    health = new QGraphicsTextItem; // Create new health display
                    health->setPos(50, 250);
                    scene()->addItem(health); // Add health to the correct scene
                }
                if (scene() && health->scene() != scene()) { // Check if health is in the correct scene
                    scene()->addItem(health); // Add health to the correct scene
                }
                health->setPlainText(QString("Health: ") + QString::number(health_arr[0]));
            }
            if(health_arr[0] <= 0){ // Check if arr[0] exists and health is non-positive
                if (scene()) { // Check if scene exists

                    scene()->removeItem(arr[0]);
                    scene()->removeItem(this);
                } else {
                    qDebug() << "Enemy scene is null";
                }
                delete arr[0];
                arr[0] = nullptr; // Set arr[0] to null pointer after deletion
                Player::Right = true;

                setPos(x(),y());
            }
            return;
        }
        if (scene()) { // Check if scene exists

            //scene()->removeItem(arr[0]);
            scene()->removeItem(this);
        }
        // Collision with bullet

    }
    if (health && scene()) { // Check if health item exists and scene exists
        scene()->removeItem(health); // Remove previous health display if no collision
        delete health; // Delete previous health display
        health = nullptr; // Reset health pointer
    }
    QList<QGraphicsItem*> colliding_itemsworker1 = collidingItems();
    for(int i = 0; i < colliding_itemsworker1.size(); i++){
    if(typeid(*(colliding_itemsworker1[i])) == typeid(worker))
        {
    //     if(enemy_health > 0){
    //         enemy_health--;
    //     }
    //     if(enemy_health == 0){
         scene()->removeItem(colliding_itemsworker1[i]);
        delete colliding_itemsworker1[i];
      }
    }
    // }

}



QGraphicsTextItem* health2 = nullptr; // Declare health outside the loop

void Enemy::move_left(){
    setPos(x()-5, y());
    QList<QGraphicsItem*> colliding_items2 = collidingItems();

    for(int i = 0; i < colliding_items2.size(); i++) {
        // if(typeid(*(colliding_items2[i])) == typeid(Bullet)) {
        //     if(enemy_health > 0){
        //         enemy_health--;
        //     }
        //     if(enemy_health == 0){
        //         scene()->removeItem(this);
        //         delete this;
        //     }
        // }
        if(typeid(*(colliding_items2[i])) == typeid(Fence)) {
            setPos(450, y());
            is_hit = true;
            if(health_arr[1] && health_arr[1] > 0) { // Check if arr[1] exists and health is positive
                hit(1);
                if (!health2) { // Check if health2 is null
                    health2 = new QGraphicsTextItem; // Create new health display
                    health2->setPos(400, 250);
                    scene()->addItem(health2); // Add health2 to the correct scene
                }
                if (scene() && health2->scene() != scene()) { // Check if health2 is in the correct scene
                    scene()->addItem(health2); // Add health2 to the correct scene
                }
                health2->setPlainText(QString("Health: ") + QString::number(health_arr[1]));
            }
            if(health_arr[1] <= 0){ // Check if arr[0] exists and health is non-positive
                if (scene()) { // Check if scene exists

                    scene()->removeItem(arr[1]);
                    scene()->removeItem(this);
                } else {
                    qDebug() << "Enemy scene is null";
                }
                delete arr[1];
                arr[1] = nullptr; // Set arr[0] to null pointer after deletion
                Player::Left = true;

                setPos(x(),y());
            }
            return;
        }
        if (scene()) { // Check if scene exists

            //scene()->removeItem(arr[0]);
            scene()->removeItem(this);
        }
    }
    if (health2 && scene()) { // Check if health item exists and scene exists
        scene()->removeItem(health2); // Remove previous health display if no collision
        delete health2; // Delete previous health display
        health2 = nullptr; // Reset health pointer
    }
    QList<QGraphicsItem*> colliding_itemsworker2 = collidingItems();
    for(int i = 0; i < colliding_itemsworker2.size(); i++){
        if(typeid(*(colliding_itemsworker2[i])) == typeid(worker))
        {
            //     if(enemy_health > 0){
            //         enemy_health--;
            //     }
            //     if(enemy_health == 0){
            scene()->removeItem(colliding_itemsworker2[i]);
            delete colliding_itemsworker2[i];
        }
    }
    // }
}

QGraphicsTextItem* health3 = nullptr;

void Enemy::move_up(){
    setPos(x(), y()-5);
    QList<QGraphicsItem*> colliding_items2 = collidingItems();

    for(int i = 0; i < colliding_items2.size(); i++) {
        // if(typeid(*(colliding_items2[i])) == typeid(Bullet)) {
        //     if(enemy_health > 0){
        //         enemy_health--;
        //     }
        //     if(enemy_health == 0){
        //         scene()->removeItem(this);
        //         delete this;
        //     }
        // }
        if(typeid(*(colliding_items2[i])) == typeid(Fence)) {
            setPos(x(), 450);
            is_hit = true;
            if(health_arr[3] && health_arr[3] > 0) { // Check if arr[1] exists and health is positive
                hit(3);
                if (!health3) { // Check if health2 is null
                    health3 = new QGraphicsTextItem; // Create new health display
                    health3->setPos(250, 450);
                    scene()->addItem(health3); // Add health2 to the correct scene
                }
                if (health3->scene() != scene()) { // Check if health2 is in the correct scene
                    scene()->addItem(health3); // Add health2 to the correct scene
                }
                health3->setPlainText(QString("Health: ") + QString::number(health_arr[3]));
            }
            if(health_arr[3] <= 0){ // Check if arr[0] exists and health is non-positive
                if (scene()) { // Check if scene exists

                    scene()->removeItem(arr[3]);
                    scene()->removeItem(this);
                } else {
                    qDebug() << "Enemy scene is null";
                }
                delete arr[3];
                arr[3] = nullptr; // Set arr[0] to null pointer after deletion
                Player::Up = true;

                setPos(x(),y());
            }
            return;
        }
    }
    if (health3 && scene()) { // Check if health item exists and scene exists
        scene()->removeItem(health3); // Remove previous health display if no collision
        delete health3; // Delete previous health display
        health3 = nullptr; // Reset health pointer
    }
    QList<QGraphicsItem*> colliding_itemsworker3 = collidingItems();
    for(int i = 0; i < colliding_itemsworker3.size(); i++){
        if(typeid(*(colliding_itemsworker3[i])) == typeid(worker))
        {
            //     if(enemy_health > 0){
            //         enemy_health--;
            //     }
            //     if(enemy_health == 0){
            scene()->removeItem(colliding_itemsworker3[i]);
            delete colliding_itemsworker3[i];
        }
    }
    // }
}
QGraphicsTextItem* health4 = nullptr;

void Enemy::move_down(){
    setPos(x(), y()+5);
    QList<QGraphicsItem*> colliding_items2 = collidingItems();

    for(int i = 0; i < colliding_items2.size(); i++) {
        // if(typeid(*(colliding_items2[i])) == typeid(Bullet)) {
        //     if(enemy_health > 0){
        //         enemy_health--;
        //     }
        //     if(enemy_health == 0){
        //         scene()->removeItem(this);
        //         delete this;
        //     }
        // }
        if(typeid(*(colliding_items2[i])) == typeid(Fence)) {
            setPos(x(), 25);
            is_hit = true;
            if(health_arr[2] && health_arr[2] > 0) { // Check if arr[1] exists and health is positive
                hit(2);
                if (!health4) { // Check if health2 is null
                    health4 = new QGraphicsTextItem; // Create new health display
                    health4->setPos(250, 50);
                    scene()->addItem(health4); // Add health2 to the correct scene
                }
                if (health4->scene() != scene()) { // Check if health2 is in the correct scene
                    scene()->addItem(health4); // Add health2 to the correct scene
                }
                health4->setPlainText(QString("Health: ") + QString::number(health_arr[2]));
            }
            if(health_arr[2] <= 0){ // Check if arr[0] exists and health is non-positive
                if (scene()) { // Check if scene exists

                    scene()->removeItem(arr[0]);
                    scene()->removeItem(this);
                } else {
                    qDebug() << "Enemy scene is null";
                }
                delete arr[2];
                arr[2] = nullptr; // Set arr[0] to null pointer after deletion
                Player::Down = true;

                setPos(x(),y());
            }
            return;
        }
    }
    if (health4 && scene()) { // Check if health item exists and scene exists
        scene()->removeItem(health4); // Remove previous health display if no collision
        delete health4; // Delete previous health display
        health4 = nullptr; // Reset health pointer
    }
    QList<QGraphicsItem*> colliding_itemsworker4 = collidingItems();
    for(int i = 0; i < colliding_itemsworker4.size(); i++){
        if(typeid(*(colliding_itemsworker4[i])) == typeid(worker))
        {
            //     if(enemy_health > 0){
            //         enemy_health--;
            //     }
            //     if(enemy_health == 0){
            scene()->removeItem(colliding_itemsworker4[i]);
            delete colliding_itemsworker4[i];
        }
    }
    // }
}

//Fence* arr[24];

/*void setFenceObject(Fence*& obj){

        arr[0] = obj;

}*/


Enemy::Enemy(Fence** arr):arr(arr) {


    // QPixmap enemy("C:/Users/omars/OneDrive/Desktop/Uni/AUC/Semester 6/CS II/Lab/Assignments/Assignment 3/Chicken.png");
    // setPixmap(enemy.scaled(25,25));

    setRect(0, 0, 25, 25);

    int left_x = 0;
    int right_x = 550;
    int LR_y = (rand() % 3 + 1) * 100;

    int down_y = 500;
    int down_x = (rand() % 2 + 2) * 100;

    // Decides left or right or down
    // int direction_arr1[2] = {left_x, right_x};
    int decider = rand() % 3;
    if(decider == 0){
        setPos(left_x, LR_y);
    }
    if(decider == 1){
        setPos(right_x, LR_y);
    }
    if(decider == 2){
        setPos(down_x, down_y);
    }

    // Decides the y for left or right and the x for down



    // int x1, random_number_y1, x2, random_number_x3, y3, y4;
    // // Left and Right columns
    // x1 = 0;
    // x2 = 550;

    // //random_number_y1.display();
    // // Up and Down
    // random_number_x3 = rand() % (251) + 150;
    // random_number_y1 = rand() % 501;

    // y3 = 0;
    // y4 = 450;

    // //Left and right
    // int arr_1[4] = {x1, random_number_y1, x2, random_number_y1};

    // //Up and Down
    // int arr_2[4] = {y3, random_number_x3, y4, random_number_x3};

    // // Randomizes the choice either arr[0] or arr[2]
    // int final_random = rand()%2;
    // final_random *= 2;
    // // Decides which array to access
    // int arr_decider = rand() % 2;
    // arr_decider = arr_decider * 2 + 4;
    // if(arr_decider == 4){
    //     setPos(arr_1[final_random], arr_1[final_random+1]);
    // }
    // else{
    //     setPos(arr_2[final_random+1], arr_2[final_random]);
    // }

    // // Decide which way to move
    if(x() == 0 && !Player::Right){
        // move right
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this,SLOT (move_right()));
        timer->start(50);
        if(Player::Right){
            timer->stop();
        }
    }
    if(x() == 550 && !Player::Left){
        // move left
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this,SLOT (move_left()));
        timer->start(50);
        if(Player::Left){
            timer->stop();
        }
    }
    // if(arr_decider == 6 && final_random == 0 && !Player::Down){
    //     // move down
    //     QTimer * timer = new QTimer();
    //     connect(timer, SIGNAL(timeout()),this,SLOT (move_down()));
    //     timer->start(50);
    //     if(Player::Down){
    //         timer->stop();
    //     }
    // }
    if(y() == 500 && !Player::Up){
        // move up
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this,SLOT (move_up()));
        timer->start(50);
        if(Player::Up){
            timer->stop();
        }
    }

    if(Player::Right){
        QTimer * timer = new QTimer();
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(goToClanRight()));
        timer->start(50);
        if(clanCollision){
            timer->stop();
        }
    }
    if(Player::Left){
        QTimer * timer = new QTimer();
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(goToClanLeft()));
        timer->start(50);
        if(clanCollision){
            timer->stop();
        }
    }
    if(Player::Up){
        QTimer * timer = new QTimer();
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(goToClanUp()));
        timer->start(50);
        if(clanCollision){
            timer->stop();
        }
    }
    if(Player::Down){
        QTimer * timer = new QTimer();
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(goToClanLDown()));
        timer->start(50);
        if(clanCollision){
            timer->stop();
        }
    }

   /* while (is_hit = true && arr[0]->getHealth() > 0){
        arr[0]->decHealth();
    }*/




    //Handling collision with fence

   /* setPos(x(),y()-10);
    if(pos().y()+100<0){
        //scene()->removeItem(this);
        delete this;
    }*/

}

