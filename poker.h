#include <vector>

#ifndef	POKER_H
#define	POKER_H

class Poker{
    private:
        std::vector<string> dealtcards;
        std::vector<string> playerone;
        std::vector<string> playertwo;
        std::vector<string> playerthree;
        int playerOneMoney;
        int playerTwoMoney;
        int playerThreeMoney;
       

    public:
        void fold(); 
        void deal(); // if card already dealt if call random again
                               //number of players * 2 + 5
        void displayCards();
        int numCards(); //returns number of cards in dealtcard vector
        void money(int amount, char AorS); // each persons money
        //int getmoney(); // returns money,how much each player has
        //void totalmoney(int amount); // pool of money
        string win(); //win calls winner money at the end
                      //couts winner money 
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

        Poker();  
        ~Poker();

         //void raise(int player, int amount);
        //void check(int player);
        //void checkDuplicates(); 
        //int winnerMoney(int player); 
}
