#pragma once
#include "EquipmentItem.h"

class Item;

class Player;

class Armor : public virtual EquipmentItem
{
public:
	Armor(std::string name, double price, int required_level, int armor_value) : EquipmentItem(name, price, required_level), Item(name, price) {
		this->armor_value = armor_value;
	}
	~Armor();
	virtual void action(Player *player);
	int get_armor_value() { return armor_value; }
	int take_hit(int value);
private:
	int armor_value;
};

