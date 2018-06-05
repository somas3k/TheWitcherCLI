#pragma once
#include "Location.h"
#include "NonPlayerCharacter.h"

class NPCsLocation : public virtual Location
{
public:
	NPCsLocation();
	NPCsLocation(std::string name, std::string welcome_message) : Location(name, welcome_message) {}
	virtual void go_ahead(Player *player);

	void set_npcs(std::list<NonPlayerCharacter*> npcs) { this->npcs = npcs; }
	~NPCsLocation();
private:
	std::list<NonPlayerCharacter*> npcs;
};

