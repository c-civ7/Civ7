#include <iostream> 
#include "card.cpp"
#include "inventoryPlayer.cpp"
#include <vector>
#include <string>

using namespace std;

void buildDeck(vector<Card*> &deck, int decksize){
    for(int i=0; i<decksize; i++){
    for(int c = FOREST; c <= MOUNTAIN; c++){
        for(int n = 2; n <= 12; n++){
           deck.push_back(new tileCard((Land)c,n));
        }
    }
    }
}

void renderdeck(vector<Card*> deck, int r, int c){
    if(deck.size() > 0){
        int x=0;
        int temp=0;
        for(int k=0; k<c; k++){
            for(int j=0; j<= 7; j++){
            for(int i =0; i < r; i++){
            cout << deck.at(x)->render(j)<< " ";
             x++;
          }x=temp;
        cout  << endl;
        }temp=temp+r;
}
}
else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}       

void shuffle(vector<Card*> &deck){
    Card* temp;
    int idx1, idx2;
    for(int i = 0; i < 10000; i++){
        idx1 = rand() % deck.size();
        idx2 = rand() % deck.size();
        
        temp = deck.at(idx1);
        deck.at(idx1) = deck.at(idx2);
        deck.at(idx2) = temp;
    }
}

void buildInitial(vector<Card*> &deck,int decksize, string player, vector<Card*>&hand){
    int i=1;  
    int idx1;
    while(i==1){
        idx1=rand()% decksize;
        if(deck.at(idx1)->getType()==-1)
        i==1;
        else
        i=0;
    }
    Card* temp=(new settlementCard(deck.at(idx1)->getLand(), deck.at(idx1)->getNumber(), player));
    deck.at(idx1)=temp;
    hand.push_back(new settlementCard(deck.at(idx1)->getLand(), deck.at(idx1)->getNumber(), player));
}

int setResources(Inventory &inventory, int n){
    inventory.setBricks(n);
    inventory.setWood(n);
    inventory.setGrain(n);
    inventory.setWool(n);
    inventory.setOre(n);
}

void coutResources(Inventory &inventory){
    cout << "These are your resources:"<< endl;
    cout <<"Wood(" << inventory.getWood() << ")  ";
    cout <<"Bricks(" << inventory.getBricks() << ")  ";
    cout <<"Grain(" << inventory.getGrain() << ")  ";
    cout <<"Wool(" << inventory.getWool() << ")  ";
    cout <<"Ore(" << inventory.getOre() << ")  ";
    cout <<"Victory Points: " << inventory.getVictory()<< endl;
}

void buildSettlement(vector<Card*> &deck, string player, int r, int c, vector<Card*>&hand,Inventory &inventory){
    int row, column,loop=1;
    int idx;
    while(loop==1){
    cout<< player << " where would you like to place your new settlement card:" << " enter row"<< endl;
    cin >> row;
    cout << "Enter column:"<< endl;
    
    cin >> column;
    
    idx=(row*r)+column;
    if( (row>=0 && row<=(r)) && (column>=0 && column<=(c))){
    if(deck.at(idx)->getType()!=-1 && deck.at(idx)->getType()!=-2){
    if(column==0 && row== 0){
            if(deck.at(idx+r)->getName()==player || deck.at(idx+1)->getName()==player){
            loop=0;
            }
        }
    else if(column==0 && row!=0){
        if(deck.at(idx-r)->getName()==player || deck.at(idx+r)->getName()==player || deck.at(idx+1)->getName()==player){
            loop=0;
        }
    }
    else if(column==(c-1) && row==0){
        if(deck.at(idx+r)->getName()==player || deck.at(idx-1)->getName()==player){
            loop=0;
        }
    }else if(column==(c-1)&&row!=0){
            if(deck.at(idx-r)->getName()==player || deck.at(idx+r)->getName()==player || deck.at(idx-1)->getName()==player){
            loop=0;
            }
    }else if(column!=0&&row==0){
            if(deck.at(idx+r)->getName()==player || deck.at(idx-1)->getName()==player || deck.at(idx+1)->getName()==player){
            loop=0;
            }
    }else if(deck.at(idx-r)->getName()==player || deck.at(idx+r)->getName()==player|| deck.at(idx+1)->getName()==player || deck.at(idx-1)->getName()==player){
                loop=0;
             }
    }       
    }  
    if(loop==0){
        Card* temp=(new settlementCard(deck.at(idx)->getLand(), deck.at(idx)->getNumber(), player));
        deck.at(idx)=temp;
        hand.push_back(new settlementCard(deck.at(idx)->getLand(), deck.at(idx)->getNumber(), player));
    }
    if(loop==1)
        cout<< "WRONG CHOICE, TRY AGAIN"<< endl;
    }
    inventory.setBricks(inventory.getBricks()-1);
    inventory.setWool(inventory.getWool()-1);
    inventory.setWood(inventory.getWood()-1);
    inventory.setGrain(inventory.getGrain()-1);
}
//buildcity would technically be able to build a city on top of a city :/
void buildCity(vector<Card*> &deck, string player, int r, int c, vector<Card*>&hand, Inventory &inventory){
    int idx, row, column,loop=1;
    
    while(loop==1){
    cout << player <<" where would you like to build a city?(MUST BE IN YOUR SETTLEMENT): " << "enter row"<< endl;
    cin>> row;
    cout << "Enter Column: "<< endl;
    cin>> column;
    idx=(row*r)+column;
    
    if(deck.at(idx)->getName()==player){
        Card* temp=(new cityCard(deck.at(idx)->getLand(), deck.at(idx)->getNumber(), player));
        deck.at(idx)=temp;
        hand.push_back(new cityCard(deck.at(idx)->getLand(), deck.at(idx)->getNumber(), player));
        loop=0;
    }
    if(loop==1)
        cout<< "Wrong choice!, try again!"<< endl;
    }
    inventory.setGrain(inventory.getGrain()-3);
    inventory.setOre(inventory.getOre()-2);
}

void addResources(vector<Card*>&hand, Inventory &inventory, int num){
    
    for(int i=0; i<hand.size();i++){
        if (hand.at(i)->getType()==-1 && hand.at(i)->getNumber()==num){
            switch(hand.at(i)->getLand()){
                case (FOREST):
                    inventory.setWood(inventory.getWood()+1);
                break;
                case (HILLS):
                    inventory.setBricks(inventory.getBricks()+1);
                break;
                case (FIELD):
                    inventory.setGrain(inventory.getGrain()+1);
                break;
                case (PASTURE):
                    inventory.setWool(inventory.getWool()+1);
                break;
                case (MOUNTAIN):
                    inventory.setOre(inventory.getOre()+1);
                break;
                default: break;
            }
        }
       else if (hand.at(i)->getType()==-2&&hand.at(i)->getNumber()==num){
            switch(hand.at(i)->getLand()){
                case (FOREST):
                    inventory.setWood(inventory.getWood()+2);
                break;
                case (HILLS):
                    inventory.setBricks(inventory.getBricks()+2);
                break;
                case (FIELD):
                    inventory.setGrain(inventory.getGrain()+2);
                break;
                case (PASTURE):
                    inventory.setWool(inventory.getWool()+2);
                break;
                case (MOUNTAIN):
                    inventory.setOre(inventory.getOre()+2);
                break;
                default: break;
            }
        }    

    }
}

void takeTurn(vector<Card*>&deck, string player, int r, int c,vector<Card*>&hand, Inventory &inventory){
    int dice;
    int temp, temp2;
    dice= rand()% 6+1;
    temp= rand()%6+1;
    dice=dice+temp;
    cout << "You rolled a "<< dice << "!" <<endl;
    addResources(hand, inventory, dice);
    coutResources(inventory);
    temp=1;
    
    while(temp==1){
    int choice;
    cout<< player << " Would you like to buy, trade, or skip turn?? (1-3)"<< endl;
    cin >> choice;
    switch(choice){
        case 1:
            cout<< "Would you like to buy a settlement, City, or develepment card? (1-3)"<< endl;
            cin >> choice;
            switch(choice){
                case 1:
                    if(inventory.getBricks()>=1 && inventory.getGrain()>=1 && inventory.getWool()>=1 && inventory.getWood()>=1){
                        buildSettlement(deck, player, r, c, hand,inventory);
                        temp=0;
                        }else
                        cout << "you don't have enough materials to buy a settlement"<< endl;
                        break;
                case 2:
                    if(inventory.getGrain()>=3 && inventory.getOre()>=2){
                        buildCity(deck,player,r, c, hand, inventory);
                        temp=0;
                        }else
                        cout << "you don't have enough materials to buy a city"<< endl;
                    break;
                case 3:
                
                    break;
                default:
                    break;
            }
            break;
        case 2:
            cout<< "What materials would you like to trade?Remember you need 3 resources of one material to trade for 1"<< endl;
            cout<< "1 for wood, 2 for bricks, 3 for grain, 4 for wool, and 5 for Ore"<< endl;
            cin>> temp2;
            //Here you check if theres 3 materials, if not, u cant do this shit then DAWG
            cout<< "What material would you like to have instead?"<< endl;
            cout<< "1 for wood, 2 for bricks, 3 for grain, 4 for wool, and 5 for Ore"<< endl;
            cin>> temp2;
            break;
        case 3:
            cout<< "SKIP"<< endl;
            temp=0;
            break;
        default: 
            break;
         }
    }
}


int main(){
    srand(time(0));
    
    int row, column, numPlayers;
    
    string player;
    vector<string> players;

    cout<< "how many rows would you like?"<< endl;
    cin >>row;
    cout<< "how many columns would you like?"<< endl;
    cin>> column;
    int deckSize= row*column;
    
    vector<Card*> deck;
    buildDeck(deck, deckSize);
    shuffle(deck);
    
    cout<< "How many players are there?"<< endl;
    cin>> numPlayers;
    
    vector<vector<Card*>> hands(numPlayers);
    vector<Inventory> inventory(numPlayers);

    for(int i=0; i<numPlayers;i++){
    cout << "name of player #" << i << ":"<< endl;
    cin >> player;
    players.push_back(player);
    buildInitial(deck,deckSize, player, hands.at(i));
    setResources(inventory.at(i),1);
    }
    renderdeck(deck, row, column);
 
   while(1){
       for(int i=0; i<numPlayers; i++){
           takeTurn(deck, players.at(i), row, column, hands.at(i), inventory.at(i));
           renderdeck(deck, row, column);
       }
   }
    
  
    return 0;
}