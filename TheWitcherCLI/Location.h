#pragma once
#include <string>
#include "Player.h"
class Location
{
public:
	Location();
	Location(std::string n, std::string w_message) : name(n), welcome_message(w_message) {}
	~Location();

	virtual void go_ahead(Player *player) = 0;
	friend ostream & operator<< (ostream &out, const Location &l) {
		out << l.name;
		return out;
	}

private:
	std::string name;
	std::string welcome_message;

};

