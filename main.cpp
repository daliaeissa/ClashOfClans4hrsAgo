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
#include <QCoreApplication>
#include<QPixmap>
#include <QPen>
#include <QTimer>
#include <QFont>
#include <QPointF>
#include<vector>
#include "startmenu.h"
#include "ui_startmenu.h"

static bool started = false;


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
    StartMenu start_menu;
    start_menu.show();
    return a.exec();
}
