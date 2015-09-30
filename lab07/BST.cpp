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
	root -> find(b);
}

void BST::print_from_value(int c) {
	if (root -> find(c)) {
		root -> print_from_value(c);
		cout << endl;
	}

	else {
		cout << "Node " << c << " not found" << endl;
	}
	
}

void BST::remove(int) {

}

void BST::clear() {

}

BST::~BST() {

}

int BST::sum() {

}

int BST::size() {

}

float BST::average() {
	
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

	if (find(c)) {
		
		if (left != nullptr) {
			left -> print_from_value(c);		
		}	
		
		cout << data << " ";

		if (right != nullptr) {
			right -> print_from_value(c);
		}
	
	}
	
}

void Node::remove(int) {

}

void Node::clear() {

}

Node::~Node() {

}

int Node::sum() {

}

int Node::size() {

}

float Node::average() {

}