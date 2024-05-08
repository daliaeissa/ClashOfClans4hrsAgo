#include "player.h"
#include<QGraphicsScene>
#include "Fence.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QtMath>
#include<QDebug>

Player::Player(QGraphicsScene* scene, Fence** arr) : arr(arr) {
    QPixmap playerPixmap("C:/Users/omars/OneDrive/Desktop/Uni/AUC/Semester 6/CS II/Project/ClashOfClans1/Images/Player.png");
    setPixmap(playerPixmap.scaled(50, 50));
    setPos(250, 200);
    scene->addItem(this); // Add the player to the scene
}

bool Player::Right = false;
bool Player::Left = false;
bool Player::Up = false;
bool Player::Down = false;



void Player::createEnemy(){
    Enemy* enemy = new Enemy(arr);
    scene()->addItem(enemy);

}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        setRotation(rotation() - 5);
        angle= angle-5;
        qDebug() << "angle left: " << angle;
        if (angle == 360 || angle == -360){
            angle =0;
        }
        //setRotation(rotation() - 5);
    } else if (event->key() == Qt::Key_Right) {
        setRotation(rotation() + 5);
        angle= angle+5;
        qDebug() << "angle right: " << angle;
        if (angle == 360 || angle == -360){
            angle =0;
         }
    } else if (event->key() == Qt::Key_Space) {
        // Create Bullet
        Bullet *bullet = new Bullet(angle);
        //player->setRect(250, 200, 50, 50);

        //bullet->setPos(x() + 90.5, y());
        scene()->addItem(bullet);
    }
}



