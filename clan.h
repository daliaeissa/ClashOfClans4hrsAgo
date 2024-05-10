#ifndef CLAN_H
#define CLAN_H
#include<QGraphicsItem>
#include<QObject>
#include<QGraphicsPixmapItem>
#include<QPixmap>

class Clan:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Clan(QGraphicsScene* scene);
    static int clan_health;
    static int counter;
    static bool end_of_time;

public slots:
    void setHealth(int clan_health);
    static int getHealth();
};

#endif// CLAN_H
