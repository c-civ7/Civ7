#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <sstream>
#include<string>
#include<iomanip>


using namespace std;

enum Land{FOREST, HILLS, FIELD, PASTURE, MOUNTAIN};

class Card{
    protected:
    
    Land LAND;
    int number;
    string player;
    int type;
    
    public:
    void setLand(Land);
    void setNumber(int);
    void setName(string);
    void setType(int);
    int getNumber();
    int getType();
    Land getLand();
    string getName();
    virtual string render(int); 
};


class tileCard: public Card{
    public:
    tileCard(Land, int);
    string render(int);
};

class settlementCard: public Card{
    public:
    settlementCard(Land, int,string);
    string render(int);
};

class cityCard: public Card{
    public:
    cityCard(Land, int,string);
    string render(int);
};


#endif