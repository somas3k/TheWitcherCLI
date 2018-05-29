#pragma once
#include "Person.h"
#include <string>

using namespace std;
class Enemy : public virtual Person
{
public:
	Enemy() {}
	Enemy(string name, int gaining_experience) : Person(name) {
		this->gaining_experience = gaining_experience;
	}
	~Enemy();
	int hit_value();
private:
	int gaining_experience;
};

