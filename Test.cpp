#include "doctest.h"
#include "sources/player.h"


TEST_CASE("No-Special-Skills Test") {

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

   // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

	// Deal 26 cards each to both players 
   for (unsigned long int i = 0; i < 26; i++) {
     p1.addCard(deck[i]);
     p2.addCard(deck[i + 26]);
   }

   while (true) {

     cout << "\nPress any key to play a round...\n";
     //cin.get();

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