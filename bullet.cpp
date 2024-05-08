#include "bullet.h"
#include<QGraphicsScene>
#include<QTimer>
#include"Enemy.h"
#include"player.h"

Bullet::Bullet(int a) {
    QPixmap bulletpic("C:/Users/omars/OneDrive/Desktop/Uni/AUC/Semester 6/CS II/Project/ClashOfClans1/Images/Bullet.png");
    setPixmap(bulletpic.scaled(50, 50));
    setPos(240, 200);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    angle = a;
}


void Bullet::move() {
    // QList<QGraphicsItem*> colliding_items = collidingItems();
    // for (int i = 0, n = colliding_items.size(); i < n; ++i){
    //     if (typeid(*(colliding_items[i])) == typeid(Enemy)){
    //         Player::increaseScore();
    //         qDebug() << "Bullet hit an enemy!" << Player::getScore();
    //         scene()->removeItem(colliding_items[i]);
    //         scene()->removeItem(this);
    //         delete colliding_items[i];
    //         delete this;
    //         return;
    //     }
    // }
    //y_move = 5*qTan(qDegreesToRadians(angle));
    //y_move = 5;

    if (angle >= 270){
        x_move = 5;
        y_move = 5*qTan(qDegreesToRadians(angle));
        setPos(x()- (5*x_move), y() - (5*y_move));
    }
    if (angle <= -270){
        x_move = 5;
        y_move = 5*qTan(qDegreesToRadians(angle));
        setPos(x()-x_move, y() - y_move);
    }
    else if (angle == 90){
        x_move = 0;
        y_move = 2;
    }
    else if (angle == -90){
        x_move = 0;
        y_move = -2;
    }
    else if (angle > 90 || angle < -90){
        x_move = 5;
        y_move = 5*qTan(qDegreesToRadians(angle));
        setPos(x()+x_move, y() + y_move);
    }
    else if (angle < 90 && angle > -90){
        x_move = 5;
        y_move = 5*qTan(qDegreesToRadians(angle));
        setPos(x()-x_move, y() - y_move);
    }

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            if(scene()){
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
                return;
            }

        }
    }

    //setPos(x()+x_move, y() + y_move);
    // if(pos().y() + 50 < 200){
    //     scene()->removeItem(this);
    //     //delete this;
    // }
    // if(pos().x() + 25 < 200){
    //     scene()->removeItem(this);
    //     //delete this;
    // }
    // if(pos().x() + 25 > 400){
    //     scene()->removeItem(this);
    //     //delete this;
    // }
    // if(pos().y() + 50 > 400){
    //     scene()->removeItem(this);
    //     //delete this;
    // }
}
