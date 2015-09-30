#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_STRINGS = 100;


struct Set {
  string stringSet[MAX_STRINGS];
  string stringSet2[MAX_STRINGS];
  int numStrings;
  int numStrings2;
  Set(){
    numStrings = 0;
    numStrings2 = 0;
  }
  
  void printSet() {
    //cout <<"numString = " << numStrings << endl;
    if (numStrings2 == 0) {
      for (int i = 0; i < numStrings; ++i) {
        if (stringSet[i] != ""){
          cout << stringSet[i] << endl;
        }     
      }
    }

    else {
      for (int i = 0; i < numStrings2; ++i) {
        if (stringSet2[i] != ""){
          cout << stringSet2[i] << endl;
        }     
      }
    }
  }

  void outputCheck(string words) {
    for (int i = 0; i < numStrings; ++i) {
      stringSet[i] = words; 
    }
  }

  void addSet(string word) {
    stringSet[numStrings] = word;
    ++numStrings;
  }

  void reset() {
    numStrings = 0;
    numStrings2 = 0;
  }

  void unionCheck(string word) {
    int found = 0;
    for (int i = 0; i < numStrings; ++i) {
      if (stringSet[i] == word) {
        ++found;
      }
    }
    if (found == 0){
      stringSet[numStrings] = word;
      ++numStrings;
    }
  }

  void substractCheck(string word2) {
    for (int i = 0; i < numStrings; ++i) {
      if (stringSet[i] == word2){
        stringSet[i] = "";
        --i;
      }
    }
  }

  void differenceCheck(string word) {
    int found = 0;
    for (int i = 0; i < numStrings; ++i) {
      if (stringSet[i] == word) {
        ++found;
      }
    }
   
   if (found == 0){
      stringSet[numStrings] = word;
      ++numStrings;
    }

    else {
      for (int i = 0; i < numStrings; ++i) {
        if (stringSet[i] == word){
          stringSet[i] = "";
          --i;
        }
      }
    }
  }

  void intersectCheck(string word) {
    int found = 0;
    for (int i = 0; i < numStrings; ++i) {
      if (stringSet[i] == word) {
        ++found;
      }
    }
    
    if (found != 0){
      stringSet2[numStrings2] = word;
      ++numStrings2;
    }

    else {
      for (int i = 0; i < numStrings; ++i) {
        if (stringSet[i] == word){
          stringSet2[i] = "";
          --i;
        }
      }
    }  
  }

  void find(string word) {
    int found = 0;
    for (int i = 0; i < numStrings; ++i) {
      if (stringSet[i] == word) {
        cout << "Item " << word << " was found" << endl;
        ++found;
      }
    }

    if (found == 0) {
      cout << "Item " << word << " was not found" << endl;
    }
  }

  void remove(string word2) {
    int found = 0;
    for (int i = 0; i < numStrings; ++i){
      if (stringSet[i] == word2){
        stringSet[i] = "";
        --i;
        ++found;
      }
    } 
    if (found == 0) {
      cout << word2 << " is not in the set" << endl;
    }
  }

};

int main() {
	ifstream input;
	ofstream output;
	Set set;
 	string inFileName;
	string outFileName;
	string tempString;
  	string line;
  	bool NORMAL(true);
  	bool VERBOSE(true);
  	bool SILENT(true);
  	int option;
 
 //Starts in verbose 
  VERBOSE = 1;
  NORMAL = 0;
  SILENT = 0;

  while (option != 0) {
    if (VERBOSE){
      cout << "0. Exit" << endl;
      cout << "1. Input file <filename>" << endl;
      cout << "2. Union file <filename>" << endl;
      cout << "3. Substract file <filename>" << endl;
      cout << "4. Difference file <filename>" << endl;
      cout << "5. Intersect file <filename>" << endl;
      cout << "6. Reset current set to empty string" << endl;
      cout << "7. Output file <filename>" << endl;
      cout << "8. Print current set to console" << endl;
      cout << "9. Find <item name>" << endl;
      cout << "10. Insert <item name>" << endl;
      cout << "11. Delete <item name>" << endl;
      cout << "12. Verbose output" << endl;
      cout << "13. Normal output" << endl;
      cout << "14. Silent output" << endl;
      cout << "15. Help" << endl;
    } 

    else if (NORMAL) {
      cout << ">" << flush;
    } 

    cin >> option;
    if (option == 1) {
      if (VERBOSE || NORMAL){
        cout << "Input file name: " << flush;
      }  
      cin >> inFileName;
      if (VERBOSE || NORMAL) {
        cout << "Input file name is " << inFileName << endl;  
      }

      
      input.open(inFileName.c_str());
      if (VERBOSE || NORMAL){
        if(input.good()){
          cout << "New set loaded" << endl;
        }
      }

      if (input.fail()) {
        cout << "File " << inFileName << " cannot be opened" << endl;
      }

      while(!input.eof()) {
        input >> tempString;
        set.addSet(tempString);
      }
      input.close();
    }

    else if (option == 2) {
      if (VERBOSE || NORMAL){
        cout << "Union file name: " << flush;
      }  
      cin >> inFileName;
      if (VERBOSE || NORMAL) {
        cout << "Union file name is " << inFileName << endl;  
      }

      input.open(inFileName.c_str());
      if (VERBOSE || NORMAL){
        if(input.good()){
          cout << "Union completed" << endl;
        }
      }

      if (input.fail()) {
        cout << "File " << inFileName << " cannot be opened" << endl;
      }

      while(!input.eof()) {
        input >> tempString;
        set.unionCheck(tempString);
      }
      input.close();
    } 

    else if (option == 3) {
      if (VERBOSE || NORMAL){
        cout << "Substract file name: " << flush;
      }  
      cin >> inFileName;
      if (VERBOSE || NORMAL) {
        cout << "Substract file name is " << inFileName << endl;  
      }

      input.open(inFileName.c_str());
      if (VERBOSE || NORMAL){
        if(input.good()){
          cout << "Substract completed" << endl;
        }
      }

      if (input.fail()) {
        cout << "File " << inFileName << " cannot be opened" << endl;
      }

      while(!input.eof()) {
        input >> tempString;
        set.substractCheck(tempString);
      }
      input.close();
    }

    else if (option == 4) {
      if (VERBOSE || NORMAL){
        cout << "Difference file name: " << flush;
      }  
      cin >> inFileName;
      if (VERBOSE || NORMAL) {
        cout << "Difference file name is " << inFileName << endl;  
      }

      input.open(inFileName.c_str());
      if (VERBOSE || NORMAL){
        if(input.good()){
          cout << "Difference completed" << endl;
        }
      }

      if (input.fail()) {
        cout << "File " << inFileName << " cannot be opened" << endl;
      }

      while(!input.eof()) {
        input >> tempString;
        set.differenceCheck(tempString);
      }
      input.close();
    } 

    else if (option == 5) {
      if (VERBOSE || NORMAL){
        cout << "Intersect file name: " << flush;
      }  
      cin >> inFileName;
      if (VERBOSE || NORMAL) {
        cout << "Intersect file name is " << inFileName << endl;  
      }

      input.open(inFileName.c_str());
      if (VERBOSE || NORMAL){
        if(input.good()){
          cout << "Intersect completed" << endl;
        }
      }

      if (input.fail()) {
        cout << "File " << inFileName << " cannot be opened" << endl;
      }

      while(!input.eof()) {
        input >> tempString;
        set.intersectCheck(tempString);
      }
      input.close();
    }

    else if (option == 6) {
      if (VERBOSE || NORMAL) {
        cout << "Reset completed" << endl;
      } 
      set.reset();
    }

    else if (option == 7) {
      if (VERBOSE || NORMAL) {
        cout << "Output file name: " << flush;
      }  
      cin >> outFileName;
      if (VERBOSE || NORMAL) {
        cout << "Output file name is " << outFileName << endl;
      }
      output.open(outFileName.c_str());
      if (output.fail()) {
        cout << "File " << outFileName << " cannot be opened" << endl;
      }
      set.outputCheck(tempString);
      output << tempString << endl;
    }

    else if (option == 8) {
      set.printSet();
      cout << endl;
    }

    else if (option == 9) {
      input >> tempString;
      if (VERBOSE || NORMAL) {
        cout << "Find: " << flush;
      }
      cin >> tempString;
      set.find(tempString);
      
    }

    else if (option == 10) {
      if(VERBOSE || NORMAL) {
        cout << "Insert: " << flush;
      }
      cin >> tempString;
      set.unionCheck(tempString);
    }

    else if (option == 11) {
      if(VERBOSE || NORMAL) {
        cout << "Delete: " << flush;
      }
      cin >> tempString;
      set.remove(tempString);
    }

    else if (option == 12) {
      VERBOSE = 1;
      NORMAL = 0;
      SILENT = 0;
    }

    else if (option == 13) {
      VERBOSE = 0;
      NORMAL = 1;
      SILENT = 0;
    }

    else if (option == 14) {
      VERBOSE = 0;
      NORMAL = 0;
      SILENT = 1;
    }

    else if (option == 15) {
      cout << "0. Exit" << endl;
      cout << "1. Input file <filename>: open and read a list from a file to the current list" << endl;
      cout << "2. Union file <filename>: open and union a set from a file with the current set" << endl;
      cout << "3. Substract file <filename>: open and subtract set from a file from the current set" << endl;
      cout << "4. Difference file <filename>: open and find the difference between a set from a file and the current set" << endl;
      cout << "5. Intersect file <filename>: open and find the intersection between a set from a file and the current set" << endl;
      cout << "6. Reset current set to empty string" << endl;
      cout << "7. Output file <filename>: open and write the current set to a file " << endl;
      cout << "8. Print current set to console" << endl;
      cout << "9. Find <item name>: if <item name> is in the current set" << endl;
      cout << "10. Insert <item name>: add <item name> to the current set if it is not already in it" << endl;
      cout << "11. Delete <item name>: remove <item name> from the current set if it is in it" << endl;
      cout << "12. Verbose output: Displays messages and menu everytime" << endl;
      cout << "13. Normal output: Only displays messages and uses the '>' prompt in everyline" << endl;
      cout << "14. Silent output: Only displays error messages" << endl;
      cout << "15. Help" << endl;
    }

  }
  return 0;  
}