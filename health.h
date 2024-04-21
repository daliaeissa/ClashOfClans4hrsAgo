#ifndef HEALTH_H
#define HEALTH_H
#include<QObject>
#include<QGraphicsTextItem>

class Health: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Health();
    int health_bar = 3;
public slots:
    void decHealth();
    void setHealth(int h);
    void incHealth();
    //int getHealth();
};

#endif // HEALTH_H

