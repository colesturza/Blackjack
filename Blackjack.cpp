/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  Blackjack.cpp
 */

#include "Blackjack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int findMaxIndex(vector<int> v) {
    int max_score = -1;
    int max_index = -1;
    for(int i = 0; i < (int)v.size(); i++) {
        if(v[i] > max_score && v[i] <= 21) {
            max_score = v[i];
            max_index = i;
        }
    }
    return max_index;
}

void tieIndices(vector<int> v, vector<int> tie_indices, int num) {
    for(int i = 0; i < (int)v.size(); i++) {
        if(v[i] == num) {
            tie_indices.push_back(i);
        }
    }
}

Blackjack::Blackjack() {

}

Blackjack::Blackjack(Player player1, vector<Opponent> opponents, int num_of_rounds, string filename) {
	this->player1 = player1;
	this->opponents = opponents;
	this->num_of_rounds = num_of_rounds;
	game_save_name = filename;
	round = 0;
}

Blackjack::Blackjack(string filename) {
	game_save_name = filename;
	game_deck.resetDeck();
	this->loadPreviousGame(filename);
}

Blackjack::~Blackjack() {

}

void Blackjack::dealCards() {
    
    for(int i = 0; i < (rand() % (100-10) + 10); i++)
        this->game_deck.shuffle();
    
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < (int)opponents.size() + 1; j++) {
			Card temp(0, 0);
            
			if(j < (int)opponents.size())
				temp = this->dealCard(j);
			else
				temp = this->dealCard();
			
            if(i == 0) {
				visible_cards.push_back(temp);
				discarded_cards.push_back(temp);
			}
			else {
				discarded_cards.push_back(temp);
			}
		}
	}
}

Card Blackjack::dealCard(int player_index) {
    Card temp(0, 0);
    temp = game_deck.drawCard();
    opponents[player_index].addCard(temp);
    return temp;
}

Card Blackjack::dealCard() {
    Card temp(0, 0);
    temp = game_deck.drawCard();
    player1.addCard(temp);
    return temp;
}

void Blackjack::askPlayersToHit() {
    bool player_pass = false;
	bool pass[(int)opponents.size()];
	for(int i = 0; i < (int)opponents.size(); i++) {
		pass[i] = false;
	}
    
	bool all_players_pass = false;
    
	while(!all_players_pass) {
        if(player_pass == false && util::calcScore(player1.getHand()) <= 21) {
			string input;
			cout << "\nDo you want to hit or pass? (type p to pass, otherwise you'll hit):\n";
			cin >> input;

			if(input == "p") {
				player_pass = true;
			}
			else {
                Card temp(0, 0);
				temp = this->dealCard();
                discarded_cards.push_back(temp);
			}
		}
        else
            player_pass = true;

		for(int i = 0; i < (int)opponents.size(); i++) {
			if(pass[i] == false) {
				pass[i] = !opponents[i].desideHit(visible_cards);
				if(pass[i] == false) {
					cout << "Opponent " << i+1 << " hit.\n";
					cout << endl;
                    Card temp(0, 0);
					temp = this->dealCard(i);
                    discarded_cards.push_back(temp);
				}
				else {
                    pass[i] = true;
					cout << "Opponent " << i+1 << " passed.\n";
					cout << endl;
				}
			}
		}
        
        this->printGameState();
        cout << endl;
        cout << endl;
        
        if(player_pass == true)
            all_players_pass = true;
		for(int i = 0; i < (int)opponents.size(); i++) {
			if(pass[i] == false) {
				all_players_pass = false;
			}
		}
	}
}

Player Blackjack::getRoundWinner() {
    vector<int> scores;
	for(int i = 0; i < (int)opponents.size(); i++) {
		scores.push_back(util::calcScore(opponents[i].getHand()));
	}
    scores.push_back(util::calcScore(player1.getHand()));
    
    int max_score_index = findMaxIndex(scores);

	player1.resetHand();

	for(int i = 0; i < (int)opponents.size(); i++) {
		opponents[i].resetHand();
	}

    visible_cards.clear();
    
	if((int)game_deck.getDeck().size() <= 15) {
		game_deck.resetDeck();
		game_deck.fillDeck();
		discarded_cards.clear();
		cout << "The deck has been reset.\n";
	}
	round++;

    if((int)opponents.size() > max_score_index) {
        return opponents[max_score_index].getName();
    }
    return player1;
}

Player Blackjack::getGameWinner() {
	vector<int> scores;
	scores.push_back(util::calcScore(player1.getHand()));
	for(int i = 0; i < (int)opponents.size(); i++) {
		scores.push_back(opponents[i].getPoints());
	}

    return player1;
}

int Blackjack::getRound(){
	return round;
}

int Blackjack::getNumOfRounds(){
	return num_of_rounds;
}

void Blackjack::printGameState() {
    for(int j = 0; j < 35; j++) {
        cout << "*";
    }
    cout << endl;
    cout << player1.getName() << "'s Hand:" << endl;
    vector<Card> temp = player1.getHand();
    for(int i = 0; i < (int)temp.size(); i++) {
        cout << temp[i].getCardStr() << endl;
    }
    for(int i = 0; i < (int)opponents.size(); i++) {
        for(int j = 0; j < 35; j++) {
            cout << "*";
        }
        cout << endl;
        cout << opponents[i].getName() << "'s Hand:" << endl;
        temp = opponents[i].getHand();
        for(int j = 0; j < (int)temp.size(); j++) {
            if(util::findCard(temp[j], visible_cards) != -1)
                cout << temp[j].getCardStr() << endl;
            else
                cout << "blank" << endl;
        }
    }
    for(int j = 0; j < 35; j++) {
        cout << "*";
    }
    cout << endl;
}

void Blackjack::printGameStateEOR() {
    for(int j = 0; j < 35; j++) {
        cout << "*";
    }
    cout << endl;
    cout << player1.getName() << "'s Hand:" << endl;
    vector<Card> temp = player1.getHand();
    for(int i = 0; i < (int)temp.size(); i++) {
        cout << temp[i].getCardStr() << endl;
    }
    for(int i = 0; i < (int)opponents.size(); i++) {
        for(int j = 0; j < 35; j++) {
            cout << "*";
        }
        cout << endl;
        cout << opponents[i].getName() << "'s Hand:" << endl;
        temp = opponents[i].getHand();
        for(int j = 0; j < (int)temp.size(); j++) {
            cout << temp[j].getCardStr() << endl;
        }
    }
    for(int j = 0; j < 35; j++) {
        cout << "*";
    }
    cout << endl;
}

void Blackjack::saveGame() {
	ofstream file_out;
	file_out.open(game_save_name, ios::out | ios::trunc);

	//Round number
	file_out << round << "\n";

	//Last round number
	file_out << num_of_rounds << "\n";

	//Players names
	file_out << player1.getName() << ", ";
	for(int i = 0; i < (int)opponents.size(); i++) {
		if(i < (int)opponents.size() - 1)
			file_out << opponents[i].getName() << ", ";
		else
			file_out << opponents[i].getName() << "\n";
	}

	//Players points
	file_out << player1.getPoints() << ", ";
	for(int i = 0; i < (int)opponents.size(); i++) {
		if(i < (int)opponents.size() - 1)
			file_out << opponents[i].getPoints() << ", ";
		else
			file_out << opponents[i].getPoints() << "\n";
	}

	//Opponents difficulty
	for(int i = 0; i < (int)opponents.size(); i++) {
		if(i < (int)opponents.size() - 1)
			file_out << opponents[i].getDiff() << ", ";
		else
			file_out << opponents[i].getDiff() << "\n";
	}

	//Discarded Cards
	for(int i = 0; i < (int)discarded_cards.size(); i++) {
		if(i < (int)opponents.size() - 1)
			file_out << discarded_cards[i].getSuit() << "\t" << discarded_cards[i].getRank() << ", ";
		else
			file_out << discarded_cards[i].getSuit() << "\t" << discarded_cards[i].getRank() << "\n";
	}

	//Game Deck
	for(int i = 0; i < (int)game_deck.getDeck().size(); i++) {
		if(i < (int)opponents.size() - 1)
			file_out << game_deck.getCard(i).getSuit() << "\t" << game_deck.getCard(i).getRank() << ", ";
		else
			file_out << game_deck.getCard(i).getSuit() << "\t" << game_deck.getCard(i).getRank() << "\n";
	}

	file_out.close();

}

Card makeCard(string str) {
	int s = str.front();
	int r = str.back();
	Card temp(s, r);
	return temp;
}

void Blackjack::loadPreviousGame(string filename) {
	ifstream file_in;
	file_in.open(game_save_name);
	if(file_in.fail()) {
		cout << "failed to load game.";
		exit(EXIT_FAILURE);
	}

	string line;

	//Round number
	getline(file_in, line, '\n');
	this->round = stoi(line);

	line = "";

	//Last round number
	getline(file_in, line, '\n');
	this->num_of_rounds = stoi(line);

	line = "";

	//Players names
	vector<string> names;
	getline(file_in, line);
	util::split(line, ',', names);
	int num_of_players = (int)names.size();

	line = "";

	//Players points
	string points[num_of_players];
	getline(file_in, line, '\n');
	util::split(line, ',', points, num_of_players);

	line = "";

	//Opponents difficulty
	string difficulties[num_of_players - 1];
	getline(file_in, line, '\n');
	util::split(line, ',', points, num_of_players - 1);

	Player temp(names[0], stoi(points[0]));
	player1 = temp;

	for(int i = 1; i < num_of_players; i++) {
		Opponent temp(names[i], stoi(difficulties[i-1]), stoi(points[i]));
		opponents.push_back(temp);
	}

	line = "";

	//Discarded Cards
	vector<string> dis_cards;
	getline(file_in, line);
	util::split(line, ',', dis_cards);

	for(int i = 0; i < (int)dis_cards.size(); i++) {
		discarded_cards.push_back(makeCard(dis_cards[i]));
	}

	line = "";

	//Game Deck
	vector<string> g_deck;
	getline(file_in, line);
	util::split(line, ',', g_deck);

	for(int i = 0; i < (int)g_deck.size(); i++) {
		game_deck.addCard(makeCard(g_deck[i]));
	}

	file_in.close();
}
