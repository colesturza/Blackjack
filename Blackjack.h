/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  Blackjack.h
 */

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "Opponent.h"
#include "Deck.h"
#include "util.h"
#include <vector>
#include <iostream>
#include <memory>
#include <fstream>
#include <cstdlib>

using namespace std;

class Blackjack {
	public:
	    Blackjack();

		/*! @fn Blackjack(vector<Player> players, string filename)
		 *  Constructor for Blackjack.
		 *	@param players all players in game.
		 *	@param filename name of file to save game as.
	     */
		Blackjack(Player player1, vector<Opponent> opponents, int num_of_rounds, string filename);

		/*! @fn Blackjack(string filename)
		 *  Constructor for Blackjack. Loads a previous saved file.
		 *	@param filename
	     */
		Blackjack(string filename);

		/*! @fn ~Blackjack()
		 *  Deconstructor for Blackjack.
	     */
		~Blackjack();

		/*! @fn void dealCards()
		 *  Deals two cards to each player.
	     */
		void dealCards();

		/*! @fn void dealCard(int player_index)
		 *  Deals a cards to one player.
		 *	@param player_index index of player that is delt the card.
	     */
		Card dealCard(int player_index);

		Card dealCard();

		/*! @fn void askPlayersToHit()
		 *  Asks each player if they want to hit.
	     */
		void askPlayersToHit();

		/*! @fn Player getRoundWinner()
		 *  Gets the winner of the round.
		 * 	@return Player the winning player of the round.
	     */
		Player getRoundWinner();

		/*! @fn Player getGameWinner()
		 *  Gets the winner of the game.
		 * 	@return Player the winning player of the game.
	     */
		Player getGameWinner();

		/*! @fn vector<Card> getVisibleCards()
		 *  Gets all the visible cards in the game.
		 * 	@return vector<Card> all the visible cards.
	     */
		vector<Card> getVisibleCards();

		/*! @fn int getRound()
		 *  Gets the round.
		 * 	@return round
	     */
		int getRound();

		int getNumOfRounds();

		/*! @fn void printGameState()
		 *  prints game table.
	     */
		void printGameState();
    
        void printGameStateEOR();

		/*! @fn saveGame()
		 *  Saves the current game.
	     */
		void saveGame();

		void loadPreviousGame(string filename);

	private:
		string game_save_name;
		Player player1;
		vector<Opponent> opponents;
		vector<Card> visible_cards;
		vector<Card> discarded_cards;
		Deck game_deck;
		int round;
		int num_of_rounds;

};

/*! @class Blackjack
 *  This class represents a game of Blackjack.
 */

#endif // BLACKJACK_H
