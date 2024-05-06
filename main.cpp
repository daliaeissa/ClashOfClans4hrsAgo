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

// Define a structure to represent a node
struct Node {
    QPointF position; // Position of the node
    bool isClanNode; // Flag to indicate if this is the clan node

    // Constructor to initialize the position and the flag
    Node(const QPointF& pos, bool isClan = false) : position(pos), isClanNode(isClan) {}
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Define the size of the playable area and the size of each node
    int areaWidth = 200;
    int areaHeight = 300;
    int nodeWidth = 20;
    int nodeHeight = 20;

    // Calculate the number of nodes along each dimension
    int numNodesX = areaWidth / nodeWidth;
    int numNodesY = areaHeight / nodeHeight;

    // Create a vector to store all the nodes
    std::vector<Node> nodes;

    // Populate the nodes with their positions
    for (int y = 0; y < numNodesY; ++y) {
        for (int x = 0; x < numNodesX; ++x) {
            // Calculate the position of the node
            QPointF position(x * nodeWidth, y * nodeHeight);

            // Determine if this node is the clan node
            bool isClanNode = (position.x() == 70 && position.y() == 220);

            // Create a new node with the calculated position and add it to the vector
            nodes.emplace_back(position, isClanNode);
        }
    }

    // Output the positions of all nodes and indicate the clan node (for demonstration purposes)
    for (const auto& node : nodes) {
        qDebug() << "Node position:" << node.position << "Is clan node:" << node.isClanNode;
    }

    // Create Clan
    Clan *clan = new Clan();
    clan->setRect(250, 300, 50, 50);
    // Fences
    Fence *LeftFence = new Fence(400, 350);
    LeftFence->setRect(150, 50, 50, 400);
   // LeftFence->Display();
    Fence *RightFence = new Fence(400, 350);
    RightFence->setRect(400, 50, 50, 400);
   // RightFence->Display();
    Fence *TopFence = new Fence(400, 350);
    TopFence->setRect(200, 50, 200, 50);
   // TopFence->Display();
    Fence *BottomFence = new Fence(400, 350);
    BottomFence->setRect(200, 400, 200, 50);
   // BottomFence->Display();

    // Array of fences
    Fence* arr[4] = {LeftFence, RightFence, TopFence, BottomFence};/*{ fence1, fence2, fence3, fence4, fence5, fence6, fence7, fence8, fence9, fence10, fence11, fence12,
                      fence13, fence14, fence15, fence16, fence17,fence18, fence19, fence20, fence21, fence22, fence23, fence24};*/


    // Create scene
    QGraphicsScene scene;
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
    Start w;
    w.show();
    return a.exec();
}
