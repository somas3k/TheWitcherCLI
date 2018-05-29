#pragma once
#include "Item.h"

class Item;

class Player;

class Potion : public virtual Item
{
public:
	Potion(std::string name, double price, int healing_value) : Item(name, price) {
		this->healing_value = healing_value;
	}
	~Potion();
	virtual void action(Player *player);
private:
	int healing_value;
};

