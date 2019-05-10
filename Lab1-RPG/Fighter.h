#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include "FighterInterface.h"

#include <string>

class Fighter : public FighterInterface 
{
protected:
	Fighter() {};
	std::string fighterName; //name
	int currentHP; //currenthp
	int maxHP; //maxhp
	int strength; //strength
	int speed; //speed
	int magic; //magic
public:
	Fighter(std::string fighterName, int maxHP, int strength, int speed, int magic);
	std::string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	virtual int getDamage();
	virtual void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility();
};

#endif