#pragma once
#include "Item.h"

class Item;

class Player;

class EquipmentItem : public virtual Item
{
public:
	EquipmentItem() {}
	EquipmentItem(std::string name, double price, int required_level) : Item(name, price) {
		this->required_level = required_level;
	}
	~EquipmentItem();
	virtual void action(Player *player) = 0;
private:
	int required_level;
};

