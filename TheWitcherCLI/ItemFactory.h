#pragma once
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Item.h"
#include "Utils.h"
class ItemFactory
{
public:
	ItemFactory(std::string wPath, std::string aPath) : weaponsPath(wPath), armorsPath(aPath) { load_names(); }
	~ItemFactory();

	std::list<Item*> get_items_for_npc(int amount);
private:
	std::string weaponsPath;
	std::string armorsPath;	
	std::string *weapons_names;
	int weapons_size;

	std::string *armors_names;
	int armors_size;
	void load_names();
};

