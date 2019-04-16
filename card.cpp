#include "card.h"
#include "inventoryPlayer.h"


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

void Card::setType(int p){
    type=p;
}

Land Card::getLand(){
    return LAND;
}
int Card::getNumber(){
    return number;
}
string Card:: getName(){
    return player;
}

int Card:: getType(){
    return type;
}

tileCard::tileCard(Land c, int n){
    setLand(c);
    setNumber(n);
}

settlementCard::settlementCard(Land c, int n, string player){
    setLand(c);
    setNumber(n);
    setName(player);
    setType(-1);
}

cityCard::cityCard(Land c, int n, string player){
    setLand(c);
    setNumber(n);
    setName(player);
    setType(-2);
}

//developmentCard::developmentCard(){
  
//}


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
     stringstream ss1;
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
        case 2: return "|       __ _       |";
        case 3: return "|      |   |       |";
        case 4: return "|      |_ _|       |";
        case 5: return "|                  |";
        case 6:
        ss1<< "|"   << setw(18)  << setfill(' ')   << player << "|";
        return ss1.str();
        break;
        case 7: return "|__________________|";
        default:
            return "";
    }
}


string cityCard::render(int line){
     stringstream ss;
     stringstream ss1;
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
        case 2: return "|      |---|       |";
        case 3: return "|      |---|       |";
        case 4: return "|      |---|       |";
        case 5: return "|      |___|       |";
        case 6:
        ss1<< "|"   << setw(8)  << setfill(' ')   << player << "|";
        return ss1.str();
        break;
        case 7: return "|__________________|";
        default:
            return "";
    }
}


//int developmentCard::victoryCard{
    //setVictory(getVictory() + 1);
//}
//int developmentCard::harvestCard{
   // setBricks(getBricks() + 1);
    //setWood(getWood() + 1);
    //setWool(getWool()  + 1);
   // setField(getField() + 1);
    //setOre(getOre() + 1);
//}