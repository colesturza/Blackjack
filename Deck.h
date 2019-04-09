/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  Deck.h
 */

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <iostream>

using namespace std;

class Deck {
	public:
		/*! @fn Deck()
		 *  Constructor for Deck. Fills my_deck.
	     */
		Deck();

		/*! @fn ~Deck()
		 *  Deconstructor for Deck.
	     */
		~Deck();

		/*! @fn void shuffle()
		 *  reorders my_dack.
	     */
		void shuffle();

		/*! @fn Card drawCard()
		 *  Draws card from my_deck.
		 *	@return Card the card that was drawn
	     */
		Card drawCard();

		/*! @fn Card getCard(int index)
		 *  Returns Card at given index.
		 *	@return Card the card in the deck of the given index.
	     */
		Card getCard(int index);

		vector<Card> getDeck();

		/*! @fn void resetDeck()
		 *  Resets my_deck to initial state.
	     */
		void resetDeck();

		void removeCard(int index);
		void addCard(Card c);
		
		/*! @fn void fillDeck()
		 *  Fills my_deck.
	     */
		void fillDeck();

	private:
		vector<Card> my_deck;
};

/*! @class Deck
 *  This is a class that represents a Deck.
 */

#endif // DECK_H
