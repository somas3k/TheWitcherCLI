#pragma once
#include "Player.h"
#include <list>
#include "Location.h"
class Game
{
public:
	Game();
	~Game();

private:
	Player * player;
	list<Location*> locations;

};

