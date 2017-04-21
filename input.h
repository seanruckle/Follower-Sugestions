#ifndef INPUT_H
#define INPUT_H
#include <vector>
#include "graph.h"


class input {
private:

public:
	input();	//constructor
	bool readFile(char* fileName, graph* data);		//reads the data from the file
};
#endif