#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::main_menu()
{
	bool exit = false;

	while (!exit)
	{
		std::cout << "Please choose option: " << std::endl;
		std::cout << "[1] Start new game" << std::endl;
		std::cout << "[2] Load game" << std::endl;
		std::cout << "[3] Exit" << std::endl;

		int option;

		std::cin >> option;

		try {
			switch (option) {
			case 1:
				play(true);
				break;
			case 2:
				play(false);
				break;
			case 3:
				exit = true;
				break;
			default:
				throw WrongTypedOptionException("Your typed option is wrong, please try again");
			}
		}
		catch (GameException& e) { std::cout << e.what() << std::endl; }
	}
}

void Game::play(bool new_game) throw(GameException)
{
	if (new_game) {
		player_creator();
		player->set_location(locations_loader());
		game();

	}
	else throw NotYetImplementedException("This option is not implemented actually, please choose another one");
}

void Game::player_creator()
{
	std::cout << "Type player name: " << std::endl;
	std::string name;
	std::cin >> name;

	Weapon *w = new Weapon("Basic Weapon", 0, 1, 10);
	Armor *a = new Armor("Basic Armor", 0, 1, 30);
	Potion *p1 = new Potion("Small Potion", 0, 20);
	Potion *p2 = new Potion("Small Potion", 0, 20);
	Potion *p3 = new Potion("Small Potion", 0, 20);

	std::list<Item*> items;
	items.push_back(w);
	items.push_back(a);
	items.push_back(p1);
	items.push_back(p2);
	items.push_back(p3);

	player = new Player(name, items);
}

Location* Game::locations_loader()
{
	locations = factory.get_enemies_locations();
	Location* basic_location = factory.get_npcs_location();
	locations.push_back(basic_location);
	return basic_location;
}

void Game::game()
{
	bool exit = false;
	while (!exit) 
	{
		std::cout << (*player) << std::endl;
		std::cout << "Actual location: " << *player->get_actual_location() << std::endl;
		std::cout << "Choose option: " << std::endl;
		std::cout << "[1] Go ahead" << std::endl;
		std::cout << "[2] Change location" << std::endl;
		std::cout << "[3] Go to your items" << std::endl;
		std::cout << "[4] Exit " << std::endl;

		int opt;
		std::cin >> opt;

		switch (opt) {
		case 1:
			player->get_actual_location()->go_ahead(player);
			break;
		case 2:
			location_changer();
			break;
		case 3:
			items_actions();
			break;
		case 4:
			exit = true;
			break;
		}
	}
}

void Game::location_changer()
{
	std::cout << "Available locations:" << std::endl;

	for (int i = 0; i < (int)locations.size(); ++i) {
		Location *l = locations.at(i);
		std::cout << "[" << i << "] " << *l << std::endl;
	}
	std::cout << "[" << locations.size() << "] Return" << std::endl;
	bool is_changed = false;
	int opt;
	while (!is_changed) {
		try {
			std::cout << "Type location number:" << endl;

			std::cin >> opt;
			if (opt < 0 || opt > (int)locations.size()) {
				throw WrongTypedOptionException("Your typed option is wrong, please try again");
			}
			is_changed = true;
		}
		catch (WrongTypedOptionException& e) { std::cout << e.what() << std::endl; }
	}
	if (opt != (int)locations.size()) {
		player->set_location(locations.at(opt));
	}

}

void Game::items_actions()
{
	std::cout << "Your items:" << std::endl;
	int index = 0;
	for (auto it = player->get_items()->begin(); it != player->get_items()->end(); it++) {
		Item* item = *it;
		std::cout << "[" << index++ << "] " << *item << endl;
	}
	std::cout << "[" << player->get_items()->size() << "] Return" << std::endl;
	bool is_chosen = false;
	int opt;
	while (!is_chosen) {
		try {
			std::cin >> opt;
			if (opt < 0 || opt >(int)player->get_items()->size()) throw WrongTypedOptionException("Your typed option is wrong, please try again");
			is_chosen = true;
		}
		catch (WrongTypedOptionException& e) { std::cout << e.what() << std::endl; }
	}
	if (opt != (int)player->get_items()->size()) {
		auto it = player->get_items()->begin();
		std::advance(it, opt);
		(*it)->action(player);
	}
		

	
}
