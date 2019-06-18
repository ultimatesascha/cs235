#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "PathfinderInterface.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pathfinder : public PathfinderInterface {
	public:
		Pathfinder();
		~Pathfinder();
		bool validMaze();
		virtual string toString() const;
		virtual void createRandomMaze();
		virtual bool importMaze(string file_name);
		virtual vector<string> solveMaze();
		bool findPath(int x, int y, int z, vector<string>& path);
	private:
		string file_name;
		int currentMaze[5][5][5];
		int tempMaze[5][5][5];
		vector<string> path;
};


#endif