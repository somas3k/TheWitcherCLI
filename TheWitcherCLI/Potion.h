#pragma once
#include "Item.h"
#include "Player.h"


class Potion : public virtual Item
{
public:
	Potion(std::string name, double price, int healing_value) : Item(name, price) {
		this->healing_value = healing_value;
	}
	~Potion();
	virtual void action(Player *player);
protected:
	virtual void print(std::ostream &out) const {
		out << "Name: " << name  << " Healing value: " << healing_value;
	}
private:
	int healing_value;
};

