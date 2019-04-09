/*! Cole Sturza
 *  Recitation: 123 – Thomas Lillis
 *  Assignment 8
 *  main.cpp
 */

#include <iostream>
#include <cstdlib>
#include "Blackjack.h"

using namespace std;

int main() {
    Blackjack game;

	string input;
    cout << "Hello, Welcome to Blackjack, would you like to load a game or play a new one? (enter 1 to load a game, anything else starts a new one)." << endl;
	cin >> input;

	// Loads a old game.
	if(input == "1") {
		string input;
		cout << "Enter the filename." << endl;
		cin >> input;
		Blackjack game1(input);
		game = game1;
	}
	// Makes a new game.
	else {
		cout << "Enter your name." << endl;
		cin.ignore();
        getline(cin, input);
		Player player1(input);

		int num;
		cout << "Enter a number for opponents. (1-5, anything else and there will be 5 opponents :) )." << endl;
		cin >> num;
		if(!(num >= 1 && num <= 5)) {
			num = 5;
		}

		int num2;
		cout << "Enter a number of rounds. I'm not going to stop you from entering 1,000,000,000,000,000,000. :)" << endl;
		cin >> num2;

        string input2;
		cout << "Enter a filename." << endl;
		cin >> input2;

		vector<Opponent> opponents;

		string botname;
		int diff;

		for(int i = 1; i < num + 1; i++) {
            cout << "Enter a name for opponent " << i << ".\n";
            cin.ignore();
            getline(cin, botname);
			cout << "Enter a difficulty. (1-4, anything else and there will be 4 opponents).\n";
            cin >> diff;
			if(!(diff >= 1 && diff <= 4)) {
				diff = 4;
			}
            Opponent temp(botname, diff);
            opponents.push_back(temp);
		}

		Blackjack game1(player1, opponents, num2, input2);
		game = game1;
	}

    
    while (game.getRound() < game.getNumOfRounds()) {
        game.dealCards();
        game.printGameState();
        game.askPlayersToHit();
        game.printGameStateEOR();
        Player temp;
        temp = game.getRoundWinner();
        cout << temp.getName() << " wins round " << game.getRound() << endl;
        if(game.getRound() != game.getNumOfRounds()) {
            cout << "do you want to play another round? (enter y, anything else will end the game and save.)" << endl;
            cin >> input;
            if(input != "y") {
                game.saveGame();
                return 0;
            }
        }
    }

    Player temp;
    temp = game.getGameWinner();

    cout << temp.getName() << " wins!!!!";

    return 0;
}
