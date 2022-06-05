#include "Node.h"
#include "Instance.h"

void Node::featureSearch()//Literally just translated into c++ from that matlab code
{
	int feature = 0;
	double accuracy = 0;
	
	for (int i = 0; i < this->dataObjects.size(); i++)
	{
		vector<int> currentFeatureSet;	
		int featureToAdd;			
		double bestSoFar = 0;
		//cout << "This will be the classification for our instance:-l\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ " << this->dataObjects.at(i).getClassification() << endl;
		for (int k = 0; k < this->dataObjects.front().dataSize(); k++)
		{
			if (this->contains(currentFeatureSet, k + 1))
			{
				std::cout << "On the " << to_string(k + 1) << "th level of the search tree" << std::endl;
			//	cout << "This will be the classicfications data: " << this->dataObjects.at(i).getInstanceDataElement(k) << endl;
				std::cout << "--Considering adding the " << to_string(k + 1) << "feature" << std::endl;
				//cout << "Random vector elements " << this->dataObjects.at(i).getInstanceDataVector().at(k) << endl;
				//cout << "Currnet features : " << currentFeatureSet.at(i) << endl;
				accuracy = leaveOneOut(this->dataObjects.at(i),this->dataObjects.at(i).getInstanceDataVector(),currentFeatureSet,i+1);/*leaveOneOut();*/
				cout << "Accuracy right after coming out of leaveontout: " << accuracy << endl;
				cout << "Accuracy right after coming out of leaveontout: " << bestSoFar << endl;
			}
		
			if (accuracy > bestSoFar)
			{
				bestSoFar = accuracy;
			cout << "------------------------Updated Acc: " << bestSoFar << ". Is also the best and the feature we want to add ---------------------------------------" << endl;
				featureToAdd = k + 1;
	//			cout << "This should match: " << to_string(featureToAdd) << endl;
				//cout << featureToAdd << "Feautre add " << endl;
				currentFeatureSet.push_back(featureToAdd);
			}
			accuracy = 0;

		}

		cout << "Using feature(s): " << currentFeatureSet.size();
		cout << "{ ";
		for (int i = 0; i < currentFeatureSet.size(); i++)
		{
			cout << currentFeatureSet.at(i) << ",";
		}
		cout << "}";
//		cout << currentFeatureSet.at(i) << "What i is: " << i << endl;
//		cout << "On level " << to_string(i + 1) << " i added feature " << to_string(featureToAdd) << " to current set" << endl << endl << endl << endl;
		//bestSoFar = 0;
	}
}

void Node::backwardElimination(int data)
{
	//	set<int> currentFeatureSet; 
	//}
}
double Node::leaveOneOut(Instance dataInstance,vector<double> data, vector<int> currentFeatures, int featureToAdd)
{
	int number_correctly_classified = 0;

	//for (int i = 0; i < data.size(); i++)
	//{
	//	
		Instance object_to_classify = dataInstance; //= data(i,2:end)
		int label_object_to_classify = object_to_classify.getClassification(); // = data(i,1)	q
		//int nearest_neighbor_label = 0;
		//cout << "the label of the one we want to classify: ----------------------------------------------" << label_object_to_classify << endl;
		//cout << "Passed data 1:" << dataInstance.getInstanceDataElement(i) << endl;
		//cout << "Object element 1:" << data.at(i) << endl;
		//cout << "Passed data 2:" << object_to_classify.getInstanceDataElement(i) << endl;
		//cout << "This the label : " << label_object_to_classify << endl;
		//double nearest_neighbor_distance = 1000000;
		//double nearest_neighbor_location = 1000000;
		double nearest_neighbor_distance = 1000000;
		double nearest_neighbor_location = 1000000;
		for (int k = 0; k < data.size(); k++)
		{
			int nearest_neighbor_label = 0;

			double distance = 0;
			if (k != featureToAdd)
			{
				//cout << "new round: " << k <<	 endl;
				
				for (int j = 0; j < data.size(); j++)
				{
					////cout << "Passed data comparinson" << dataInstance.getInstanceDataElement(j) << endl;
					////cout << "comparing to: " << data.at(j) << endl;
					//distance += pow((this->dataObjects.at(j).getInstanceDataElement(i) - this->dataObjects.at(k).getInstanceDataElement(j)),2);
					//distance += pow((data.at(i) - this->dataObjects.at(k).getInstanceDataElement(j)), 2);
					distance += pow((dataInstance.getInstanceDataElement(j) - this->dataObjects.at(k).getInstanceDataElement(j)), 2);
				//	cout << "Is this actually changing " << this->dataObjects.at(k).getInstanceDataElement(j) << endl << endl;
					/*cout << "distance before suqaring" << distance << endl;*/
				}
				distance = sqrt(distance);
				//cout << "distancafter  suqaring" << distance << endl;
	//			cout << "This is the distance : " << distance << endl;
	///*			cout << "New line: " << endl;*/
				//cout << "Nearest neighbor distance: 1" << nearest_neighbor_distance << endl;
				if (distance < nearest_neighbor_distance)
				{
					nearest_neighbor_distance = distance;
					//cout << "Nearest neighbor distance:2 " << nearest_neighbor_distance << endl;
					nearest_neighbor_location = k + 1;
					//cout << "k = " << k << endl;
					cout << "Nearest neigbor location: " << nearest_neighbor_location << endl;
					nearest_neighbor_label = this->dataObjects.at(k).getClassification();// = data(nearest_neighbor_location,1)
					//cout << "label of what we're passing in : " << dataInstance.getClassification() << endl;
					//cout << "Label of the object we working with : " << this->dataObjects.at(k).getClassification() << endl;
					//cout << "Label of nearest neighbor " << nearest_neighbor_label << endl;
				}
			}

			if (label_object_to_classify == nearest_neighbor_label)
			{
				number_correctly_classified += number_correctly_classified + 1;
			}
		}
			//if (label_object_to_classify == nearest_neighbor_label)
			//{
			//	number_correctly_classified += number_correctly_classified + 1;
			//}
	//		 
	//}
	cout << "Instances correctly guessed: " << number_correctly_classified/* << "data size : " << this->dataObjects.size()*/ << endl;
	accuracy = (1.0 * number_correctly_classified) / (1.0* this->dataObjects.size()); //size(data,1)
	cout << "accuracy:::::: " << accuracy * 100 << "%" << endl;
	return accuracy;
}

bool Node::contains(vector<int> featureSet, int feature)
{
	if (featureSet.size() == 0)
	{
		return 1;
	}
	//cout << "Feature Size for the features " << featureSet.size() << endl;
	for (int i = 0; i < featureSet.size(); i++)
	{
		cout << "Feature we're checking: " << feature << endl
			<< "Actual feature(s) we have: " << featureSet.at(i) << endl;
		if (featureSet.at(i) == feature)
		{
		//	cout << "This is outputting because: " << to_string(featureSet.at(i)) << "=" << to_string(feature) << endl;
			return 0;
		}
	}
	//cout << "This is outputting because the features did not match: returning" << endl;
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
		//int i = 0;
		while (getline(list_of_data, line))
		{
			
			//cout << line << endl;
			Instance instance(line);
			this->dataObjects.push_back(instance);
			//cout << "This is how many times the while loop is running: " << i << endl << endl;
		}
		list_of_data.close();
	}
}
