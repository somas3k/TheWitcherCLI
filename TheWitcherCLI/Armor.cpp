#include "stdafx.h"
#include "Armor.h"


Armor::~Armor()
{
}

void Armor::action(Player *player)
{
}

int Armor::take_hit(int value)
{
	if (this->armor_value < 0) return value;
	this->armor_value -= value;
	if (this->armor_value < 0) return abs(this->armor_value);
	return 0;
}
