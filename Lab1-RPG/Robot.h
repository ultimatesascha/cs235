#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Fighter.h"
#include <cmath>

class Robot :Fighter {
public:
	virtual ~Robot() {}
	Robot(std::string fighterName, int maxHP, int strength, int speed, int magic);
	virtual int getDamage();
	virtual void reset();
	virtual bool useAbility();
	virtual void regenerate();
private:
	int ROBOT_ENERGY_MULTIPLIER = 2;
	int maxEnergy;
	int currentEnergy;
	int bonusDamage;
	//energy variable

};

#endif