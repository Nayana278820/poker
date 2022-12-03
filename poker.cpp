//bool royalFlush(int player){
#include "poker.h"
using namespace std;
#include <vector>

#include <string>

poker::poker() {
 playerOneMoney = 0;
};
/*
int win(){
        bool count = false;
	if(straightFlush() == true){
		cout << "Won by rank 9";
	}
	else if(fourOfAKind() == true){
		cout << "Won by rank 8";
	}
	else if(fullHouse() == true){
		cout << "Won by rank 7";
	}
	else if(flush() == true){
		cout << "Won by rank 6";
	}
	else if(straight() == true){
		cout << "Won by rank 5";
	}
	else if(threeOfAKind() == true){
		cout << "Won by rank 4";
	}
	else if(twoPair() == true){
		cout << "Won by rank 3";
	}
	else if(pair() == true){
		cout << "Won by rank 2";
	}
        else if(highCard() == true ){
                cout << "Won by rank 1";
        }
	return count;	

}
int check_winner(){
	if (win() == true ){
                cout << "Player wins";
        }
}
bool straightFlush(){
	if(straight() && flush()){
		return true;
	}
	else{
		return false;
	}
};

bool fourOfAKind(){
	for(int i = 0; i < playerOne.size(); i++){
		int count = 0;
		string cardToCheck = playerOne[i];
		count++;
		// check if have two of same cards in hand
		if(i == 0){
			if(cardToCheck == playerOne[i + 1]){
				count ++;
			}
		}
		for(int j = 0; j < dealtcards.size(); j++){
			if(cardToCheck == dealtcards[i]){
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
	return false;
}

bool fullHouse(){
	if(threeOfAKind() && pair()){
		return true;
	}
	else{
		return false;
	}
	return false;
}

bool flush(){
	for(int i = 0; i < playerOne.size(); i++){
		char sign = playerOne[i].at(1);
		int count = 0;
		if(i == 0){
			if(sign == playerOne[i + 1].at(1)){
				count++;
			}
		}
		for(int j = 0; j < dealtcards.size(); j++){
			char sign2 = dealtcards[j].at(1);
			if(sign == sign2){
				count++;
			}
		}

		if(count == 5){
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}

bool straight (){
	// NOT FINISHED!
	//for(int
	//int num = playerone[i].at(0) - 64;

	// made a heap of the ints
	return false;
}

bool threeOfAKind(){
	for(int i = 0; i < playerOne.size(); i++){
		int count = 0;
		string cardToCheck = playerOne[i];
		count++;
		// check if have two of same cards in hand
		if(i == 0){
			if(cardToCheck == playerOne[i + 1]){
				count ++;
			}
		}
		for(int j = 0; j < dealtcards.size(); j++){
			if(cardToCheck == dealtcards[i]){
				count++;
			}
		}

		if(count == 3){
			return true;
		}
	}
	return false;
}

bool twoPair(){
	int count =0;
	for(int i = 0; i < playerOne.size(); i++){
		for(int j = 0; j < dealtcards.size(); j++){
			if(player[i] == dealtcards[j]){
				count++;
				// so that will go to next card in player's deck
				j = dealtcards.size();
			}
		}
	}
	if(count == 2){
		return true;
	}
	else{
		return false;
	}
}
bool pair(){
	// if both of cards are same
	if(playerOne[0] == playerOne[1]){
		return true;
	}
	for(int i = 0; i < playerone.size(); i++){
		for(int j = 0; i < dealtcards.size(); j++){
			if(playerone[i] == dealtcards[j]){
				return true;
			}
		}
	}
	else{
		return false;
	}
}
bool highCard(){
	int biggestCard = 0;
	for(int i = 0; i < playerOne.size(); i++){
		if(playerOne[i] > biggestCard){
			playerone = biggestCard;
		}
	}
	// we'll always have highest card
	return true;
}
////////////////////////////////////////////////////////////////////////////////
/// 
void fold(){ // lay down your cards and stop playing
    playerOne.clear();
 }*/

void displayCards(){

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

// Deals five random cards to player 
// also checks for duplicates
void poker::dealHand(int numCards)
{
    int cards = 0;
    for(int i = 0; i < numCards; i++) {
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
                playerOne.push_back(j); // add it to the player cards vector
         /*   if(numPlayer == 2){
                playertwo.push_back(j); // add it to the player cards vector
            }
            if(numPlayer == 3){
                playerthree.push_back(j); // add it to the player cards vector
            }*/
    }
}
/*
bool straight (){
	// NOT FINISHED!
	//for(int
	//int num = playerone[i].at(0) - 64;

	// made a heap of the ints
	int count=0;
for(int i = 0; i < playerOne.size(); i++){
		for(int j = 0; j < dealtcards.size(); j++){
			if( (player[j] - dealtcards[i]) == 1) {
				count++;
				// so that will go to next card in player's deck
				j = dealcards.size();
			}
		}
	}
	if(count == 4){
		return true;
	}
	else{
		return false;
	}
}
*/