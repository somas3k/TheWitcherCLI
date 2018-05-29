#pragma once
#include "Person.h"
#include <string>

class Person;

class KillablePerson : public Person
{
public:
	KillablePerson(std::string name) : Person(name) { this->hp = 100; this->level = 1; }
	~KillablePerson();
private:
	int hp;
	int level;
};

