#ifndef BST_H
#define BST_H

class Node {
	private:
		int data;
		Node *left;
		Node *right;

	public:
		Node(int);
		void insert(int);
		void print_inorder();
		bool find(int);
		void print_from_value(int);
		Node* getMin(Node*, Node*);
		Node* remove(int);
		void clear();
		~Node();
		int sum();
		int size();
		float average();
};

class BST {
	private:
		Node *root;

	public:
		BST();
		void insert(int);
		void print_inorder();
		bool find(int);
		void print_from_value(int);
		void remove(int);
		void clear();
		~BST();
		int sum();
		int size();
		float average();
};

#endif
