//
//  MainMenu.h
//  Project2
//
//  Created by Miles Mulet on 6/11/14.
//  Copyright (c) 2014 Miles Mulet. All rights reserved.
//

#ifndef __Project2__MainMenu__
#define __Project2__MainMenu__

#include <iostream>
#include "multiset.h"

const int NORMAL = 0;
const int VERBOSE = 1;
const int SILENT = 2;

bool MainMenu(MultiSet * currentSet, int currentMode); //Acts as a main menu for the user
bool userInput(int & menuDecision, string &tempString1, int & tempInt, int inputMode); //Mutating Helper Function (Procedure) used to gather user input.

#endif /* defined(__Project2__MainMenu__) */
