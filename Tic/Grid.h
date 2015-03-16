#pragma once

#define GRID_SIZE 9
#define NULL_C ' '

using namespace std;

class Grid
{
public:
	char* array;
	char player_val;
	char comp_val;

	Grid();
	~Grid();

	void init();
	void print();
	void set_val(int, char);
	void input_select();
	void player_turn();
	void comp_turn();
	void reset();

	bool game_over();

	int check_winner();

private:
	int check_horiz();
	int check_vert();
	int check_diag();
};

