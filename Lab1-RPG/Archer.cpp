#include "Archer.h"

Archer::Archer(std::string fighterName, int maxHP, int strength, int speed, int magic) {
	this->fighterName = fighterName;
	this->maxHP = maxHP;
	this->currentHP = maxHP;
	this->strength = strength;
	this->speed = speed;
	this->magic = magic;
	this->currentSpeed = speed;
}
/*
*	getDamage()
*
*	Returns the amount of damage a fighter will deal.
*
*	Archer:
*	This value is equal to the Archer's speed.
*/
int Archer::getDamage() {
	int damage = currentSpeed;
	return damage;
}
/*
*	reset()
*
*	Restores a fighter's current hit points to its maximum hit points.
*
*	Archer:
*	Also resets an Archer's current speed to its original value.
*/
void Archer::reset() {
	currentHP = maxHP;
	currentSpeed = speed;
}
/*
*	useAbility()
*
*	Attempts to perform a special ability based on the type of fighter.  The
*	fighter will attempt to use this special ability just prior to attacking
*	every turn.
*
*	Archer: Quickstep
*	Increases the Archer's speed by one point each time the ability is used.
*	This bonus lasts until the reset() method is used.
*	This ability always works; there is no maximum bonus speed.
*
*	Return true if the ability was used; false otherwise.
*/
bool Archer::useAbility() {
	int originalCurrentSpeed = currentSpeed;
	currentSpeed += 1;
	if (originalCurrentSpeed != currentSpeed) {
		return true;
	}
	else {
		return false;
	}
}
/*
*	regenerate()
*
*	Increases the fighter's current hit points by an amount equal to one sixth of
*	the fighter's strength.  This method must increase the fighter's current hit
*	points by at least one.  Do not allow the current hit points to exceed the
*	maximum hit points.
*/
void Archer::regenerate() {
	int addedHP = static_cast<int>(strength * static_cast<double>(1) / 6);

	if (addedHP < 1) {
		addedHP = 1;
	}
	if ((addedHP + currentHP) > maxHP) {
		currentHP = maxHP;
	}
	else {
		currentHP += addedHP;
	}
}