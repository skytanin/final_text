#pragma once
#include"Character.h"
#include"Monster.h"
#include"PlayCharacter.h"
#include "Map.h"
#include"GameMonster.h"
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class Game
{

public:
	Game();
	Game(char*, char*, char*); //release用
	Game(const char*, const char*, const char*); //debug用
	void Play();
	int action;
private:
	vector<Character> character_list;
	vector<Monster> monster_list;
	AllMonster allmonster;
};
