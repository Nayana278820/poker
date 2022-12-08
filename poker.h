// HEADER
#ifndef	POKER_H
#define	POKER_H
#include <string>
#include<vector>

using namespace std;

class poker{
    private:
        std::vector<string> dealtcards;
        std::vector<string> playerOne;
		std::vector<string> AI;
        int playerOneMoney;
		int AIMoney;
		int tableMoney;

    public:
        string deal();			// deal a single card
								// if card already dealt, will grab another card
        void dealHand(int numcards, string player);
        void printCards(string player); 
        int numCards();			// returns number of cards in dealtcard vector
        int win(string player); // couts what player won and returns rank of that winning
		void changeMoney(int amount, string player, char addOrSub); // adds or subtracts an amount of money
																	// from a player and the pool of money on table
		void winMoney(string player);	// add or subtracts money from player and pool of money on table when someone wins
		int getMoney(string player);
		// Below: will return true if the player's cards has that win condition or false otherwise
        bool royalFlush(string player);
        bool straighFlush(string player);
        bool fourOfAKind(string player);
        bool fullHouse(string player);
        bool flush(string player);
        bool straight(string player);
        bool threeOfAKind(string player);
        bool twoPair(string player);
        bool pair(string player);
        bool highCard();

        poker();  
        //~poker();
};

#endif
