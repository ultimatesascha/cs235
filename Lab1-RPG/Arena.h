#include "ArenaInterface.h"
#include <vector>
#include <sstream>

class Arena : public ArenaInterface 
{
	std::vector<FighterInterface*> fighters;
public:
	virtual ~Arena() {};
	bool addFighter(std::string info);
	bool removeFighter(std::string name);
	FighterInterface* getFighter(std::string name);
	int getSize();
};