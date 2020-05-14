#include "PlayCharacter.h"

PlayCharacter::PlayCharacter(string _name, int _hp)
{
	name = _name;
	maxhp = _hp;
	hp = _hp;
	shield = 0;
};


PlayCharacter::PlayCharacter()
{
};

PlayCharacter::~PlayCharacter()
{
};

void PlayCharacter::AddCard(CharacterCard reg)
{
	owncard.push_back(reg);
};
int PlayCharacter::gethp()
{
	return hp;
}
;

int PlayCharacter::getmaxhp()
{
	return maxhp;
}
;

int PlayCharacter::getshield()
{
	return shield;
}
;
