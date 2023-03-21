#include "doctest.h"
#include "sources/player.hpp"
#include "sources/card.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace ariel;

///// setting up test envirosment
/**
 * @brief createDeck
 * just as it sound create shuffeled full play card deck and return it
 * @return shuffeled full play card deck
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

   // Shuffle the deck using random_shuffle from algorithm library 
   srand(time(NULL)); 
   random_shuffle(deck.begin(), deck.end());
  return deck;
}

/// @brief deal the accepted deck and deal it to the players
/// @param a : Player 1 
/// @param b : Player 2
/// @param deck : accepted deck
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

TEST_CASE("No-Special-Skills Test") {

  vector<Card> deck = createDeck();
  // Create two players with their names 
  Player p1("Alice");
  Player p2("Bob");
  deal(p1, p2,deck);

   while (true) {
    
    cout << "\nPress any key to play a round...\n";
    cin.get();

    if (p1.hand.empty() || p2.hand.empty()) { 
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