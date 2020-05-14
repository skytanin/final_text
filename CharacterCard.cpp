#include "CharacterCard.h"

CharacterCard::CharacterCard()
{
	id = "";
	speed = 0;
}
CharacterCard::CharacterCard(string _id, int _speed)
{
	id = _id;
	speed = _speed;
};
string CharacterCard::getid()
{
	return id;
};
int CharacterCard::getspeed()
{
	return speed;
};

void CharacterCard::AddTop(action_method reg)
{
	TopAction.push_back(reg);
};
void CharacterCard::AddUnder(action_method reg)
{
	UnderAction.push_back(reg);
};
