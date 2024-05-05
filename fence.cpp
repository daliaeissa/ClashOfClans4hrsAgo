#include "fence.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>

int Fence::getHealth(){
    return health;
}
void Fence::setHealth(int h){
    health = h;
}
void Fence::incHealth(){
    health++;
}
void Fence::decHealth(){
    health--;
}

void Fence::set_hit(){
    is_hit = true;
}


int Fence::health = 100;
bool Fence::is_hit = false;

Fence::Fence(int x, int y):x(x),y(y) {
    /*QTimer * time1 = new QTimer();
    QObject::connect(time1, SIGNAL(timeout()),this,SLOT(Display()));
    time1->start(1000);*/
}
/*void Fence::Display()
{

    if (scene())
    {
        // Iterate over all items in the scene
        QList<QGraphicsItem*> itemsList = scene()->items();
        for (QGraphicsItem* item : itemsList) {
            // Check if the item is a QGraphicsTextItem and its position matches (x, y)
            if (item->type() == QGraphicsTextItem::Type && item->pos() == QPointF(x(), y()))
            {
                scene()->removeItem(item); // Remove the previous health display
                delete item; // Free memory allocated for the QGraphicsTextItem
                Fence::is_hit = false;
                break; // Stop iterating after finding and removing the item
            }
        }

        // Create a new health display
        QGraphicsTextItem* health_display = new QGraphicsTextItem;
        health_display->setPlainText(QString("Health: ") + QString::number(Fence::getHealth()));
        health_display->setDefaultTextColor(Qt::red);
        health_display->setPos(x(), y());
        scene()->addItem(health_display); // Add the updated health display
    }
}
// void Fence::Display() {
    // if (scene()){
    //     QGraphicsTextItem* health_display = new QGraphicsTextItem;
    //     health_display->setPlainText(QString("Health: ") + QString::number(getHealth()));
    //     health_display->setDefaultTextColor(Qt::red);
    //     health_display->setPos(x, y);
    //     if(is_hit == true){
    //         scene()->removeItem(health_display);
    //     }
    //     scene()->removeItem(health_display);
    //     health_display->setPlainText(QString("Health: ") + QString::number(getHealth()));
    //     health_display->setDefaultTextColor(Qt::red);
    //     health_display->setPos(x, y);
    //     scene()->addItem(health_display);
    //     is_hit = false;
    // }
  /*  QList<QGraphicsItem*> colliding_items2 = collidingItems();
    for(int i=0;i<colliding_items2.size();i++)
    {
        if(typeid(*(colliding_items2[i])) == typeid(Enemy))
        {
            //QTimer * timer = new QTimer();
            if(getHealth() > 0 && !is_hit){
                //this->decHealth();
                set_hit();
            }
            if(getHealth() == 0){

                delete this;
            }
            return;
        }
    }*/
    /*if (scene()) {
        // Iterate over all items in the scene
        QList<QGraphicsItem*> itemsList = scene()->items();
        for (QGraphicsItem* item : itemsList) {
            // Check if the item is a QGraphicsTextItem and its position matches (x, y)
            if (item->type() == QGraphicsTextItem::Type && item->pos() == QPointF(x, y)) {
                scene()->removeItem(item); // Remove the previous health display
                delete item; // Free memory allocated for the QGraphicsTextItem
                is_hit = false;
                break; // Stop iterating after finding and removing the item
            }
        }

        // Create a new health display
        QGraphicsTextItem* health_display = new QGraphicsTextItem;
        health_display->setPlainText(QString("Health: ") + QString::number(getHealth()));
        health_display->setDefaultTextColor(Qt::red);
        health_display->setPos(x, y);
        scene()->addItem(health_display); // Add the updated health display
    }*/
//}



