#pragma once

#include <set>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;
class Node
{
private:
	double bestSoFar;
	double accuracy;
	vector<double> data;
	int feature;
	set<int> features;
	vector<Instance> dataObjects;
public:
	Node() {}
	double leaveOneOut() { return rand()%100; }
	double leaveOneOut(vector<int[]>, set<int>, set<int>);
	void featureSearch(int);
	void backwardElimination(int);
	bool contains(vector<int>,int);
	void setBestSoFar();
	void setAccuracy();
	void Train();
	string Test();
	int getFeature() { return feature; }
	double getAccuracy() { return accuracy; }
	double getBestSoFar() { return bestSoFar; }
	void readData();
};
