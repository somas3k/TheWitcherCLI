#include "stdafx.h"
#include "Player.h"


Player::~Player()
{
}

//returns true if dead
bool Player::take_attack(int attack_value){	
	if (armor != nullptr) {
		int left_attack_value = armor->take_hit(attack_value);
		this->hp -= left_attack_value;
	}
	else {
		this->hp -= attack_value;
	}
	if (this->hp <= 0) {
		this->hp = 0;
		return true;
	}
	return false;
}

int Player::hit_value()
{
	int hit = ((double)level / MAX_LEVEL) * BASIC_HIT;
	if (this->weapon != nullptr) {
		return hit + this->weapon->get_hit();
	}
	return hit;	
}

