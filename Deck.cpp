/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  Deck.cpp
 */

#include "Deck.h"
#include <algorithm>
#include <iostream>

using namespace std;

Deck::Deck() {
	this->fillDeck();
}

Deck::~Deck() {

}

void Deck::shuffle() {
	random_shuffle(my_deck.begin(), my_deck.end());
}

Card Deck::drawCard() {
	Card card(my_deck.back().getSuit(), my_deck.back().getRank());
	my_deck.pop_back();
	return card;
}

Card Deck::getCard(int index) {
	return my_deck[index];
}

vector<Card> Deck::getDeck() {
    return my_deck;
}

void Deck::resetDeck() {
	my_deck.clear();
}

void Deck::removeCard(int index) {
    my_deck.erase(my_deck.begin() + index);
}

void Deck::addCard(Card c) {
	my_deck.push_back(c);
}

void Deck::fillDeck() {
	for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 13; j++)
        {
            Card card(i, j);
            my_deck.push_back(card);
        }
    }
}


