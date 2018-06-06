#include "stdafx.h"
#include "LocationFactory.h"
#include "EnemiesLocation.h"
#include "NPCsLocation.h"
#include <fstream>



LocationFactory::~LocationFactory()
{
}

vector<Location*> LocationFactory::get_enemies_locations()
{
	vector<Location*> locations;
	for (int i = 0; i < location_size; ++i) {
		std::string name = location_names[i];
		EnemiesLocation *loc = new EnemiesLocation(name, "Welcome in " + name);
		loc->set_enemies(person_factory.generate_enemies(20));
		locations.push_back(loc);
	}
	return locations;
}

Location * LocationFactory::get_npcs_location()
{
	NPCsLocation * loc = new NPCsLocation(std::string("Market"), "Welcome on Market, We wish you can find what you need");
	list<NonPlayerCharacter*> npcs;
	npcs.push_back(person_factory.generate_tradesman());
	npcs.push_back(person_factory.generate_tradesman());
	npcs.push_back(person_factory.generate_wiseman());
	npcs.push_back(person_factory.generate_riddler());
	loc->set_npcs(npcs);
	return loc;
}



void LocationFactory::load()
{
	std::ifstream in(locations_path);
	if (!in.bad())
	{
		location_size = (int)(std::count(std::istreambuf_iterator<char>(in),
			std::istreambuf_iterator<char>(), '\n') + 1);
		in.seekg(0, std::ios::beg);
		location_names = new std::string[location_size];
		std::string line;
		int index = 0;
		while (getline(in, line))
		{
			location_names[index++] = line;
		}
	}
	in.close();
}
