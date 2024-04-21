#ifndef CLAN_H
#define CLAN_H
#include<QGraphicsItem>
#include<QObject>

class Clan:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Clan();
};

#endif // CLAN_H
