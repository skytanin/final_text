#include "OneMonster.h"

OneMonster::OneMonster()
{
}

bool OneMonster::attack_this_one(int character_attack)
{
	this->hp = this->hp - ((character_attack - this->GetShield()) > 0 ? (character_attack - this->GetShield()) : 0);
	
	if (hp <= 0)
	{
		this->alive = 0;
		cout << code << " is killed!!"<<endl;
		return 1;
	}
	return 0;
}

void OneMonster::action()
{
	for (string str : this->states->action_list)
	{
		if (str == "attack")
		{
			attack();
		}
		else if(str=="heal")
		{
			heal();
		}
		else if (str == "shield")
		{
			shield();
		}
		else if (str == "move")
		{
			this->move();
		}
	}
}

void OneMonster::attack()
{
}

void OneMonster::heal()
{
	int tmp_hp = this->hp;
	tmp_hp += this->states->hp;
	this->hp = tmp_hp < this->orginal_states->hp ? tmp_hp : orginal_states->hp;
	cout << this->code << " heal" << this->states->hp << ", now hp is " << this->hp<<endl;
	getchar();
}

void OneMonster::move()
{
}

void OneMonster::shield()
{
	cout << code << " shield " << this->states->shield << "this turn"<<endl;
	getchar();
}
