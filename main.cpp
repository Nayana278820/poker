#include<vector>
#include<iostream>

using namespace std;

int main(){
	char move;
	//int numPlayers;
	int numFolds;
	int raiseAmnt;
	cout << "Welcome to single player poker!\n";
	//cin >> numPlayers;

	Poker players = new Poker(); // call constructor to initalize the vectors of the players

	dealHand(); // deal cards to the players
	
	// need a display cards function to display the cards that the dealer puts down
	displayCards(3); // parameter: how many cards we need displayed


	// do it until we have 5 cards down or until everyone but one player won
	while(players.numCards() < 6){
		// Ask each player for first move;
		//int i;
		//for(i = 1; i < numPlayers + 1; i++){
			cout << "Player,  what is your move (fold = f, raise = r, check = c, deal = d)? ";
			cin >> move;

			if(move == 'f'){
				players.fold();
				numFold ++;
			}
			else if(move == 'r'){
				cout << "How much is your raise? ";
				cin >> raiseAmnt;
				//players.raise(i, raiseAmnt); // NEED TO ADD THIS TO THE READER FILE- SECOND PARAMETER!!!
				money(raiseAmnt, s);
				totalmoney(raiseAmnt);
				break; // if someone raises, everyone else needs to go again to try to match the raise
			}
			else if(move == 'c'){
				players.check();
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

		if(numFolds == 1){
			players.win(); // in function: when fold, give cards back- then need to check who has cards left (prob first thing to check)
			break;
		}
		
		if(players.numCards() != 5){
			displayCards(1);
		}
	}

	players.win(); // cout who won and how much they won
}