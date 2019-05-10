#include "Fighter.h"

Fighter::Fighter(std::string fighterName, int maxHP, int strength, int speed, int magic) {
	this->fighterName = fighterName;
	this->maxHP = maxHP;
	this->currentHP = maxHP;
	this->strength = strength;
	this->speed = speed;
	this->magic = magic;
}

std::string Fighter::getName() {
	return this->fighterName;
}
int Fighter::getMaximumHP() {
	return this->maxHP;
}
int Fighter::getCurrentHP() {
	return this->currentHP;
}
int Fighter::getStrength() {
	return this->strength;
}
int Fighter::getSpeed() {
	return this->speed;
}
int Fighter::getMagic() {
	return this->magic;
}
/*
*	takeDamage(int)
*
*	Reduces the fighter's current hit points by an amount equal to the given
*	damage minus one fourth of the fighter's speed.  This method must reduce
*	the fighter's current hit points by at least one.  It is acceptable for
*	this method to give the fighter negative current hit points.
*
*	Examples:
*		damage=10, speed=7		=> damage_taken=9
*		damage=10, speed=9		=> damage_taken=8
*		damage=10, speed=50		=> damage_taken=1
*/
void Fighter::takeDamage(int damage) {
	int damageTaken = static_cast<int>(damage - (static_cast<double>(speed) / 4));

	if (damageTaken < 1) {
		damageTaken = 1;
	}

	currentHP -= damageTaken;
}