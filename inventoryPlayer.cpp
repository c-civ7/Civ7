#include "inventoryPlayer.h"


using namespace std;

void Inventory::setWood(int w){
    wool= w;
}
void Inventory::setBricks(int b){
    bricks = b;
}
void Inventory::setField(int F){
    field = F;
}
void Inventory::setWool(int w){
    wool = w;
}
void Inventory::setOre(int o){
    ore = o;
}
void Inventory::setVictory(int V){
    victory = V;
}




int Inventory::getWood(int w){
    return  wool;
}
int Inventory::getBricks(int b){
    return bricks;
}
int Inventory::getField(int F){
    return field;
}
int Inventory::getWool(int w){
   return wool;
}
int Inventory::getOre(int o){
    return ore;
}
int Inventory::getVictory(int V){
    return victory;
}