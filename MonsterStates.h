#pragma once
#include"GameMonster.h"
#include"OneMonster.h"
#include"MonsterStatesIn.h"
#include"Monster.h"
class Monster_states//每回合怪物狀態
{
public:
	Monster_states() {};
	Monster_states(Monster);
	void UesCard();
	void reset();
	inline string ReturnStates();
	bool retake;
private:
	void SetStatesString(handcard);
	string name;
	void input_states(Game_Monster_states&,Monster::MonsterStatus);
	void change_states(const Game_Monster_states& ordinary,Game_Monster_states &this_round,handcard card);
	vector<handcard> cards;
	Game_Monster_states ordinary_orginal;
	Game_Monster_states ordinary_elite;
	Game_Monster_states this_round_ordinary;
	Game_Monster_states this_round_elite;
};