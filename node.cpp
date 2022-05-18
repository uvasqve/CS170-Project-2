#include "node.h"
#include <iostream>
#include <string>

void Node::featureSearch(int data)//Literally just translated into c++ from that matlab code
{
	std::set<int> currentFeatureSet;

	for (int i = 0; i < data; i++)
	{
		std::cout << "On the " << std::to_string(i) << "th level of the search tree" << std::endl;
		std::set<int> featuresToAdd;
		this->bestSoFar = 0;

		for (int k = 1; k < data; k++)
		{
			if (contains(currentFeatureSet, feature))
			{
				std::cout << "--Considering adding the " << std::to_string(k) << "feature" << std::endl;
				this->accuracy = leaveOneOut();
			}
			//use an interator
			if (this->accuracy > this->bestSoFar)
			{
				this->bestSoFar = this->accuracy;
				featuresToAdd.insert(k);

			}
		}

	}
}
