/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  Opponent.h
 */

#ifndef OPPONENT_H
#define OPPONENT_H

#include "Player.h"
#include "Deck.h"
#include <iostream>
#include "util.h"

using namespace std;

class Opponent : public Player {
	public:
		/*! @fn Opponent(string name, int difficulty)
		 *  Constructor for Opponent.
		 *	@param name
		 *	@param difficulty
	     */
		Opponent(string name, int difficulty);

		Opponent(string name, int difficulty, int points);
		
		/*! @fn ~Opponent()
		 *  Deconstructor for Opponent.
	     */
		~Opponent();

		/*! @fn int getDiff()
		 *  Getter class member function for difficulty.
		 *	@return difficulty
	     */
		int getDiff();

		/*! @fn bool desideHit()
		 *  Desides if the opponent object will hit or pass.
		 *	@param known_cards cards AI knows have been drawn.
		 *	@return bool true if the AI desides to hit.
	     */
		bool desideHit(vector<Card> known_cards);

		int findCountOfGoodCombos(vector<Card> temp_deck);

		static const int MAX_DIFF = 4;
		static const int MIN_DIFF = 1;

    private:
        int difficulty;
};

/*! @class Opponent
 *  This class inherits from Player and is an AI Blackjack player.
 */

#endif // OPPONENT_H
