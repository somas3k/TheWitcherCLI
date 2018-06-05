#include "stdafx.h"
#include "FightSystem.h"


FightSystem::FightSystem()
{
}


FightSystem::~FightSystem()
{
}

KillablePerson *FightSystem::fight(KillablePerson * e1, KillablePerson * e2)
{
	while (true)
	{
		bool is_e2_dead = e2->take_attack(e1->hit_value());
		if (!is_e2_dead) {
			bool is_e1_dead = e1->take_attack(e2->hit_value());
			if (is_e1_dead) return e2;
			
		}
		else return e1;
	}
}
