#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Grid.h"

Grid::Grid() {
	init();
}

Grid::~Grid() {
	free(array);
}

// Initializes the grid with null character values
void Grid::init() {
	array = (char*)malloc(sizeof(char) * GRID_SIZE);
	for (int i = 0; i < GRID_SIZE; i++) {
		array[i] = NULL_C;
	}
}

// Displays the grid on the console in its current state
void Grid::print() {
	for (int i = 0; i < GRID_SIZE; i += 3) {
		cout << "|||||||||||\n" << 
			"||" << array[i] << 
			"||" << array[i + 1] << 
			"||" << array[i + 2] << 
			"||" << endl;
	}
	cout << "|||||||||||\n" << endl;
}

// Change a value on the grid
void Grid::set_val(int cell, char val) {
	array[cell] = val;
}

// User selects X or O
void Grid::input_select() {
	char p_choice;
	bool is_valid = false;
	while (!is_valid) {
		cout << "Choose your weapon(X/O): " << endl;
		cin >> p_choice;
		if (toupper(p_choice) == 'X') {
			player_val = 'X';
			comp_val = 'O';
			is_valid = true;
		}
		else if (toupper(p_choice) == 'O') {
			player_val = 'O';
			comp_val = 'X';
			is_valid = true;
		}
		else {
			cout << "invalid input(input select). Try again" << endl;
		}
	}
}

// Player takes a turn
void Grid::player_turn() {
	int choice;
	bool is_valid = false;
	while (!is_valid) {
		cout << "Choose a cell(0-8): " << endl;
		cin >> choice;
		if (choice >= 0 && choice < 9 && array[choice] == NULL_C) {
			is_valid = true;
		}
		else {
			cout << "Invalid input(player turn). Try again" << endl;
		}
	}
	set_val(choice, player_val);
}

// Computer Generates a random choice and sets value
void Grid::comp_turn() {
	srand(time(NULL));
	bool is_valid = false;
	int choice;
	while (!is_valid) {
		choice = rand() % 9;
		if (choice >= 0 && choice < 9 && array[choice] == NULL_C) {
			is_valid = true;
		}
	}
	set_val(choice, comp_val);
}

void Grid::reset() {
	for (int i = 0; i < GRID_SIZE; i++) {
		array[i] = NULL_C;
	}
}

// Checks if all possible options have been selected
bool Grid::game_over() {
	bool result = true;
	for (int i = 0; i < GRID_SIZE; i++) {
		if (array[i] == NULL_C) {
			result = false;
		}
	}
	return result;
}

// Return 1 if player wins. -1 if computer wins. 0 if neither
int Grid::check_winner() {
	int result = 0;
	
	if (check_horiz() == 1 || check_vert() == 1 || check_diag() == 1) {
		result = 1;
	}
	else if (check_horiz() == -1 || check_vert() == -1 || check_diag() == -1) {
		result = -1;
	}
	return result;
}

// Return 1 for player win condition, -1 for comp win condition, 0 for neither
int Grid::check_horiz() {
	int result = 0;

	for (int i = 0; i < 3; i+= 3) {
		if (array[i] == player_val &&
			array[i + 1] == player_val &&
			array[i + 2] == player_val) {
			result = 1;
		} else if (array[i] == comp_val &&
			array[i + 1] == comp_val &&
			array[i + 2] == comp_val) {
			result = -1;
		}
	}
	return result;
}

// Return 1 for player win condition, -1 for comp win condition, 0 for neither
int Grid::check_vert() {
	int result = 0;
	
	for (int i = 0; i < 3; i++) {
		if (array[i] == player_val &&
			array[i + 3] == player_val &&
			array[i + 6] == player_val) {
			result = 1;
		}
		else if (array[i] == comp_val &&
			array[i + 3] == comp_val &&
			array[i + 6] == comp_val) {
			result = -1;
		}
	}
	return result;
}

// Return 1 for player win condition, -1 for comp win condition, 0 for neither
int Grid::check_diag() {
	int result = 0;
	
	if ((array[0] == player_val && array[4] == player_val && array[8] == player_val) || 
		(array[2] == player_val && array[4] == player_val && array[6] == player_val)) {
		result = 1;
	}
	else if ((array[0] == comp_val && array[4] == comp_val && array[8] == comp_val) || 
		(array[2] == comp_val && array[4] == comp_val && array[6] == comp_val)) {
		result = -1;
	}
	return result;
}
