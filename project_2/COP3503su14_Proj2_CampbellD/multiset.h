#ifndef MULTISET_H
#define MULTISET_H

using namespace std;

class Item{

private:
	string name;
	int count;
	

public:
	Item();
	Item(string, int);
	~Item();

	string getName();
	int getCount();
	void setName(string);
	void setCount(int);	
};

class Multiset{

private:	
	vector<Item> list;
	vector<Item> list2;
	vector<Item> list3;
	int outputMode;

	Item convertStringToItem(string);

	
public:
	Multiset();
	~Multiset();

	void setList(vector<Item>);
	vector<Item> getList();
	void setOutputMode(int);
	int getOutputMode();

	void readListFromFile(int);
	void testFile(string);
	bool readListFromFile(string);
	void unionSet();
	void saveToFile();
	void find();
	void insert();
	void clear();
	void print();
	void deleteFromList();
	void reduce();
	void max();
};


#endif