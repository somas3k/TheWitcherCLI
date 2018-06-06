#pragma once
#pragma warning( disable : 4290 ) 
#include "Player.h"
#include <list>
#include "Location.h"
#include "Potion.h"
#include "WrongTypedOptionException.h"
#include "GameException.h"
#include "NotYetImplementedException.h"
#include "LocationFactory.h"
class Game
{
public:
	Game();
	~Game();
	void main_menu();
private:
	Player * player;
	vector<Location*> locations;
	LocationFactory factory = LocationFactory("enemies_locations_names.txt");

	

	void play(bool new_game) throw(GameException);

	void player_creator();

	Location* locations_loader();

	void game();

	void location_changer();

	void items_actions();
};

