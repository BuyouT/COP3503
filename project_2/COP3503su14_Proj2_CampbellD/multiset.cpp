#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>
#include "multiset.h"

using namespace std;

Item::Item(){}

Item::Item(string newName, int newCount){
	name = newName;
	count = newCount;
}



Item::~Item(){}

string Item::getName(){
	return name;
}
int Item::getCount(){
	return count;
}
void Item::setName(string newName){
	name = newName;
}
void Item::setCount(int newAge){
	count = newAge;
}

/////////////////////////////////////////////////////////////////
// Multiset                                                    //
/////////////////////////////////////////////////////////////////

Multiset::Multiset(){
	outputMode = 1; // 0 = silent, 1 = normal, 2 = verbose
}

Multiset::~Multiset(){}


bool sortByName(Item &A, Item &B) //function to sort items by name
{
	return (A.getName() < B.getName());
}

vector<Item> Multiset::getList(){
	return list;
};

void Multiset::setOutputMode(int newMode){
	outputMode = newMode;
}

int Multiset::getOutputMode(){
	return outputMode;
}

bool Multiset::readListFromFile(string fileName){
	fileName += ".txt"; 
	std::ifstream inFile(fileName.c_str()); // attempt to open the file
	if (inFile.fail())
		std::cerr << "File " << fileName << ".txt" << " failed to open.\n";
	if (inFile.is_open()){ // if it is open
		if (outputMode == 2) cout << "Success opening file.\n";// if in verbose mode
		for (std::string line; getline(inFile, line);) // go through each line				
			list.push_back(convertStringToItem(line)); // add the line to the list
		if (outputMode > 0) cout << "New multiset loaded.\n";
		return true;
	}
	else{
		return false;
	}
}

void Multiset::testFile(string fileName){
	ifstream file;
	//bool result = true;
	file.exceptions(ifstream::failbit | ifstream::badbit);
	try {
		//file.open(fileName);
		//while (!file.eof()) file.get();
	}
	catch (ifstream::failure e) {
		cerr << "Exception opening/reading file.\n";
		if (outputMode == 2) cout << "Test failed.\n";// if in verbose mode
		//result = false;
	}
	//return result;

	file.close();
}

void Multiset::readListFromFile(int choice){
	string fileName;
	std::cin >> fileName; fileName += ".txt"; // ask for the file name
	//testFile(fileName); // test for errors
	std::ifstream inFile(fileName.c_str()); // attempt to open the file
	if (inFile.fail())
		std::cerr << "File: " << fileName << ".txt" << " failed to open.\n";
	if (inFile.is_open()){ // if it is open
		switch (choice){
		case 0: // read list from file
			list.clear(); if (outputMode == 2) cout << "List cleared.\n";// if in verbose mode
			for (std::string line; getline(inFile, line);) // go through each line
				list.push_back(convertStringToItem(line)); // add the line to the list
			if (outputMode > 0) cout << "New multiset loaded.\n";
			break;
		case 1: // subtract: if current(list) > file(list2), keep with difference, else delete
			list2.clear(); // file
			for (std::string line; getline(inFile, line);) // go through each line				
				list2.push_back(convertStringToItem(line)); // add the line to the list			
			list3.clear();
			for (std::vector<string>::size_type i = 0; i != list.size(); i++){  // for each current list item
				for (std::vector<string>::size_type j = 0; j != list2.size(); j++) { // for each file list item
					if (list[i].getName() == list2[j].getName() && list[i].getCount() > list2[j].getCount()){ // if duplicate is found and current(list) > file(list2)
						list3.push_back(Item(list[i].getName(), list[i].getCount() - list2[j].getCount()));
						if (outputMode == 2) cout << "Duplicate found.\n";// if in verbose mode
					}
				}
			}
			list.clear(); list = list3; list2.clear(); list3.clear();
			if (outputMode > 0) cout << "Subtraction completed.\n";// if not in silent mode
			break;
		case 2: // difference: Add it if it doesn't exist. Count = |a - b| if it does already exist. if count = 0, delete item
			for (std::string line; getline(inFile, line);) // go through each line				
				list.push_back(convertStringToItem(line)); // add the line to the list
			list2.clear();
			std::sort(list.begin(), list.end(), sortByName); // sort the list
			for (std::vector<string>::size_type i = 0; i != list.size(); i++) { // for each list item
				if (i < list.size() - 1 && list[i + 1].getName() == list[i].getName()){ // if duplicate is found
					if (abs(list[i].getCount() - list[i + 1].getCount()) != 0){
						list2.push_back(Item(list[i].getName(), abs(list[i].getCount() - list[i + 1].getCount()))); // add it to temp list
						if (outputMode == 2) cout << "Match found.\n";// if in verbose mode
					}
				}
				else if (i == list.size() && list[i - 2].getName() != list[i - 1].getName())list2.push_back(list[i - 1]); // last two aren't the same, add last one
				else if (i > 0 && list[i - 1].getName() == list[i].getName()){} //do nothing
				else list2.push_back(list[i]);
			}
			list.clear(); list = list2; list2.clear();			
			if (outputMode > 0) cout << "Difference completed.\n";// if not in silent mode
			break;
		case 3: // Intersection: if they both exist, take the minimum, else, nothing gets added to the set
			for (std::string line; getline(inFile, line);) // go through each line				
				list.push_back(convertStringToItem(line)); // add the line to the list
			list2.clear();
			std::sort(list.begin(), list.end(), sortByName); // sort the list
			for (std::vector<string>::size_type i = 0; i <= list.size(); i++) { // for each list item
				if (i < list.size() - 1 && list[i + 1].getName() == list[i].getName()){ // if duplicate is found					
					list2.push_back(Item(list[i].getName(), min(list[i].getCount(), list[i + 1].getCount()))); // add it to temp list
					if (outputMode == 2) cout << "Match found.\n";// if in verbose mode
				}
			}
			list.clear(); list = list2; list2.clear();
			if (outputMode > 0) cout << "Intersection completed.\n";// if not in silent mode
			break;		
		}
	}
	else
		cerr << "Error opening file.\n";
}

void Multiset::unionSet(){ 
	list2.clear();
	std::sort(list.begin(), list.end(), sortByName); // sort the list
	for (std::vector<string>::size_type i = 0; i != list.size(); i++) { // for each list item
		if (i < list.size() - 1 && list[i + 1].getName() == list[i].getName()){ // if duplicate is found
			list2.push_back(Item(list[i].getName(), list[i].getCount() + list[i + 1].getCount())); // add it to temp list
			if (outputMode == 2) cout << "Match found.\n";// if in verbose mode
		}
		else if (i == list.size() && list[i - 2].getName() != list[i - 1].getName())list2.push_back(list[i - 1]); // last two aren't the same, add last one
		else if (i > 0 && list[i - 1].getName() == list[i].getName()){} //do nothing
		else list2.push_back(list[i]);
	}
	list.clear(); list = list2; list2.clear();
	if (outputMode > 0) cout << "Union completed.\n"; // if not in silent mode
}

void Multiset::saveToFile(){
	string outputFileName;
	std::cin >> outputFileName; outputFileName += ".txt";// ask for the file name
	testFile(outputFileName);
	ofstream outFile(outputFileName.c_str());// attempt to open the file
	if (outFile.is_open()){// if it is open
		if (outputMode == 2) cout << "File opened.\n";// if in verbose mode
		for (std::vector<string>::size_type i = 0; i != list.size(); i++) { // for each list item
			outFile << list[i].getName() << " " << list[i].getCount() << "\n"; // add that item to file
		}
		outFile.close();
		if (outputMode > 0) cout << "Save to " << outputFileName << " completed.\n";// if not in silent mode
	}
	else
		cout << "Error opening file.\n";
}

void Multiset::find(){
	bool foundString = false;
	string stringInQuestion;
	int count = -1;
	std::cin >> stringInQuestion;// ask for the search string
	for (std::vector<string>::size_type i = 0; i != list.size(); i++) { // for each list item
		if (list[i].getName() == stringInQuestion) {
			foundString = true; // if the list item equals the search string
			count = list[i].getCount();
			if (outputMode == 2) cout << "Item found.\n";// if in verbose mode
		}
	}	
	if (foundString) cout << "Item " << stringInQuestion << " found with count " << count << ".\n";
	else cout << "Item " << stringInQuestion << " not found.\n";
}

void Multiset::insert(){ // if item exists, add counts together
	string stringToInsert, countToInsert;
	std::cin >> stringToInsert; // ask for the string to insert
	std::cin >> countToInsert; // ask for the count to insert
	int count = atoi(countToInsert.c_str());
	list.push_back(convertStringToItem(stringToInsert + " " + countToInsert)); // add it to the list

	list2.clear();
	std::sort(list.begin(), list.end(), sortByName); // sort the list
	for (std::vector<string>::size_type i = 0; i != list.size(); i++) { // for each list item
		if (i < list.size() - 1 && list[i + 1].getName() == list[i].getName()){ // if duplicate is found
			count = list[i].getCount() + list[i + 1].getCount();
			list2.push_back(Item(list[i].getName(), count)); // add it to temp list
			if (outputMode == 2) cout << "Duplicate found.\n";// if in verbose mode
		}
		else if (i == list.size() && list[i - 2].getName() != list[i - 1].getName())list2.push_back(list[i - 1]); // last two aren't the same, add last one
		else if (i > 0 && list[i - 1].getName() == list[i].getName()){} //do nothing
		else list2.push_back(list[i]);
	}
	list.clear();
	list = list2;
	list2.clear();

	if (outputMode > 0) cout << stringToInsert << " inserted with count " << count << ".\n";// if not in silent mode
}

void Multiset::clear(){
	list.clear();
	if (outputMode > 0) cout << "Reset completed\n";
}

void Multiset::print(){
	cout << "Current multiset:\n";
	for (std::vector<string>::size_type i = 0; i != list.size(); i++) // for eact list item
		cout << list[i].getName() << " " << list[i].getCount() << "\n"; // print list item
}

Item Multiset::convertStringToItem(string input){
	std::istringstream split(input);
	std::vector<std::string> tokens;
	for (std::string each; std::getline(split, each, ' '); tokens.push_back(each));
	if (tokens.size() != 2){
		cerr << "One or more of the lines of the file were not in the correct format.\nAn example of the correct format is; apple 5\n";
		return Item();
	}
	else
		return Item(tokens[0], atoi(tokens[1].c_str()));
}

void Multiset::deleteFromList(){
	string stringToDelete;
	bool itemFound = false;
	std::cin >> stringToDelete;// ask for the string to delete
	for (std::vector<string>::size_type i = 0; i != list.size() - 1; i++)  // for each list item
		if (list[i].getName() == stringToDelete){
			list.erase(list.begin() + i); //remove	list item if it matches	
			if (outputMode > 0) cout << "Item " << stringToDelete << " deleted.\n";
			itemFound = true;
		}
	if (outputMode > 0 && !itemFound) cout << "Item " << stringToDelete << " not in multiset.\n";
}

void Multiset::reduce(){
	bool foundString = false;
	string stringInQuestion;
	std::cin >> stringInQuestion;// ask for the search string
	int amount;
	std::cin >> amount;// ask for the amount
	for (std::vector<string>::size_type i = 0; i != list.size(); i++) { // for each list item
		if (list[i].getName() == stringInQuestion) {// if the list item equals the search string
			foundString = true; 
			if (outputMode == 2) cout << "Match found.\n";// if in verbose mode
			list[i].setCount(list[i].getCount() - amount);
			if (list[i].getCount() - amount < 1){
				list.erase(list.begin() + i); //remove	list item if < 0
				cout << "Item " << stringInQuestion << " removed.\n";
			}
			else if (outputMode > 0) cout << "Item " << stringInQuestion << " reduced to " << list[i].getCount() << "\n";// if not in silent mode
		} 
	}
	if (!foundString) cout << stringInQuestion << " not in multiset.\n";
}

void Multiset::max(){
	list2.clear();
	std::sort(list.begin(), list.end(), sortByName); // sort the list
	for (std::vector<string>::size_type i = 0; i != list.size(); i++) { // for each list item
		if (i < list.size() - 1 && list[i + 1].getName() == list[i].getName()){ // if duplicate is found
			list2.push_back(Item(list[i].getName(), std::max(list[i].getCount(), list[i + 1].getCount()))); // add it to temp list
			if (outputMode == 2) cout << "Match found.\n";// if in verbose mode
		}
		else if (i == list.size() && list[i - 2].getName() != list[i - 1].getName())list2.push_back(list[i - 1]); // last two aren't the same, add last one
		else if (i > 0 && list[i - 1].getName() == list[i].getName()){} //do nothing
		else list2.push_back(list[i]);
	}
	list.clear(); list = list2; list2.clear();
	if (outputMode > 0) cout << "Max completed.\n"; // if not in silent mode
}