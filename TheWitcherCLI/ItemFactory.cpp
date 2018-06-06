#include "stdafx.h"
#include "ItemFactory.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"


ItemFactory::~ItemFactory()
{
}

std::list<Item*> ItemFactory::get_items_for_npc(int amount)
{
	std::list<Item*> items;
	int weapons_amount = (int) (amount * 0.3);
	int armors_amount = (int) (amount * 0.3);
	int potions_amount = amount - weapons_amount - armors_amount;
	srand((unsigned)time(NULL));

	for (int i = 0; i < weapons_amount; ++i) {
		int required_level = generate_random_item_level();
		int price = generate_random_price(100) * required_level;
		int hit = generate_hit(50) * required_level;
		std::string name = weapons_names[generate_random_index(weapons_size)];
		items.push_back(new Weapon(name, price, required_level, hit));
	}

	for (int i = 0; i < armors_amount; ++i) {
		int required_level = generate_random_item_level();
		int price = generate_random_price(100) * required_level;
		int armor = generate_hit(50) * required_level;
		items.push_back(new Armor(armors_names[generate_random_index(armors_size)], price, required_level, armor));
	}

	for (int i = 0; i < potions_amount; ++i) {
		int price = generate_random_price(100);
		int healing_value = price / 2;
		std::string name;
		if (price < 34) name = "Small Potion";
		else if (price < 67) name = "Medium Potion";
		else name = "Big Potion";
		items.push_back(new Potion(name, price, healing_value));
	}
	return items;

}

void ItemFactory::load_names()
{
	std::ifstream in(weaponsPath);	
	if (!in.bad()) 
	{
		weapons_size = (int) (std::count(std::istreambuf_iterator<char>(in),
			std::istreambuf_iterator<char>(), '\n') + 1);
		in.seekg(0, std::ios::beg);	//ustawia iterator do zczytywania na poczatku
		weapons_names = new std::string[weapons_size];
		std::string line;
		int index = 0;
		while (getline(in, line))
		{	
			weapons_names[index++] = line;
		}
	}
	in.close();

	std::ifstream in2(armorsPath);
	if (!in2.bad())
	{
		armors_size = (int) (std::count(std::istreambuf_iterator<char>(in2),
			std::istreambuf_iterator<char>(), '\n') + 1);
		armors_names = new std::string[armors_size];
		std::string line;
		in2.seekg(0, std::ios::beg);
		int index = 0;
		while (getline(in2, line))
		{
			armors_names[index++] = line;
		}
	}
	in2.close();
	

	

}
