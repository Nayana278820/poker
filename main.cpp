// HEADER
#include<vector>
#include<iostream>
#include "poker.h"
#include <time.h>
#include <cstdlib>
#include <random>
#include <ctime>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    srand(time(NULL));
	char move;
	int numFolds = 0;
	int raiseAmnt;
	cout << "Welcome to poker vs. AI!\n";
	cout << "------------------------\n";
	cout << "Both you and AI start off with 50 coins\n";

	poker *players = new poker(); // call constructor to initalize the coins

    cout << "Your cards are: ";
	// Deal cards to user and AI
    players->dealHand(2, "player"); 
    players->printCards("player");

	cout << "The AI has also been dealt cards.\n";
	players->dealHand(2, "AI");
    
    cout << "The cards on table are: ";
	players->dealHand(3, "dealer"); 
    players->printCards("dealer");

    // Game played until there are 5 cards on the table
    while(players->numCards() < 5){
		int AImove = rand() % 3; // range 0 - 2	

		cout << "\nWhat is your move (fold = f, raise = r, check = c)? ";
		cin >> move;

		if(move == 'f'){
			cout << "You folded. AI wins!\n";
			return 0;
		}
		else if(move == 'r'){
			cout << "How much is your raise? ";
			cin >> raiseAmnt;
			players->changeMoney(raiseAmnt, "player", 's');

			// If user chooses to raise, AI will need to either call, raise, or fold
			int AIRaiseMove = rand() % 2;
			if(AIRaiseMove == 0){
				cout << "AI folds. You win!\n";
				return 0;
			}
			else if(AIRaiseMove == 1){
				cout << "AI raises 10 coins. Would you like to meet this (y/n)? ";
				players->changeMoney(10, "AI", 's');
				char yesOrNo;
				cin >> yesOrNo;
				// If choose not to call, will be forced to fold
				if(yesOrNo == 'y'){
					players->changeMoney(10, "player", 's');
				}
				else{
					cout << "Player folds. AI wins!\n";
					return 0;
				}

			}
		}
		// If user checks ('c'), will go to AI's turn

		// If user raised, AI's turn is already taken care of in that while loop
		if(move != 'r'){
			if(AImove == 0) { // fold
				cout << "AI folded. You win!\n";
				return 0;
			}
			else if(AImove == 1){ // raise
				cout << "AI raises 10 coins.\n";
				players->changeMoney(10, "AI", 's');
				cout << "Would you like to meet this bet (y/n)? ";
				char yesOrNo;
				cin >> yesOrNo;

				if(yesOrNo == 'y'){
					players->changeMoney(10, "player", 's');
				}
				else{
					cout << "You fold. AI wins!";
					return 0;
				}
			}
			else if(AImove == 2){
				cout << "AI checks.\n";
			}
		}
	
		// Add another card to table and then start process over again
		cout << endl;
        players->dealHand(1, "dealer");
        cout << "Table's cards are now: ";
        players->printCards("dealer");
	}

	cout << "AI's cards are: ";
	players->printCards("AI");

	// Check who won that round based on which win conditions they won
    if(players->win("player") > players->win("AI")){
		cout << "You win! ";
		players->winMoney("player");
	}
	// If there is a tie, AI automatically wins
	else{ 
		cout << "AI wins!";
		players->winMoney("AI");
	}

	// Display coins for each player at end
	cout << endl << endl;
	cout << "You now have " << players->getMoney("player") << " coins\n";
	cout << "AI now has " << players->getMoney("AI") << " coins\n";
    return 1;
}

