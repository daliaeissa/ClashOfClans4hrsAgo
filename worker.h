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
public slots:
    void moveWorker1();
    void moveWorker2();
    void moveWorker3();
    void moveWorker4();
};

#endif // WORKER_H
