#include "Node.h"
#include "Instance.h"

void Node::featureSearch()//Literally just translated into c++ from that matlab code
{
	ofstream myfile;

	int feature = 0;
	double accuracy = 56.4;
	cout << "Running nearest neigbor with no features (default rate), using 'leave-one-out' evaluation, I get an accuracy of" << accuracy << "%" << endl;
	for (int i = 0; i < this->dataObjects.size(); i++)
	{
		vector<int> currentFeatureSet;	
		int featureToAdd;			
		double bestSoFar = 0;
		for (int k = 0; k < this->dataObjects.front().dataSize(); k++)
		{
			if (this->contains(currentFeatureSet, k + 1))
			{
				accuracy = /*leaveOneOut(this->dataObjects.at(i),this->dataObjects.at(i).getInstanceDataVector(),currentFeatureSet,i+1);*/leaveOneOut();
			}
		
			if (accuracy > bestSoFar)
			{
				bestSoFar = accuracy;
				cout << "Using feature(s) {" << k+1 << "} accuracy is " << bestSoFar << "%" << endl;
				featureToAdd = k + 1;
				currentFeatureSet.push_back(featureToAdd);
			}
			accuracy = 0;
		}

		cout << "Feature set " /*<< currentFeatureSet.size()*/;
		cout << "{ ";
		for (int i = 0; i < currentFeatureSet.size(); i++)
		{
			cout << currentFeatureSet.at(i) << ",";
		}
		cout << "}";
		cout << endl << endl;
		myfile.close();
	}
}

void Node::backwardElimination()
{
	vector<double> currentFeatureSet;
	for (int i = 0; i < this->dataObjects.front().dataSize(); i++)//push all the features we're using
	{
			
	}
}
double Node::leaveOneOut(Instance dataInstance,vector<double> data, vector<int> currentFeatures, int featureToAdd)
{
		int number_correctly_classified = 0;
		Instance object_to_classify = dataInstance; //= data(i,2:end)
		int label_object_to_classify = object_to_classify.getClassification(); // = data(i,1)	q
		double nearest_neighbor_distance = 1000000;
		double nearest_neighbor_location = 1000000;
		for (int k = 0; k < data.size(); k++)
		{
			int nearest_neighbor_label = 0;

			double distance = 0;
			if (k != featureToAdd)
			{
				for (int j = 0; j < data.size(); j++)
				{
					distance += pow((dataInstance.getInstanceDataElement(j) - this->dataObjects.at(k).getInstanceDataElement(j)), 2);
				}
				distance = sqrt(distance);
				if (distance < nearest_neighbor_distance)
				{
					nearest_neighbor_distance = distance;
					nearest_neighbor_location = k + 1;
					nearest_neighbor_label = this->dataObjects.at(k).getClassification();// = data(nearest_neighbor_location,1)
				}
			}

			if (label_object_to_classify == nearest_neighbor_label)
			{
				number_correctly_classified += number_correctly_classified + 1;
			}
		}
	accuracy = (1.0 * number_correctly_classified) / (1.0* this->dataObjects.size()); //size(data,1)
	return accuracy;
}

bool Node::contains(vector<int> featureSet, int feature)// is it in here ? if so leave
{
	if (featureSet.size() == 0)
	{
		return 1;
	}
	for (int i = 0; i < featureSet.size(); i++)
	{
		if (featureSet.at(i) == feature)
		{
			return 0;
		}
	}
	return 1;
}

string Node::readData(string filename)
{
	string sNum;//string but a number
	string number;
	ifstream list_of_data;
	list_of_data.open(filename.c_str());// converting the filename inputed from the user into an actual openable filename
	string line;

	if (list_of_data.is_open())
	{
		while (getline(list_of_data, line))
		{
			Instance instance(line);//we scan line by line
			this->dataObjects.push_back(instance);//after scanning we pass it into an array of Instances, and also partition the data into the classification and data
		}
		list_of_data.close();
	}
	return "There are " + to_string(this->dataObjects.front().dataSize()) + " features, with " + to_string(this->dataObjects.size()) + " instances.";
}
