#pragma once
#include "Location.h"

class EnemiesLocation : public virtual Location
{
public:
	EnemiesLocation();
	EnemiesLocation(std::string name, std::string welcome_message) : Location(name, welcome_message) {}
	virtual void go_ahead(Player *player);
	~EnemiesLocation();

	void set_enemies(std::list<Enemy*> enemies) { this->enemies = enemies; }

private:
	std::list<Enemy*> enemies;
};

