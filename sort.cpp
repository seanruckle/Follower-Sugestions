#include <fstream>
#include <iostream>
#include <string>
#include "graph.h"
#include "vertex.h"
#include <queue>
#include "sort.h"

sort::sort() {}		//constructor

std::vector<vertex*> sort::sortCent(std::queue < vertex*> suggest){		//sorts the data
	vertex* temp;
	unsigned int i;
	unsigned int j;
	//int k;
	int check = 0;
	
	if (suggest.size() == 0) {	//if the suggestion list is empty it does nothing and leaves
		return output;
	}
	while (suggest.size() != 0) {		//loops through until the suggested list is empty
		temp = suggest.front();			//gets and removes the value from the suggestion list
		suggest.pop();
		for (i = 0; i <= output.size(); i++) {		//loops through the entire output list
			
			if (output.size() == 0) {			//output is empty
				output.push_back(temp);
				break;
			}
			if (i == output.size()) {		//at the end of the vector
				output.push_back(temp);
				break;
			}
			if (temp->getInDegree() < output[i]->getInDegree()) {
				//if the new in centrality is less then the current
				continue;
			}
			else if (temp->getInDegree() > output[i]->getInDegree()) {	//if the new in centrality is greater then the current
				/////////////////
				if (output[i] == output.front()) {
					output.insert(output.begin(), temp);
					break;
				}
				/////////////////
				output.insert(output.begin() + i, temp); //changed
				break;
			}
			else if (temp->getInDegree() == output[i]->getInDegree()) { //if the in centrality is the same
				//sort alphabetically
				j = i;
				check = 0;
				while (j < output.size() && check == 0) {
					if (j == output.size()) {		//at the end of the vector
						output.push_back(temp);
						break;
					}
					if (temp->getInDegree() != output[j]->getInDegree()) {		//if it is no longer equal and all other strings were the same
						/////////////////
						if (output[j] == output.front()) {
							output.insert(output.begin(), temp);
							break;
						}
						/////////////////
						output.insert(output.begin() + j, temp); //changed this thing
						check = 1;
						break;
					}
					/////////////////
					if (output[j] == output.back()) {
						if (temp->getLower() > output[j]->getLower()) {
							output.push_back(temp);
						}
						else {
							output.insert(output.begin() + j, temp);
						}
						break;
					}
					/////////////////
					if (temp->getLower() > output[j]->getLower() && temp->getLower() < output[j + 1]->getLower()) {		//alphabetically after the curent and before the next
						/////////////////
						if (output[j] == output.back()) {
							output.insert(output.begin() + j, temp);
							break;
						}
						/////////////////
						output.insert(output.begin() + j + 1, temp);
						check = 1;
						break;
					}
					else if (temp->getLower() < output[j]->getLower()) {		//alphabetically  before the next
						output.insert(output.begin() + j, temp);
						check = 1;
						break;
					}
					j++;
				}
				break;
			}
		}
	}
	return output;
}