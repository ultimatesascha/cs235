#include <iostream> 
#include <set>
#include <map>
#include <list>
#include <vector>
#include <sstream>
#include <fstream>
#include <time.h>

using namespace std;

int main() {
	// Open file to read
	cout << "What file do you want to read? ";
	string filelocation;
	
	getline(cin, filelocation);
	filelocation += ".txt";

	cout << "Reading from " << filelocation << endl;
	
	ifstream myfile(filelocation); // Open the file at the location the user asks for
	if (myfile.is_open()) // If it worked write out the values
	{
		vector<string> tokens;
		set <string> unique;
		string next_line;  // Each data line
		ifstream in(filelocation);
		while (getline(in, next_line)) {
			istringstream iss(next_line);
			string token;
			while (iss >> token) {
				string nopunct = "";
				for (auto &c : token) { // Remove Punctuation      
					if (isalpha(c)) {
						nopunct += c;
					}
				}
				tokens.push_back(nopunct);
				unique.insert(nopunct);
			}
		}
		//cout << "Number of words " << tokens.size() << endl;                 //comment these lines later
		//cout << "Number of unique words " << unique.size() << endl;         //
		for (set<string>::iterator it = unique.begin(); it != unique.end(); ++it)
		//	cout << ' ' << *it;           //comment these lines later
		//cout << endl;                     //
		myfile.close();

		filelocation = filelocation.substr(0, filelocation.length() - 4);

		ofstream outfileSet;
		outfileSet.open(filelocation + "_set.txt");

		for (set<string>::iterator it = unique.begin(); it != unique.end(); ++it)
			outfileSet << *it << endl;
		outfileSet.close();

		ofstream outfileVector;
		outfileVector.open(filelocation + "_vector.txt");
		for (int i = 0; i < tokens.size(); i++) {
			outfileVector << tokens.at(i) << endl;
		}
		outfileVector.close();

		ofstream outfileMap;
		outfileMap.open(filelocation + "_1_1.txt");

		map<string, string> wordmap;
		string last = "";
		for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
			wordmap[last] = *it;
			outfileMap << wordmap[last] << ", " << last << endl;
			last = *it;
			
		}

		string state = "";
		for (int i = 0; i < 100; i++) {
			cout << wordmap[state] << " ";
			state = wordmap[state];
		}
		cout << endl << endl;

		map<string/*keys*/, vector<string>/*values*/> wordMap;
		state = "";
		for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
			wordMap[state].push_back(*it);
			
			state = *it;
		}
		state = "Luke";
		for (int i = 0; i < wordMap[state].size(); i++) {
			cout << wordMap[state].at(i) << ", ";
		}
		cout << endl << endl;

		srand(time(NULL)); // this line initializes the random number generated
						   // so you dont get the same thing every time
		state = "";
		for (int i = 0; i < 100; i++) {
			int ind = rand() % wordMap[state].size();
			cout << wordMap[state][ind] << " ";
			state = wordMap[state][ind];
		}
		cout << endl << endl;

		int M = 2;
		map<list<string>, vector<string>> finalmap;
		list<string> key;
		for (int i = 0; i < M; i++) {
			key.push_back("");
		}

		for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
			finalmap[key].push_back(*it);
			key.push_back(*it);
			key.pop_front();
		}

		key.clear();
		for (int i = 0; i < M; i++) {
			key.push_back("");
		}
		for (int i = 0; i < 100; i++) {
			int ind = rand() % finalmap[key].size();
			cout << finalmap[key][ind] << " ";
			key.push_back(finalmap[key][ind]);
			key.pop_front();
		}

		cout << endl << endl;
		outfileMap.close();

		
	
	}
	else {
		// If the file open didnt work, print out an error
		cout << "Unable to open file";
	}
	

	system("pause");
	return 0;
}