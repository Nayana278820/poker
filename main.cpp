#include<vector>
#include<iostream>
//#include "poker.h"
#include <time.h>
#include <cstdlib>
#include <random>
#include <ctime>
#include <stdio.h>

using namespace std;

class poker{
    private:
        std::vector<string> dealtcards;
        std::vector<string> playerOne;
        int playerOneMoney;
       

    public:
       //int playerOneMoney;
        void fold(); 
        string deal(); // if card already dealt if call random again
                               //number of players * 2 + 5
        void dealHand(int numcards, string player);
        void displayCards();
        int numCards(); //returns number of cards in dealtcard vector
        void money(int amount, char AorS); // each persons money
        //int getmoney(); // returns money,how much each player has
        //void totalmoney(int amount); // pool of money
        string win(); //win calls winner money at the end
                      //couts winner money 
        bool royalFlush();
        bool straighFlush();
        bool fourOfAKind();
        bool fullHouse();
        bool flush();
        bool straight();
        bool threeOfAKind();
        bool twoPair();
        bool pair();
        bool highCard();

        poker();  
        ~poker();

};

int main(){
  //  int rand();
   srand((unsigned)time(0));
	char move;
	//int numPlayers;
	int numFolds =0;
	int raiseAmnt;
	cout << "Welcome to single player poker!\n";
	//cin >> numPlayers;

	poker *players = new poker(); // call constructor to initalize the vectors of the players

    cout << "Your cards are: ";
    players->dealHand(2, "player"); // deal cards to the players
    cout << endl;
    
    cout << "The cards on table are: ";
	players->dealHand(3, "dealer"); // deal cards to the players

    // do it until we have 5 cards down or until everyone but one player won
    while(players->numCards() < 6){
		// Ask each player for first move;
		//int i;
		//for(i = 1; i < numPlayers + 1; i++){
			cout << "\nPlayer,  what is your move (fold = f, raise = r, check = c, deal = d)? ";
			cin >> move;

			if(move == 'f'){
				players->fold();
				numFolds ++;
			}
			else if(move == 'r'){
				cout << "How much is your raise? ";
				cin >> raiseAmnt;
				//players.raise(i, raiseAmnt); // NEED TO ADD THIS TO THE READER FILE- SECOND PARAMETER!!!
				//money(raiseAmnt, s);
				//totalmoney(raiseAmnt);
				break; // if someone raises, everyone else needs to go again to try to match the raise
			}
            else if(move == 'c'){
				//players.check();
			}
		}

		/*if(move == 'r'){
			// for initalizer: start with next player (circular way)
			// for condition- stop when get back to that person
			// if they want to meet
			char raise;
			for(i = (i + 1) % numPlayers; i != i; i++){
				cout << "Player " << i << ", would you like to meet the raise (y/n)? ";
				cin >> raise;
				if(raise == 'y'){
					// not the same as raising but same logic so user that same function
					//players.raise(i, raiseAmnt);
					money(raiseAmnt, s, i);
					totalmoney(raiseAmnt);
				}
				else if(raise == 'n'){
					players.fold(i);
				}
			}
		}*/
		/*if(numFolds == 1){
		//	players->win(); // in function: when fold, give cards back- then need to check who has cards left (prob first thing to check)
			cout << "you folded";
            return;
		}
		*/
	//	if(players->numCards() != 5){
			players->dealHand(1, "player");
	//	}
    return 1;
	}

	//players->win(); // cout who won and how much they won
//}
	
poker::poker() {
    playerOneMoney = 0;
};

void poker::fold(){ // lay down your cards and stop playing
    playerOne.clear();
 }

int poker::numCards(){
    return playerOne.size();
}

 string poker::deal (){
    string card;
    //int rand();
    //srand(time(NULL));
     int playerCard = (rand() % (13 - 1 + 1)) + 1;
     
  //  srand(time(NULL));
    int playerSuit = (rand() % (4 - 1 + 1)) + 1;

    string num;
 
    switch(playerCard)
    {
        case 1: num = "1"; 
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
        case 11: num = "11"; 
        break;
        case 12: num = "12"; 
        break;
        case 13: num = "13"; 
        break;
    }

    string face;
 
    switch(playerSuit)
    {
        case 1: face = "H"; break;
        case 2: face = "S"; break;
        case 3: face = "D"; break;
        case 4: face = "C"; break;
    }
    card = (num + face);
    return card; 
}

// Deals five random cards to player 
// also checks for duplicates
void poker::dealHand(int numCards, string player){
    int cards = 0;
    for(int i = 0; i < numCards; i++) {
       string card = deal();

        // Checks through players cards to make sure card is not same
        // as player's cards
        for(int k = 0; k < playerOne.size() ; k++){
            if (card == playerOne[k]){ // if card is already in player cards
                card = deal(); // j has a random card now
                k=0;
            }
            else{
                continue; // if the card is already dealt, then get a new card again
            }
        }

        // Need to also check through dealer's cards to make sure
        // aren't any duplicated
        for(int k = 0; k < dealtcards.size() ; k++){
            if (card == dealtcards[k]){ // if card is already in dealt cards
                card = deal(); // j has a random card now
                k=0;
            }
            else{
                continue; // if the card is already dealt, then get a new card again
            }
        }

        // When everything is checked, push back onto right vector
        if(player == "player"){
                playerOne.push_back(card);
                cout << playerOne[i] << " ";
            }
        else{
            dealtcards.push_back(card);
            cout << dealtcards[i] << " ";
        }
    }
}
	// need a display cards function to display the cards that the dealer puts down
	//players.displayCards(3); // parameter: how many cards we need displayed