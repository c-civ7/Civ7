#include "card.h"


using namespace std;

void Card::setLand(land L){
    land = l;
}


string Card::render(int line){
    switch(line){
        case 0: return ".............";
        case 1: 
            switch(Land){
                case (FOREST):
                    return "|   |";
                break;
                case (HILLS):
                    return "|   |";
                break;
                case (FIELD):
                    return "|   |";
                break;
                case (PASTURE):
                    return "|   |";
                break;
                case (MOUNTAIN):
                    return "|   |"
                break;
            break;
            }
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
    
