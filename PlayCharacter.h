#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include"CharacterCard.h"

struct Point
{
	int x;
	int y;
};

class PlayCharacter
{
public:
	PlayCharacter();
	~PlayCharacter();
	PlayCharacter(string, int);
	void AddCard(CharacterCard);
	Point location;
	int gethp();
	int getmaxhp();
	int getshield();
private:
	string name;
	int maxhp;
	int hp;
	int shield;
	vector<CharacterCard>owncard;
};
