#include <iostream>
#include <fstream>
#include <string>
#include "COP3503su14_Proj2_RicardoR.h"
using namespace std;


int main(int argc, char ** argv) {
	Set set;
	ifstream input;
	ofstream output;
	string inFileName;
	string outFileName;
	string tempString;
	string line;
	int number = 0;
	bool NORMAL(true);
	bool VERBOSE(true);
	bool SILENT(true);
	int option = -1;

		if (argc > 1) {
			if(argv[1] == string("-s")){
				VERBOSE = 0;
				NORMAL = 0;
				SILENT = 1;    
			} 

			else if (argv[1] == string("-v")) {
				VERBOSE = 1;
				NORMAL = 0;
				SILENT = 0;
			}

			if (argv[1] == string("-h")) {
				cout << "=============================================================" << endl;
				cout << "Usage: proj2 [-s][-v][-h][-f <filename>]" << endl;
				cout << "   -s: silent mode" << endl;
				cout << "   -v: verbose mode" <<endl;
				cout << "   -h: print this help" << endl;
				cout << "   -f: <filename>: read <filename> into the current set" << endl;
				cout << "=============================================================" << endl;
				cout << "0. Exit" << endl;
				cout << "1. Input file <filename>" << endl;
				cout << "2. Union file <filename>" << endl;
				cout << "3. Subtract file <filename>" << endl;
				cout << "4. Difference file <filename>" << endl;
				cout << "5. Intersect file <filename>" << endl;
				cout << "6. Reset current set to empty string" << endl;
				cout << "7. Output file <filename>" << endl;
				cout << "8. Print current set to console" << endl;
				cout << "9. Find <item name>: if <item name> is in the current set" << endl;
				cout << "10. Insert <item name>" << endl;
				cout << "11. Delete <item name>" << endl;
				cout << "12. Reduce <item name> <count>" << endl;
				cout << "13. Verbose output" << endl;
				cout << "14. Normal output" << endl;
				cout << "15. Silent output" << endl;
				cout << "16. Help" << endl;
				cout << "=============================================================" << endl;

				VERBOSE = 0;
				NORMAL = 1;
				SILENT = 0;
			}

			if (argv[n] == string ("-f")) {
				inFileName = argv[n];
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
						bool read_fail = false;
						input >> tempString >> number;
						if (read_fail = input.fail()) {
							cout << "input failure check if every string contains a count" << endl;
							continue;
						}
						set.unionCheck(tempString, number);
						tempString.clear();
					}
					input.close();
			}
		 
			if (argc > 2) {
				if (argv[2] == string ("-f")) {
					inFileName = argv[3];
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
						bool read_fail = false;
						input >> tempString >> number;
						if (read_fail = input.fail()) {
							cout << "input failure check if every string contains a count" << endl;
							continue;
						}
						set.unionCheck(tempString, number);
						tempString.clear();
					}
					input.close();
				}
			}
			
		}

		else {
			VERBOSE = 0;
			NORMAL = 1;
			SILENT = 0;
		}

	while (option != 0) {
		if (VERBOSE) {
			cout << "0. Exit" << endl;
			cout << "1. Input file <filename>" << endl;
			cout << "2. Union file <filename>" << endl;
			cout << "3. Subtract file <filename>" << endl;
			cout << "4. Difference file <filename>" << endl;
			cout << "5. Intersect file <filename>" << endl;
			cout << "6. Reset current set to empty string" << endl;
			cout << "7. Output file <filename>" << endl;
			cout << "8. Print current set to console" << endl;
			cout << "9. Find <item name>" << endl;
			cout << "10. Insert <item name>" << endl;
			cout << "11. Delete <item name>" << endl;
			cout << "12. Reduce <item name> <count>" << endl;
			cout << "13. Verbose output" << endl;
			cout << "14. Normal output" << endl;
			cout << "15. Silent output" << endl;
			cout << "16. Help" << endl;
			cout << ">" << flush;
		} 

		else if (NORMAL) {
			cout << ">" << flush;
		} 

		cin >> option;
		if (option == 1) {
			set.reset();
			if (VERBOSE || NORMAL){
				cout << "Input file name: " << flush;
			}  
			cin >> inFileName;
			if (VERBOSE || NORMAL) {
				cout << "Input file name is " << inFileName << endl;  
			}

			
			input.open(inFileName.c_str());
			if (input.fail()) {
				cout << "File " << inFileName << " cannot be opened" << endl;
			}
			
			if(input.good()){
				if (VERBOSE || NORMAL) {
					cout << "New set loaded" << endl;
				}
				while(!input.eof()) {
					bool read_fail = false;
					input >> tempString >> number;
					if (read_fail = input.fail()) {
						cout << "input failure check if every string contains a count" << endl;
						continue;
					}
					set.unionCheck(tempString, number);
					tempString.clear();
				}
				input.close();
			}
			
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
			if (input.fail()) {
				cout << "File " << inFileName << " cannot be opened" << endl;
			}
			
			else if(input.good()){
				if (VERBOSE || NORMAL) {
					cout << "Union completed" << endl;
				} 
				while(!input.eof()) {
					bool read_fail = false;
					input >> tempString >> number;
					if (read_fail = input.fail()) {
						cout << "input failure check if every string contains a count" << endl;
						continue;
					}
					set.unionCheck(tempString, number);
					tempString.clear();
				}
				input.close();
			}
		} 

		else if (option == 3) {
			if (VERBOSE || NORMAL){
				cout << "Subtract file name: " << flush;
			}  
			cin >> inFileName;
			if (VERBOSE || NORMAL) {
				cout << "Subtract file name is " << inFileName << endl;  
			}

			input.open(inFileName.c_str());
			if (input.fail()) {
				cout << "File " << inFileName << " cannot be opened" << endl;
			}
			
			else if(input.good()){
				if (VERBOSE || NORMAL) {
					cout << "Subtract completed" << endl;
				}
				while(!input.eof()) {
					bool read_fail = false;
					input >> tempString >> number;
					if (read_fail = input.fail()) {
						cout << "input failure check if every string contains a count" << endl;
						continue;
					}
					set.subtractCheck(tempString, number);
					tempString.clear();
				}
				input.close();
			}
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
			if (input.fail()) {
				cout << "File " << inFileName << " cannot be opened" << endl;
			}
			
			else if(input.good()){
				if (VERBOSE || NORMAL){
					cout << "Difference completed" << endl;
				}
				while(!input.eof()) {
					bool read_fail = false;
					input >> tempString >> number;
					if (read_fail = input.fail()) {
						cout << "input failure check if every string contains a count" << endl;
						continue;
					}
					set.differenceCheck(tempString, number);
					tempString.clear();
				}
				input.close();
			}
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
			if (input.fail()) {
				cout << "File " << inFileName << " cannot be opened" << endl;
			}
			
			else if(input.good()){
				if (VERBOSE || NORMAL){
					cout << "Intersect completed" << endl;
				}
				while(!input.eof()) {
					bool read_fail = false;
					input >> tempString >> number;
					if (read_fail = input.fail()) {
						cout << "input failure check if every string contains a count" << endl;
						continue;
					}
					set.intersectCheck(tempString, number);
					tempString.clear();
				}
				input.close();
			}
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
			set.outputCheck(tempString, number);
			output << tempString << number << endl;
		}

		else if (option == 8) {
			cout << "Current multiset:" << endl;
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
			getline(cin, tempString);
			if(VERBOSE || NORMAL) {
				cout << "by: " << flush;
			}
			cin >> number;
			set.unionCheck(tempString, number);
			cout << tempString << " was added by a count of " << number << endl;
		}

		else if (option == 11) {
			if(VERBOSE || NORMAL) {
				cout << "Delete: " << flush;
			}
			cin >> tempString;
			set.remove(tempString);
			cout << tempString << " was deleted" << endl;
		}

		else if (option == 12) {
			if(VERBOSE || NORMAL) {
				cout << "Reduce: " << flush;
			}
			cin >> tempString;
			if(VERBOSE || NORMAL) {
				cout << "by: " << flush;
			}
			cin >> number;
			set.reduce(tempString, number);
			cout << tempString << " was reduced by a count of " << number << endl;
		}

		else if (option == 13) {
			VERBOSE = 1;
			NORMAL = 0;
			SILENT = 0;
		}

		else if (option == 14) {
			VERBOSE = 0;
			NORMAL = 1;
			SILENT = 0;
		}

		else if (option == 15) {
			VERBOSE = 0;
			NORMAL = 0;
			SILENT = 1;
		}

		else if (option == 16) {
			cout << "0. Exit" << endl;
			cout << "1. Input file <filename>" << endl;
			cout << "2. Union file <filename>" << endl;
			cout << "3. Subtract file <filename>" << endl;
			cout << "4. Difference file <filename>" << endl;
			cout << "5. Intersect file <filename>" << endl;
			cout << "6. Reset current set to empty string" << endl;
			cout << "7. Output file <filename>" << endl;
			cout << "8. Print current set to console" << endl;
			cout << "9. Find <item name>: if <item name> is in the current set" << endl;
			cout << "10. Insert <item name>" << endl;
			cout << "11. Delete <item name>" << endl;
			cout << "12. Reduce <item name> <count>" << endl;
			cout << "13. Verbose output" << endl;
			cout << "14. Normal output" << endl;
			cout << "15. Silent output" << endl;
			cout << "16. Help" << endl;
		}

	}
	return 0;  
}
