#include "stdafx.h"
#include "Potion.h"


Potion::~Potion()
{
}

void Potion::action(Player *player)
{
	player->heal(healing_value);
	player->get_items()->remove(this);
}

