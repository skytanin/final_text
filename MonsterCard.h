#pragma once
#include<string>
#include<vector>
#include<iostream>

using namespace std;

class handcard
{
public:
	handcard(int no, int speed, string move_value, int attack_value,
		int range_value, int heal_value, int shield_value, char retake,vector<string>);
	int No;//•Òåj
	int agility;//•q·
	string move;
	int attack;
	int range;
	int heal;
	int shield;
	char retake;//dô
	bool available;// 1 ‰Â—p
	vector<string> action_order;
};