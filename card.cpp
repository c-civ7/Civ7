#include "card.h"


using namespace std;

void Card::setLand(Land L){
    LAND = L;
}
void Card::setNumber(int n){
    number = n;
}
void Card::setName(string p){
    player = p;
}


tileCard::tileCard(Land c, int n){
    setLand(c);
    setNumber(n);
}

settlementCard::settlementCard(Land c, int n, string player){
    setLand(c);
    setNumber(n);
    setName(player);
}



string Card::render(int line){
    switch(line){
        case 0: return ".............";
        case 1: return "|           |";
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return "";
    }
}

string tileCard::render(int line){
     stringstream ss;
    switch(line){
        case 0: return "....................";
        case 1: 
            switch(LAND){
                case (FOREST):
                    if(number<10)
                    ss << "|Forest           "<<  number << "|";
                    if(number>=10)
                    ss << "|Forest          "<<  number << "|";
                    return ss.str();
                break;
                case (HILLS):
                    if(number<10)
                    ss<< "|Hills            " <<  number << "|";
                    if(number>=10)
                    ss<< "|Hills           " <<  number << "|";
                    return ss.str();
                break;
                case (FIELD):
                     if(number<10)
                    ss<< "|Fields           " <<  number << "|";
                     if(number>=10)
                     ss<< "|Fields          " <<  number << "|";
                    return ss.str();
                break;
                case (PASTURE):
                    if(number<10)
                    ss<< "|Pasture          " <<  number << "|";
                    if(number>=10)
                    ss<< "|Pasture         " <<  number << "|";
                    return ss.str();
                break;
                case (MOUNTAIN):
                    if(number<10)
                    ss<< "|Mountain         " <<  number << "|";
                    if(number>=10)
                    ss<< "|Mountain        " <<  number << "|";
                    return ss.str();
                break;
                default: return "";
            }
        case 2: return "|                  |";
        case 3: return "|                  |";
        case 4: return "|                  |";
        case 5: return "|                  |";
        case 6: return "|                  |";
        case 7: return "|__________________|";
        default:
            return "";
    }
}
    
string settlementCard::render(int line){
    stringstream ss;
    switch(line){
        case 0: return ".............";
        case 1: 
            switch(LAND){
                case (FOREST):
                    ss << "|Forest  "<<  number << " |";
                    return ss.str();
                break;
                case (HILLS):
                    ss<< "|Hills " <<  number << " |";
                    return ss.str();
                break;
                case (FIELD):
                    ss<< "|Fields " <<  number << " |";
                    return ss.str();
                break;
                case (PASTURE):
                    ss<< "|Pasture " <<  number << " |";
                    return ss.str();
                break;
                case (MOUNTAIN):
                    ss<< "|Mountain " <<  number << " |";
                    return ss.str();
                break;
                default: return "";
            }
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return "";
    }
}
    
