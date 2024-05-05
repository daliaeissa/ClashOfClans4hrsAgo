#ifndef FENCE_H
#define FENCE_H
#include <QObject>
#include <QGraphicsRectItem>

class Fence : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Fence(int x, int y);
    static int health;
    int x, y;
    static bool is_hit;


public slots:
    void setHealth(int h);
    static int getHealth();
    void incHealth();
    static void decHealth();
    //void Display();
    static void set_hit();

};


#endif // FENCE_H
