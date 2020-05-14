#pragma once
#include<iostream>
#include<vector>

using namespace std;

struct action_method
{
	string action;
	int value;

};

class CharacterCard
{
public:
	CharacterCard();
	CharacterCard(string, int);
	string getid();
	int getspeed();
	void AddTop(action_method);
	void AddUnder(action_method);
private:
	string id;
	int speed;
	vector<action_method>TopAction;
	vector<action_method>UnderAction;
};
