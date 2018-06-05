#pragma once
#include <string>
class LocationFactory
{
public:
	LocationFactory(std::string l_path) : locations_path(l_path) { load(); }
	~LocationFactory();
private:
	std::string locations_path;
	std::string *location_names;

	void load();

	int location_size;
};

