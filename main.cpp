#include "start.h"
#include "Player.h"
#include "Clan.h"
#include "fence.h"
#include "enemy.h"
#include "worker.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QPen>
#include <QTimer>
#include <QFont>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Clan
    Clan *clan = new Clan();
    clan->setRect(250, 300, 50, 50);

    // Create Player (Cannon)
    Player *player = new Player();
    player->setRect(250, 200, 50, 50);
    //player->settingFences();

    // Create fence1



    // Create fence2
    Fence *fence2 = new Fence(200, 50);
    fence2->setRect(200, 50, 50, 50);
    //fence2->Display();
    /*QGraphicsTextItem *health_display = new QGraphicsTextItem();
    int health = fence2->health;
    health_display->setPlainText(QString("Health: ") + QString::number(health));
    //health_display->setFont(font());
    health_display->setDefaultTextColor(Qt::red);
    health_display->setPos(400,0);health_display->setPlainText(QString("Health: ") + QString::number(health));
    //health_display->setFont(font());
    health_display->setDefaultTextColor(Qt::red);
    health_display->setPos(400,0);*/

    // Create fence3
    Fence *fence3 = new Fence(250, 50);
    fence3->setRect(250, 50, 50, 50);


    // Create fence4
    Fence *fence4 = new Fence(300, 50);
    fence4->setRect(300, 50, 50, 50);

    // Create fence5
    Fence *fence5 = new Fence(350, 50);
    fence5->setRect(350, 50, 50, 50);

    // Create fence6
    Fence *fence6 = new Fence(400, 50);
    fence6->setRect(400, 50, 50, 50);

    // Create fence7
    Fence *fence7 = new Fence(150, 100);
    fence7->setRect(150, 100, 50, 50);

    // Create fence8
    Fence *fence8 = new Fence(150, 150);
    fence8->setRect(150, 150, 50, 50);

    // Create fence9
    Fence *fence9 = new Fence(150, 200);
    fence9->setRect(150, 200, 50, 50);

    // Create fence10
    Fence *fence10 = new Fence(150, 250);
    fence10->setRect(150, 250, 50, 50);

    // Create fence11
    Fence *fence11 = new Fence(150, 300);
    fence11->setRect(150, 300, 50, 50);

    // Create fence12
    Fence *fence12 = new Fence(150, 350);
    fence12->setRect(150, 350, 50, 50);

    // Create fence13
    Fence *fence13 = new Fence(150, 400);
    fence13->setRect(150, 400, 50, 50);

    // Create fence14
    Fence *fence14 = new Fence(200, 400);
    fence14->setRect(200, 400, 50, 50);

    // Create fence15
    Fence *fence15 = new Fence(250, 400);
    fence15->setRect(250, 400, 50, 50);

    // Create fence16
    Fence *fence16 = new Fence(300, 400);
    fence16->setRect(300, 400, 50, 50);

    // Create fence17
    Fence *fence17 = new Fence(350, 400);
    fence17->setRect(350, 400, 50, 50);

    // Create fence18
    Fence *fence18 = new Fence(400, 400);
    fence18->setRect(400, 400, 50, 50);

    // Create fence24
    Fence *fence24 = new Fence(400, 100);
    fence24->setRect(400, 100, 50, 50);

    // Create fence23
    Fence *fence23 = new Fence(400, 150);
    fence23->setRect(400, 150, 50, 50);

    // Create fence22
    Fence *fence22 = new Fence(400, 200);
    fence22->setRect(400, 200, 50, 50);

    // Create fence21
    Fence *fence21 = new Fence(400, 250);
    fence21->setRect(400, 250, 50, 50);

    // Create fence20
    Fence *fence20 = new Fence(400, 300);
    fence20->setRect(400, 300, 50, 50);

    // Create fence19
    Fence *fence19 = new Fence(400, 350);
    fence19->setRect(400, 350, 50, 50);

    // Array of fences
    Fence* arr[24] = { fence2, fence3, fence4, fence5, fence6, fence7, fence8, fence9, fence10, fence11, fence12,
                      fence13, fence14, fence15, fence16, fence17,fence18, fence19, fence20, fence21, fence22, fence23, fence24};


    // Create scene
    QGraphicsScene scene;
    scene.setSceneRect(0,0,600,500); // factor 50
    // Putting Player
    scene.addItem(player);
    // Putting clan
    scene.addItem(clan);
    // Putting fences

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
    scene.addItem(fence24);

    /*QTimer * time1 = new QTimer();
    QObject::connect(time1, SIGNAL(timeout()),fence2,SLOT(Display()));
    time1->start(1000);*/
    //fence2->decHealth();

 //scene.addItem(health_display);
    // Putting workers
    worker* worker1 = new worker();
    worker1->setRect(200,275,50,50);
    scene.addItem(worker1);
    worker* worker2 = new worker();
    worker2->setRect(200,175,50,50);
    scene.addItem(worker2);
    worker* worker3 = new worker();
    worker3->setRect(350,175,50,50);
    scene.addItem(worker3);
    worker* worker4 = new worker();
    worker4->setRect(350,275,50,50);
    scene.addItem(worker4);
    worker* worker5 = new worker();
    worker5->setRect(275,100,50,50);
    scene.addItem(worker5);
    worker* worker6 = new worker();
    worker6->setRect(275,350,50,50);
    scene.addItem(worker6);

    //Create view

    QGraphicsView view;
    view.setFixedSize(600,500);
    view.setScene(&scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QTimer * time_enemy = new QTimer();
    QObject::connect(time_enemy, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time_enemy->start(2500);

    view.show();
    Start w;
    w.show();
    return a.exec();
}
