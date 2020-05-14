#include "Monster.h"

Monster::Monster(string name)
{
	this->name = name;
}

void Monster::set_ordinary(int hp, int attack, int range)
{
	this->ordinary.hp = hp;
	this->ordinary.attack = attack;
	this->ordinary.range = range;
}

void Monster::set_elite(int e_hp, int e_attack, int e_range)
{
	this->elite.hp = e_hp;
	this->elite.attack = e_attack;
	this->elite.range = e_range;
}

void Monster::getcard(int no, int speed, string move_value, int attack_value,
	int range_value, int heal_value, int shield_value, char retake,vector<string> action)
{
	cards.push_back(handcard(no,speed,move_value,attack_value,range_value,heal_value,shield_value,retake,action));
}
