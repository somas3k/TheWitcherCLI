#pragma once
#include "EquipmentItem.h"

class EquipmentItem;

class Player;

class Armor : public virtual EquipmentItem
{
public:
	Armor() {}
	Armor(std::string name, double price, int required_level, int armor_value) : EquipmentItem(name, price, required_level) {
		this->armor_value = armor_value;
	}
	~Armor();
	virtual void action(Player *player);
private:
	int armor_value;
};

