#include "doctest.h"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include "sources/game.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

//for output checks
#include <stdio.h>
#include <unistd.h>

using namespace std;
using namespace ariel;

///// setting up test envirosment
/**
 * @brief createDeck
 * just as it sound create full play card deck and return it
 * @return full play card deck
*/
vector<Card> createDeck(){
  // Create a vector to store all 52 cards in the deck
  vector<Card> deck;
  // Create all 52 cards and add them to the deck
  for (int i = 1; i <= 13; i++) {
     deck.push_back(Card(i, 'S')); // Spades
     deck.push_back(Card(i, 'H')); // Hearts 
     deck.push_back(Card(i, 'D')); // Diamonds 
     deck.push_back(Card(i, 'C')); // Clubs 
   }
  return deck;
}

/**
 * @brief accept deck and shuffle it randomly
 * @param vector<card> of play cards
 * @return shuffeled deck
*/
vector<Card> shuffle_deck(vector<Card> deck){
  // Shuffle the deck using random_shuffle from algorithm library 
  srand(time(NULL)); 
  random_shuffle(deck.begin(), deck.end());
  return deck;
}

/**
 * @brief deal the accepted deck and to the players
 * @param a : Player 1 
 * @param b : Player 2
 * @param deck : accepted deck
*/
void deal(Player a, Player b, vector<Card> deck)
{
  // Deal 26 cards each to both players 
   for (unsigned long int i = 0; i < 26; i++) {
     a.addCard(deck[i]);
     b.addCard(deck[i + 26]);
   }
}


// stdout checks
#define BUFFER_SIZE 1024
int stdoutSave;
char outputBuffer[BUFFER_SIZE];

void replaceStdout()
{
    fflush(stdout); //clean everything first
    stdoutSave = dup(STDOUT_FILENO); //save the stdout state
    freopen("NUL", "a", stdout); //redirect stdout to null pointer
    setvbuf(stdout, outputBuffer, _IOFBF, 1024); //set buffer to stdout
}

void restoreStdout()
{
    freopen("NUL", "a", stdout); //redirect stdout to null again
    dup2(stdoutSave, STDOUT_FILENO); //restore the previous state of stdout
    setvbuf(stdout, NULL, _IONBF, BUFFER_SIZE); //disable buffer to print to screen instantly
}

Game create_game(){
  Player p1("Aharon");
  Player p2("Barak");
  Game g(p1,p2);
  return g;
}
/// player creation test
TEST_CASE("Player creation test")
{
  CHECK_NOTHROW(Player p1("Aharon"));
}
/// player parameter test
TEST_CASE("Player creation test")
{
  Player p1("Aharon");
  CHECK_EQ(p1.name,"Aharon");
  CHECK(p1.hand.empty());
}
TEST_CASE("diffrent cards name tests Card test")
{
  CHECK_NOTHROW(Card card(1,'S'));
}
/// card name test
TEST_CASE("diffrent cards name tests Card test")
{
  //ace card
  Card card1(1,'S');
  CHECK_EQ(card1.print(),"Ace of Spades");
  // royal family card
  Card card2(13,'H');
  CHECK_EQ(card2.print(),"King of hearts");
  //regular card
  Card card3(7,'D');
  CHECK_EQ(card3.print(),"7 of diamonds");
}
/// player accept cards
TEST_CASE("player acccept cards test"){
  Player p1("Aharon");
  Card card(1,'A');
}
TEST_CASE("full deck deal without game test case") {
  vector<Card> deck = createDeck();
  deck = shuffle_deck(deck);

  // Create two players 
  Player p1("Aharon");
  Player p2("Barak");
  deal(p1, p2, deck);

  while (true) {
    // cout << "\nPress any key to play a round...\n";
    // cin.get();
    if (p1.stacksize() <= 0 || p2.stacksize() <= 0) { 
      break; // End the game if either player has no cards left 
    }

    cout << "\n" << p1.name << "'s card: ";
    Card c1 = p1.playCard(); 
    CHECK_NOTHROW(c1.print()); 

    cout << "\n" << p2.name << "'s card: ";
    Card c2 = p2.playCard(); 
    CHECK_NOTHROW(c2.print());
  }
}

TEST_CASE("Create game test"){
  Player p1("Aharon");
  Player p2("Barak");
  CHECK_NOTHROW(Game g1(p1,p2));
}

TEST_CASE("game functions not throws test"){
  Game g1 = create_game();
  CHECK_NOTHROW(g1.playTurn());
  CHECK_NOTHROW(g1.printLastTurn());
  CHECK_NOTHROW(g1.printLog());
  CHECK_NOTHROW(g1.printStats());
  CHECK_NOTHROW(g1.playAll());
  CHECK_NOTHROW(g1.printWiner());
}

TEST_CASE("game got no winner till we play at least one round"){
  Game g = create_game();
  CHECK_THROWS(g.printWiner());
  g.playTurn();
  CHECK_NOTHROW(g.printWiner());
}

TEST_CASE("forced win for Barak test case")
{
  vector<Card> deck = createDeck();
  deck = shuffle_deck(deck);
  // Create two players 
  Player p1("Aharon");
  Player p2("Barak");
  deal(p1, p2, deck);
  Game g(p1,p2);
  replaceStdout(); 
  string output(outputBuffer);
  CHECK_NE(output.find(p2.name),std::string::npos);
  restoreStdout();
}

TEST_CASE("no 2 games simulatously test case"){
  Player p1("Aharon");
  Player p2("Barak");
  Player p2("gili");
  CHECK_NOTHROW(Game g1(p1,p2));
  // should throw but didn't find test case for that
  // CHECK_THROWS(Game::Game(p1,p3));

}

