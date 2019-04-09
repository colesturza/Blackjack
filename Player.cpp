/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  Player.cpp
 */

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
    name = "UNK";
}

Player::Player(string name) {
	this->name = name;
	points = 0;
}

Player::Player(string name, int points) {
	this->name = name;
	this->points = points;
}

Player::~Player() {

}

void Player::addCard(Card card) {
	my_hand.push_back(card);
}

vector<Card> Player::getHand() {
	return my_hand;
}

int Player::getPoints() {
	return points;
}

string Player::getName() {
    return name;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::addPoint() {
	points++;
}

void Player::resetHand() {
	my_hand.clear();
}
