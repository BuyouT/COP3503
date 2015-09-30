#ifndef GROUP_H
#define GROUP_H
#include <string>

using namespace std;

const int GROUP_SIZE = 10;

class Person {
	private:
		string names;
		int ages;
	public:
		string getName();
		void setName(string names);
		int getAge();
		void setAge(int ages);		
};

class Group {
	private:	
		int names_size;
		int ages_size;
		Person people[GROUP_SIZE];
	public:
		Group();		
		int insert_person(string, int);
		int delete_person(string);
		void print_people();
		int find_index(string);
};

#endif
