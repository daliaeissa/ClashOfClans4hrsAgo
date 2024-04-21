#include "health.h"
#include <QGraphicsScene>
#include<QFont>

QGraphicsTextItem *health_display = new QGraphicsTextItem();

void Health::incHealth(){
    health_bar++;
}
void Health::decHealth(){
    health_bar--;
}
void Health::setHealth(int h){
    health_bar = h;
}
/*int Health::getHealth(){
    return health_bar;
}*/


Health::Health()
{
    /*health_display->setPlainText(QString("Health: ") + QString::number(getHealth()));
    health_display->setFont(font());
    health_display->setDefaultTextColor(Qt::red);
    health_display->setPos(400,0);
   // scene()->addItem(health_display);*/
}

