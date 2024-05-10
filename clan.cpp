#include "clan.h"
#include <QGraphicsScene>
#include <QTimer>

int Clan::clan_health = 200;
int Clan::counter = 0;
bool Clan::end_of_time = false;


Clan::Clan(QGraphicsScene* scene) {
    QPixmap clanPixmap("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/Computer Science 2/Project/ClashOfClans2/Images/Clan.jpeg");
    setPixmap(clanPixmap.scaled(50, 50));
    setPos(250, 300);
    scene->addItem(this);
}
int Clan::getHealth(){
    return clan_health;
}
void Clan::setHealth(int clan_health){
    clan_health;
}
