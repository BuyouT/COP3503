#ifndef DYNAMICARRAY
#define DYNAMICARRAY
#include <iostream>
#include <string>

using namespace std;

class DynamicArray {
private:
	string *fun;
	int logicalSize;
	int physicalCapacity;
	void grow();
public:
	DynamicArray();
	DynamicArray(int capacity);
	~DynamicArray();
	bool insert(string);
	string remove();
	string remove(int index);
	void remove(string str);
	int index_of(string str);
	string item_at(int index);
	int size();
	int capacity();
	void clear();
	void copyDynamicArray(DynamicArray&);
	void addElements(DynamicArray&);
	string toString() const;
	DynamicArray& operator=(const DynamicArray&);
	const DynamicArray operator+(const DynamicArray&) const;
	const DynamicArray operator-(const DynamicArray&)const;
	string& operator[](const int index);
	friend ostream& operator<<(ostream&, const DynamicArray);
};

#endif
