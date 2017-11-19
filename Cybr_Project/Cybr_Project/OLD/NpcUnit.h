#pragma once
#include "Unit.h"

class NpcUnit : public Unit {
private:
	int faction;
public:
	NpcUnit(int faction);
};
