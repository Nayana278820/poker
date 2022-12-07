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
void poker::winMoney(string player){ // player will be the winner
	if(player == "player"){
		//return (playerOneMoney + tableMoney);
		playerOneMoney += tableMoney;
	}
	else if(player == "AI"){
		AIMoney += tableMoney;
	}
	// tie
	else{ // each player gets their money back
		playerOneMoney += (tableMoney / 2);
		AIMoney += (tableMoney / 2);
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
	if(addOrSub == 'a'){
		tableMoney -= amount;
	}
	else{
		tableMoney += amount;
	} // if(win("player") > win("AI)) -> win amount
}

void poker::fold(string player){ // lay down your cards and stop playing
	if(player == "player"){
		playerOne.clear();
	}
	else if(player == "AI"){
		AI.clear();
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

// Deals five random cards to player 
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
                //cout << playerOne[i] << " ";
        }
		else if(player == "AI"){
			AI.push_back(card);
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

// Poker Hands

bool poker::highCard(){
	int biggestCard = 0;
    int num;
/*	for(int i = 0; i < playerOne.size(); i++){
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
	}*/
	// we'll always have highest card
    //cout << biggestCard;
	return true;
}

bool poker::pair(string player){
	// if both of cards are same
    int numOfCardOne = 0;
    int numOfCardTwo = 0;
    int numOfDealtCard = 0;

    // Get numbers of both of player's cards so that we can compare them
	if(player == "player"){
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
	}
	else if(player == "AI"){
		if(AI[0].length() == 2){
			numOfCardOne = AI[0].at(0) - 48;
		}
		else if(AI[0].length() == 3){
			numOfCardOne = 10 + (AI[0].at(1) - 48);
		}
		//cout << "numOfCardOne: " << numOfCardOne << endl;

		if(AI[1].length() == 2){
			numOfCardTwo = AI[1].at(0) - 48;
		}
		else if(AI[1].length() == 3){
			numOfCardTwo = 10 + (AI[1].at(1) - 48);
		}
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
bool poker::twoPair(string player){
	int count = 0;
    int numOfCardOne;
    int numOfCardTwo;
    int numOfDealtCard;

	if(player == "player"){
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
bool poker::threeOfAKind(string player){
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

    
	if(player == "player"){
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

bool poker::straight (string player){
	// if both of cards are same
    int count =0;
    int numOfCardOne = 0;
    int numOfCardTwo = 0;
    int numOfDealtCard = 0;
    vector<int> sortedCards;
    
    /*dealtcards[0] = "8C";
    dealtcards[1] = "3H";
	dealtcards[2[ = "13C";
    dealtcards[3] = "12D";
    dealtcards[4] = "2H";
    playerOne[0] = "7D";
    playerOne[1] = "9D";*/
 
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
  
  //bubble sort
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
       // cout << "hi";
        if(sortedCards[i] + 1 == sortedCards[i+1]){
           fiveInARow ++;
		   for(int j = 0; j < 4; j++){ // for 4 cards after
				if((sortedCards[j+1] - sortedCards[j]) == 1){
					fiveInARow ++;	
				}
		   }
		   //if(fiveInARow >= 5){
		//		return true;
		  // }
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
bool poker::flush(string player){ // same as three of a kind but for 5 cards 
    int count1 = 0;
    int count2 = 0;
    char signOfCardOne;
    char signOfCardTwo;
    char signOfDealtCard;
   
    /*dealtcards[0] = "5H";
    dealtcards[1] = "9S";
	dealtcards[2] = "4H";
    dealtcards[3] = "7H";
    dealtcards[4] = "9C";
    playerOne[0] = "4C";
    playerOne[1] = "10H";*/
    
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
    
	if(player == "player"){
		if(playerOne[0].length() == 2){
			signOfCardOne = playerOne[0].at(1);
		}
		else if(playerOne[0].length() == 3){
			signOfCardOne = (playerOne[0].at(2));
		}
		//cout << "numOfCardOne: " << numOfCardOne << endl;

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
		//cout << "numOfCardOne: " << numOfCardOne << endl;

		if(AI[1].length() == 2){
			signOfCardTwo = AI[1].at(1);
		}
		else if(AI[1].length() == 3){
			signOfCardTwo = (AI[1].at(2));
		}
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
	if(count1 >= 4 || count2 >=4){
		return true;
	}
	else{
		return false;
	}
}

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
/*
    cout << " the player's cards are: ";
    printCards("player");

    cout << " the dealer's cards are: ";
    printCards("dealer");
    */

	if(player == "player"){
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
bool poker::straighFlush(string player){
	if(straight(player) && flush(player)){
		return true;
	}
	else{
		return false;
	}
}
/*void*/int poker::win(string player){
	int returnVal;
    /*dealtcards[0] = "10D";
    dealtcards[1] = "2S";
	dealtcards[2] = "7C";
    dealtcards[3] = "4H";
    dealtcards[4] = "4S";
    playerOne[0] = "13D";
    playerOne[1] = "10S";
    //bool count = false;
	//
	
    dealtcards[0] = "8C";
    dealtcards[1] = "3H";
	dealtcards[2[ = "13C";
    dealtcards[3] = "12D";
    dealtcards[4] = "2H";
    playerOne[0] = "7D";
    playerOne[1] = "9D";
	cout << "player's cards: ";
	printCards("player");
	cout << endl;
	cout << "dealer's cards: ";
	printCards("dealer");
	cout << endl;*/
    /*dealtcards[0] = "8C";
    dealtcards[1] = "3H";
	dealtcards[2] = "13C";
    dealtcards[3] = "12D";
    dealtcards[4] = "2H";
    playerOne[0] = "7D";
    playerOne[1] = "9D";*/
	string name;
	if(player == "player"){
		name = "You";
	}
	else{
		name = "AI";
	}
	
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
