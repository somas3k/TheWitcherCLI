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

class Player : public KillablePerson
{
public:	
	Player(std::string name, list<Item> *items) : KillablePerson(name) { 
		this->items = items;
		this->money = 100;
		this->experience = 0;
	}
	~Player();
	void fight_with(Enemy *enemy);
private:
	double money;
	int experience;
	Weapon *weapon;
	Armor *armor;
	std::list<Item> *items;
};
