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
    int field=1;
    int wool=1;
    int ore=1;
    
    //VICTORY POINTS
    int victory=0;
    
    
    public:
    void setWood(int);
    void setBricks(int);
    void setField(int);
    void setWool(int);
    void setOre(int);
    void setVictory(int);
    
    int getWood(int);
    int getBricks(int);
    int getField(int);
    int getWool(int);
    int getOre(int);
    int getVictory(int);
};

#endif