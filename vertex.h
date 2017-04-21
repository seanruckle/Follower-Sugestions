#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include <vector>

class vertex {
private:
	std::string user;		//string to store the user
	std::string lowerUser;	//string to store a lowercase version of th user
	std::vector<vertex*> followers;		//pointers to the people following the user
	std::vector<vertex*> following;		//pointers to the people the user is following
	int inDegree;		//the in degree of a user
	int visited;		//if the user is visited or not
public:
	vertex();	//constructor
	~vertex();	//destructor
	vertex(std::string user);		//constructor that adds a user and calculates some other things
	std::string getRoot();		//gets a user
	void setUser(std::string newUser);		//sets a user
	void addFollower(vertex* user, vertex* follower);	//adds a follower
	void addFollowing(vertex* user, vertex* following);	//adds someone following
	int getSize();		//gets the size of the followers list
	std::string getLower();	//gets the lowercase string
	std::string getUser();		//gest a user
	void setInDegree(int i);	//sets the in degree
	int getInDegree();		//gets the indegree
	void setVisited(int i);		//sets the visited
	int getVisited();		//gets the visited
	vertex* getFollowing(int i);	//gets a follower at a certain index
	int followSize();			//gets the size of the following list
};
#endif