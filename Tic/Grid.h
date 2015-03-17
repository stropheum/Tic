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
	void comp_turn_ai();
	void reset();

	bool game_over();

	int check_winner();

private:
	int check_horiz();
	int check_vert();
	int check_diag();

	void ai_diag_select(int &choice, bool &diag_found);
	void ai_horiz_select(int &choice, bool &horiz_found);
	void ai_vert_select(int &choice, bool &vert_found);
};

