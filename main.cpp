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
	//cin >> numPlayers;

	poker *players = new poker(); // call constructor to initalize the vectors of the players

    cout << "Your cards are: ";
    players->dealHand(2, "player"); // deal cards to the players
    players->printCards("player");//cout << endl;

	cout << "The AI has also been dealt cards.\n";
	players->dealHand(2, "AI");
    
    cout << "The cards on table are: ";
	players->dealHand(3, "dealer"); // deal cards to the players
    players->printCards("dealer");

	//int count = 1;
    // do it until we have 5 cards down or until everyone but one player won
    while(players->numCards() < 5){
		int AImove = rand() % 3; // range 0 - 2	
		// Ask each player for first move;

			cout << "\nWhat is your move (fold = f, raise = r, check = c)? ";
			cin >> move;

			if(move == 'f'){
				//players->fold("player");
				//playerFold++;
				cout << "You folded. AI wins!\n";
				return 0;
			}
			else if(move == 'r'){
				cout << "How much is your raise? ";
				cin >> raiseAmnt;
				players->changeMoney(raiseAmnt, "player", 's'); // NEED TO ADD THIS TO THE READER FILE- SECOND PARAMETER!!!

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
					if(yesOrNo == 'y'){
						players->changeMoney(10, "player", 's');
					}
					else{
						cout << "Player folds. AI wins!\n";
						return 0;
					}

				}
				
				break; // if someone raises, everyone else needs to go again to try to match the raise
			}
			else if(move == 'c'){
	
			}

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
	
		cout << endl;
        players->dealHand(1, "dealer");
        cout << "Table's cards are now: ";
        players->printCards("dealer");
	}

	cout << "AI's cards are: ";
	players->printCards("AI");
    if(players->win("player") > players->win("dealer")){
		cout << "You win! ";
		//cout << "You now have " << players->winAmount("player") << " coins.\n";
		players->winMoney("player");
	}
	else{ //if(players->win("dealer") > players->win("dealer")){
		cout << "AI wins!";
		//cout << "AI now has " << players->winAmount("AI") << " coins.\n";
		players->winMoney("AI");
	}
/*	else{
		cout << "Tie!";
		players ->winMoney("tie");
	}*/
	cout << endl << endl;
	cout << "You now have " << players->getMoney("player") << " coins\n";
	cout << "AI now has " << players->getMoney("AI") << " coins\n";
    return 1;
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
			//players->dealHand(1, "player");
	//	}
   

	//players->win(); // cout who won and how much they won
//}

