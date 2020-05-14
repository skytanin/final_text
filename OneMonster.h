#pragma once
#include"GameMonster.h"
#include"MonsterStates.h"
#include"MonsterStatesIn.h"
class OneMonster
{
public:
	OneMonster();
	struct Position
	{
		int row;
		int col;
	};
	bool attack_this_one(int character_attack);//”í‘Å return ¥”ÛŽ€–S 1=Ž€
	int GetShield()
	{
		return states->shield;
	}
	bool alive;// 1=alive
	string name;
	char code;//‘ãåj
	int hp;
	void action();
private:
	Position position;
	const Game_Monster_states* orginal_states;
	const Game_Monster_states* states;
	void attack();
	void heal();
	void move();
	void shield();
};