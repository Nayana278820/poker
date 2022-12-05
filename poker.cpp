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
 }

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
            }
    }
}
*/
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

poker::poker() {
    playerOneMoney = 0;
};

void poker::fold(){ // lay down your cards and stop playing
    playerOne.clear();
 }

int poker::numCards(){
    return dealtcards.size();
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
                //cout << playerOne[i] << " ";
            }
        else{
            dealtcards.push_back(card);
            //cout << dealtcards[i] << " ";
        }
    }
}
void poker::printCards(string player){
        if (player == "player"){
            for(int i = 0; i < playerOne.size(); i++){
                cout << playerOne[i] + " ";
            }
        }
        else{
            for(int i = 0; i < dealtcards.size(); i++){
                cout << dealtcards[i] + " ";
            }
        }
        cout << endl;
}

// Poker Hands

bool poker::highCard(){
	int biggestCard = 0;
    int num;
	for(int i = 0; i < playerOne.size(); i++){
        // If the card 
        if(playerOne[i].length() == 2){
            num = playerOne[i].at(0) - 48;
        }
        else if(playerOne[i].length() == 3){
            //num = playerOne[i].at(0) + playerOne[i].at(1);
            // if card has length of 3, add 10 to the ASCII value of the
            // second char
            num = 10 + (playerOne[i].at(1) - 48);
        }

		if(num > biggestCard){
			biggestCard = num;
		}
	}
	// we'll always have highest card
    //cout << biggestCard;
	return true;
}

bool poker::pair(){
	// if both of cards are same
    int numOfCardOne = 0;
    int numOfCardTwo = 0;
    int numOfDealtCard = 0;

    // Get numbers of both of player's cards so that we can compare them
    if(playerOne[0].length() == 2){
        numOfCardOne = playerOne[0].at(0) - 48;
    }
    else if(playerOne[0].length() == 3){
        numOfCardOne = 10 + (playerOne[0].at(1) - 48);
    }
    //cout << "numOfCardOne: " << numOfCardOne << endl;

    if(playerOne[1].length() == 2){
        numOfCardTwo = playerOne[1].at(0) - 48;
    }
    else if(playerOne[1].length() == 3){
        numOfCardTwo = 10 + (playerOne[1].at(1) - 48);
    }
    //cout << "numOfCardTwo: " << numOfCardTwo << endl;

    // If both have same number, means that they are a pair
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
        //cout << "numOfDealtCard " << numOfDealtCard << endl;

        if(numOfDealtCard == numOfCardOne || numOfDealtCard == numOfCardTwo){
		    return true;
	    }
    }
    return false;

}
bool poker::twoPair(){
	int count = 0;
    int numOfCardOne;
    int numOfCardTwo;
    int numOfDealtCard;

    if(playerOne[0].length() == 2){
        numOfCardOne = playerOne[0].at(0) - 48;
    }
    else if(playerOne[0].length() == 3){
        numOfCardOne = 10 + (playerOne[0].at(1) - 48);
    }
    //cout << "numOfCardOne: " << numOfCardOne << endl;

    if(playerOne[1].length() == 2){
        numOfCardTwo = playerOne[1].at(0) - 48;
    }
    else if(playerOne[1].length() == 3){
        numOfCardTwo = 10 + (playerOne[1].at(1) - 48);
    }


	for(int i = 0; i < dealtcards.size(); i++){
        if(dealtcards[i].length() == 2){
            numOfDealtCard = dealtcards[i].at(0) - 48;
        }
        else if(dealtcards[i].length() == 3){
            numOfDealtCard = 10 + (dealtcards[i].at(1) - 48);
        }

        if(numOfDealtCard == numOfCardOne || numOfDealtCard == numOfCardTwo){
            //cout << "numOfCardOne: " << numOfCardOne << endl;
            //cout << "numOfCardTwo: " << numOfCardTwo << endl;
            //cout << "dealtCards " << numOfDealtCard << endl;
            count++;
            //cout << "count: " << count << endl;
	    }
    }

	if(count == 2){
		return true;
	}
	else{
		return false;
	}
}
bool poker::threeOfAKind(){
	int count = 0;
    int numOfCardOne;
    int numOfCardTwo;
    int numOfDealtCard;


/*
    cout << " the player's cards are: ";
    printCards("player");

    cout << " the dealer's cards are: ";
    printCards("dealer");
    */

    if(playerOne[0].length() == 2){
        numOfCardOne = playerOne[0].at(0) - 48;
    }
    else if(playerOne[0].length() == 3){
        numOfCardOne = 10 + (playerOne[0].at(1) - 48);
    }
    //cout << "numOfCardOne: " << numOfCardOne << endl;

    if(playerOne[1].length() == 2){
        numOfCardTwo = playerOne[1].at(0) - 48;
    }
    else if(playerOne[1].length() == 3){
        numOfCardTwo = 10 + (playerOne[1].at(1) - 48);
    }


	for(int i = 0; i < dealtcards.size(); i++){
        if(dealtcards[i].length() == 2){
            numOfDealtCard = dealtcards[i].at(0) - 48;
        }
        else if(dealtcards[i].length() == 3){
            numOfDealtCard = 10 + (dealtcards[i].at(1) - 48);
        }

        if(numOfDealtCard == numOfCardOne || numOfDealtCard == numOfCardTwo){
           // cout << "numOfCardOne: " << numOfCardOne << endl;
            //cout << "numOfCardTwo: " << numOfCardTwo << endl;
            //cout << "dealtCards " << numOfDealtCard << endl;
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

bool poker::straight (){
	// if both of cards are same
    int count =0;
    int numOfCardOne = 0;
    int numOfCardTwo = 0;
    int numOfDealtCard = 0;
    vector<int> sortedCards;
    
    /*dealtcards[0] = "3H";
    dealtcards[1] = "2H";
    dealtcards[3] = "5H";
    dealtcards[4] = "2A";
    playerOne[0] = "4H";
    playerOne[1] = "1H";
 */
    for(int i = 0; i < playerOne.size(); i++){
        if(playerOne[i].length() == 2){
            sortedCards.push_back(playerOne[i].at(0) - 48);
        }
        else if(playerOne[i].length() == 3){
            sortedCards.push_back(10 + (playerOne[i].at(1) - 48));
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
  
  // sort(sortedCards.begin(), sortedCards.end());
  //bubble sort
    for(int i =0; i<sortedCards.size(); i++){
         for(int j=0; j<sortedCards.size()-i-1; j++){
        int swap;
        if(sortedCards[j] > sortedCards[j+1]){
            //swap(sortedCards[j], sortedCards[j + 1]);
            swap = sortedCards[j];
            sortedCards[j] = sortedCards[j+1];
            sortedCards[j+1] = swap;
            

        }
    }
    }
   
    for(int i = 0; i < sortedCards.size()-1; i++){
       // cout << "hi";
        if(sortedCards[i] + 1 == sortedCards[i+1]){
           count ++;
          /* cout << "sorted : " << sortedCards[i] << endl;
           cout << "sorted+1 : " << sortedCards[i+1] << endl;
           cout << "count : " << count<< endl;
           */
        }
    }
       if(count >= 4){
        return true;
       }
        else{
            return false;
        }
       }
bool poker::flush(){ // same as three of a kind but for 5 cards 
    int count1 = 0;
    int count2 = 0;
    char signOfCardOne;
    char signOfCardTwo;
    char signOfDealtCard;
   
   /*dealtcards[0] = "3H";
    dealtcards[1] = "2H";
    dealtcards[3] = "5H";
    dealtcards[4] = "2A";
    playerOne[0] = "4H";
    playerOne[1] = "1H";
    */
/*
    dealtcards[0] = "3H";
    dealtcards[1] = "5H";
    dealtcards[3] = "6H";
    dealtcards[4] = "2H";
    playerOne[0] = "7A";
    playerOne[1] = "3H";
    */

   /* cout << " the player's cards are: ";
    printCards("player");

    cout << " the dealer's cards are: ";
    printCards("dealer"); */
    

    if(playerOne[0].length() == 2){
        signOfCardOne = playerOne[1].at(1);
    }
    else if(playerOne[0].length() == 3){
        signOfCardOne = (playerOne[2].at(2));
    }
    //cout << "numOfCardOne: " << numOfCardOne << endl;

    if(playerOne[1].length() == 2){
        signOfCardTwo = playerOne[1].at(1);
    }
    else if(playerOne[1].length() == 3){
        signOfCardTwo = (playerOne[1].at(2));
    }


	for(int i = 0; i < dealtcards.size(); i++){
        if(dealtcards[i].length() == 2){
            signOfDealtCard = dealtcards[i].at(1);
        }
        else if(dealtcards[i].length() == 3){
            signOfDealtCard = (dealtcards[i].at(2));
        }

            // cout << "numOfCardOne: " << numOfCardOne << endl;
            //cout << "numOfCardTwo: " << numOfCardTwo << endl;
            //cout << "dealtCards " << numOfDealtCard << endl;
        if(signOfDealtCard == signOfCardOne){
            count1++;
           /* cout << "sign of Dealt card: " << i << " " << signOfDealtCard << endl;
            cout << "Sign of cardone: " << i << " " << signOfCardOne << endl;
            cout << "count1:  " << count1; */
	    }
        if(signOfDealtCard == signOfCardTwo){
            count2++;
            /*
            cout << "sign of Dealt card: " << i << " " << signOfDealtCard << endl;
            cout << "Sign of cardone: " << i << " " <<signOfCardOne << endl;
            cout << "count2: " << count2; */
        }
    }

    // count will be three if both of player's cards are of same sign and 
    // two of same same sign are on the table
    // will be four if one of player's cards and four of table's cards are same sign
	if(count1 >= 3 || count2 >=3){
		return true;
	}
	else{
		return false;
	}
    }

bool poker::fullHouse(){
	if(threeOfAKind() && pair()){
		return true;
	}
	else{
		return false;
	}
    }
bool poker::fourOfAKind(){
	int count = 0;
    int numOfCardOne;
    int numOfCardTwo;
    int numOfDealtCard;
/*
    cout << " the player's cards are: ";
    printCards("player");

    cout << " the dealer's cards are: ";
    printCards("dealer");
    */

    if(playerOne[0].length() == 2){
        numOfCardOne = playerOne[0].at(0) - 48;
    }
    else if(playerOne[0].length() == 3){
        numOfCardOne = 10 + (playerOne[0].at(1) - 48);
    }
    //cout << "numOfCardOne: " << numOfCardOne << endl;

    if(playerOne[1].length() == 2){
        numOfCardTwo = playerOne[1].at(0) - 48;
    }
    else if(playerOne[1].length() == 3){
        numOfCardTwo = 10 + (playerOne[1].at(1) - 48);
    }


	for(int i = 0; i < dealtcards.size(); i++){
        if(dealtcards[i].length() == 2){
            numOfDealtCard = dealtcards[i].at(0) - 48;
        }
        else if(dealtcards[i].length() == 3){
            numOfDealtCard = 10 + (dealtcards[i].at(1) - 48);
        }

        if(numOfDealtCard == numOfCardOne || numOfDealtCard == numOfCardTwo){
           // cout << "numOfCardOne: " << numOfCardOne << endl;
            //cout << "numOfCardTwo: " << numOfCardTwo << endl;
            //cout << "dealtCards " << numOfDealtCard << endl;
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
bool poker::straighFlush(){
	if(straight() && flush()){
		return true;
	}
	else{
		return false;
	}
}
int poker::win(){
        bool count = false;
	if(straighFlush() == true){
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