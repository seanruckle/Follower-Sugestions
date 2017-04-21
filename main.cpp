#include <iostream>
#include "graph.h"
#include "input.h"
#include "output.h"
#include "vertex.h"
#include "sort.h"
#include <vector>

int main(int argc, char *argv[]) {

	input file;
	graph data;
	vertex* user;
	output outfile;
	std::queue<vertex*> myQueue;
	sort sortedData;
	std::vector<vertex*> output;

	if (argc != 3) {		//checks the number of inputs on the command line
		std::cout << "usage: sna inputfile outputfile" << std::endl;
		return -1;
	}
	
	if (file.readFile(argv[1], &data) == false) {			//read the file and create the graph
	//if (file.readFile("input1.txt", &data) == false) {
		return 0;
	};
	if (data.getSize() == 0) {			//if the file is empty print an empty file
		outfile.empty(argv[2]);
	//	outfile.empty("output.txt");
		return 0;
	}

	user = data.calcCentrality();		//calculates the user with the higest in centrality

	myQueue = data.BFS(user);		//runs the BFS search
	output = sortedData.sortCent(myQueue);		//sorts the data by centrallity and alphabetically

	outfile.printOutput(user, output, argv[2]);
	data.deleteData();	//frees memory
	return 0;	
}