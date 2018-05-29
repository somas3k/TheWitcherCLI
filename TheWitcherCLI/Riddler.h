#pragma once
#include "Enemy.h"
#include "NonPlayerCharacter.h"

class Riddler : public Enemy, public NonPlayerCharacter
{
public:
	Riddler(string name, int gaining_experience, string riddle, string answer) : Enemy(name, gaining_experience) {}
	virtual void interact_with_player(Player player);
	~Riddler();
};

