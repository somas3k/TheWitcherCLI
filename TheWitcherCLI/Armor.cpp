#include "stdafx.h"
#include "Armor.h"


Armor::~Armor()
{
}

void Armor::action(Player *player)
{	
	Armor* actual_armor = player->get_armor();
	player->set_armor(this);
	player->get_items()->remove(this);
	player->get_items()->push_back(actual_armor);
}

int Armor::take_hit(int value)
{
	if (this->armor_value < 0) return value;
	this->armor_value -= value;
	if (this->armor_value < 0) return abs(this->armor_value);
	return 0;
}
