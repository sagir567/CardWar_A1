//
// Created by sagi yosef azulay on 23/03/2023.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include <iostream>
#include <stack>
#include "card.hpp"

using namespace std;

namespace ariel {

    static int count=0;
    class Player {
    private:
        // empty for the tests


    public:
        int getScore() ;

        int getWins() ;

        int getLoses() ;
        int score;
        double wins;
        double loses;



        string name;

        stack <Card*> cardsTaken;
        stack <Card*> deck;


        Player(string name) {
            count +=1;
            this->name = name;
            this->score = 0;
            loses=wins=0;

        }

        Player() {
            count+=1;
            this->name = "player"+ to_string(count);
            this->score = 0;
            loses=wins=0;
        }

        double getRatio();

        int cardesTaken();// prints the amount of cards this player has won.

        int stacksize();//prints the amount of cards left. should be 21 but can be less if a draw was played

        string getName();

        Card* drawCard(); //draws a card from the deck


        void addCard(Card* card,stack<Card*> s);

        Card playCard();



    };
}
#endif //UNTITLED_PLAYER_H
