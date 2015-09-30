//
//  MainMenu.cpp
//  Project2
//
//  Created by Miles Mulet on 6/11/14.
//  Copyright (c) 2014 Miles Mulet. All rights reserved.
//

#include "MainMenu.h"

bool MainMenu(MultiSet * currentSet, int currentMode){
    int menuDecision; //The decision that the user uses
    string tempString1 = "";
    string tempString2;
    int    tempInt = -1; //Temp variables used for input/output
    if(currentMode == 0){ // Normal Mode
        cout << ">";
    }
    else if (currentMode == 1){ //Verbose Mode
        cout << "0. Exit\n1. Input File\n2. Union File\n3. Subtract File\n4. Difference File\n5. Intersect File\n6. Rest Current Multiset\n7. Output to File\n8. Print Current Set\n9. Find Item\n10. Insert Item\n11. Delete Item\n12. Reduce Item\n13. Verbose Output\n14. Normal Output\n15. Silent Output\n16. Help\n\n17. Maximum\n18. Toggle Autocorrect\n>";
    }
    
    if(!userInput(menuDecision, tempString1, tempInt, 0)){
        return true;
    }

    
    switch(menuDecision){
        case 0:
                if(currentMode != 2){
                    cout << "\n\nThanks for using me!" << endl;
                }
                return false;
                break;
        case 1:
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the input filename: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 2)) {
                    
                    }
                }
                currentSet->inputMultiSet(tempString1);
                break;
        case 2:
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the filename to union: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 2)) {
                    
                    }
                }
            
                currentSet->unionMultiSet(tempString1);
                break;
        case 3:
                if(currentSet->GetSize() == 0){
                    if(currentMode != 2)
                        cout << "\nHey! The multiset is currently empty!" << endl;
                    break;
                }
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the filename to subtract: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 2)) {
                    
                    }
                }
                currentSet->subtractMultiSet(tempString1);
                break;
        case 4:
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the filename to difference: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 2)) {
                    
                    }
                }
                currentSet->differenceMultiSet(tempString1);
                break;
        case 5:
                if(currentSet->GetSize() == 0){
                    if(currentMode != 2)
                        cout << "\nHey! The multiset is currently empty!" << endl;
                    break;
                }
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the filename to intersect: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 2)) {
                    
                    }
                }
                currentSet->intersectMultiset(tempString1);
                break;
        case 6:
                if(currentMode != 2)
                    cout << "\n";
                currentSet->resetMultiSet();
                break;
        case 7:
                if(currentSet->GetSize() == 0){
                    if(currentMode != 2)
                        cout << "\nHey! The multiset is currently empty!" << endl;
                    break;
                }
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the output filename: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 2)) {
                    
                    }
                }
                currentSet->outputMultiSet(tempString1);
                break;
        case 8:
                if(currentSet->GetSize() == 0){
                    if(currentMode != 2)
                        cout << "\nHey! The multiset is currently empty!" << endl;
                    break;
                }
                if(currentMode != 2)
                    cout << "\n";
                currentSet->printMultiSet();
                break;
        case 9:
                if(currentSet->GetSize() == 0){
                    if(currentMode != 2)
                        cout << "\nHey! The multiset is currently empty!" << endl;
                    break;
                }
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the item name: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 2)) {
                    
                    }
                }
            
                tempInt = currentSet->findMultiSet(tempString1).numberFound;
                if((tempInt = currentSet->findMultiSet(tempString1).numberFound) > 0){
                    if(currentSet->GetAutoCorrectMode() || currentSet->findMultiSet(tempString1).truncationsUsed == 0){
                    cout << "Item " << tempString1.substr(0,tempString1.size() - currentSet->findMultiSet(tempString1).truncationsUsed) << " found with count " << tempInt << endl;
                    }
                    else{
                        cout << "Item " << tempString1 << " not found. Did you mean \"" << currentSet->findMultiSet(tempString1).stringGuess << "\"?" << endl;
                    }
                }
                else{
                    cout << "Item " << tempString1 << " not found" << endl;
                }
                break;
        case 10:
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the item name and the number of the item you wish to add: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 3)) {
                    
                    }
                    if(tempInt == -1){
                        cout << "\nPlease enter the number of " << tempString1 << " that you would like to add: ";
                        while (!userInput(menuDecision, tempString1, tempInt, 1)) {
                    
                        }
                    }
                }
                currentSet->insertMultiSet(tempString1, tempInt);
                break;
        case 11:
                if(currentSet->GetSize() == 0){
                    if(currentMode != 2)
                        cout << "\nHey! The multiset is currently empty!" << endl;
                    break;
                }
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the item name: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 2)) {
                    
                    }
                }
                currentSet->deleteMultiSet(tempString1);
                break;
        case 12:
                if(currentSet->GetSize() == 0){
                    if(currentMode != 2)
                        cout << "\nHey! The multiset is currently empty!" << endl;
                    break;
                }
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the item name and the number of the item you wish to reduce: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 3)) {
                    
                    }
                    if(tempInt == -1){
                        cout << "\nPlease enter the number of " << tempString1 << " that you would like to reduce: ";
                        while (!userInput(menuDecision, tempString1, tempInt, 1)) {
                    
                        }
                    }
                }
                currentSet->reduceMultiSet(tempString1, tempInt);
                break;
        case 13:
                cout << "\nSwitched to Verbose Output!" << endl;
                currentMode = 1;
                currentSet->SetOutputMode(1);
                break;
        case 14:
                cout << "\nNormal Mode" << endl;
                currentMode = 0;
                currentSet->SetOutputMode(0);
                break;
        case 15:
                currentMode = 2;
                currentSet->SetOutputMode(2);
                break;
        case 16:
                currentSet->displayHelp();
                break;
        case 17:
                if(tempString1 == ""){
                    if(currentMode != 2)
                        cout << "\nPlease enter the filename: ";
                
                    while (!userInput(menuDecision, tempString1, tempInt, 1)) {
                    
                    }
                }
                currentSet->maxMultiSet(tempString1);
                break;
        case 18:
                currentSet->toggleAutoCorrectMode();
                break;
        default:
                cerr << "Error! Something went wrong; we're not supposed to be here...";
                break;
    }
    
    return true;
}

bool userInput(int & menuDecision, string & tempString1, int & tempInt, int inputMode){ //Input Mode: 0 -- default, can take all three arguments; 1 -- Expects an integer only; 2 -- Expects a string Only; 3 -- expects a string and then an integer
    string tempLine;
    while( getline(cin, tempLine)){
         istringstream record(tempLine);
        
         switch(inputMode){
                default:
                     record >> menuDecision;
                    
                     if(record.fail() || menuDecision > 18){
                        cerr << "Error: Please enter a number between 0 and 18!" << endl;
                        return false;
                     }
                    
                     if(!record.eof()){
                        record >> tempString1;
                        if(record.fail()){
                             cerr << "Error: Input invalid for the command " << menuDecision << endl;
                            return false;
                        }
                        if(!record.eof()){
                            record >> tempInt;
                            if(record.fail()){
                                cerr << "Error: Input invalid for the command " << menuDecision << " " << tempString1 << endl;
                                return false;
                            }
                            if(!record.eof()){
                                cerr << "Error: Too many arguments!" << endl;
                                return false;
                            }
                        }
                        
                     }
                     break;
                 
                case 1:
                     record >> tempInt;
                    
                     if(record.fail()){
                        cerr << "Error: Please enter a number!" << endl;
                        return false;
                     }
                    
                     if(!record.eof()){
                        record >> tempString1;
                        if(!record.fail()){
                             cerr << "Error: Input invalid for the command " << menuDecision << endl;
                            return false;
                        }
                        
                     }
                     break;
                 
                case 2:
                     record >> tempString1;
                 
                     if(record.fail()){
                        cerr << "Error: Please enter a string!" << endl;
                        return false;
                     }
                 
                    if(!record.eof()){
                        cerr << "Error: Input invalid for the command " << menuDecision << endl;
                        return false;
                    }
                    break;
                 case 3:
                    record >> tempString1;
                
                    if(record.fail()){
                        cerr << "Error: Please enter a string first!" << endl;
                        return false;
                    }
                 
                    if(!record.eof()){
                 
                        record >> tempInt;
                     
                        if(record.fail()){
                            cerr << "Error: Please enter a number after you enter the string!" << endl;
                            return false;
                        }
                    }
                 
                    
                    break;
                    
         }
        break;
    }
    return true;
}