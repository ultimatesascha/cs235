#ifndef CLERIC_HPP_
#define CLERIC_HPP_

#include "Fighter.h"

//Cleric - Relies on magic to deal damage.  Also can heal itself using mana, restoring hit points (max/starting mana equal to 5*magic).
//			Only Clerics have mana.

class Cleric : public Fighter {
public:
	virtual ~Cleric() {}
	Cleric(std::string fighterName, int maxHP, int strength, int speed, int magic);
	virtual int getDamage();
	virtual void reset();
	virtual bool useAbility();
	virtual void regenerate();
	virtual void takeDamage(int damage) = 0;
protected:
private:
	int MANA_MULTIPLIER = 5;
	int maxMana = MANA_MULTIPLIER * magic;
	int currentMana;
};

#endif