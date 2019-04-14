#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <sstream>
#include<string>


using namespace std;

enum Land{FOREST, HILLS, FIELD, PASTURE, MOUNTAIN};

class Card{
    protected:
    
    Land LAND;
    int number;
    string player;
    
    public:
    void setLand(Land);
    void setNumber(int);
    void setName(string);
    int getNumber();
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

class developmentCard: public Card{
    public:
    developmentCard();
   
};





#endif