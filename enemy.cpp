#include "enemy.h"
#include "Fence.h"
#include "Bullet.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QThread>
#include<QDebug>
#include<QPixmap>
#include<QGraphicsPixmapItem>

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

bool is_hit = false;
QGraphicsTextItem* health = nullptr; // Declare health outside the loop


// Inside Enemy::move_right() function
void Enemy::move_right() {
    setPos(x() + 5, y());
    QList<QGraphicsItem*> colliding_items2 = collidingItems();

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
                if (health->scene() != scene()) { // Check if health is in the correct scene
                    scene()->addItem(health); // Add health to the correct scene
                }
                health->setPlainText(QString("Health: ") + QString::number(health_arr[0]));
            }
            if(health_arr[0] <= 0){ // Check if arr[0] exists and health is non-positive
                if (scene()) { // Check if scene exists
                    scene()->removeItem(arr[0]);
                } else {
                    qDebug() << "Enemy scene is null";
                }
                delete arr[0];
                arr[0] = nullptr; // Set arr[0] to null pointer after deletion
                while(x()!=400){
                    setPos(x()+5, y());
                }
            }
            return;
        }
        // Collision with bullet

    }
    if (health && scene()) { // Check if health item exists and scene exists
        scene()->removeItem(health); // Remove previous health display if no collision
        delete health; // Delete previous health display
        health = nullptr; // Reset health pointer
    }
    // QList<QGraphicsItem*> colliding_items3 = collidingItems();
    // for(int i = 0; i < colliding_items3.size(); i++){
    // if(typeid(*(colliding_items3[i])) == typeid(Bullet)) {
    //     if(enemy_health > 0){
    //         enemy_health--;
    //     }
    //     if(enemy_health == 0){
    //         scene()->removeItem(this);
    //         delete this;
    //     }
    // }
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
                if (health2->scene() != scene()) { // Check if health2 is in the correct scene
                    scene()->addItem(health2); // Add health2 to the correct scene
                }
                health2->setPlainText(QString("Health: ") + QString::number(health_arr[1]));
            }
            if(health_arr[1] <= 0){ // Check if arr[1] exists and health is non-positive
                if (scene()) { // Check if scene exists
                    scene()->removeItem(arr[1]);
                } else {
                    qDebug() << "Enemy scene is null";
                }
                delete arr[1];
                arr[1] = nullptr; // Set arr[1] to null pointer after deletion
            }
            return;
        }
    }
    if (health2 && scene()) { // Check if health item exists and scene exists
        scene()->removeItem(health2); // Remove previous health display if no collision
        delete health2; // Delete previous health display
        health2 = nullptr; // Reset health pointer
    }
    // QList<QGraphicsItem*> colliding_items3 = collidingItems();
    // for(int i = 0; i < colliding_items3.size(); i++){
    //     if(typeid(*(colliding_items3[i])) == typeid(Bullet)) {
    //         if(enemy_health > 0){
    //             enemy_health--;
    //         }
    //         if(enemy_health == 0){
    //             scene()->removeItem(this);
    //             delete this;
    //         }
    //     }
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
            if(health_arr[3] <= 0){ // Check if arr[1] exists and health is non-positive
                if (scene()) { // Check if scene exists
                    scene()->removeItem(arr[3]);
                } else {
                    qDebug() << "Enemy scene is null";
                }
                delete arr[3];
                arr[3] = nullptr; // Set arr[1] to null pointer after deletion
            }
            return;
        }
    }
    if (health3 && scene()) { // Check if health item exists and scene exists
        scene()->removeItem(health3); // Remove previous health display if no collision
        delete health3; // Delete previous health display
        health3 = nullptr; // Reset health pointer
    }
    // QList<QGraphicsItem*> colliding_items3 = collidingItems();
    // for(int i = 0; i < colliding_items3.size(); i++){
    //     if(typeid(*(colliding_items3[i])) == typeid(Bullet)) {
    //         if(enemy_health > 0){
    //             enemy_health--;
    //         }
    //         if(enemy_health == 0){
    //             scene()->removeItem(this);
    //             delete this;
    //         }
    //     }
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
            if(health_arr[2] <= 0){ // Check if arr[1] exists and health is non-positive
                if (scene()) { // Check if scene exists
                    scene()->removeItem(arr[2]);
                } else {
                    qDebug() << "Enemy scene is null";
                }
                delete arr[2];
                arr[2] = nullptr; // Set arr[1] to null pointer after deletion
            }
            return;
        }
    }
    if (health4 && scene()) { // Check if health item exists and scene exists
        scene()->removeItem(health4); // Remove previous health display if no collision
        delete health4; // Delete previous health display
        health4 = nullptr; // Reset health pointer
    }
    // QList<QGraphicsItem*> colliding_items3 = collidingItems();
    // for(int i = 0; i < colliding_items3.size(); i++){
    //     if(typeid(*(colliding_items3[i])) == typeid(Bullet)) {
    //         if(enemy_health > 0){
    //             enemy_health--;
    //         }
    //         if(enemy_health == 0){
    //             scene()->removeItem(this);
    //             delete this;
    //         }
    //     }
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
    int x1, random_number_y1, x2, random_number_x3, y3, y4;
    // Left and Right columns
    x1 = 0;
    x2 = 550;

    //random_number_y1.display();
    // Up and Down
    random_number_x3 = rand() % (251) + 150;
    random_number_y1 = rand() % 501;

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

