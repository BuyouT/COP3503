// Author: Purnell Jones
// File: main.cpp
// This file contains main

// <iostream> below will not run 
#include <iostream>
#include "graph.h"
using namespace std;

void menu(){

    cout << "0. Exit\n1. Add a vertex\n2. Add an edge\n3. Print the graph\n4. Print the edges of a vertex" << endl;   
}
// Should provide the functionality described in the lab
int main(int argc, char ** argv){

    Graph graph;
    int userNumInput = -1;
    string userTextInput;
    // displays option to the user
    menu();

    while(userNumInput != 0){

        // check if userNumInput is valid
        if(userNumInput <= 4 && userNumInput >= 1){

            if(userNumInput == 1){

                cout << "You are adding a vertex. Please enter a string." << endl;
                cin >> userTextInput;
                graph.addVertex(userTextInput);
            }
            else if(userNumInput == 2){

                cout << "You are adding a edge. Please enter first string." << endl;
                cin >> userTextInput;
                string vert1 = userTextInput;

                cout << "You are adding a edge. Please enter second string." << endl;
                cin >> userTextInput;
                string vert2 = userTextInput;

                graph.addEdge(vert1,vert2);
            }
            else if(userNumInput == 3){

                graph.printGraph();
            } 
            else if(userNumInput == 4){

                cout << "You are printing the edges of a vertex. Please enter the vertex you'd like the edges of." << endl;
                cin >> userTextInput;
                graph.printEdgesOfVertex(userTextInput);
            }           

            cout << "\n" << flush;
            menu();
            cout << "\n" << flush;
        }
        //userNumInput invalid
        else{
            cout << "Please enter a number between 1 and 4." << endl;
        }
        cin >> userNumInput;
    }

    cout << "You have Exited." << endl;
    return 0;
}
