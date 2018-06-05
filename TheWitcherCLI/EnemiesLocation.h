#pragma once
#include "Location.h"

class EnemiesLocation : Location
{
public:
	EnemiesLocation();
	EnemiesLocation(std::string name, std::string welcome_message) : Location(name, welcome_message) {}
	virtual void go_ahead(Player *player);
	~EnemiesLocation();

private:
	std::list<Enemy> *enemies;
};

