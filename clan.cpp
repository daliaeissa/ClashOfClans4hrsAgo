#include "clan.h"
#include <QGraphicsScene>
#include <QTimer>

int Clan::clan_health = 200;
int Clan::counter = 0;

Clan::Clan() {

}
int Clan::getHealth(){
    return clan_health;
}
void Clan::setHealth(int clan_health){
    clan_health;
}
