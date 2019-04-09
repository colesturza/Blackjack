/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  Player.h
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include <iostream>

using namespace std;

class Player {
	public:
	    Player();

		/*! @fn Player(name)
		 *  Constructor for Player.
		 *	@param name
	     */
		Player(string name);
		
		Player(string name, int points);

		/*! @fn ~Player()
		 *  Deconstructor for Player.
	     */
		~Player();

		/*! @fn void addCard(Card card)
		 *  Adds card to my_hand.
		 *	@param card card to add to my_hand.
	     */
		void addCard(Card card);

		/*! @fn vector<Card> getHand()
		 *  Getter class member function for my_hand.
		 *	@return my_hand
	     */
		vector<Card> getHand();

		/*! @fn int getPoints()
		 *  Getter class member function for points.
		 *	@return points
	     */
		int getPoints();

		/*! @fn void addPoint()
		 *  Increments points by one.
	     */
		void addPoint();

		string getName();
		
		void setName(string name);

		/*! @fn void resetHand()
		 *  emptys player's hand.
	     */
		void resetHand();

	protected:
		string name;
		int points;
		vector<Card> my_hand;
};

/*! @class Player
 *  This is a class that represents a Blackjack player.
 */

#endif // PLAYER_H
