#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<unordered_map>
#include"Monster.h"
#include"OneMonster.h"
#include"MonsterStates.h"
#include"MonsterStatesIn.h"
using namespace std;


class AllMonster
{
public:
	AllMonster(vector<Monster> input);
	AllMonster() {};
	OneMonster GetOneMonster(char code);//輸入代號

	void UseCard();
	void End_This_Round();//reset
private:
	map<char, OneMonster> Game_Monster_list;//所有場上怪物
	unordered_map<string, Monster_states> Monster_states_list;//同種怪物共用狀態<name,states>
};
