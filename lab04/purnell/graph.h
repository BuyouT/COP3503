// Author: Purnell Jones
// File: graph.h
// This file contains protypes

#ifndef GRAPH_H		//if not define in file
#define	GRAPH_H		// then define below in file

#include <iostream>
using namespace std;


	const int MAX_VERTICES = 100;
	const int MAX_EDGES = 4950;
class Graph
{

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
	int getIndex(string vert);
	bool vertexExist(string vert);
};


#endif

// Things to put in header
// prototypes
// global constants
// template code
// class definition