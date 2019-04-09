/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  Card.h
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card {
	public:
		/*! @fn Card(int suit, int rank)
		 *  Constructor for Card.
		 *	@param suit the suit of the card
		 *	@param rank the rank of the card
	     */
		Card(int suit, int rank);

		/*! @fn ~Card()
		 *  Deconstructor for Card.
	     */
		~Card();

		/* Static Constant Class Member Variables */

		static const int MAX_SUIT;
		static const int MAX_RANK;
		static const int MIN_SUIT;
		static const int MIN_RANK;

		static const string SPADES;
		static const string CLUBS;
		static const string HEARTS;
		static const string DIAMONDS;

		static const string ACE;
		static const string TWO;
		static const string THREE;
		static const string FOUR;
		static const string FIVE;
		static const string SIX;
		static const string SEVEN;
		static const string EIGHT;
		static const string NINE;
		static const string TEN;
		static const string JACK;
		static const string QUEEN;
		static const string KING;

		/*! @fn int getSuit()
		 *  Getter class member function for suit.
		 *	@return suit
	     */
		int getSuit();

		/*! @fn int getRank()
		 *  Getter class member function for rank.
		 *	@return rank
	     */
		int getRank();

		/*! @fn string getCardStr()
		 *  Getter class member function for card_str.
		 *	@return card_str
	     */
		string getCardStr();

		/*! @fn bool setSuit(int suit)
		 *  Setter class member function for suit. Updates card_str with new suit.
		 *	@param suit new suit number.
		 *	@return bool returns true if new suit has been accepted.
	     */
		bool setSuit(int suit);

		/*! @fn bool setRank(int rank)
		 *  Setter class member function for rank. Updates card_str with new rank.
		 *	@param rank new rank number.
		 *	@return bool returns true if new rank has been accepted.
	     */
		bool setRank(int rank);

	private:
		int suit;
		int rank;
		string card_str;

		/*! @fn void updateCardStr(suit, rank)
		 *  Class member function that updates card_str with its new suit and/or rank.
		 *	@param suit new suit number.
		 *	@param rank new rank number.
	     */
		void updateCardStr(int suit, int rank);
};

/*! @class Card
 *  This is a class that represents a Card.
 */

#endif // CARD_H
