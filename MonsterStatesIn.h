#pragma once
#include"GameMonster.h"
struct Game_Monster_states
{
	vector<string> action_list;
	string StatesString;
	int hp;//heal
	int shield;
	int attack;
	int range;
	int this_round_speed;
	string move;
	Game_Monster_states()
	{
		hp = 0;
		shield = 0;
		attack = 0;
		range = 0;
		this_round_speed = 0;
		move = "";
	}
};