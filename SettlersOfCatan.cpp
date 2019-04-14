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

void buildSettlement(vector<Card*> &deck,int decksize, string player){
   int idx1=rand()% decksize;
 
    Card* temp=(new settlementCard(deck.at(idx1)->getLand(), deck.at(idx1)->getNumber(), player));
    deck.at(idx1)=temp;


}

int main(){
    srand(time(0));
    
    int row;
    int column;
   
    int numPlayers;
    string player;
    
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
    buildSettlement(deck,deckSize, player);
    }
    renderdeck(deck, row, column);
    
    cout<< " DO YOU LIKE IT RAW?!!!"<< endl;
    cin >> column;
    return 0;
}