// game.cpp
#include "game.h"
#include "Player.h"
#include "Clan.h"
#include "fence.h"
#include "enemy.h"
#include "worker.h"
#include "Bullet.h"
#include "start.h"
#include "Player.h"
#include "Clan.h"
#include "fence.h"
#include "enemy.h"
#include "worker.h"
#include "Bullet.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include<QPixmap>
#include <QPen>
#include <QTimer>
#include <QFont>
#include <QPointF>
#include<vector>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QTimer>
#include <QDebug>
#include "game.h"
#include "gameworker.h"
#include <QThread>

game::game()
{
    // Constructor implementation, if needed
}

void game::runGame()
{
    GameWorker *worker = new GameWorker();
    QThread *thread = new QThread();
    worker->moveToThread(thread);
    GameWorker::connect(thread, &QThread::started, worker, &GameWorker::startGame);
    thread->start();
}

void game::initializeGame()
{
    int argc = 1; // At least one argument
    char arg[] = "game"; // Dummy argument
    char *argv[] = { arg, nullptr }; // Default value for argv
    QApplication a(argc, argv);


    // Create scene
    QGraphicsScene scene;

    // Create Clan
    Clan *clan = new Clan(&scene);
    //clan->setRect(250, 300, 50, 50);
    // Fences
    //Fence *LeftFence = new Fence(400, 350, &scene, 50, 400);
    Fence *LeftFence = new Fence(140, -47, &scene, 70, 556);
    //LeftFence->setRect(150, 50, 50, 400);
    // LeftFence->Display();
    //Fence *RightFence = new Fence(400, 350, &scene, 50, 400);
    Fence *RightFence = new Fence(390, -47, &scene, 70, 556);
    //RightFence->setRect(400, 50, 50, 400);
    // RightFence->Display();
    // Fence *TopFence = new Fence(400, 350, &scene, 200, 50);
    Fence *TopFence = new Fence(150, 38, &scene, 300, 70);
    //TopFence->setRect(200, 50, 200, 50);
    // TopFence->Display();
    Fence *BottomFence = new Fence(150, 388, &scene, 300, 70);
    //BottomFence->setRect(200, 400, 200, 50);
    // BottomFence->Display();

    // Array of fences
    Fence* arr[4] = {LeftFence, RightFence, TopFence, BottomFence};/*{ fence1, fence2, fence3, fence4, fence5, fence6, fence7, fence8, fence9, fence10, fence11, fence12,
                      fence13, fence14, fence15, fence16, fence17,fence18, fence19, fence20, fence21, fence22, fence23, fence24};*/


    // Create Player (Cannon)

    //player->setRect(250, 200, 50, 50);
    scene.setSceneRect(0,0,600,500);
    Player *player = new Player(&scene, arr);
    player->setTransformOriginPoint(QPointF(25, 25));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // factor 50
    // Putting Player
    scene.addItem(player);
    // Putting Bullet
    //scene.addItem(Bullet);
    // Putting clan
    scene.addItem(clan);
    // Putting fences
    /*  scene.addItem(fence1);
    scene.addItem(fence2);
    scene.addItem(fence3);
    scene.addItem(fence4);
    scene.addItem(fence5);
    scene.addItem(fence6);
    scene.addItem(fence7);
    scene.addItem(fence8);
    scene.addItem(fence9);
    scene.addItem(fence10);
    scene.addItem(fence11);
    scene.addItem(fence12);
    scene.addItem(fence13);
    scene.addItem(fence14);
    scene.addItem(fence15);
    scene.addItem(fence16);
    scene.addItem(fence17);
    scene.addItem(fence18);
    scene.addItem(fence19);
    scene.addItem(fence20);
    scene.addItem(fence21);
    scene.addItem(fence22);
    scene.addItem(fence23);
    scene.addItem(fence24);*/
    scene.addItem(LeftFence);
    scene.addItem(RightFence);
    scene.addItem(TopFence);
    scene.addItem(BottomFence);

    /*QTimer * time1 = new QTimer();
    QObject::connect(time1, SIGNAL(timeout()),fence2,SLOT(Display()));
    time1->start(1000);*/
    //fence2->decHealth();

    //scene.addItem(health_display);
    // Putting workers
    worker* worker1 = new worker();
    //worker1->setRect(200,225,50,50);
    worker1->setRect(240,300,25,25);//right of clan
    scene.addItem(worker1);
    worker* worker2 = new worker();
    //worker2->setRect(350,225,50,50);
    worker2->setRect(260,300,25,25);//left of clan
    scene.addItem(worker2);
    worker* worker3 = new worker();
    //worker3->setRect(275,100,50,50);
    worker3->setRect(250,290,25,25);//top of clan
    scene.addItem(worker3);
    worker* worker4 = new worker();
    //worker4->setRect(275,350,50,50);
    worker4->setRect(250,310,25,25);//bottom of clan
    scene.addItem(worker4);

    //Create view

    QGraphicsView view;
    view.setFixedSize(600,500);
    view.setScene(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QTimer * time_enemy = new QTimer();
    QObject::connect(time_enemy, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time_enemy->start(2000);

    QTimer *time_worker1 = new QTimer();
    QObject::connect(time_worker1, SIGNAL(timeout()),worker1,SLOT(moveWorker1()));
    time_worker1->start(30);
    QTimer *time_worker2 = new QTimer();
    QObject::connect(time_worker2, SIGNAL(timeout()),worker2,SLOT(moveWorker2()));
    time_worker2->start(30);
    QTimer *time_worker3 = new QTimer();
    QObject::connect(time_worker3, SIGNAL(timeout()),worker3,SLOT(moveWorker3()));
    time_worker3->start(50);
    QTimer *time_worker4 = new QTimer();
    QObject::connect(time_worker4, SIGNAL(timeout()),worker4,SLOT(moveWorker4()));
    time_worker4->start(30);

    view.show();
    // Start w;
    // w.show();
    a.exec();
}
