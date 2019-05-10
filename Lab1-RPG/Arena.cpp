#include "Arena.h"

/*
*	addFighter(string)
*
*	Adds a new fighter to the collection of fighters in the arena. Do not allow
*	duplicate names.  Reject any string that does not adhere to the format
*	outlined in the lab specs.
*
*	Return true if a new fighter was added; false otherwise.
*/

bool Arena :: addFighter(std::string info) {
	bool fighterAdded = true;
	std::string fighterName;
	char fighterClass; 
	int maxHP;
	int strength;
	int speed;
	int magic;

	std::stringstream ss;

	ss << info;
	ss >> fighterName;
	if (ss.fail()) {
		ss.clear();
		return false;
	}

	ss >> fighterClass;
	if (ss.fail()) {
		ss.clear();
		return false;
	}

	ss >> maxHP;
	if (ss.fail()) {
		ss.clear();
		return false;
	}

	ss >> strength;
	if (ss.fail()) {
		ss.clear();
		return false;
	}

	ss >> speed;
	if (ss.fail()) {
		ss.clear();
		return false;
	}

	ss >> magic;
	if (ss.fail()) {
		ss.clear();
		return false;
	}

	if (ss.rdbuf()->in_avail() != 0) {
		return false;
	}

	for (int i = 0; i < fighters.size(); i++) {
		if (fighters.at(i)->getName() == fighterName) {
			fighterAdded = false;
			return fighterAdded;
		}
	}

	if (fighterClass == 'A') {
		fighters.push_back(new Archer(fighterName, maxHP, strength, speed, magic));
	}
	else if (fighterClass == 'C') {
		fighters.push_back(new Cleric(fighterName, maxHP, strength, speed, magic));
	}
	else if (fighterClass == 'R') {
		fighters.push_back(new Robot(fighterName, maxHP, strength, speed, magic));
	}
	else {
		return false; //Fighet was not added because we did not recognize its fighting class
	}
	return fighterAdded;
	//return true or false

	//duplicate names no bueno

	//if name exists return false

	//Format: name, type, maxpts, strength, speed, magic
		//string stream into each part
}

/*
*	removeFighter(string)
*
*	Removes the fighter whose name is equal to the given name.  Does nothing if
*	no fighter is found with the given name.
*
*	Return true if a fighter is removed; false otherwise.
*/
bool Arena :: removeFighter(std::string name) {
	bool fighterRemoved = false;

	for (int i = 0; i < fighters.size(); i++) {
		if (fighters.at(i)->getName() == name) {
			fighterRemoved = true;

			delete fighters.at(i);
			fighters.erase(fighters.begin() + i);

			return fighterRemoved;
		}
	}
	//check if name exist
		//if not found return false
		//if found
			//remove from list
			//return true
	return fighterRemoved;
}
/*
*	getFighter(string)
*
*	Returns the memory address of a fighter whose name is equal to the given
*	name.  Returns NULL if no fighter is found with the given name.
*
*	Return a memory address if a fighter is found; NULL otherwise.
*/
FighterInterface* Arena :: getFighter(std::string name) {
	//check if name exists
		//if not found return NULL pointer
		//if found return pointer to fighter

	for (int i = 0; i < fighters.size(); i++) {
		if (fighters.at(i)->getName() == name) {

			return fighters.at(i);
		}
	}
	return NULL;
}
/*
*	getSize()
*
*	Returns the number of fighters in the arena.
*
*	Return a non-negative integer.
*/
int Arena :: getSize() {
	//return size of list
	return fighters.size();
}