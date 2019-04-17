#ifndef INVENTORYPLAYER_H
#define INVENTORYPLAYER_H

#include <iostream>
#include <sstream>
#include<string>


using namespace std;


class Inventory{
    private:
    
    //RESOURCES
    int wood;
    int bricks;
    int grain;
    int wool;
    int ore;
    
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
    

};

#endif