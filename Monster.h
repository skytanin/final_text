#pragma once
#include <string>
#include <vector>
#include"MonsterCard.h"

using namespace std;

class Monster
{
public:
	Monster(string name);
	void set_ordinary(int hp, int attack, int range);
	void set_elite(int e_hp, int e_attack, int e_range);
	void getcard(int no,int speed,string move_value,int attack_value,
		int range_value,int heal_value,int shield_value,char retake,vector<string>);
	struct MonsterStatus
	{
		int hp;
		int attack;
		int range;
	};
	friend class AllMonster;
	friend class Monster_states;
	friend class OneMonster;
private:
	string name;
	MonsterStatus ordinary;
	MonsterStatus elite;//äÅ‰p‰ö
	vector<handcard> cards;
};

