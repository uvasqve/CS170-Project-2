#include "Node.h"
#include "Instance.h"

void Node::featureSearch(int data)//Literally just translated into c++ from that matlab code
{
	Node l;
	vector<int> currentFeatureSet;
	int feature = 0;
	double bestSoFar = 0;
	double accuracy = 0;
	for (int i = 0; i < data; i++)
	{
		std::cout << "On the " << to_string(i+1) << "th level of the search tree" << std::endl;
		int featureToAdd;
		for (int k = 0; k < data; k++)
		{
				if (l.contains(currentFeatureSet, k + 1))
				{
					std::cout << "--Considering adding the " << to_string(k + 1) << "feature" << std::endl;
					accuracy = leaveOneOut();
					//cout << "ACCu" << accuracy << endl;
				}

			//use an interator
			if (accuracy > bestSoFar)
			{
				bestSoFar = accuracy;
				cout << "Updated Acc: " << bestSoFar << ". Is also the best and the feature we want to add" << endl;
				featureToAdd = k+1;
				cout << "This should match: " << to_string(featureToAdd) << endl;
				//cout << featureToAdd << "Feautre add " << endl;

			}
		}
		currentFeatureSet.push_back(featureToAdd);
		cout << currentFeatureSet.at(i) << "What i is: " << i << endl;
		cout << "On level " << to_string(i+1) << " i added feature " << to_string(featureToAdd) << " to current set"<< endl << endl << endl << endl;
		bestSoFar = 0;
		accuracy = 0;
	}
}	

//void Node::backwardElimination(int data)
//{
////	set<int> currentFeatureSet; 
////}
//double Node::leaveOneOut(vector<int[]> data, set<int> currentFeatures, set<int> featureToAdd)
//{
//	int number_correctly_classified = 0;
//	int dataSize = 0;
//
//	for (int i = 0; i < dataSize; i++)
//	{
//		int object_to_classify; //= data(i,2:end)
//		int label_object_to_classify; // = data(i,1)
//		int nearest_neighbor_label;
//
//		double nearest_neighbor_distance = 1000000;
//		double nearest_neighbor_location = 1000000;
//		for (int k = 0; i < data; i++)
//		{
//			if (k != i)
//			{
//				double distance;
//				if (distance < nearest_neighbor_distance)
//				{
//					nearest_neighbor_distance = distance;
//					nearest_neighbor_location = k;
//					nearest_neighbor_label;// = data(nearest_neighbor_location,1)
//				}
//			}
//		}
//			if (label_object_to_classify == nearest_neighbor_label)
//			{
//				number_correctly_classified += number_correctly_classified + 1;
//			}
//
//	}
//	accuracy = number_correctly_classified; //size(data,1)
//}

/*#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;


int main()
{
	string number;
	float actual = 0;

	cout << "Enter a number" << endl;
	cin >> number;

	//hard code breaking up the number;;;
	char symbol = '0';
	int endNum = 0;

	double decimal = stod(number.substr(0, 9));
	if (symbol == '+')
	{
		decimal *= pow(10, endNum);
	}
	else if (symbol == '-')
	{
		decimal /= pow(10, endNum);
	}
	return 0;
}*/
bool Node::contains(vector<int> featureSet,int feature)
{
	if (featureSet.size() == 0)
	{
		return 1;
	}
	cout << "Feature Size for the features " << featureSet.size() << endl;
	for (int i = 0; i < featureSet.size(); i++)
	{
		cout << "Feature we're checking: " << feature << endl 
			 << "Actual feature(s) we have: " << featureSet.at(i) << endl;
		if (featureSet.at(i) == feature)
		{
			cout << "This is outputting because: " << to_string(featureSet.at(i)) << "=" << to_string(feature) << endl;
		return 0;
		}
	}
	cout << "This is outputting because the features did not match: returning" << endl;
	return 1;
}

void Node::readData()
{
	string sNum;//string but a number
	string number;
	ifstream list_of_data;
	list_of_data.open("small-test-dataset.txt");
	string line;

	if (list_of_data.is_open())
	{
		while (getline(list_of_data, line))
		{
			cout << line << endl;
			Instance instance(line);
		}
		list_of_data.close();
	}
}
