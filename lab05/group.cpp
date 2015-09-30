#include "group.h"
#include <iostream>

using namespace std;

Group::Group() {
	names_size = 0;
	ages_size = 0;
}

int Group::find_index(string name){
    int index = -1;
    for(int i=0;i<names_size; i++){
        if(people[i].getName() == name){
            index = i;
            i = names_size;
        }
    }
    return index;
}

int Group::insert_person(string name, int age){
    // If our group is full, we cannot add anymore
    if(names_size == GROUP_SIZE) return 0;

    // Find where we need to insert the person
    int index = names_size;
    for(int i=0;i<names_size; i++){
        if(people[i].getName().compare(name) > 0){
            index = i;
            i = names_size;
        }
    }

    // Move everyone else down one space to make room
    for(int i=names_size;i>index;i--){
        people[i].setName(people[i-1].getName());
        people[i].setAge(people[i-1].getAge());
    }

    // Insert the person
    people[index].setName(name);
    people[index].setAge(age);
    names_size++;
    return 1;
}

int Group::delete_person(string name){
    // Check if the person is in the list
    int index = find_index(name);
    if(index == -1) return 0;

    // Move everyone lower than the one we are deleting 
    for(int i=index;i<names_size;i++){
        people[i].setName(people[i+1].getName());
        people[i].setAge(people[i+1].getAge());
    }

    names_size--;
    ages_size--;

    return 1;
}

void Group::print_people(){
    for(int i=0;i<names_size;i++){
        cout << people[i].getName() << ", " << people[i].getAge() << endl;
    }
}

string Person::getName() {
	return names;
}

int Person::getAge() {
	return ages;
}

void Person::setName(string names) {
	this -> names = names;
}

void Person::setAge(int ages) {
	if (ages >= 0) {
		this -> ages = ages;
	}
	
	else {
		cout << "Invalid age" << endl;
	}
}




