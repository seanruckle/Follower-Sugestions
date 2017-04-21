#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <string>
#include "vertex.h"
#include<queue>

class graph {
private:
	std::vector<vertex*> List;		//the main graph vector
public:
	graph();		//constructor
	void populate(vertex* user, vertex* follower);			//adds the users and follower to the needed vectors
	void inputData(std::string root, std::string follower);		//puts the data in the graph
	vertex* createUser(std::string newUser);		//creates a user
	vertex* DoesItExist(std::string name);			//checks if a user exists
	vertex* calcCentrality();				//calculates the user with the highes in centrality
	int getSize();		//gets the size of the graph
	std::queue<vertex*> BFS(vertex* user);	//runs the BFS
	void deleteData();		//clears memory
	
};
#endif