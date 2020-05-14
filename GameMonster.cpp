#include"GameMonster.h"

AllMonster::AllMonster(vector<Monster> input)//將讀檔放入遊戲
{
	/*
		每隻怪物放入
	*/
	for (auto monster:input)
	{
		this->Monster_states_list[monster.name] = Monster_states(monster);
	}
}

OneMonster AllMonster::GetOneMonster(char code)
{
	return Game_Monster_list[code];
}

void AllMonster::UseCard()
{
	for (auto& states : this->Monster_states_list)
	{
		states.second.UesCard();
	}
}

void AllMonster::End_This_Round()
{
	for (auto& a : Monster_states_list)
	{
		if (a.second.retake)
		{
			a.second.reset();
		}
	}
}
