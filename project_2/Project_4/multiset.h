//
//  multiset.h
//  Project2
//
//  Created by Miles Mulet on 6/9/14.
//  Copyright (c) 2014 Miles Mulet. All rights reserved.
//

#ifndef __Project2__multiset__
#define __Project2__multiset__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h> // atoi //

using namespace std;


struct foundSettings{ //A struct used by MultiSet::findMultiset(string filename) in order to return both 1. the number of units it found and 2. The number of truncations it had to do to the original string in order to find it.
    int numberFound;
    int truncationsUsed;
    string stringGuess;
    
    foundSettings(int a, int b){
        numberFound = a;
        truncationsUsed = b;
    }
    
    void applySettings(int a, int b){
        numberFound = a;
        truncationsUsed = b;
    }
    
    void applySettings(int a, int b, string s){
        numberFound = a;
        truncationsUsed = b;
        stringGuess = s;
    }

};

class MultiSet{
    private:
        ifstream input;
        ofstream output;
        vector<string> currentSet;
        string HELP_MESSAGE;
        int    CORRECTION_RANGE;;
        int outputMode;
        bool autoCorrectMode;
    public:
        //Main Functions
        void inputMultiSet(string filename);
        void printMultiSet();
        void unionMultiSet(string filename);
        void subtractMultiSet(string filename);
        void differenceMultiSet(string filename);
        void intersectMultiset(string filename);
        void resetMultiSet();
        void outputMultiSet(string filename);
        foundSettings  findMultiSet(string itemName);
        void insertMultiSet(string itemName, int itemQuantity);
        void deleteMultiSet(string itemName);
        void reduceMultiSet(string itemName, int reduceQuantity);
        void displayHelp();
        void maxMultiSet(string filename);
        void toggleAutoCorrectMode();
        //--------------------
    
        //Constructors
    
        MultiSet(int mode);
        MultiSet();
    
        //--------
    
        //Helper Functions (sorted by return type)
    
        void setErrorHandling(vector<string> & currentSet);
    
        bool setInput(string filename, vector<string> & currentSet);
        bool compareItemName(string itemName, int index);
    
        int minimum(int a, int b);
        int maximum(int a, int b);
    
        //----------------------------------------
    
        //Getters/Setters
    
        void SetOutputMode(int mode);
        int GetOutputMode();
    
        int GetSize();
    
        bool GetAutoCorrectMode();
    
        //---------------
    
};

#endif /* defined(__Project2__multiset__) */
