#include <fstream>
#include <iostream>
#include <string>
#include "vertex.h"

vertex::vertex() {}		//constructor
vertex::~vertex() {}	//destructor

vertex::vertex(std::string newUser) {	//constructor that adds a string, adds a version of the string in lowercase and sets visited to 0;
	int i = 0;
	char c;
	user = newUser;
	
	while (newUser[i]) {
		c = (tolower(newUser[i]));
		newUser[i] = c;
		i++;
	}
	lowerUser = newUser;
	visited = 0;
}
std::string vertex::getRoot() {		//returns a user string
	return this->user;
}

void vertex::setUser(std::string newUser) {		//sets a user
	user = newUser;
	return;
}
void vertex::addFollower(vertex* user, vertex* follower) {		//adds someone to the list of followers
	this->followers.push_back(follower);
	return;
}
void vertex::addFollowing(vertex* user, vertex* following) {		//adds someone to the list of following
	this->following.push_back(following);
	return;
}

int vertex::getSize() {			//gets the size of the followers list
	return this->followers.size();
}
std::string vertex::getLower() {	//gets the lowercase string
	return this->lowerUser;
}

std::string vertex::getUser() {		//returns a user string
	return this->user;
}
void vertex::setInDegree(int i) {		//sets the in degree
	this->inDegree = i;
	return;
}

int vertex::getInDegree() {			//gets the in degree
	return this->inDegree;
}
void vertex::setVisited(int i) {	//sets the visited value
	this->visited = i;
	return;
}
int vertex::getVisited() {		//gets the visited
	return this->visited;
}
vertex* vertex::getFollowing(int i) {	//gets a certain follower at index i
	return this->following[i];
}
int vertex::followSize() {			//gets the size of the following list
	return this->following.size();
}