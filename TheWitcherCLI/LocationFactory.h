#pragma once
#include <string>
#include "Location.h"
#include "PersonFactory.h"
class LocationFactory
{
public:
	LocationFactory(std::string l_path) : locations_path(l_path) { load(); }
	~LocationFactory();

	vector<Location*> get_enemies_locations();
	Location* get_npcs_location();
private:
	std::string locations_path;
	std::string *location_names;

	PersonFactory person_factory = PersonFactory("riddles.txt", "wisdoms.txt", "enemies_names.txt");

	void load();

	int location_size;
};

