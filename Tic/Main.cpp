#include <iostream>
#include <string>
#include <time.h>
#include "Grid.h"

void flip_coin();
void main_loop();
void disp_winner();
void cap(string&);

Grid grid;

bool p_first; // Determines if player goes first or second

int main() {
	bool play_again = true;
	string replay;
	while (play_again) {
		grid.reset(); // Reset grid

		flip_coin();
		grid.input_select();
		main_loop();
		disp_winner();
		cout << "Would you like to play again?(Yes/No): " << endl;
		cin >> replay;
		cap(replay);
		if (replay.compare("NO") == 0) {
			cout << "Thanks for playing!" << endl;
			play_again = false;
		}
	}
	system("PAUSE");
}

// The main game loop
void main_loop() {
	while (grid.check_winner() == 0) {
		if (p_first) {
			system("CLS");
			grid.print();
			grid.player_turn();
			if (grid.check_winner() == 1 || grid.check_winner() == -1 || grid.game_over()) {
				break;
			}
			grid.comp_turn();
			system("CLS");
			grid.print();
			if (grid.check_winner() == 1 || grid.check_winner() == -1 || grid.game_over()) {
				break;
			}
		}
		else {
			system("CLS");
			grid.comp_turn();
			grid.print();
			if (grid.check_winner() == 1 || grid.check_winner() == -1 || grid.game_over()) {
				break;
			}
			grid.player_turn();
			system("CLS");
			grid.print();
			if (grid.check_winner() == 1 || grid.check_winner() == -1 || grid.game_over()) {
				break;
			}
		}
	}
}

// Displays winner upon game completion
void disp_winner() {
	system("CLS");
	grid.print();
	if (grid.check_winner() == 1) {
		cout << "Congratulations, You've won!" << endl;
	}
	else if (grid.check_winner() == -1) {
		cout << "You Lose. Better luck next time" << endl;
	}
	else {
		cout << "The game is a tie! Everyone wins" << endl;
	}
	system("PAUSE");
}

void flip_coin() {
	srand(time(NULL));
	bool is_valid = false;
	string input;
	int result;

	while (!is_valid) {
		cout << "Choose heads or tails: " << endl;
		cin.clear();
		fflush(stdin);
		getline(cin, input);
		cap(input);
		if (input.compare("HEADS") == 0 || 
			input.compare("TAILS") == 0) {
			is_valid = true;
		}
		else {
			cout << "Invalid input(coin flip). Try again" << endl;
		}
	}
	result = rand() % 2;
	if (result == 0 && input.compare("TAILS") == 0 ||
		result == 1 && input.compare("HEADS") == 0) {
		p_first = true;
		cout << "You have won the toss. You will go first" << endl;
	}
	else {
		p_first = false;
		cout << "You have lost the toss. The computer will go first" << endl;
	}
	system("PAUSE");
}

// Converts a string to all caps
void cap(string &input) {
	for (int i = 0; i < input.size(); i++) {
		input.at(i) = toupper(input.at(i));
	}
}
