#ifndef FENCE_H
#define FENCE_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Fence : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Fence(int x, int y, QGraphicsScene *scene, int w, int l);
    static int health;
    int x, y;
    int w, l;
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
