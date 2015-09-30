#include <iostream>
#include "graph.h"
using namespace std;

int main(int argc, char ** argv){
    int opt; 
    Graph graph;
	string input;
	string input1;
	string input2;
	string input3;    	

	do{
        cout << "0. Exit" << endl;
        cout << "1. Add an edge" << endl;
        cout << "2. Add a vertex" << endl;
        cout << "3. Print the graph" << endl;
        cout << "4. Print edges of a vertex" << endl;
		cout << "5. Print number of vertices" << endl;
        cin >> opt;
        if (opt == 2) {
            cout << "Please input a name for your vertex" << endl;
            cin >> input;
            cout << "Vertex name -- " << input << endl;
            graph.addVertex(input);            
        }

        else if (opt == 1) {
            cout << "Please add two inputs to add in vertices" << endl;
            cin >> input1;
            cout << "First vertex in edge -- " << input1 << endl;
            cin >> input2;
            cout << "Second vertex in edge -- " << input2 << endl;
            graph.addEdge(input1, input2);
        }

        else if (opt == 3) {
            graph.printGraph();
        }

        else if (opt == 4) {
            cout << "Please choose a vertex" << endl;
            cin >> input3;
            cout << "Vertex name -- " << input3 << endl;
            graph.printEdgesOfVertex(input3);
        }

		else if (opt == 5) {
			cout << "Number of vertices is -- " << flush;
			cout << graph.num_vertices() << endl;
		}}
    while (opt != 0);
    return 0;}
