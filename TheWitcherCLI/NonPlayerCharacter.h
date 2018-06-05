#pragma once
#include "Person.h"
#include "Player.h"
class NonPlayerCharacter : public virtual Person
{
public:
	NonPlayerCharacter() {}
	NonPlayerCharacter(string name) : Person(name) {}
	virtual void interact_with_player(Player *player) = 0;
	
	~NonPlayerCharacter();
};

