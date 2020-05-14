#include "MonsterStates.h"

Monster_states::Monster_states(Monster input)
{
	this->cards = input.cards;
	input_states(this->ordinary_orginal, input.ordinary);
	input_states(this->this_round_ordinary, input.ordinary);
	input_states(this->ordinary_elite, input.elite);
	input_states(this->this_round_elite, input.elite);
	this->name = input.name;
	retake = 0;
}

void Monster_states::UesCard()
{
	//debug mode
	for (auto &card : this->cards)
	{
		if (card.available)
		{
			SetStatesString(card);
			change_states(ordinary_orginal, this_round_ordinary, card);
			change_states(ordinary_elite, this_round_elite, card);
			card.available = 0;
			if (card.retake == 'r') 
				this->retake = 1;
			else
			{
				this->retake = 0;
			}
			break;
		}
	}
	//end
}

void Monster_states::reset()
{
	for (auto& card : cards)
	{
		card.available = 1;
	}
}

inline string Monster_states::ReturnStates()
{
	return this->this_round_ordinary.StatesString;
}


void Monster_states::SetStatesString(handcard card)
{
	string re;
	re = name + " "+to_string(card.agility);
	for (string str : card.action_order)
	{
		if (str == "attack")
		{
			re += " "+str + " " + to_string(card.attack);
		}
		else if (str == "heal")
		{
			re += " " + str + " " + to_string(card.heal);
		}
		else if (str == "shield")
		{
			re += " " + str + " " + to_string(card.shield);
		}
		else if (str == "move")
		{
			re += " " + str + " "+card.move;
		}
		else if (str == "range")
		{
			re += " " + str + " " + to_string(card.range);
		}
	}
	this->this_round_ordinary.StatesString = re;
	this->this_round_elite.StatesString = re;
}

void Monster_states::input_states(Game_Monster_states& a, Monster::MonsterStatus input)
{
	a.attack = input.attack;
	a.hp = input.hp;
	a.range = input.range;
	a.shield = 0;
	a.this_round_speed = 0;
}

void Monster_states::change_states(const Game_Monster_states& ordinary, Game_Monster_states &this_round, handcard card)
{
	this_round.attack = ordinary.attack+card.attack;
	this_round.range = ordinary.range + card.range;
	this_round.shield = card.shield;
	this_round.hp = card.heal;
	this_round.move = card.move;
	this_round.this_round_speed = card.agility;
	this_round.action_list = card.action_order;
}

