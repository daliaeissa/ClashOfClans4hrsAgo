#ifndef WORKER_H
#define WORKER_H
#include<QGraphicsItem>
#include<QGraphicsRectItem>
#include<QObject>
#include<QGraphicsPixmapItem>
#include<QGraphicsScene>

class worker: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    worker(int x, int y, QGraphicsScene *scene);
    int x, y;
public slots:
    void moveWorker1();
    void moveWorker2();
    void moveWorker3();
    void moveWorker4();
};

#endif // WORKER_H
