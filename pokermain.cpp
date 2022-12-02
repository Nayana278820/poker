#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

 void fold(int playernum){ // lay down your cards and stop playing
    if(playernum == 1){
    playerone.clear();
    }
    /*if(playernum == 2){
    playertwo.clear();
    }
    if(playernum == 3){
    playerthree.clear();
    }*/
 }

 string deal(){
    string card;

    int playerCard = (rand() % (13 - 1 + 1)) + 1;
    int playerSuit = (rand() % (4 - 1 + 1)) + 1;

    string num;
 
    switch(playerCard)
    {
        case 1: num = "Ace"; 
        break;
        case 2: num = "2"; 
        break;
        case 3: num = "3"; 
        break;
        case 4: num = "4"; 
        break;
        case 5: num = "5"; 
        break;
        case 6: num = "6"; 
        break;
        case 7: num = "7"; 
        break;
        case 8: num = "8"; 
        break;
        case 9: num = "9"; 
        break;
        case 10: num = "10"; 
        break;
        case 11: num = "Jack"; 
        break;
        case 12: num = "Queen"; 
        break;
        case 13: num = "King"; 
        break;
    }

    string face;
 
    switch(playerSuit)
    {
        case 1: face = " of Hearts"; break;
        case 2: face = " of Spades"; break;
        case 3: face = " of Diamonds"; break;
        case 4: face = " of Clubs"; break;
    }
 
    card = (num + face);
 
    return card; 
}


// Deals five random cards to player 
// also checks for duplicates
void dealHand(int numPlayer )
{
    int cards = 0;
    for(int i = 0; i < 2; i++) {
        string j = deal();

        for(int k = 0; k < dealtcards.size(); k++){
            if (j == dealtcards[k]){ // if card is already in dealt cards
                string j = deal(); // j has a random card now
                k=0;
            }
            else{
            continue; // if the card is already dealt, then get a new card again
        }
        }

            if(numPlayer == 1){
                playerone.push_back(j); // add it to the player cards vector
            }
         /*   if(numPlayer == 2){
                playertwo.push_back(j); // add it to the player cards vector
            }
            if(numPlayer == 3){
                playerthree.push_back(j); // add it to the player cards vector
            }*/
    }
}

