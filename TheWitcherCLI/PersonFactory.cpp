#include "stdafx.h"
#include "PersonFactory.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Utils.h"


Riddler * PersonFactory::generate_riddler()
{
	std::string riddle = riddles[generate_random_index(riddles_size)];
	std::vector<std::string> tokens = split(riddle, ':');
	if (tokens.size() == 2) {
		int gaining_experience = generate_hit(100);
		return new Riddler(std::string("Riddler"), gaining_experience, tokens.at(0), tokens.at(1));
	}
	return nullptr;
}

Wiseman * PersonFactory::generate_wiseman()
{
	std::string wisdom = wisdoms[generate_random_index(wisdoms_size)];
	return new Wiseman("Wiseman", wisdom);
}

list<Enemy*> PersonFactory::generate_enemies(int amount)
{
	std::list<Enemy*> enemies_list;
	for (int i = 0; i < amount; ++i) {
		std::string name = enemies[generate_random_index(enemies_size)];
		int gaining_exp = generate_hit(100);
		enemies_list.push_back(new Enemy(name, gaining_exp));
	}
	return enemies_list;
}

Tradesman* PersonFactory::generate_tradesman()
{
	
	return new Tradesman("Tradesman", item_factory.get_items_for_npc(30));
}

PersonFactory::~PersonFactory()
{
}

void PersonFactory::load()
{
	std::ifstream in(riddles_path);
	if (!in.bad())
	{
		riddles_size = (int)(std::count(std::istreambuf_iterator<char>(in),
			std::istreambuf_iterator<char>(), '\n') + 1);
		in.seekg(0, std::ios::beg);
		riddles = new std::string[riddles_size];
		std::string line;
		int index = 0;
		while (getline(in, line))
		{
			riddles[index++] = line;
		}
	}
	in.close();

	std::ifstream in2(wisdoms_path);
	if (!in2.bad())
	{
		wisdoms_size = (int)(std::count(std::istreambuf_iterator<char>(in2),
			std::istreambuf_iterator<char>(), '\n') + 1);
		in2.seekg(0, std::ios::beg);
		wisdoms = new std::string[wisdoms_size];
		std::string line;
		int index = 0;
		while (getline(in2, line))
		{
			wisdoms[index++] = line;
		}
	}
	in2.close();

	std::ifstream in3(enemies_path);
	if (!in2.bad())
	{
		enemies_size = (int)(std::count(std::istreambuf_iterator<char>(in3),
			std::istreambuf_iterator<char>(), '\n') + 1);
		in3.seekg(0, std::ios::beg);
		enemies = new std::string[enemies_size];
		std::string line;
		int index = 0;
		while (getline(in3, line))
		{
			enemies[index++] = line;
		}
	}
	in3.close();
}
