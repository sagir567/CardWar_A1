#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;
static int i = 1;

TEST_CASE("Test 1 - Initialization") {
    Player p1("Alice");
    Player p2("Bob");
    cout << "TEST-  " << i++ << "\n\n";

    Game game(p1, p2);
    cout << "first check\n";
    CHECK(p1.getName() == "Alice");

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);

    cout << "second check \n";
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("TEST 2 -objects counting ") {
    cout << "TEST-  " << i++ << "\n\n";
    Player p1;
    Player p2;

    CHECK(p1.getName() == "player5");
    CHECK(p2.getName() == "player6");
}

TEST_CASE("TEST 3 - check stats initiating ") {
    cout << "TEST-  " << i++ << "\n\n";
    Player p1("frodo");

    CHECK(p1.getLoses() == 0);
    CHECK(p1.getWins() == 0);
    CHECK(p1.getWins() == 0);
    CHECK(p1.getRatio() == -1.0);
}

TEST_CASE("TEST 4 -check game constructor dealing the cards") {
    cout << "TEST- " << i++ << "\n\n";
    Player p1("$Plif");
    Player p2("bob");

    CHECK(p1.deck.size() == 0);
    CHECK(p1.deck.size() == 0);

    Game game(p1, p2);

    CHECK(p1.deck.size() == 26);
    CHECK(p2.deck.size() == 26);
}

TEST_CASE("TEST 5 -") {
    cout << "TEST- " << i++ << "\n\n";
    Player p1("sam");
    Card c(10, "hearts");
    p1.deck.push(&c);
    Card *copy = p1.drawCard();
    //    CHECK(&copy == &c);
    CHECK(copy->getValue() == c.getValue());
}

TEST_CASE("TEST 6 - Test Card class") {
    cout << "TEST- " << i++ << "\n\n";
    Card c1(1, "clubs");
    CHECK(c1.getValue() == 1);
    CHECK(c1.getSuit() == "clubs");
}

TEST_CASE("TEST 7 - Test Player's addCard and cardesTaken") {
    cout << "TEST- " << i++ << "\n\n";
    Player p1("TestPlayer");
    Card c1(5, "spades");
    Card c2(10, "hearts");

    p1.addCard(&c1,p1.deck);
    p1.addCard(&c2,p1.deck);

    CHECK(p1.cardesTaken() == 2);
}

TEST_CASE("TEST 8 - Test Player's drawCard with empty deck") {
    cout << "TEST- " << i++ << "\n\n";
    Player p1("EmptyDeckPlayer");

    CHECK(p1.drawCard() == nullptr);
}

TEST_CASE("TEST 9 - Test Game's playTurn with equal cards") {
    cout << "TEST- " << i++ << "\n\n";
    Player p1("saroman");
    Player p2("sauron");
    Game game(p1, p2);

    Card c1(10, "hearts");
    Card c2(10, "spades");

    p1.deck.push(&c1);
    p2.deck.push(&c2);
    cout << "------------p--------------";
    game.playTurn(); // It doesn't handle equal cards yet
    cout << "--------------------------";
    CHECK(p1.cardsTaken.size() == 0);
    CHECK(p2.cardsTaken.size() == 0);
    cout << "--------------------------";
}

TEST_CASE("TEST 10 - Test Card's toString method") {
    cout << "TEST- " << i++ << "\n\n";
    Card c(5, "diamonds");

    CHECK(c.toString() == "5 of diamonds");
}

TEST_CASE("Test 11 - Card default constructor generates valid card") {
    cout << "TEST- " << i++ << "\n\n";
    Card c;
    CHECK(c.getValue() >= 1);
    CHECK(c.getValue() <= 13);
    CHECK((c.getSuit() == "spades" || c.getSuit() == "diamonds" || c.getSuit() == "hearts" || c.getSuit() == "clubs"));
}

TEST_CASE("Test 12 - Card constructor with parameters") {
    cout << "TEST- " << i++ << "\n\n";
    Card c(5, "spades");
    CHECK(c.getValue() == 5);
    CHECK(c.getSuit() == "spades");
}

TEST_CASE("Test 13 - Card toString") {
    cout << "TEST- " << i++ << "\n\n";
    Card c(5, "hearts");
    CHECK(c.toString() == "5 of hearts");
}

TEST_CASE("Test 14 - Player addCard increments cardsTaken") {
    cout << "TEST- " << i++ << "\n\n";
    Player p("test");
    Card* c1 = new Card(5, "spades");
    Card* c2 = new Card(10, "diamonds");
    p.addCard(c1,p.deck);
    p.addCard(c2,p.deck);
    CHECK(p.cardesTaken() == 2);
}




TEST_CASE("Test 15 - Player getRatio with loses") {
    cout << "TEST- " << i++ << "\n\n";
    Player p("test");
    p.wins = 5.0;
    p.loses = 3.0;
    CHECK(p.getRatio() == 5.0 / 3);
}

TEST_CASE("Test 16 - Player getRatio without loses") {
    cout << "TEST- " << i++ << "\n\n";
    Player p("test");
    p.wins = 3;
    p.loses = 0;
    CHECK(p.getRatio() == -1.0);

}

TEST_CASE("Test 17 - Player's default constructor generates unique names") {
    cout << "TEST- " << i++ << "\n\n";
    Player p1;
    Player p2;
    Player p3;
    CHECK(p1.getName() != p2.getName());
    CHECK(p1.getName() != p3.getName());
    CHECK(p2.getName() != p3.getName());
}

TEST_CASE("Test 18 - Test Game constructor deals cards to each player") {
    cout << "TEST- " << i++ << "\n\n";
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}




TEST_CASE("Test 19 - Game playTurn handles ties") {
    cout << "TEST- " << i++ << "\n\n";
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    Card c1(10, "hearts");
    Card c2(10, "spades");

    p1.deck.push(&c1);
    p2.deck.push(&c2);

    game.playTurn(); // It doesn't handle equal cards yet

    CHECK(p1.cardsTaken.size() == 0);
    CHECK(p2.cardsTaken.size() == 0);
}

TEST_CASE("Test 20 - Test Game playTurn with a winner") {
    cout << "TEST- " << i++ << "\n\n";
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    Card c1(10, "hearts");
    Card c2(2, "spades");
    Card* _C1=&c1;
    Card* _C2=&c2;
    p1.addCard(_C1,p1.deck);
    p2.addCard(_C2,p2.deck);

    game.playTurn();
    //
    CHECK(p1.cardsTaken.size() == 2);
    CHECK(p2.cardsTaken.size() ==0 );
    CHECK(p1.cardesTaken() == 2);
    CHECK(p2.cardesTaken() == 0);
    cout<<"-------------------------\n";
    CHECK(p1.getWins() == 1);
    CHECK(p2.getLoses() == 1);
}






