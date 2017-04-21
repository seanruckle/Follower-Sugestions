#ifndef SORT_H
#define SORT_H
#include <vector>
#include "graph.h"


class sort {
private:
	std::vector<vertex*> output;	//a vector to store the output
public:
	sort();		//constructor
	std::vector<vertex*> sortCent(std::queue < vertex*> suggest);	//sorts the data by centrality and alphabetically
};
#endif