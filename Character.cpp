#include "Character.h"

Character::Character()
{
	exit(1);
};
Character::Character(string _name, int _hp, int _alpha_card)
{
	name = _name;
	hp = _hp;
	alpha_card = _alpha_card;
};

void Character::AddCard(CharacterCard reg)
{
	owncard.push_back(reg);
};
CharacterCard Character::getCard(string str)
{
	CharacterCard reg;
	for (int i = 0; i < (int)owncard.size(); i++)
	{
		if (owncard[i].getid() == str)
			return owncard[i];
	}
	return reg;
};
int Character::getalpha_card()
{
	return alpha_card;
};

int Character::gethp()
{
	return hp;
}
string Character::getname()
{
	return name;
}
;
