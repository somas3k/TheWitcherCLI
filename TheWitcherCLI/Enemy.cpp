#include "stdafx.h"
#include "Enemy.h"


Enemy::~Enemy()
{
}

int Enemy::hit_value()
{
	int hit = ((double)level / MAX_LEVEL) * BASIC_HIT;
	return hit;
}

bool Enemy::take_attack(int attack_value)
{
	this->hp -= attack_value;
	if (this->hp <= 0) return true;
	return false;
}
