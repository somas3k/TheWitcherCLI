#include "stdafx.h"
#include "Weapon.h"


Weapon::~Weapon()
{
}

void Weapon::action(Player *player)
{
	if (player->get_weapon() != nullptr) {
		Weapon* actual_weapon = player->get_weapon();
		player->get_items()->push_back(actual_weapon);
	}
	player->set_weapon(this);
	player->get_items()->remove(this);
	
}
