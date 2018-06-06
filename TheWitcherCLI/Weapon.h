#pragma once
#include "EquipmentItem.h"
#include "Utils.h"
#include "Player.h"

class EquipmentItem;

class Weapon : public virtual EquipmentItem
{
public:
	Weapon() {}
	Weapon(std::string name, double price, int required_level, int hit_value) : EquipmentItem(name, price, required_level) , Item(name, price) {
		this->hit_value = hit_value;
	}
	~Weapon();
	virtual void action(Player *player);
	int get_hit() { return generate_hit(hit_value); }
	virtual void print(std::ostream &out) const {
		out << "Name: " << name << " Req Level: " << required_level << " Hit value: " << hit_value;
	}
	
private:
	int hit_value;
};

