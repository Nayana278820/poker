#include <vector>
#ifndef	POKER_H
#define	POKER_H
#include <string>
#include<iostream>

using namespace std;

/*
class poker{
    private:
        std::vector<string> dealtcards;
        std::vector<string> playerOne;
        int playerOneMoney;
       

    public:
       //int playerOneMoney;
        void fold(); 
        string deal(); // if card already dealt if call random again
                               //number of players * 2 + 5
        void dealHand(int numcards);
        void displayCards();
        int numCards(); //returns number of cards in dealtcard vector
        void money(int amount, char AorS); // each persons money
        //int getmoney(); // returns money,how much each player has
        //void totalmoney(int amount); // pool of money
        int win(); //win calls winner money at the end
                      //couts winner money 
        int check_winner();
        bool royalFlush();
        bool straighFlush();
        bool fourOfAKind();
        bool fullHouse();
        bool flush();
        bool straight();
        bool threeOfAKind();
        bool twoPair();
        bool pair();
        bool highCard();

        poker();  
        ~poker();

         //void raise(int player, int amount);
        //void check(int player);
        //void checkDuplicates(); 
        //int winnerMoney(int player); 
};

#endif POKER_H

*/

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
       //int playerOneMoney;
	   int winAmount(string player);
        void fold(string player); 
        string deal(); // if card already dealt if call random again
                        //number of players * 2 + 5
        void dealHand(int numcards, string player);
        //void displayCards();
        void printCards(string player); 
        int numCards(); //returns number of cards in dealtcard vector
        //void money(int amount, char AorS, string player); // each persons money
        //int getmoney(); // returns money,how much each player has
        //void totalmoney(int amount); // pool of money
        int win(string player); //win calls winner money at the end
                                 //couts winner money 
		void changeMoney(int amount, string player, char addOrSub); // adds or subtracts an amount of money
		                                             // from a player
		void winMoney(string player);
		int getMoney(string player);
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
        ~poker();
};

#endif //POKER_H
