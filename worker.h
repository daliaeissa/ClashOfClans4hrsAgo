#ifndef WORKER_H
#define WORKER_H
#include<QGraphicsItem>
#include<QGraphicsRectItem>
#include<QObject>
#include<QGraphicsPixmapItem>

class worker: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    worker();
};

#endif // WORKER_H
