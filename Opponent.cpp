/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  Opponent.cpp
 */

#include "Opponent.h"
#include <iostream>

using namespace std;

bool isGoodCombo(vector<Card> player_hand, Card test_card, int min_score) {
	vector<Card> test_hand = player_hand;
	test_hand.push_back(test_card);
	if(util::calcScore(test_hand) >= min_score) {
		return true;
	}
	return false;
}

int Opponent::findCountOfGoodCombos(vector<Card> temp_deck) {
	int count = 0;
	for(int i = 0; i < temp_deck.size(); i++) {
		if(isGoodCombo(my_hand, temp_deck[i], 17)) {
			count++;
		}
	}

	return count;
}

Opponent::Opponent(string name, int difficulty) : Player(name) {
	if(difficulty >= MIN_DIFF && difficulty <= MAX_DIFF) {
		this->difficulty = difficulty;
	}
	else if(difficulty < MIN_DIFF) {
		this->difficulty = MIN_DIFF;
	}
	else {
		this->difficulty = MAX_DIFF;
	}
}

Opponent::Opponent(string name, int difficulty, int points) : Player(name, points) {
	if(difficulty >= MIN_DIFF && difficulty <= MAX_DIFF) {
		this->difficulty = difficulty;
	}
	else if(difficulty < MIN_DIFF) {
		this->difficulty = MIN_DIFF;
	}
	else {
		this->difficulty = MAX_DIFF;
	}
}

Opponent::~Opponent() {

}

int Opponent::getDiff() {
	return difficulty;
}

bool Opponent::desideHit(vector<Card> known_cards) {

	if(util::calcScore(my_hand) >= 21) {
		return false;
	}

	Deck temp_deck;
	for(int i = 0; i < 52; i++) {
		for(int j = 0; j < known_cards.size(); j++) {
			if(temp_deck.getCard(i).getSuit() == known_cards[j].getSuit() && temp_deck.getCard(i).getRank() == known_cards[j].getRank()) {
				temp_deck.removeCard(i);
			}
		}
	}

	int count = this->findCountOfGoodCombos(temp_deck.getDeck());
	float percent_of_good_combos = (float)count/temp_deck.getDeck().size();

	if(difficulty == 1 && percent_of_good_combos >= 0.2)
		return true;
	if(difficulty == 2 && percent_of_good_combos >= 0.3)
		return true;
	if(difficulty == 3 && percent_of_good_combos >= 0.4)
		return true;
	if(difficulty == 4 && percent_of_good_combos >= 0.5)
		return true;
	return false;
}
