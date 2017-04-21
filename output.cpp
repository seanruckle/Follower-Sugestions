#include <fstream>
#include <iostream>
#include <string>
#include "output.h"
#include "vertex.h"

output::output() {}		//constructor

bool output::printUser(vertex* user, char* fileName) {		//prints a single user and their centrality, (not currently used)
	std::ofstream outS;

	outS.open(fileName);
	if (!outS.is_open()) {
		std::cout << "File couldn't be opened";
		return false;
	}
	outS << "Looking for new accounts for " << user->getUser() << " (" << user->getInDegree() << ")" << " to follow" << std::endl;
	return true;
}
bool output::empty(char* fileName) {		//prints an empty file
	std::ofstream outS;

	outS.open(fileName);
	if (!outS.is_open()) {				//checks if the file could be open
		std::cout << "File couldn't be opened";
		return false;
	}
	outS << std::endl;
	outS.close();
	return true;
}
bool output::printOutput(vertex* user, std::vector<vertex*> output, char* fileName) {		//prints the user with the highest centrality and the suggestion for them
	std::ofstream outS;
	unsigned int i;

	outS.open(fileName);

	outS << "Looking for new accounts for " << user->getUser() << " (" << user->getInDegree() << ")" << " to follow" << std::endl;	//pritns the highest user
	if (!outS.is_open()) {
		std::cout << "File couldn't be opened";
		return false;
	}
	for (i = 0; i < output.size(); i++) {		//loops through the list of suggestions and prints them all
		outS << output[i]->getUser() << " (" << output[i]->getInDegree() << ")" << std::endl;
	}
	outS.close();
	return true;
}