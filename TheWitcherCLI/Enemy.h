#pragma once
#include "KillablePerson.h"
#include <string>

using namespace std;
class Enemy : public virtual KillablePerson
{
public:
	Enemy() {}
	Enemy(string name, int gaining_experience) : KillablePerson(name), Person(name) {
		this->gaining_experience = gaining_experience;
	}
	~Enemy();
	int hit_value();
	virtual bool take_attack(int attack_value);
	int get_exp() { return gaining_experience; }
	friend ostream & operator<< (ostream &out, const Enemy &e) {
		return out << "Name: " << e.name << " HP: " << e.hp << " Level: " << e.level << " Gaining exp: " << e.gaining_experience;
	}
private:
	int gaining_experience;
};

