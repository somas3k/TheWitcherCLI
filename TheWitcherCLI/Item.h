#pragma once
#include <string>
#include <iostream>

class Player;

class Item
{
public:
	const std::string name;
	Item() : name("") {}
	Item(std::string n, double p) : name(n), price(p) {}
	~Item();
	virtual void action(Player *player) = 0;
private:	
	double price;
};

