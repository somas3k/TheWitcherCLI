#pragma once
#include "EquipmentItem.h"

class EquipmentItem;

class Player;

class Weapon : public virtual EquipmentItem
{
public:
	Weapon() {}
	Weapon(std::string name, double price, int required_level, int hit_value) : EquipmentItem(name, price, required_level) {
		this->hit_value = hit_value;
	}
	~Weapon();
	virtual void action(Player *player);
private:
	int hit_value;
};

