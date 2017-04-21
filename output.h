#ifndef OUTPUT_H
#define OUTPUT_H
#include "vertex.h"

class output {
private:

public:
	output();		//constructor
	bool printUser(vertex* user, char* fileName);	//prints a single user
	bool printOutput(vertex* user, std::vector<vertex*> output, char* fileName);	//prints the highest user and their suggestions
	bool empty(char* fileName);		//prints an empty file
};	
#endif
