/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  Card.cpp
 */

#include "Card.h"
#include <iostream>

using namespace std;

const int Card::MAX_SUIT = 4;
const int Card::MAX_RANK = 13;
const int Card::MIN_SUIT = 1;
const int Card::MIN_RANK = 1;

const string Card::SPADES = "Spades";
const string Card::CLUBS = "Clubs";
const string Card::HEARTS = "Hearts";
const string Card::DIAMONDS = "Diamonds";

const string Card::ACE = "Ace of ";
const string Card::TWO = "Two of ";
const string Card::THREE = "Three of ";
const string Card::FOUR = "Four of ";
const string Card::FIVE = "Five of ";
const string Card::SIX = "Six of ";
const string Card::SEVEN = "Seven of ";
const string Card::EIGHT = "Eight of ";
const string Card::NINE = "Nine of ";
const string Card::TEN = "Ten of ";
const string Card::JACK = "Jack of ";
const string Card::QUEEN = "Queen of ";
const string Card::KING = "King of ";

Card::Card(int suit, int rank) {
	this->suit = suit;
	this->rank = rank;
	this->updateCardStr(suit, rank);
}

Card::~Card() {

}

int Card::getSuit() {
	return suit;
}

int Card::getRank() {
	return rank;
}

string Card::getCardStr() {
	return card_str;
}

bool Card::setSuit(int suit) {
	if(suit >= MIN_SUIT && suit <= MAX_SUIT) {
		this->suit = suit;
		updateCardStr(suit, rank);
		return true;
	}
	return false;
}

bool Card::setRank(int rank) {
	if(suit >= MIN_RANK && suit <= MAX_RANK) {
		this->rank = rank;
		updateCardStr(suit, rank);
		return true;
	}
	return false;
}

void Card::updateCardStr(int suit, int rank) {
	switch(rank)
    {
        case 1: card_str = ACE;
            break;
        case 2: card_str = TWO;
            break;
        case 3: card_str = THREE;
            break;
        case 4: card_str = FOUR;
            break;
        case 5: card_str = FIVE;
            break;
        case 6: card_str = SIX;
            break;
        case 7: card_str = SEVEN;
            break;
        case 8: card_str = EIGHT;
            break;
        case 9: card_str = NINE;
            break;
        case 10: card_str = TEN;
            break;
        case 11: card_str = JACK;
            break;
        case 12: card_str = QUEEN;
            break;
        case 13: card_str = KING;
			break;
		default: card_str = "UNK of ";
    }

    switch(suit) {
        case 1: card_str += SPADES;
            break;
        case 2: card_str += CLUBS;
            break;
        case 3: card_str += HEARTS;
            break;
        case 4: card_str += DIAMONDS;
			break;
		default: card_str = '0';
    }
}
