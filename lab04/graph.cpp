#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph() {
	cout << "Graph()" << endl;	
	numVertices = 0;
	numEdges = 0;
}

void Graph::printGraph() {	
	for (int i = 0; i < numVertices; ++i) {
    	cout << "Vertices: " << "[" << vertices[i] << "] ";
    }

    cout << endl;

    for (int j = 0; j < numEdges; ++j) {
    	cout << "Edges: " << "(" << vertices[edges[j][0]] << ", " << vertices[edges[j][1]] << ") "; 
   	}
    cout << endl;
    cout << "printGraph()" << endl;
}

void Graph::printEdgesOfVertex(string vert) {
	int ind = getIndex(vert);
    if (ind == -1) {
    	cout << "Vertices does not exist!" << endl;
    }

    else if (ind != -1) {
    	for (int j = 0; j < numEdges; ++j) {
        	if (ind == edges[j][0] || ind == edges[j][1]) {
            	cout << "(" << vertices[edges[j][0]] << ", " << vertices[edges[j][1]] << ") ";
           	}
       	}
            
       	cout << endl;
   	}
  cout << "printEdgesOfVertex(string vert)" << endl;
}
        
void Graph::addVertex(string vert) {
	vertices[numVertices] = vert;
	++numVertices;
  cout << "addVertex(string vert)" <<endl;
}	

void Graph::addEdge(string vert1, string vert2) {
	if (getIndex(vert1) == -1 || getIndex(vert2) == -1) {
   		cout << "Error: the input vertex does not exist" << endl;
	}

   	else {
    	edges[numEdges][0] = getIndex(vert1);
        edges[numEdges][1] = getIndex(vert2);
        ++numEdges;
   	}   
  cout << "addEdge(string vert1, string vert2)" << endl;
}

int Graph::getIndex(string nVer) {
 	int index = -1;
    for (int i = 0; i < numVertices; ++i) {
    	if (vertices[i] == nVer) {
      		index = i;
       	}

    }
    cout << "getIndex(string nVer)" << endl;
   	return index;
}

int Graph::num_vertices() {
	int numberofvertices = numVertices;
	return numberofvertices;
}