#pragma once
#include "Unit.h"

class PlayerUnit : public Unit {
private:
	std::string playerName;
	bool isPlayer = true;
public:
	PlayerUnit(unsigned int id, std::string playerName, bool isPlayer);
};