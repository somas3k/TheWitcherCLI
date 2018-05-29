#pragma once
#include "NonPlayerCharacter.h"
class Wiseman : public NonPlayerCharacter
{
public:
	Wiseman(string name, string wisdom) :NonPlayerCharacter(name) {
		this->wisdom = wisdom;
	}
	virtual void interact_with_player(Player player);
	~Wiseman();
private:
	string wisdom;
};

