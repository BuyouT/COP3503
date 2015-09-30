#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include "multiset.h"

using namespace std;

void printTheMenu(){
	std::cout << "\n0. Exit \n" << 
		"1. input file\n" << 
		"2. union file\n" << 
		"3. subtract file\n" << 
		"4. difference file\n" << 
		"5. intersect file\n" << 
		"6. reset current set\n" << 
		"7. output file\n" << 
		"8. print current set\n" << 
		"9. find\n" << 
		"10. insert\n" << 
		"11. delete\n" << 
		"12. reduce\n" <<
		"13. verbose output\n" <<
		"14. normal output\n" <<
		"15. silent output\n" <<
		"16. help\n";
		"17. max\n";
}

void help(){
	std::cout << "\nAvailable Commands:\n" <<
		"0. Exit \n" << 
		"1. input file <filename>: open and read a list from a file to the current list\n" << 
		"2. union file <filename>: open and union a set from a file with the current set\n" << 
		"3. subtract file <filename>: open and subtract set from a file from the current set\n" << 
		"4. difference file <filename>: open and find the difference between a set from a file and the current set\n" << 
		"5. intersect file <filename>: open and find the intersection between a set from a file and the current set\n" << 
		"6. reset current set to the empty set\n" << 
		"7. output file <filename>: open and write the current set to a file \n" << 
		"8. print current set to the console\n" << 
		"9. find <item name>: test if <item name> is in the current set\n" << 
		"10. insert <item name>: add <item name> to the current set if it is not already in it\n" << 		
		"11. delete <item name>: remove <item name> from the current set if it is in it\n" << 
		"12. reduce <item name> <count>: reduce the number of <item name> by <count>\n" <<
		"13. verbose output\n" << 
		"14. normal output\n" << 
		"15. silent output\n" << 
		"16. help\n" <<
		"17. max <filename>: open and find the maximum between a multiset from a file and the current multiset. \n";
}



int main(int argc, char ** argv){
	Multiset multiset;
	int choice = -1;
	bool exit = false;

	for (int i = 0; i < argc; ++i) //argv is a pointer array of characters and has argc elemnts. The first element is the name of the executable file. In our case ./proj2
	{
		if (std::string(argv[i]) == "-s")// silent mode.
			multiset.setOutputMode(0);
		else if (std::string(argv[i]) == "-v")//verbose mode.
			multiset.setOutputMode(2);
		else if (std::string(argv[i]) == "-h")//show help menu.
			help();
		else if (std::string(argv[i]) == "-f")//open a file
		{
			if (multiset.getOutputMode() > 0 && multiset.readListFromFile(std::string(argv[i + 1])))
					cout << "\nNew multiset loaded.\n";
			else
				cout << "Error opening file.\n";
		}
	}

	help();
	while (!exit)
	{
		if (multiset.getOutputMode() > 0) cout << "> "; // not in silent mode
		std::cin >> choice; // get menu choice from user
		if (cin.fail()) { std::cin.clear(); cin.ignore(numeric_limits <streamsize>::max(), '\n'); }// don't crash if the user doens't enter a number.
		char exitChoice;
		switch (choice){
		case 0: // 0. exit
			std::cin.clear();
			cout << "Are you sure you want to exit? (y,n) ";
			std::cin >> exitChoice;
			if (exitChoice == 'y') exit = true;
			break;
		case 1: // 1. input file <filename>: open and read a list from a file to the current list
			multiset.readListFromFile(0);
			break;
		case 2: // 2. union file <filename>: open and union a set from a file with the current set 
			multiset.readListFromFile(0);
			multiset.unionSet();
			break;
		case 3: // 3. subtract file <filename>: open and subtract set from a file from the current set
			multiset.readListFromFile(1);
			break;
		case 4: // 4. difference file <filename>: open and find the difference between a set from a file and the current set 
			multiset.readListFromFile(2);
			break;
		case 5: // 5. intersect file <filename>: open and find the intersection between a set from a file and the current set
			multiset.readListFromFile(3);
			break;
		case 6: // 6. reset current set to the empty set
			multiset.clear();
			break;
		case 7: // 7. output file <filename> : open and write the current set to a file
			multiset.saveToFile();
			break;
		case 8: // 8. print current set to the console
			multiset.print();
			break;
		case 9: // 9. find <item name>: test if <item name> is in the current set
			multiset.find();
			break;
		case 10: // 10. insert <item name>: add <item name> to the current set if it is not already in it
			multiset.insert();
			break;
		case 11: // 11. delete <item name>: remove <item name> from the current set if it is in it
			multiset.deleteFromList();
			break;
		case 12: // 12. reduce <item name> <count>: reduce the number of <item name> by <count>
			multiset.reduce();
			break;
		case 13: // 13. verbose output (same as normal but with the menu)
			multiset.setOutputMode(2);
			break;
		case 14: // 14. normal output (greater than sign. "set loaded". no menu)
			multiset.setOutputMode(1);
			break;
		case 15: // 15. silent output (only display errors. no menu. no greater than sign.)
			multiset.setOutputMode(0);
			break;
		case 16: // 16. help (show very wordy menu) max <filename>: open and find the maximum between a multiset from a file and the current multiset. 
			help();
			break;
		case 17: // 17. max <filename>: open and find the maximum between a multiset from a file and the current multiset. 
			multiset.readListFromFile(0);
			multiset.max();
			break;
		default:
			std::cout << "That choice isn’t valid.\n";
		}
		if (multiset.getOutputMode() == 2) printTheMenu();
		std::cin.clear();
	}
	return 0;
}