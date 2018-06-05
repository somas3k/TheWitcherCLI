#include "stdafx.h"
#include "Weapon.h"


Weapon::~Weapon()
{
}

void Weapon::action(Player *player)
{
	Weapon* actual_weapon = player->get_weapon();
	player->set_weapon(this);
	player->get_items()->remove(this);
	player->get_items()->push_back(actual_weapon);
}
