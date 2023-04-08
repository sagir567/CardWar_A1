//
// Created by sagi yosef azulay on 23/03/2023.
//

#ifndef UNTITLED_CARD_H
#define UNTITLED_CARD_H

#include <iostream>

using namespace std;

namespace ariel {

    class Card {
    private:
        int value;
        string suit;
    public:

        Card(int value, string suit) {
            this->value = value;
            this->suit = suit;
        }
        Card() {
            srand(time(NULL));
            int s = rand()%4;
            this->value = (rand()%13)+1;

            switch (s) {
                case 0:{
                    this->suit = "spades";
                }
                case 1:{
                    this->suit = "diamonds";
                }
                case 2:{
                    this->suit = "hearts";
                }
                case 3:{
                    this->suit = "clubs";
                }

            }
        }

        ~Card() {

        }






        int getValue();

        string getSuit();

        string toString();
    };
}


#endif //UNTITLED_CARD_H
