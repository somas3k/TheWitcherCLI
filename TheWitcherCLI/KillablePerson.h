#pragma once
#include "Person.h"
#include <string>

class Person;

class KillablePerson : public virtual Person
{
public:
	static const int BASIC_HIT = 100;
	static const int MAX_LEVEL = 30;
	static const int MAX_HP = 100;

	KillablePerson() {}
	KillablePerson(std::string name) : Person(name) { this->hp = 100; this->level = 1; }
	~KillablePerson();
	int get_hp() { return hp; }
	void heal(int hp) {
		this->hp += hp;
		if (this->hp > MAX_HP) this->hp = MAX_HP;
	}
	virtual bool take_attack(int attack_value) = 0;
	virtual int hit_value() = 0;
protected:
	int hp;
	int level;
};

