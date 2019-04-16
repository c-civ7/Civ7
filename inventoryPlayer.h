#ifndef INVENTORYPLAYER_H
#define INVENTORYPLAYER_H

#include <iostream>
#include <sstream>
#include<string>


using namespace std;


class Inventory{
    protected:
    
    //RESOURCES
    int wood=1;
    int bricks=1;
    int grain=1;
    int wool=1;
    int ore=1;
    
    //VICTORY POINTS
    int victory=0;
    
    
    public:
    void setWood(int);
    void setBricks(int);
    void setGrain(int);
    void setWool(int);
    void setOre(int);
    void setVictory(int);
    
    
    int getWood();
    int getBricks();
    int getGrain();
    int getWool();
    int getOre();
    int getVictory();
    
//class playerInventory:: public Inventory(){
  //  public:
 //  int outputInv();
//}
};

#endif