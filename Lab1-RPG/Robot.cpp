#include "Robot.h"

//Robot - Relies on strength to deal damage.Also can use stored energy to temporarily increase damage(max / starting energy equal to 2 * magic).
//			Only Robots have energy.
Robot::Robot(std::string fighterName, int maxHP, int strength, int speed, int magic) {
	this->fighterName = fighterName;
	this->maxHP = maxHP;
	this->currentHP = maxHP;
	this->strength = strength;
	this->speed = speed;
	this->magic = magic;
	this->maxEnergy = 2 * magic;
	this->currentEnergy = maxEnergy;
	this->bonusDamage = 0;
}

/*
*	getDamage()
*
*	Returns the amount of damage a fighter will deal.
*
*	Robot:
*	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
*/
int Robot::getDamage() {
	int damage = strength + bonusDamage;
	return damage;
}
/*
*	reset()
*
*	Restores a fighter's current hit points to its maximum hit points.
*
*	Robot:
*	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
*	Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0.
*/
void Robot::reset() {
	currentHP = maxHP;
	currentEnergy = maxEnergy;
	bonusDamage = 0;
}
/*
*	useAbility()
*
*	Attempts to perform a special ability based on the type of fighter.  The
*	fighter will attempt to use this special ability just prior to attacking
*	every turn.
*
*	Robot: Shockwave Punch
*	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
*	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
*	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
*		Examples:
*		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
*		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
*		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
*		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
*
*	Robot Note:
*	The bonus damage formula should be computed using double arithmetic, and only
*	the final result should be cast into an integer.
*	Return true if the ability was used; false otherwise.
*/
bool Robot::useAbility() {
	if (currentEnergy >= ROBOT_ABILITY_COST) {
		bonusDamage = static_cast<int>(strength * (static_cast<double>(std::pow(currentEnergy / maxEnergy, 4))));
		currentEnergy - +ROBOT_ABILITY_COST;
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
void Robot::regenerate() {
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

