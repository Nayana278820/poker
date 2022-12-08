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

poker::poker() {
    playerOneMoney = 50;
	AIMoney = 50;
	tableMoney = 0;
};

int poker::getMoney(string player){
	if(player == "player"){
		return playerOneMoney;
	}
	else{
		return AIMoney;
	}
}

// player will be the winner of the game - need to add money on table to the winner's money
void poker::winMoney(string player){
	if(player == "player"){
		playerOneMoney += tableMoney;
	}
	else if(player == "AI"){
		AIMoney += tableMoney;
	}
}

void poker::changeMoney(int amount, string player, char addOrSub){
	if(player == "player"){
		if(addOrSub == 'a'){
			playerOneMoney += amount;
		}
		else{
			playerOneMoney -= amount;
		}
	}
	if(player == "AI"){
		if(addOrSub == 'a'){
			AIMoney += amount;
		}
		else{
			AIMoney -= amount;
		}
	}
	// If are adding money to a player, will be taking away from the pool of money on the table
	// Opposite for subtracting money
	if(addOrSub == 'a'){
		tableMoney -= amount;
	}
	else{
		tableMoney += amount;
	} 
}

int poker::numCards(){
    return dealtcards.size();
}

string poker::deal (){
    string card;

    int playerCard = (rand() % (13 - 1 + 1)) + 1;
     
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

// Deals random cards to player 
// also checks for duplicates
void poker::dealHand(int numCards, string player){
    int cards = 0;
    for(int i = 0; i < numCards; i++) {
       string card = deal();

        // Checks through players cards to make sure card is not same
        // as player's cards
		if(player == "player"){
			for(int k = 0; k < playerOne.size() ; k++){
				if (card == playerOne[k]){ // if card is already in player cards
					card = deal(); // j has a random card now
					k=0;
				}
				else{
					continue; // if the card is already dealt, then get a new card again
				}
			}
		}
		else if (player == "AI"){
			for(int k = 0; k < AI.size() ; k++){
				if (card == AI[k]){ // if card is already in player cards
					card = deal(); // j has a random card now
					k=0;
				}
				else{
					continue; // if the card is already dealt, then get a new card again
				}
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
        }
		else if(player == "AI"){
			AI.push_back(card);
		}
        else{
            dealtcards.push_back(card);
        }
    }
}
void poker::printCards(string player){
        if (player == "player"){
            for(int i = 0; i < playerOne.size(); i++){
                cout << playerOne[i] + " ";
            }
        }
		else if(player == "AI"){
			for(int i = 0; i < AI.size(); i++){
				cout << AI[i] + " ";
			}
		}
        else{
            for(int i = 0; i < dealtcards.size(); i++){
                cout << dealtcards[i] + " ";
            }
        }
        cout << endl;
}


bool poker::highCard(){
	// Will always have highest card
	return true;
}

bool poker::pair(string player){
	// if both of cards are same
    int numOfCardOne = 0;
    int numOfCardTwo = 0;
    int numOfDealtCard = 0;

    // Get numbers of both of player's cards using ASCII so that we can compare them
	if(player == "player"){
		if(playerOne[0].length() == 2){
			numOfCardOne = playerOne[0].at(0) - 48;
		}
		else if(playerOne[0].length() == 3){
			numOfCardOne = 10 + (playerOne[0].at(1) - 48);
		}

		if(playerOne[1].length() == 2){
			numOfCardTwo = playerOne[1].at(0) - 48;
		}
		else if(playerOne[1].length() == 3){
			numOfCardTwo = 10 + (playerOne[1].at(1) - 48);
		}
	}
	else{
		if(AI[0].length() == 2){
			numOfCardOne = AI[0].at(0) - 48;
		}
		else if(AI[0].length() == 3){
			numOfCardOne = 10 + (AI[0].at(1) - 48);
		}

		if(AI[1].length() == 2){
			numOfCardTwo = AI[1].at(0) - 48;
		}
		else if(AI[1].length() == 3){
			numOfCardTwo = 10 + (AI[1].at(1) - 48);
		}
	}

    // If both player's or AI's cards have same number, means that they are a pair
    if(numOfCardOne == numOfCardTwo){
        return true;
    }

    // Get the number of the dealer's cards and then compare them to the
    // numbers of the players cards
    // If are the same, are a pair
    for(int i = 0; i < dealtcards.size(); i++){
        if(dealtcards[i].length() == 2){
            numOfDealtCard = dealtcards[i].at(0) - 48;
        }
        else if(dealtcards[i].length() == 3){
            numOfDealtCard = 10 + (dealtcards[i].at(1) - 48);
        }

        if(numOfDealtCard == numOfCardOne || numOfDealtCard == numOfCardTwo){
		    return true;
	    }
    }
    return false;
}
bool poker::twoPair(string player){
	int count = 0;
    int numOfCardOne;
    int numOfCardTwo;
    int numOfDealtCard;

	// Get number of both cards in hand
	if(player == "player"){
		if(playerOne[0].length() == 2){
			numOfCardOne = playerOne[0].at(0) - 48;
		}
		else if(playerOne[0].length() == 3){
			numOfCardOne = 10 + (playerOne[0].at(1) - 48);
		}

		if(playerOne[1].length() == 2){
			numOfCardTwo = playerOne[1].at(0) - 48;
		}
		else if(playerOne[1].length() == 3){
			numOfCardTwo = 10 + (playerOne[1].at(1) - 48);
		}
	}
	else if(player == "AI"){	
		if(AI[0].length() == 2){
			numOfCardOne = AI[0].at(0) - 48;
		}
		else if(AI[0].length() == 3){
			numOfCardOne = 10 + (AI[0].at(1) - 48);
		}

		if(AI[1].length() == 2){
			numOfCardTwo = AI[1].at(0) - 48;
		}
		else if(AI[1].length() == 3){
			numOfCardTwo = 10 + (playerOne[1].at(1) - 48);
		}
	}

	// Game logic as pair but count = 2 instead of 1 (would be 1 in pair)
	for(int i = 0; i < dealtcards.size(); i++){
        if(dealtcards[i].length() == 2){
            numOfDealtCard = dealtcards[i].at(0) - 48;
        }
        else if(dealtcards[i].length() == 3){
            numOfDealtCard = 10 + (dealtcards[i].at(1) - 48);
        }

        if(numOfDealtCard == numOfCardOne || numOfDealtCard == numOfCardTwo){
            count++;
	    }
    }

	if(count == 2){
		return true;
	}
	else{
		return false;
	}
}

bool poker::threeOfAKind(string player){
	int count = 0;
    int numOfCardOne;
    int numOfCardTwo;
    int numOfDealtCard;
    
	// Get numbers of cards from hand
	if(player == "player"){
		if(playerOne[0].length() == 2){
			numOfCardOne = playerOne[0].at(0) - 48;
		}
		else if(playerOne[0].length() == 3){
			numOfCardOne = 10 + (playerOne[0].at(1) - 48);
		}

		if(playerOne[1].length() == 2){
			numOfCardTwo = playerOne[1].at(0) - 48;
		}
		else if(playerOne[1].length() == 3){
			numOfCardTwo = 10 + (playerOne[1].at(1) - 48);
		}
	}
	else if(player == "AI"){	
		if(AI[0].length() == 2){
			numOfCardOne = AI[0].at(0) - 48;
		}
		else if(AI[0].length() == 3){
			numOfCardOne = 10 + (AI[0].at(1) - 48);
		}

		if(AI[1].length() == 2){
			numOfCardTwo = AI[1].at(0) - 48;
		}
		else if(AI[1].length() == 3){
			numOfCardTwo = 10 + (AI[1].at(1) - 48);
		}
	}

	// Same logic as two pairs but with count = 3
	for(int i = 0; i < dealtcards.size(); i++){
        if(dealtcards[i].length() == 2){
            numOfDealtCard = dealtcards[i].at(0) - 48;
        }
        else if(dealtcards[i].length() == 3){
            numOfDealtCard = 10 + (dealtcards[i].at(1) - 48);
        }

        if(numOfDealtCard == numOfCardOne || numOfDealtCard == numOfCardTwo){
            count++;
	    }
    }

	if(count == 3){
		return true;
	}
	else{
		return false;
	}
}

// In poker, a user has a straight if their card(s), when combined with the cards on the table,
// has 5 sequential numbers
bool poker::straight (string player){
    int count =0;
    int numOfCardOne = 0;
    int numOfCardTwo = 0;
    int numOfDealtCard = 0;
    vector<int> sortedCards;
 
	// Create a new vector of cards that contains player's cards, as well as cards from the table
    for(int i = 0; i < 5; i++){
		if(player == "player"){
			if(playerOne[i].length() == 2){
				sortedCards.push_back(playerOne[i].at(0) - 48);
			}
			else if(playerOne[i].length() == 3){
				sortedCards.push_back(10 + (playerOne[i].at(1) - 48));
			}
		}
		else if(player == "AI"){
			if(AI[i].length() == 2){
				sortedCards.push_back(AI[i].at(0) - 48);
			}
			else if(AI[i].length() == 3){
				sortedCards.push_back(10 + (AI[i].at(1) - 48));
			}
		}
    }
    for(int i = 0; i < dealtcards.size(); i++){
        if(dealtcards[i].length() == 2){
            sortedCards.push_back(dealtcards[i].at(0) - 48);
        }
        else if(dealtcards[i].length() == 3){
            sortedCards.push_back(10 + (dealtcards[i].at(1) - 48));
        }
    }
  
	// Use bubble sort on the vector so that they are in order from smallest to biggest
    for(int i =0; i< (sortedCards.size()); i++){
        for(int j=0; j<(sortedCards.size()-i-1); j++){
			int swap;
			if(sortedCards[j] > sortedCards[j+1]){
				swap = sortedCards[j];
				sortedCards[j] = sortedCards[j+1];
				sortedCards[j+1] = swap;
			}
		}
    }

	int fiveInARow = 0;
    for(int i = 0; i < sortedCards.size()-1; i++){
        if(sortedCards[i] + 1 == sortedCards[i+1]){
           fiveInARow ++;
		   // Check the 4 cards after that card to see if all the numbers are
		   // one after another
		   for(int j = 0; j < 4; j++){ 
				if((sortedCards[j+1] - sortedCards[j]) == 1){
					fiveInARow ++;	
				}
		   }
		   
		}
		if(fiveInARow >= 5){
			return true;
		}
		else{
			fiveInARow = 0;
		}
    }
	return false;
}

// Have a flush in poker if player's cards, combined with cards on table, have 5 cards with 
// the same sign
bool poker::flush(string player){ // same logic as three of a kind but for 5 cards and using sign
    int count1 = 0;
    int count2 = 0;
    char signOfCardOne;
    char signOfCardTwo;
    char signOfDealtCard;
    
	// Get sign of cards (similar logic to getting numbers)
	if(player == "player"){
		if(playerOne[0].length() == 2){
			signOfCardOne = playerOne[0].at(1);
		}
		else if(playerOne[0].length() == 3){
			signOfCardOne = (playerOne[0].at(2));
		}

		if(playerOne[1].length() == 2){
			signOfCardTwo = playerOne[1].at(1);
		}
		else if(playerOne[1].length() == 3){
			signOfCardTwo = (playerOne[1].at(2));
		}
	}
	else if(player == "AI"){
		if(AI[0].length() == 2){
			signOfCardOne = AI[0].at(1);
		}
		else if(AI[0].length() == 3){
			signOfCardOne = (AI[0].at(2));
		}

		if(AI[1].length() == 2){
			signOfCardTwo = AI[1].at(1);
		}
		else if(AI[1].length() == 3){
			signOfCardTwo = (AI[1].at(2));
		}
	}

	// Get signs of cards on table
	for(int i = 0; i < dealtcards.size(); i++){
        if(dealtcards[i].length() == 2){
            signOfDealtCard = dealtcards[i].at(1);
        }
        else if(dealtcards[i].length() == 3){
            signOfDealtCard = (dealtcards[i].at(2));
        }

		// Check cards against dealt cards to see if 5 of them will be same sign
        if(signOfDealtCard == signOfCardOne){
            count1++;
	    }
        if(signOfDealtCard == signOfCardTwo){
            count2++;
        }
    }

	if(count1 >= 4 || count2 >= 4){
		return true;
	}
	else{
		return false;
	}
}

// Have full house if have a three of a kind and a pair
bool poker::fullHouse(string player){
	if(threeOfAKind(player) && pair(player)){
		return true;
	}
	else{
		return false;
	}
}

bool poker::fourOfAKind(string player){
	int count = 0;
    int numOfCardOne;
    int numOfCardTwo;
    int numOfDealtCard;

	// Get number of cards
	if(player == "player"){
		if(playerOne[0].length() == 2){
			numOfCardOne = playerOne[0].at(0) - 48;
		}
		else if(playerOne[0].length() == 3){
			numOfCardOne = 10 + (playerOne[0].at(1) - 48);
		}

		if(playerOne[1].length() == 2){
			numOfCardTwo = playerOne[1].at(0) - 48;
		}
		else if(playerOne[1].length() == 3){
			numOfCardTwo = 10 + (playerOne[1].at(1) - 48);
		}
	}
	else if(player == "AI"){
		if(AI[0].length() == 2){
			numOfCardOne = AI[0].at(0) - 48;
		}
		else if(AI[0].length() == 3){
			numOfCardOne = 10 + (AI[0].at(1) - 48);
		}

		if(AI[1].length() == 2){
			numOfCardTwo = AI[1].at(0) - 48;
		}
		else if(AI[1].length() == 3){
			numOfCardTwo = 10 + (AI[1].at(1) - 48);
		}
	}

	// Same logic as three of a count but check if count = 4 this time
	for(int i = 0; i < dealtcards.size(); i++){
        if(dealtcards[i].length() == 2){
            numOfDealtCard = dealtcards[i].at(0) - 48;
        }
        else if(dealtcards[i].length() == 3){
            numOfDealtCard = 10 + (dealtcards[i].at(1) - 48);
        }

        if(numOfDealtCard == numOfCardOne || numOfDealtCard == numOfCardTwo){
            count++;
	    }
    }

	if(count == 4){
		return true;
	}
	else{
		return false;
	}
}

// Have a straight flush if have a straight and a flush
bool poker::straighFlush(string player){
	if(straight(player) && flush(player)){
		return true;
	}
	else{
		return false;
	}
}
int poker::win(string player){
	int returnVal;

	string name;
	if(player == "player"){
		name = "You";
	}
	else{
		name = "AI";
	}

	// Check each win function- if true, cout what the player won and return what rank it was
	if(straighFlush(player) == true){
		cout << name << " got a straight flush\n";
		returnVal = 9;
	}
	else if(fourOfAKind(player) == true){
		cout << name << " got a four of a kind\n";
		returnVal = 8;
	}
	else if(fullHouse(player) == true){
		cout << name << " got a full house\n";
		returnVal = 7;
	}
	else if(flush(player) == true){
		cout << name << " got a flush\n";
		returnVal = 6;
	}
	else if(straight(player) == true){
		cout << name << " got a straight\n";
		returnVal = 5;
	}
	else if(threeOfAKind(player) == true){
		cout << name << " got a three of a kind\n";
		returnVal = 4;
	}
	else if(twoPair(player) == true){
		cout << name << " got a two pair\n";
		returnVal = 3;
	}
	else if(pair(player) == true){
		cout << name << " got a pair\n";
		returnVal = 2;
	}
    else if(highCard() == true ){
        cout << name << " got a high card\n";
		returnVal = 1;
    }
	return returnVal;	

}
