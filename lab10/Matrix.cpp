#include <iostream>

using namespace std;

int numRows = 0;
int numColumns = 0;

read_in_two_positive_ints(int a, int b) {
	cout << "1st positive integer: " << flush
	cin >> a;
	if (a < 1) {
		cout << "Please enter a valid value" << endl;
	}

	cout << "2st positive integer: " << flush
	cin >> b;
	if (b < 1) {
		cout << "Please enter a valid value" << endl;
	}
}

initialize_a_2d_matrix(int a, int b) {
	int** matrix = new int[a][b];
}

read_in_a_2d_matrix(int** m, int a, int b) {
	m = matrix;
	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numColumns; ++j) {
			m[i] = a;
			++numRows;
			m[j] = b;
			++numColumns;
		}
	}
}
