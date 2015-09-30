//
//  main.cpp
//  Project2
//
//  Created by Miles Mulet on 6/9/14.
//  Copyright (c) 2014 Miles Mulet. All rights reserved.
//

#include <iostream>
#include "main.h"

using namespace std;


int main(int argc, const char * argv[])
{
     
    //MultiSet theSet(0); //Creates the set to be used
    MultiSet theSet;
    MultiSet * set_ptr = &theSet;
    
    int outputMode = 0;
    
    for (int n = 1; n < argc; n++){ //To set the output mode from the command line
		if(!strcmp(argv[n],"-s")){
			outputMode = 2; //silent
		}
		if(!strcmp(argv[n],"-v")){
			outputMode = 1; //Verbose
		}
        if(!strcmp(argv[n],"-h")){
            set_ptr->displayHelp();
        }
        if(!strcmp(argv[n],"-f")){
            set_ptr->inputMultiSet(argv[n + 1]);
            ++n;
        }
	}
    
    theSet.SetOutputMode(outputMode);
    
    
    while(MainMenu(set_ptr, theSet.GetOutputMode())){
        //Main loop, exits when the MainMenu function returns false (when the user exits)
    }

    return 0;
}

