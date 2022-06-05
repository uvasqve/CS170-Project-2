#pragma once

#include <set>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>
#include <time.h>
#include <math.h>

#include "Instance.h"

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
	double leaveOneOut() { return rand() % 100; }
	double leaveOneOut(Instance,vector<double>, vector<int>, int);
	void featureSearch();
	void backwardElimination();
	bool contains(vector<int>, int);
	void setBestSoFar();
	void setAccuracy();
	void Train();
	string Test();
	int getFeature() { return feature; }
	double getAccuracy() { return accuracy; }
	double getBestSoFar() { return bestSoFar; }
	string readData(string);
};
