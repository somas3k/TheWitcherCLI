// TheWitcherCLI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ItemFactory.h"
#include "PersonFactory.h"
#include "Game.h"


int main()
{
	/*ItemFactory factory(std::string("weapons.txt"), std::string("armors.txt"));

	std::list<Item*> items = factory.get_items_for_npc(50);

	for (auto it = items.begin(); it != items.end(); it++) {
		std::cout << (*it)->name << std::endl;
	}

	PersonFactory factory2(std::string("riddles.txt"), std::string("wisdoms.txt"), std::string("enemies.txt"));

	Riddler *r = factory2.generate_riddler();

	Wiseman *w = factory2.generate_wiseman();

	Tradesman *t = factory2.generate_tradesman();	
*/
	Game game;
	game.main_menu();
	system("PAUSE");

    return 0;
}

