#include <iostream> 
#include "card.cpp"
#include "inventoryPlayer.h"
#include <vector>
#include <string>

using namespace std;

void buildDeck(vector<Card*> &deck, int decksize){
    for(int i=0; i<decksize; i++){
    for(int c = FOREST; c <= MOUNTAIN; c++){
        for(int n = 2; n <= 12; n++){
           deck.push_back(new tileCard((Land)c,n));
           //deck.push_back(new settlementCard((Land)c,n, "BITCH"));
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

void buildInitial(vector<Card*> &deck,int decksize, string player){
   int idx1=rand()% decksize;
    Card* temp=(new settlementCard(deck.at(idx1)->getLand(), deck.at(idx1)->getNumber(), player));
    deck.at(idx1)=temp;
}

void buildSettlement(vector<Card*> &deck, string player, int r, int c){
    int row, column,loop=1;
    int idx;
    while(loop==1){
    cout<< player << " where would you like to place your new settlement card:" << " enter row"<< endl;
    cin >> row;
    cout << "Enter column:"<< endl;
    cin >> column;
    
    idx=(row*r)+column;
    if(column==0){
        if(deck.at(idx-row)->getName()==player || deck.at(idx+row)->getName()==player || deck.at(idx+1)->getName()==player){
            Card* temp=(new settlementCard(deck.at(idx)->getLand(), deck.at(idx)->getNumber(), player));
            deck.at(idx)=temp;
            loop=0;
        }
    }else if(column==(c-1)){
            if(deck.at(idx-row)->getName()==player || deck.at(idx+row)->getName()==player || deck.at(idx-1)->getName()==player){
            Card* temp=(new settlementCard(deck.at(idx)->getLand(), deck.at(idx)->getNumber(), player));
            deck.at(idx)=temp;
            loop=0;
            }
    }else{
         if(deck.at(idx-row)->getName()==player || deck.at(idx+row)->getName()==player|| deck.at(idx+1)->getName()==player || deck.at(idx-1)->getName()==player){
                Card* temp=(new settlementCard(deck.at(idx)->getLand(), deck.at(idx)->getNumber(), player));
                deck.at(idx)=temp;
                loop=0;
             }
        
    }
    if(loop==1)
        cout<< "WRONG CHOICE, TRY AGAIN"<< endl;
    }

}
//buildcity would technically be able to build a city on top of a city :/
void buildCity(vector<Card*> &deck, string player, int r, int c){
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
        loop=0;
    }
    if(loop==1)
        cout<< "Wrong choice!, try again!"<< endl;
    }
}

void takeTurn(vector<Card*>&deck, string player, int r, int c){
    int choice;
    cout<< player << " Would you like to build a settlement, a city, trade, or buy a development card?(1-4)"<< endl;
    cin >> choice;
    switch(choice){
        case 1:
            buildSettlement(deck, player, r, c);
            break;
        case 2:
            buildCity(deck,player,r, c);
            break;
        case 3:
            cout <<"suck MY FUCKING DICK BITCH"<< endl;
            break;
        case 4 :
            //buy development card
        default: 
            break;
    }
    
}




int main(){
    srand(time(0));
    
    int row;
    int column;
   
    int numPlayers;
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
    
    for(int i=1; i<=numPlayers;i++){
    cout << "name of player #" << i << ":"<< endl;
    cin >> player;
    players.push_back(player);
    buildInitial(deck,deckSize, player);
    }
    renderdeck(deck, row, column);
    
 
   while(1){
       for(int i=0; i<numPlayers; i++){
           takeTurn(deck, players.at(i), row, column);
           renderdeck(deck, row, column);
       }
   }
    
    
    
    return 0;
}