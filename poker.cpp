//bool royalFlush(int player){

//}
bool straightFlush(){
	if(straight() && flush()){
		return true;
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
