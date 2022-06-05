#include <iostream>

#include "Node.h"
#include "Instance.h"
using namespace std;

int main()
{
	srand(time(NULL));
	int choice = 0;
	string filename;
	cout << "Welcome to Ubaldo's Feature Selection Algorithm" << endl;
	cout << "Type in the file you want to test: " << endl;
	cin >> filename;
	cout << "Type the number of the algorithm you want to run." << endl;
	cout << "(1) Forward Selection" << endl
		<< "(2) Backward Elimination" << endl;
	cin >> choice;

	if (choice == 1)
	{
		Node n;
		cout << n.readData(filename) << endl;
		n.featureSearch();
	}
	if (choice == 2)
	{
		Node n;
		n.readData(filename);
		n.backwardElimination();
	}


	return 0;
}
