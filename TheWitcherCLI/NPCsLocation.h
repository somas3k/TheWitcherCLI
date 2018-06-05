#pragma once
#include "Location.h"
#include "NonPlayerCharacter.h"

class NPCsLocation : Location
{
public:
	NPCsLocation();
	NPCsLocation(std::string name, std::string welcome_message) : Location(name, welcome_message) {}
	virtual void go_ahead(Player *player);
	~NPCsLocation();
private:
	std::list<NonPlayerCharacter> *npcs;
};

