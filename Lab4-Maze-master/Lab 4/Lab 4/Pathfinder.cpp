#include "Pathfinder.h"

Pathfinder::Pathfinder(){
	srand(time(NULL));

	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			for (int k = 0; k <= 4; k++) {
				currentMaze[i][j][k] = 1;
			}
		}
	}
}

Pathfinder::~Pathfinder() {

}

bool Pathfinder::validMaze() {
	if (tempMaze[0][0][0] != 1) {
		return false;
	}
	if (tempMaze[4][4][4] != 1) {
		return false;
	}

	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			for (int k = 0; k <= 4; k++) {
				if (tempMaze[i][j][k] == 1 || tempMaze[i][j][k] == 0) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}

	return true;
}

//PART 1 -------------------------------------------------------------------------------------
/*
* toString
*
* Returns a string representation of the current maze. Returns a maze of all 1s if no maze
* has yet been generated or imported.
*
* A valid string representation of a maze consists only of 125 1s and 0s (each separated
* by spaces) arranged in five 5x5 grids (each separated by newlines) with no trailing newline. A valid maze must
* also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
*
* Cell (0, 0, 0) is represented by the first number in the string representation of the
* maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
* number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
* sixth number. Increasing in z means moving downward to a new grid, meaning cell
* (0, 0, 1) is the twenty-sixth cell in the maze. Cell (4, 4, 4) is represented by the last number.
*
* Returns:		string
*				A single string representing the current maze
*/
string Pathfinder::toString() const {
	string mazeString;
	stringstream ss;

	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			for (int k = 0; k <= 4; k++) {
				if (k < 4) {
					ss << currentMaze[i][j][k];
					ss << " ";
				}
			}
			ss << endl;
		}
		if (i < 4) {
			ss << endl;
		}
	}

	mazeString = ss.str();

	return mazeString;
}

/*
* createRandomMaze
*
* Generates a random maze and stores it as the current maze.
*
* The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
* in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
* solvable or unsolvable, and this method should be able to produce both kinds of mazes.
*/
void Pathfinder::createRandomMaze() {
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			for (int k = 0; k <= 4; k++) {
				currentMaze[i][j][k] = rand() % 2;
			}
		}
	}
	currentMaze[0][0][0] = 1;
	currentMaze[4][4][4] = 1;

}
//--------------------------------------------------------------------------------------------

//PART 2--------------------------------------------------------------------------------------
/*
* importMaze
*
* Reads in a maze from a file with the given file name and stores it as the current maze.
* Does nothing if the file does not exist or if the file's data does not represent a valid
* maze.
*
* The file's contents must be of the format described above to be considered valid.
*
* Parameter:	file_name
*				The name of the file containing a maze
* Returns:		bool
*				True if the maze is imported correctly; false otherwise

You will be given a filename for each maze (you must keep the Mazes folder in the working directory of your project). 
	Valid files will contain representations of mazes, with each cell represented by a 0 or a 1.
You must check to make sure that the given file contains valid maze information. Each maze should consist of exactly 125 1's or 0's. 
	Mazes may be solvable or unsolvable.
*/
bool Pathfinder::importMaze(string file_name) {
	stringstream ss;
	string maze;

	ifstream myfile;

	myfile.open(file_name);
	if (myfile.fail()) {
		return false;
	}
		for (int i = 0; i <= 4; i++) {
			for (int j = 0; j <= 4; j++) {
				for (int k = 0; k <= 4; k++) {
					myfile >> maze;
					ss << maze;
					ss >> tempMaze[i][j][k];
					if (myfile.fail()) {
						return false;
					}
				}
			}
		}

		if (validMaze()) {
			for (int i = 0; i <= 4; i++) {
				for (int j = 0; j <= 4; j++) {
					for (int k = 0; k <= 4; k++) {
						currentMaze[i][j][k] = tempMaze[i][j][k];
					}
				}
			}
			return true;
		}
		else {
			return false;
		}
		myfile.close();

		return false;
	
}
//----------------------------------------------------------------------------------------------

//PART 3 ---------------------------------------------------------------------------------------

bool Pathfinder::findPath(int x, int y, int z, vector<string>& path) {
	stringstream ss;
	ss.clear();
	string s;
	ss << "(" << x << ", " << y << ", " << z << ")";
	s = ss.str();

	path.push_back(s);

	if (x < 0 || x > 4 || y < 0 || y > 4 || z < 0 || z > 4) {
		path.pop_back();
		return false;
	}
	if (currentMaze[x][y][z] == 0) {
		path.pop_back();
		return false;
	}
	if (currentMaze[x][y][z] == 2) {
		path.pop_back();
		return false;
	}
	if (x == 4 && y == 4 && z == 4) {
		return true;
	}

	if (currentMaze[x][y][z] == 1) {
		currentMaze[x][y][z] = 2;
	}
	if (findPath(x, y + 1, z, path) || findPath(x, y - 1, z, path) || findPath(x - 1, y, z, path) || findPath(x + 1, y, z, path) || findPath(x, y, z + 1, path) || findPath(x, y, z - 1, path)) {
		return true;
	}
	else {
		path.pop_back();
		return false;
	}

}

/*
* solveMaze
*
* Attempts to solve the current maze and returns a solution if one is found.
*
* A solution to a maze is a list of coordinates for the path from the entrance to the exit
* (or an empty vector if no solution is found). This list cannot contain duplicates, and
* any two consecutive coordinates in the list can only differ by 1 for only one
* coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
* in the solution. Each string in the solution vector must be of the format "(x, y, z)",
* where x, y, and z are the integer coordinates of a cell.
*
* Understand that most mazes will contain multiple solutions
*
* Returns:		vector<string>
*				A solution to the current maze, or an empty vector if none exists
*/
vector<string> Pathfinder::solveMaze() {
	vector<string> solve;

	findPath(0, 0, 0, solve);
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			for (int k = 0; k <= 4; k++) {
				if (currentMaze[i][j][k] == 2) {
					currentMaze[i][j][k] = 1;
				}
			}
		}
	}

	return solve;
}

//---------------------------------------------------------------------------------------------------