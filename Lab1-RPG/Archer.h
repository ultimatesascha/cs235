#ifndef ARCHER_HPP
#define ARCHER_HPP

#include "Fighter.h"

class Archer : public Fighter {
public:
	virtual ~Archer() {}
	Archer(std::string fighterName, int maxHP, int strength, int speed, int magic);
	virtual int getDamage();
	virtual void reset();
	virtual bool useAbility();
	virtual void regenerate();
private:
	int currentSpeed;
};

#endif