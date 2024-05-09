#ifndef CLAN_H
#define CLAN_H
#include<QGraphicsItem>
#include<QObject>

class Clan:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Clan();
    static int clan_health;
    static int counter;

public slots:
    void setHealth(int clan_health);
    static int getHealth();
};

#endif // CLAN_H
