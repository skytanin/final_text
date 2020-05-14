#pragma once
#include<iostream>
#include<vector>
#include"CharacterCard.h"

using namespace std;

class Character
{
public:
	Character();
	Character( string , int , int );
	void AddCard(CharacterCard);
	CharacterCard getCard( string str);
	int getalpha_card();
	int gethp();
	string getname();
private:
	string name;
	int hp;
	int alpha_card;
	vector<CharacterCard>owncard;
};
