#ifndef COP3503su14_Proj2_RicardoR
#define COP3503su14_Proj2_RicardoR
#include <string>

using namespace std;

const int MAX_STRINGS = 100;

class Set {
	private:
		string stringSet[MAX_STRINGS];
		string stringSet2[MAX_STRINGS];
	  	int numStrings;
	  	int numStrings2;
	  	int countSet[MAX_STRINGS];
	  	int countSet2[MAX_STRINGS];
	
	public:
		Set();
		void printSet();
		void outputCheck(string words, int count);
		void reset();
		void unionCheck(string word, int count);
		void subtractCheck(string word, int count);
		void differenceCheck(string word, int count);
		int min(int a, int b);
		void intersectCheck(string word, int count);
		void reduce(string word, int count);
		void find(string word);
		void remove(string word);
};

#endif
