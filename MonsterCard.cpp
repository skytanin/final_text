#include "MonsterCard.h"

handcard::handcard(int no, int speed, string move_value, int attack_value,
	int range_value, int heal_value, int shield_value, char retake,vector<string> action)
{
	this->action_order = action;
	this->No = no;
	this->agility = speed;
	this->move = move_value;
	this->attack = attack_value;
	this->range = range_value;
	this->heal = heal_value;
	this->shield = shield_value;
	this->retake = retake;
	this->available = 1;
}
