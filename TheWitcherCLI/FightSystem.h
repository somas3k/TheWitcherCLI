#pragma once
#include "KillablePerson.h"
class FightSystem
{
public:
	FightSystem();
	~FightSystem();
	KillablePerson *fight(KillablePerson *e1, KillablePerson *e2);
};

