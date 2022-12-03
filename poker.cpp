//bool royalFlush(int player){
#include "poker.h"
// lol
//}
bool straightFlush(){
	if(straight() && flush()){
		return true;
	}
	else{
		return false;
	}
}
bool fourOfAKind(){
	for(int i = 0; i < playerone.size(); i++){
		int count = 0;
		string cardToCheck = playerone[i];
		count++;
		// check if have two of same cards in hand
		if(i == 0){
			if(cardToCheck == playerOne[i + 1]){
				count ++;
			}
		}
		for(int j = 0; j < dealcards.size(); j++){
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
}
bool fullHouse(){
	if(threeOfAKind() && pair()){
		return true;
	}
	else{
		return false;
	}
}
bool flush(){
	for(int i = 0; i < playerone.size(); i++){
		char sign = playerone[i].at(1);
		int count = 0;
		if(i == 0){
			if(sign == playerone[i + 1].at(1){
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
}
bool straight (){
	// NOT FINISHED!
	//for(int
	//int num = playerone[i].at(0) - 64;

	// made a heap of the ints
	
	
}
bool threeOfAKind(){
	for(int i = 0; i < playerone.size(); i++){
		int count = 0;
		string cardToCheck = playerone[i];
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
		else{
			return false;
		}
	}

}
bool twoPair(){
	for(int i = 0; i < playerone.size(); i++){
		for(int j = 0; j < dealcards.size(); j++){
			if(player[i] == dealcards[j]){
				count++;
				// so that will go to next card in player's deck
				j = dealcards.size();
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
	if(playerone[0] == playerone[1]){
		return true;
	}
	for(int i = 0; i < playerone.size(); i++){
		for(int j = 0; i < dealtcards.size(); j++){
			if(playerone[i] == dealcards[j]){
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
	for(int i = 0; i < playerone.size(); i++){
		if(playerone[i] > biggestCard){
			playerone = biggestCard;
		}
	}
	// we'll always have highest card
	return true;
}
////////////////////////////////////////////////////////////////////////////////
/// 
void fold(){ // lay down your cards and stop playing
    playerone.clear();
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
void dealHand()
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
                playerone.push_back(j); // add it to the player cards vector
         /*   if(numPlayer == 2){
                playertwo.push_back(j); // add it to the player cards vector
            }
            if(numPlayer == 3){
                playerthree.push_back(j); // add it to the player cards vector
            }*/
    }
}

bool straight (){
	// NOT FINISHED!
	//for(int
	//int num = playerone[i].at(0) - 64;

	// made a heap of the ints
	int count=0;
for(int i = 0; i < playerone.size(); i++){
		for(int j = 0; j < dealcards.size(); j++){
			if( (player[j] - dealcards[i]) == 1) {
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