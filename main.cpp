#include <iostream>

#include "Node.h"
#include "Instance.h"
using namespace std;

int main()
{
	srand(time(NULL));
	int number_of_features = 0;
	int algorithm_selection = 0;
	cout << "Welcome to Bertie Woosters (change this to your name) Feature Selection Algorithm" << endl;
	cout << "Please enter total number of features: ";
	cin >> number_of_features;
	cout << "Type the number of the algorithm you want to run." << endl;
	cout << "Forward Selection" << endl
		<< "Backward Elimination" << endl
		<< "My special algorithm" << endl;
	cin >> algorithm_selection;
	Node n;
	n.readData();
	//n.featureSearch(number_of_features);
	n.featureSearch();
	return 0;
}
