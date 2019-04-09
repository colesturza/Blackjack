/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  util.h
 */

#ifndef UTIL_H
#define UTIL_H

#include "Card.h"
#include <vector>
#include <cctype>
#include <sstream>
#include <iostream>

using namespace std;

namespace util {
	/*! @fn void split(string sentence, char sep, string arr[], int size)
	 *  Function that splits up words in a sentence, using the given separation character,
	 *  into a given array of type string.
	 *  @param sentence a sentence to split.
	 *  @param sep a character to separate the words in sentence.
	 *  @param v an vector to fill with words from sentence.
	 */
	void split(string sentence, char sep, vector<string> v);
	
	void split(string sentence, char sep, string arr[], int size);
	
	/*! @fn int calcScore(vector<Card> player_hand)
	 *  Function that calculates a player's hand's score.
	 *  @param player_hand
	 *  @return score of hand.
	 */
	int calcScore(vector<Card> player_hand);
	
	/*! @fn int findCard(Card c, vector<Card> v)
	 *  Finds a Card object in a given vector.
	 *	@param c card to look for.
	 *  @param v vector to search through.
	 *  @return index of c in v. Returns -1 if not found.
	 */
	int findCard(Card c, vector<Card> v);
}

#endif // UTIL_H
