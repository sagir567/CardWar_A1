//
// Created by sagi yosef azulay on 23/03/2023.
//

#include "card.hpp"
using namespace ariel;



int Card:: getValue() {
    return value;
}

string Card:: getSuit() {
    return suit;
}

string Card:: toString() {
    return to_string(value) + " of " + suit;
}




