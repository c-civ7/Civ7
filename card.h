#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <sstream>


using namespace std;

enum Land{FOREST, HILLS, FIELD, PASTURE, MOUNTAIN};

class card{
    protected:
    
    Land l;
    int number;
    public:
    
    virtual string render(int); 

};











#endif