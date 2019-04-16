#include "inventoryPlayer.h"


using namespace std;

void Inventory::setWood(int w){
    wood= w;
}
void Inventory::setBricks(int b){
    bricks = b;
}
void Inventory::setGrain(int g){
    grain = g;
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




int Inventory::getWood(){
    return wood;
}
int Inventory::getBricks(){
    return bricks;
}
int Inventory::getGrain(){
    return grain;
}
int Inventory::getWool(){
   return wool;
}
int Inventory::getOre(){
    return ore;
}
int Inventory::getVictory(){
    return victory;
}

//int playerInventory::outputInv(){
    //cout<< "Wool"<< Inventory.getWool()<< endl;
//}