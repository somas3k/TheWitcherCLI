#pragma once
#include "NonPlayerCharacter.h"
#include <list>

class Player;

class NonPlayerCharacter;

class Item;

class Tradesman : public virtual NonPlayerCharacter

{
public:
	Tradesman(std::string name, list<Item*> offered_items) : NonPlayerCharacter(name), Person(name) {
		this->offered_items = offered_items;
		this->money = 1000;
	}
	virtual void interact_with_player(Player *player);
	~Tradesman();
private:
	list<Item*> offered_items;
	double money;
};

