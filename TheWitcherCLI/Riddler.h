#pragma once
#include "Enemy.h"
#include "NonPlayerCharacter.h"

class Riddler : public Enemy, public NonPlayerCharacter
{
public:
	Riddler(string name, int gaining_experience, string riddle, string answer) : Enemy(name, gaining_experience), NonPlayerCharacter(name), KillablePerson(name), Person(name){
		this->riddle = riddle;
		this->answer = answer;
	}
	virtual void interact_with_player(Player *player);
	~Riddler();

private:
	std::string riddle;
	std::string answer;
};

