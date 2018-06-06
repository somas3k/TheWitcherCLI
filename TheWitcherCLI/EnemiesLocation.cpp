#include "stdafx.h"
#include "EnemiesLocation.h"
#include "FightSystem.h"
#include "Utils.h"
#include "WrongTypedOptionException.h"


EnemiesLocation::EnemiesLocation()
{
}


void EnemiesLocation::go_ahead(Player * player)
{
	auto it = enemies.begin();
	std::advance(it, generate_random_index(enemies.size()));
	Enemy* enemy = (*it);
	std::cout << "Do you want to fight with: " << std::endl;
	std::cout << *enemy << std::endl;
	
	bool is_chosen = false;
	while (!is_chosen) {
		try {
			std::cout << "Type y(Yes) or n(No):" << std::endl;
			char decision;
			std::cin >> decision;
			switch (decision) {
			case 'y':
				if (fight(player, enemy) == player) {
					player->add_exp(enemy->get_exp());
					enemies.remove(enemy);
					std::cout << "You win!!" << std::endl;
				}
				else {
					std::cout << "Your HP is 0, use potions if you have and try again";
				}
				is_chosen = true;
				break;
			case 'n':
				is_chosen = true;
				break;
			default:
				throw WrongTypedOptionException("Your typed option is wrong, please try again");
			}
		}
		catch (WrongTypedOptionException& e) { std::cout << e.what() << std::endl; }
	}
}

EnemiesLocation::~EnemiesLocation()
{
}
