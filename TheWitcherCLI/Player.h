#pragma once
#include <list>
#include <string>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "KillablePerson.h"
#include "Enemy.h"

class KillablePerson;

class Item;

class Weapon;

class Armor;

class Enemy;

class Location;

class Player : public KillablePerson
{
private:
	double money;
	int experience;
	Weapon *weapon;
	Armor *armor;
	std::list<Item*> items;
	Location *actual_location;
public:	
	Player(std::string name, list<Item*> items) : KillablePerson(name), Person(name) { 
		this->items = items;
		this->money = 100;
		this->experience = 0;
	}
	~Player();
	void set_location(Location *location) { actual_location = location; }
	virtual bool take_attack(int attack_value);
	virtual int hit_value();
	void set_weapon(Weapon *weapon) { this->weapon = weapon; }
	void add_exp(int exp) { this->experience += exp; }
	void set_armor(Armor *armor) { this->armor = armor; }
	Weapon* get_weapon() { return weapon;}
	Armor* get_armor() { return armor; }
	std::list<Item*> *get_items() { return &items; }
	Location* get_actual_location() {return actual_location;}
	friend ostream & operator<< (ostream &out, const Player &p) {
		out << "Name: " << p.name << " HP: " << p.hp << " Level: " << p.level << " EXP: " << p.experience << " ";
		/*if (p.weapon != nullptr) {
			out << (*p.weapon).name << " ";
		}
		if (p.armor != nullptr) {
			out << p.armor->name;
		}*/
		return out;
	}


};

