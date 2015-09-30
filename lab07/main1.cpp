#include "BST.h"
#include <iostream>

using namespace std;

int main (){
	BST bst;

	bst.insert(2);
	bst.insert(3);
	bst.insert(1);
	bst.insert(5);
	bst.insert(4);

	bst.print_inorder();

	cout << endl;

	cout << "Finds:" << endl;

	bst.find(1);
	bst.find(2);
	bst.find(4);
	bst.find(5);
	bst.find(23);

	cout << "print from value:" << endl;

	bst.print_from_value(5);
	bst.print_from_value(43);
}