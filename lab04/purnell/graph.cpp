// Author: Purnell Jones
// File: graph.cpp source file
// This file contains Graph class

#include "graph.h"
// file that exist in the current directory

	Graph::Graph()
	{
		numVertices = 0;
        numEdges = 0;
	}

	void Graph::printGraph(){

        cout << "Vertices: " << flush;
        for(int i = 0; i < numVertices; i++){
            // statements check how many vertices to print 
            if( !(i == (numVertices - 1) ) ){
                cout << "[" << vertices[i] << "]" << ", " ;
            }else{
                cout << "[" << vertices[i] << "]" << endl;
            }
        }


        if(numEdges != 0){
       
            cout << "Edges: " << flush;
            for(int i = 0; i < numEdges; i++){
                for(int j = 0; j < 2; j++){
                    // statements check how many edges to print 
                    if( !(i == (numEdges - 1)) ){
                    
                        if(j == 0){
                            cout << "(" << vertices[edges[i][j]] << "," << flush;       
                        }else{
                            cout << vertices[edges[i][j]] << "), " << flush;
                        }
                    }else{

                        if(j == 0){
                            cout << "(" << vertices[edges[i][j]] << "," << flush;       
                        }else{
                            cout << vertices[edges[i][j]] << ") " << flush;
                        }

                    }
                }
            }
        }else{
            // if there aren't any Edges print
            cout << "Edges: " << flush;
        }
    }

    // Print the edges of a given vertex
    void Graph::printEdgesOfVertex(string vert){

        if(vertexExist(vert)){
        
            cout << "Vertex name -- " << vert << endl;
            if(numEdges != 0){
       
                cout << "[" << vert << "]: ";
                for(int i = 0; i < numEdges; i++){
                    for(int j = 0; j < 2; j++){

                        if(vertices[edges[i][j]] == vert){

                            if(j == 0){

                            cout << "(" << vertices[edges[i][j]] << "," << vertices[edges[i][j+1]] << ") " << flush;    
                            }
                            else if (j == 1){

                                cout << "(" << vertices[edges[i][j-1]] << "," << vertices[edges[i][j]] << ") " << flush;
                            }
                        }
                    }
                }
            }
        }else{

            cout << "Error: [" << vert << "] does not exist." << flush;
        }    
        cout << endl;
    }

    // Add a vertex to the graph
    void Graph::addVertex(string vert){

        if(vertexExist(vert)){

            cout << "This vertex already exist." << endl;
        }
        else{

            vertices[numVertices] = vert;
            numVertices += 1;
            cout << "Vertex name -- " << vert << endl;
        }
    }

    // Add an edge to the graph
    void Graph::addEdge(string vert1, string vert2){

        if(vertexExist(vert1) && vertexExist(vert2)){
            
            edges[numEdges][0] = getIndex(vert1);
            edges[numEdges][1] = getIndex(vert2);
            numEdges += 1;
            cout << "First vertex in edge -- " << vert1 << "\nSecond vertex in edge -- " << vert2 << endl;
        }
        else{

            if(vertexExist(vert1) == false){

                cout << "Error: " << vert1 << " does not exist." << endl;
            }else{

                cout << "Error: [" << vert2 << "] does not exist." << endl;
            }
        }
    }
    //pass in a element
    int Graph::getIndex(string vert){

        int pos = 0;
        if(numVertices != 0){
            
            for(int i = 0; i < numVertices; i++){

                if(vert == vertices[i]){

                    pos = i;
                }
            }
        }
        return pos;
    }

	bool Graph::vertexExist(string vert){

	    bool status;
	    // checks if there are any vertices
	    if(numVertices == 0){

	        status = false;
	    }
	    else{

	        // searches through array for vert
	        for(int i = 0; i < numVertices; i++){

	            if(vert == vertices[i]){

	                status = true;
	                //breaks out of loop if vert is found stores correct counter
	                break; 
	            }else{
	            
	                status = false;
	            }
	        }
	    }

    	return status;
	}

