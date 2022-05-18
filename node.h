#pragma once
#include <set>
#include <cstdlib>

class Node
{
private:
	double bestSoFar;
	double accuracy;
	int data;
	int feature;
public:
	Node();
	double leaveOneOut() { return rand(); }	
	double leaveOneOut(int,std::set<int>,std::set<int>);
	std::set<int> features;
	void featureSearch(int);
	bool contains(std::set<int>, int feature);
	void setBestSoFar();
	void setAccuracy();
	int getFeature() { return feature; }
	double getAccuracy() { return accuracy; }
	double getBestSoFar() { return bestSoFar; }
};

