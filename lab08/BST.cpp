#include "BST.h"
#include <iostream>

using namespace std;

BST::BST(){
	root = nullptr;
}

void BST::insert (int a) {	
	if (root == nullptr){
		root = new Node(a);
	}
	
	else {
		root -> insert(a);
	}
}

void BST::print_inorder() {	
	if(root == nullptr){
        cout << "Tree empty" << endl;
        return;
    }

    root->print_inorder();
}

bool BST::find(int b) {
	// if (root -> find(b)) {
	// 	cout << "found " << b << endl;
	// }

	// else {
	// 	cout << "not found " << b << endl;
	// }
	bool itExists = root -> find(b);
	return itExists;
}

void BST::print_from_value(int c) {
	if (find(c)) {
		root -> print_from_value(c);
		cout << endl;
	}

	else {
		cout << "Node " << c << " not found" << endl;
	}
	
}

void BST::remove(int d) {
	if (find(d)) {
		root -> remove(d);
	}
}

void BST::clear() {
	root -> clear();
	root = nullptr;
}

BST::~BST() {
	
}

int BST::sum() {
    int add = root->sum();
    return add;	
}

int BST::size() {
    int big = root->size();
	return big;    	
}

float BST::average() {
	float ave = root->average();
	return ave;
}

////////Node implementation////////

Node::Node(int s) {
	data = s;
	left = nullptr;
	right = nullptr;
}

void Node::insert (int a) {
	if(a < data) {
		if (left == nullptr) {
			left = new Node(a);
		} 
		else {
			left->insert(a);
		}
	}	

	else if(a > data) {
		if(right == nullptr) {
			right = new Node(a);
		}
		else {
			right->insert(a);
		}
	}
		
}

void Node::print_inorder() {
	if (left != nullptr) {
		left -> print_inorder();		
	}	
	cout << data << " ";
	if (right != nullptr) {
		right -> print_inorder();
	}  
}

bool Node::find(int b) {

	if ( data == b ) {
        return true;
    }
    
    else if ( data > b ) {
    	return left ? left->find(b) : false;
    } 
       
    else  {
        return right ? right->find(b) : false;
    }

}

void Node::print_from_value(int c) {	

	if (data == c) {
		if (left != nullptr) {
			cout << left -> data << " ";		
		}	
		
		cout << data << " ";

		if (right != nullptr) {
			cout << right -> data << " ";
		}
	}
	
	if (left != nullptr) {
		left -> print_from_value(c);
	}	

	if (right != nullptr) {
		right -> print_from_value(c);
	}	
}

Node* Node::getMin(Node* compa, Node* compb){
	if (compa -> left == nullptr) {
		return compa;
	}

	if (compb -> left == nullptr) {
		return compb;
	}

	return getMin(compa -> left, compb -> left);
}

Node* Node::remove(int d) {

	if (data == d) {
		/////////////////No children////////////////////
		if (left == nullptr && right == nullptr) {
			delete this;
			return nullptr;
		}
		////////////////1 child///////////////////////////
		if (left != nullptr && right == nullptr) {
			delete this;
			return left;
		}

		if (right != nullptr &&  left == nullptr) {
			delete this;
			return right;
		}
		//////////////////2 children/////////////////////
		else { 
			int val = getMin(right -> left, right -> left -> left) -> data;
			// cout << "ALERT: " << val << endl;
			right = right -> remove(val);
			return this;					
		}
	}

	if (d < data && left != nullptr) {
		left = left -> remove(d);
	}	

	if (data < d && right != nullptr) {
		right = right -> remove(d);
	}
	return this;
}

void Node::clear() {
	if (left != nullptr) {
		left -> clear();
		left = nullptr;		
	}	
	
	if (right != nullptr) {
		right -> clear();
		right = nullptr;
	}

	delete this;

}

Node::~Node() {
	delete this;
}

int Node::sum() {	
	int add = data;	

	if (left != nullptr) {
		add += left -> sum();		
	}	

	if (right != nullptr) {
		add += right -> sum();
	}

	return add;	
}

int Node::size() {
	int start = 1;
	
	if (left != nullptr) {
		start += left -> size();		
	}	

	if (right != nullptr) {
		start += right -> size();
	}

	
	return start;	
}

float Node::average() {
	float ave;	
	int secondsum = sum();
	int secondsize = size();
	float castSum;
	float castSize;
	secondsum = sum();
	secondsize = size();
	castSum = secondsum;
	castSize = secondsize;
	ave = castSum/castSize;

	return ave; 
}
















