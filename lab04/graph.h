#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;
const int MAX_EDGES = 4950;

class Graph {
	private:
	string vertices[MAX_VERTICES];
    int edges[MAX_EDGES][2];
    int numVertices;
    int numEdges;

	public:
	Graph();
	void printGraph();
	void printEdgesOfVertex(string vert);
	void addVertex(string vert);
	void addEdge(string vert1, string vert2);
	int getIndex(string nVer);
	int num_vertices();
};

#endif
