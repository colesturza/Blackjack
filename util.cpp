/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  util.cpp
 */

#include "util.h"

namespace util {
	void split(string sentence, char sep, vector<string> v) {
		string str = sentence;
		stringstream ss(str);

		while(v.back().back() != '\n') {
			string temp;
			getline(ss, temp, sep);
			v.push_back(temp);
		}

		v.back().pop_back();
	}

	void split(string sentence, char sep, string arr[], int size) {
		string str = sentence;
		stringstream ss(str);

		for(int i = 0; i < size; i++) {
			string temp;
			getline(ss, temp, sep);
			arr[i] = temp;
		}
	}

	int calcScore(vector<Card> player_hand) {
		int totalScore = 0;
		bool is_ace = false;

		for(int i = 0; i < (int)player_hand.size(); i++) {
			int value = player_hand[i].getRank();
            if(value == 1) {
				is_ace = true;
			}
			if(value > 10) {
				value = 10;
			}
			totalScore += value;
		}

		if(is_ace && totalScore + 10 <= 21) {
			totalScore += 10;
		}

		return totalScore;
	}

	int findCard(Card c, vector<Card> v) {

		for(int i = 0; i < (int)v.size(); i++) {
			if(c.getSuit() == v[i].getSuit() && c.getRank() == v[i].getRank()) {
				return i;
			}
		}

		return -1;
	}
}
