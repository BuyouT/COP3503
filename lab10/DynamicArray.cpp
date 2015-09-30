#include "DynamicArray.h"

DynamicArray::DynamicArray() {
	fun = new string[5];
	logicalSize = 0;
	physicalCapacity = 5;
}
DynamicArray::DynamicArray(int capacity) {
	physicalCapacity = capacity;	
	fun = new string[capacity];
	logicalSize = 0;
}

DynamicArray::~DynamicArray() {
	delete[] fun;
}

bool DynamicArray::insert(string str) {
	if(logicalSize < physicalCapacity) {	
		fun[logicalSize]=str;
		++logicalSize;
		return true;
	}

	else if (logicalSize == physicalCapacity) {
		grow();
		insert(str);
	}

	else {
		return false;
	}
}
string DynamicArray::remove() {
	if (logicalSize > 0) {
		string tempString;
		tempString = fun[logicalSize];
		logicalSize = logicalSize-1;
		return tempString;
	}

	else {
		return "";
	}	
}
string DynamicArray::remove(int index) {
	string tempString;
	int found = 0;
	for (int i = 0; i < logicalSize; ++i) {
		if (i == index) {
			tempString = fun[i];
			fun[i] = fun[i+1];
			--logicalSize;
			++found;
		}
	}

	if (found != 0) {
		return tempString;
	}

	else {
		return "";
	}
}

void DynamicArray::remove(string str){
	for (int i = 0; i < logicalSize; ++i) {
		if (fun[i] == str) {
			fun[i] = fun [i+1];
			--i;
		}
	}
}

int DynamicArray::index_of(string str) {
	for (int i = 0; i < logicalSize; ++i) {
		if(fun[i] == str) {
			return i;
		}
	}
	return -1;
}

string DynamicArray::item_at(int index) {
	for (int i = 0; i < logicalSize; ++i) {
		if(i == index) {
			return fun[i];
		}
	}
	return "";
}

int DynamicArray::size() {
	return logicalSize;
}

int DynamicArray::capacity() {
	return physicalCapacity;
}

void DynamicArray::clear() {
	logicalSize = 0;
}

void DynamicArray::grow() {
	string *happy = new string[2*physicalCapacity];
	physicalCapacity *= 2;
	for (int i = 0; i < logicalSize; ++i) {
		happy[i] = fun[i];
	}
	delete[] fun;
	fun = happy;
}

////////////////HELPERFUNCTION////////////////////////

void DynamicArray::copyDynamicArray(DynamicArray& da) {
	fun->clear();
	for (int i = 0; i < da.size(); ++i) {
		this->insert(da.item_at(i));
	}
}

void DynamicArray::addElements(DynamicArray& da) {
	for (int i = 0; i < da.size(); ++i) {
		this->insert(da.item_at(i));
	}
}

string DynamicArray::toString() const{
	string temp;
	temp = "[ " + *fun + " ]";
	return temp;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& rhs) {
	copyDynamicArray(rhs);
}

const DynamicArray DynamicArray::operator+(const DynamicArray& rhs) const{
	// Class temp;
	// populate temp with the result of this + rhs
	// return temp
	DynamicArray temp = *this;
	temp.copyDynamicArray(temp);
	DynamicArray temp2 = rhs;
	temp.addElements(temp2);
	return temp;
}

string& DynamicArray::operator[](const int index) {
	// Return the element at index index
	return this->fun[index];
}

ostream& operator<<(ostream& os,const DynamicArray da) {
	// Ideally something like os << me.toString()
	// Just output the class as you would want it
	// return os;
	os << da.toString();
	return os;
}



