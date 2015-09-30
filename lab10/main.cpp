// Author: Purnell Jones
// File: main.cpp

#include <iostream>

#include "DynamicArray.h"

using namespace std;

int main(){

	DynamicArray myDA;

	myDA.insert("pencil");
	myDA.insert("markers");
	myDA.insert("ruler");
	myDA.insert("Gameboy");
	myDA.insert("Laptop");
	myDA.insert("cookies"); 

	cout << "size is: " << myDA.size() << endl;
	cout << "size is: " << myDA.capacity() << endl;
	

	//myDA.remove();
	

	myDA.remove(1);

	

	// myDA.insert("yeah");
	// myDA.insert("eggs");

	cout << "Element: " << myDA.item_at(1) << endl;
	cout << "Element: " << myDA.item_at(4) << endl;

	cout << "size is: " << myDA.size() << endl;
	cout << "size is: " << myDA.capacity() << endl;

	// //int test = myDA.index_of("markers");
	// //cout << test << endl;
	// myDA.remove("pencil");
	

	// myDA.item_at(4);
	

	// myDA.clear();
	


	// myDA.insert("paper");
	// myDA.insert("dirt");

	// cout << myDA.toString() << endl;

	// DynamicArray myDA2(5);

	// myDA2.insert("hammer");
	// myDA2.insert("wrench");

	// cout << myDA2.toString() << endl;

	// myDA.addElements(myDA2);

	// cout << myDA.toString() << endl;	

	return 0;
}