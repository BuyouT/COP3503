#include "COP3503su14_Proj2_RicardoR.h"
#include <iostream>
#include <string>
using namespace std;

Set::Set(){
  numStrings = 0;
  numStrings2 = 0;
}
  
void Set::printSet() {

  if (numStrings2 == 0) {
    for (int i = 0; i < numStrings; ++i) {
      if (stringSet[i] != ""){
        cout << stringSet[i] << " " << countSet[i] << endl;
      }     
    }
  }

  else {
    for (int i = 0; i < numStrings2; ++i) {
      if (stringSet2[i] != ""){
        cout << stringSet2[i] << " " << countSet2[i] <<endl;
      }     
    }
  }
}

void Set::outputCheck(string words, int count) {
  for (int i = 0; i < numStrings; ++i) {
    stringSet[i] = words; 
    countSet[i] = count;
  }
}

void Set::reset() {
  numStrings = 0;
  numStrings2 = 0;
}

void Set::unionCheck(string word, int count) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i) {
    if (stringSet[i] == word) {
      countSet[i] += count;
      ++found;
    }
  }
  if (found == 0){
    stringSet[numStrings] = word;
    countSet[numStrings] = count;
    ++numStrings;
  }

  if (numStrings == 0) {
    for (int i = 0; i < numStrings2; ++i) {
      if (stringSet2[i] == word) {
        countSet2[i] += count;
        ++found;
      }
    }
    if (found == 0){
      stringSet2[numStrings] = word;
      countSet2[numStrings] = count;
      ++numStrings;
    }
  }

  if (numStrings == MAX_STRINGS || numStrings2 == MAX_STRINGS) {
    cout << "Set is too big" << endl;
  }
}

void Set::subtractCheck(string word, int count) {
  for (int i = 0; i < numStrings; ++i) {
    if (stringSet[i] == word){
      countSet[i] -= count;
      if (countSet[i] <= 0) {
        stringSet[i] = "";
        --i;  
      }
    }
  }
}

void Set::differenceCheck(string word, int count) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i) {
    if (stringSet[i] == word) {
      countSet[i] -= count;
      if (countSet[i] < 0) {
        countSet[i] = -1*countSet[i];
      }
      ++found;
    }
  }
 
 if (found == 0){
    stringSet[numStrings] = word;
    countSet[numStrings] = count;
    ++numStrings;
  }

  else {
    for (int i = 0; i < numStrings; ++i) {
      if (stringSet[i] == word && countSet[i] == 0){
        stringSet[i] = "";
        --i;
      }
    }
  }

  if (numStrings == 0){
    for (int i = 0; i < numStrings2; ++i) {
      if (stringSet2[i] == word) {
        countSet2[i] -= count;
        if (countSet2[i] < 0) {
          countSet2[i] = -1*countSet2[i];
        }
        ++found;
      }
    }
   
   if (found == 0){
      stringSet2[numStrings] = word;
      countSet2[numStrings] = count;
      ++numStrings;
    }

    else {
      for (int i = 0; i < numStrings; ++i) {
        if (stringSet2[i] == word && count == 0){
          stringSet2[i] = "";
          --i;
        }
      }
    }
  }

  if (numStrings == MAX_STRINGS || numStrings2 == MAX_STRINGS) {
    cout << "Set is too big" << endl;
  }
}

int Set::min(int a, int b) {
  int minval;
  if (a < b) {
    minval = a;
  }
  else {
    minval = b;
  }  
  return minval;
}

void Set::intersectCheck(string word, int count) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i) {
    if (stringSet[i] == word) {
      countSet2[numStrings2] = min(countSet[i], count);
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

void Set::find(string word) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i) {
    if (stringSet[i] == word) {
      cout << "Item " << word << " was found" << " with count " << countSet[i] << endl;
      ++found;
    }
  }

  if (numStrings == 0) {
    for (int i = 0; i < numStrings2; ++i) {
      if (stringSet2[i] == word) {
        cout << "Item " << word << " was found" << " with count " << countSet[i] << endl;
        ++found;
      }
    }
  }

  if (found == 0) {
    cout << "Item " << word << " was not found" << endl;
  }
}

void Set::remove(string word) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i){
    if (stringSet[i] == word){
      stringSet[i] = "";
      --i;
      ++found;
    }
  } 

  if (numStrings == 0) {
    for (int i = 0; i < numStrings2; ++i){
      if (stringSet2[i] == word){
        stringSet2[i] = "";
        --i;
        ++found;
      }
    } 
  }

  if (found == 0) {
    cout << word << " is not in the set" << endl;
  }
}

void Set::reduce(string word, int count) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i) {
    if (stringSet[i] == word) {
      countSet[i] -= count;
      if (countSet[i] <= 0) {
        stringSet[i] = "";
        --i;  
        ++found;
      }
    }
  }

  if (numStrings == 0) {
    for (int i = 0; i < numStrings2; ++i) {
      if (stringSet2[i] == word) {
        countSet2[i] -= count;
        if (countSet2[i] <= 0) {
          stringSet2[i] = "";
          --i; 
          ++found; 
        }
      }
    }
  }

  if (found == 0) {
    cout << word << " is not in the set" << endl;
  }
}
