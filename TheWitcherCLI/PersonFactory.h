#pragma once
#include "Riddler.h"
#include "Wiseman.h"
#include "Tradesman.h"
#include "ItemFactory.h"
#include <string>
class PersonFactory
{
public:
	PersonFactory(std::string r_path, std::string w_path, std::string e_path) : riddles_path(r_path), wisdoms_path(w_path), enemies_path(e_path) { load(); }

	Riddler *generate_riddler();

	Wiseman *generate_wiseman();

	list<Enemy*> generate_enemies(int amount);

	Tradesman* generate_tradesman();
	~PersonFactory();
private:
	std::string riddles_path;
	std::string wisdoms_path;
	std::string enemies_path;

	std::string *riddles;
	std::string *wisdoms;
	std::string *enemies;

	int wisdoms_size;
	int riddles_size;
	int enemies_size;

	ItemFactory item_factory = ItemFactory(std::string("weapons.txt"), std::string("armors.txt"));

	void load();
};

