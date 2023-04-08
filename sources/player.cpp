//
// Created by sagi yosef azulay on 23/03/2023.
//א



#include "player.hpp"

using namespace ariel;


  int Player::stacksize(){
      cout<<"Player "<<name<<" have "<<deck.size()<<" cards"<<endl;
    return 26;
}

string Player::getName() {
    return name;
}

void Player::addCard(Card* card, stack<Card*> s) {
    s.push(card);
}

int Player::cardesTaken() {
    cout<<"Player "<<name<<" has won "<<cardsTaken.size()<<" cards"<<endl;
    return (int)cardsTaken.size();
}

Card* Player::drawCard() {
    if(deck.empty()) {
        cout << "no cards left" << endl;
        return nullptr;
    } else {
        Card* c = deck.top();
        deck.pop();
        return c;
    }
}

    int Player::getScore()  {
    return score;
}

int Player::getWins()  {
    return wins;
}

int Player::getLoses()  {
    return loses;
}

double Player::getRatio()  {
      if(loses ==0){
          cout<<"No loses yet, Ratio is "<<getWins()<<endl;
          return-1;
      }
      cout<< this->getWins();
      cout<< this->getLoses();
      double r = (this->getWins()/this->getLoses());
      cout<< r;

    return r;
}







