#include <fstream>
#include <iostream>
#include <string>
#include "input.h"
#include "vertex.h"
#include "graph.h"
input::input() {}		//constructor

bool input::readFile(char* fileName, graph* data) {		//inputs data from ifle
	std::ifstream inS;
	std::string root;
	std::string follower;
	vertex newnode;
	//graph data;
	//bool test;

	inS.open(fileName);		//opens specified file

	if (!inS.is_open()) {
		std::cout << "File couldn't be opened"<<std::endl;		//checks if the file can be opened
		return false;
	}

	while (!inS.eof()) {			//loops through the file and gets the data
		inS >> root >> follower;
		if (!inS.eof()) {
			data->inputData(root, follower);	//send the data to be put in the graph
		}
	}
	return true;
}
