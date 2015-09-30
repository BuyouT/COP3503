#include "BST.h"
#include <iostream>

using namespace std;

int main() {
	BST *bst = new BST();

	bst->insert(2);
	bst->insert(3);
	bst->insert(1);
	bst->insert(5);
	bst->insert(4);
	bst->insert(8);
	bst->insert(7);
	bst->insert(11);
	bst->insert(10);
	bst->insert(9);
	bst->insert(12);

	bst->print_inorder();

	cout << endl;

	//bst->print_from_value(5);

	//cout << endl;

	cout << "Expected: 15" << endl;

	cout << "Received: " << flush;

	cout << bst->sum();

	cout << endl;

	cout << "Expected: 5" << endl;

	cout << "Received: " << flush;	

	cout << bst->size();

	cout << endl;

	cout << "Expected: 3" << endl;

	cout << "Received: " << flush;	

	cout << bst->average();

	cout << endl;

	bst->remove(8);

	cout << endl;

	//bst->clear();

	bst->print_inorder();

	cout << endl;

	return 0;
}
