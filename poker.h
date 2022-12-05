#include <vector>
#ifndef	POKER_H
#define	POKER_H
#include <cstring>

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
        void dealHand(int numcards, string player);
        //void displayCards();
        void printCards(string player); 
        int numCards(); //returns number of cards in dealtcard vector
        void money(int amount, char AorS); // each persons money
        //int getmoney(); // returns money,how much each player has
        //void totalmoney(int amount); // pool of money
        int win(); //win calls winner money at the end
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

        poker();  
        ~poker();

};

#endif POKER_H