#include "Cleric.h"

Cleric::Cleric(std::string fighterName, int maxHP, int strength, int speed, int magic) {
	this->fighterName = fighterName;
	this->maxHP = maxHP;
	this->currentHP = maxHP;
	this->strength = strength;
	this->speed = speed;
	this->magic = magic;
	this->currentMana = maxMana;
}

/*
*	getDamage()
*
*	Returns the amount of damage a fighter will deal.
*
*	Robot:
*	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
*
*	Archer:
*	This value is equal to the Archer's speed.
*
*	Cleric:
*	This value is equal to the Cleric's magic.
*/
int Cleric :: getDamage() {
	int damageDealt = magic;

	return damageDealt;
}
/*
*	reset()
*
*	Restores a fighter's current hit points to its maximum hit points.
*
*	Robot:
*	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
*	Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0.
*
*	Archer:
*	Also resets an Archer's current speed to its original value.
*
*	Cleric:
*	Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
*/
void Cleric:: reset() {
	currentHP = maxHP;
	currentMana = maxMana;
}
/*
*	useAbility()
*
*	Attempts to perform a special ability based on the type of fighter.  The
*	fighter will attempt to use this special ability just prior to attacking
*	every turn.
*
*	Cleric: Healing Light
*	Increases the Cleric's current hit points by an amount equal to one third of its magic.
*	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
*	Will be used even if the Cleric's current HP is equal to their maximum HP.
*	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
*	Cleric Note:
*	This ability, when successful, must increase the Cleric's current hit points
*	by at least one, unless doing so would given the Cleric more hit points than its maximum hit points.
*	Do not allow the current hit points to exceed the maximum hit points.
*
*	Return true if the ability was used; false otherwise.
*/
bool Cleric:: useAbility() {
	if (CLERIC_ABILITY_COST >= currentMana) {
		currentMana -= CLERIC_ABILITY_COST;
		int increaseAmount = static_cast<int>(magic * (static_cast<double>(1) / 3));
		//currentHP += (magic / 3);
		if (increaseAmount < 1) {
			//Give them at least 1 extra currentHP point
			currentHP += 1;
		}
		else if ((currentHP + increaseAmount) > maxHP) {
			currentHP = maxHP;
		}
		else {
			//just add the increase to their current HP
			currentHP += increaseAmount;
		}
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
*
*	Cleric:
*	Also increases a Cleric's current mana by an amount equal to one fifth of the
*	Cleric's magic.  This method must increase the Cleric's current mana by at
*	least one.  Do not allow the current mana to exceed the maximum mana (again, 5 times its magic).
*/
void Cleric:: regenerate() {
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

	int addedMana = static_cast<int>(magic * static_cast<double>(1) / 5);
	
	if (addedMana < 1) {
		addedMana = 1;
	}
	if ((addedMana + currentMana) > maxMana) {
		currentMana = maxMana;
	}
	else {
		currentMana += addedMana;
	}
}