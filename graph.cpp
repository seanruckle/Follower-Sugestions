#include <fstream>
#include <iostream>
#include <string>
#include "graph.h"
#include "vertex.h"
#include <queue>

graph::graph() {}		//constructor

vertex* graph::DoesItExist(std::string name) {		//checks if a person is already in the graph
	int i = 0;
	int j = List.size();

	for (i = 0; i < j; i++) {					//loops through the graph to see if a person is already in it
		if (List[i]->getRoot() == name) {
			return this->List[i];
		}			
	}
	return NULL;
}

void graph::inputData(std::string newUser, std::string newFollower) {	//inputs data into the graph
	vertex* user = NULL;
	vertex* follower = NULL;
	
	if ((user = DoesItExist(newUser)) == NULL) {
		user = createUser(newUser);					//creates a new user if it doesn't already exist
	}
	if ((follower = DoesItExist(newFollower)) == NULL) {
		follower = createUser(newFollower);			//creates a follower if it already exists
	}	
	populate(user, follower);		//populates the user and follower
	return;
}

vertex* graph::createUser(std::string newUser) {	//creates a new user(newUser) 
	vertex* user;
	user = new vertex(newUser);		//creates a new user
	this->List.push_back(user);
	//user->setUser(newUser);

	return user;
}
void graph::populate(vertex* user, vertex* follower) {	//adds the follower to the users following list and the user to the followers follower list
	user->addFollower(user, follower);
	follower->addFollowing(follower, user);
}

vertex* graph::calcCentrality() {		//calculates the user with the highest centrality 
	int i = 0;
	int j = List.size();
	int temp = 0;
	vertex* user = NULL;
	vertex*userCmp = NULL;
	for (i = 0; i < j; i++) {
		if (List[i]->getSize() > temp) {		//loops through finding the user with the highest centrality
			temp = List[i]->getSize();
			user = List[i];
		}
		if (List[i]->getSize() == temp) {		//if there are two with the same centrality it is sorted alphabetically
			userCmp = List[i];
			if ((user->getLower()) > (userCmp->getLower())) {
				user = userCmp;
			}
		}
		List[i]->setInDegree(List[i]->getSize()); //sets the in degree for every user
	}
	return user;
}

int graph::getSize() {		//returns the number of verticies in the graph
	return List.size();
}
std::queue<vertex*> graph::BFS(vertex* user) {		//does the BFS
	std::queue<vertex*> myQueue;
	std::queue<vertex*> printQueue;
	vertex* temp;
	vertex*  depth1;
	vertex* depth2;
	int i;
	int j;
	int k;
	//int test;

	//myQueue.push(user);
	user->setVisited(1);

	for (k = 0; k < user->followSize(); k++) {	//loops through the list and sets the people of depth 1 to visited so they don't get added to the output
		temp = user->getFollowing(k);
		temp->setVisited(1);
	}
		for (i = 0; i < user->followSize(); i++) {	//loops through the list of poeple the root user is following
			depth1 = user->getFollowing(i);			//sets a user to a temp value
			for (j = 0; j < depth1->followSize(); j++) {	//loops through the followers of a person being followed by the root user
				depth2 = depth1->getFollowing(j);
				if (depth2->getVisited() == 0) {	//if the person of depth 2 isn't visited it gets added to the queue and set as visited
					depth2->setVisited(1);
					myQueue.push(depth2);
				}
			}
		}
		//printf("pause");
	return myQueue;
}

void graph::deleteData() {	//void graph::deleteData()
	unsigned int i;

	for (i = 0; i < List.size(); i++) {
		delete List[i];
	}

	return;
}