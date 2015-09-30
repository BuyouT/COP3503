//
//  multiset.cpp
//  Project2
//
//  Created by Miles Mulet on 6/9/14.
//  Copyright (c) 2014 Miles Mulet. All rights reserved.
//

#include "multiset.h"


string to_string(int item){

    char* thingy = itoa(item);
    return string(thingy);
}

MultiSet::MultiSet(int mode){
    this->outputMode = mode;
    autoCorrectMode = false;
    const int correctionRange = 1;
    const string theHelpMessage = "======================================================================\nUsage: proj2 [-s][-v][-h][-f <filename>]\n\t-s: silent mode\n\t-v: verbose mode\n\t-h: print this help\n\t-f <filename>: read <filename> into the current set\n======================================================================\nThe numbered commands are as follows:\n0. exit\n1. input file <filename>: open and read a list from a file to the current list\n2. union file <filename>: open and union a multiset from a file with the current multiset\n3. subtract file <filename>: open and subtract multiset from a file from the current multiset\n4. difference file <filename>: open and find the difference between a multiset from a file and the current multiset\n5. intersect file <filename>: open and find the intersection between a multiset from a file and the current multiset\n6. reset current multiset to the empty multiset\n7. output file <filename>: open and write the current multiset to a file\n8. print current multiset to the console\n9. find <item name>: test if <item name> is in the current multiset\n10. insert <item name> <item quantity>: adds <item quantity> of <item name> to the current multiset\n11. delete <item name>: remove <item name> from the current multiset if it is in it\n12. reduce <item name> <count>: reduce the number of <item name> in the current multiset by <count> if it is in it\n13. verbose output\n14. normal output\n15. silent output\n16. help\n17. Maximum <filename>: returns the maximum quantity of each element in <filename> and the current multiset\n18. Toggle Autocorrect\n======================================================================";
    HELP_MESSAGE = theHelpMessage;
    CORRECTION_RANGE = correctionRange;
}

MultiSet::MultiSet(){
    outputMode = 0;
    autoCorrectMode = false;
    const int correctionRange = 1;
    const string theHelpMessage = "======================================================================\nUsage: proj2 [-s][-v][-h][-f <filename>]\n\t-s: silent mode\n\t-v: verbose mode\n\t-h: print this help\n\t-f <filename>: read <filename> into the current set\n======================================================================\nThe numbered commands are as follows:\n0. exit\n1. input file <filename>: open and read a list from a file to the current list\n2. union file <filename>: open and union a multiset from a file with the current multiset\n3. subtract file <filename>: open and subtract multiset from a file from the current multiset\n4. difference file <filename>: open and find the difference between a multiset from a file and the current multiset\n5. intersect file <filename>: open and find the intersection between a multiset from a file and the current multiset\n6. reset current multiset to the empty multiset\n7. output file <filename>: open and write the current multiset to a file\n8. print current multiset to the console\n9. find <item name>: test if <item name> is in the current multiset\n10. insert <item name> <item quantity>: adds <item quantity> of <item name> to the current multiset\n11. delete <item name>: remove <item name> from the current multiset if it is in it\n12. reduce <item name> <count>: reduce the number of <item name> in the current multiset by <count> if it is in it\n13. verbose output\n14. normal output\n15. silent output\n16. help\n17. Maximum <filename>: returns the maximum quantity of each element in <filename> and the current multiset\n18. Toggle Autocorrect\n======================================================================";
    HELP_MESSAGE = theHelpMessage;
    CORRECTION_RANGE = correctionRange;
}

void MultiSet::SetOutputMode(int mode){
    this->outputMode = mode;
}

int MultiSet::GetOutputMode(){
    return this->outputMode;
}


void MultiSet::inputMultiSet(string filename){
    if(!setInput(filename, currentSet)) //Done initially in order to test for input and not lose data if the input is unsuccessful
        return;
    
    currentSet.clear();
    setInput(filename, currentSet);
    
    
    if(outputMode != 2)
        cout << "\nNew Set Loaded" << endl;
    return;
}

void MultiSet::printMultiSet(){
    if(outputMode != 2){
        cout << "Current Multiset: " << endl;
        for(int i = 0; i < currentSet.size(); i++){
            cout << currentSet[i] << endl;
        }
        cout << endl;
    }
}

void MultiSet::unionMultiSet(string filename){ //Unions the file multiset with the current multiset
    vector<string> tempSet;
    
   if(!setInput(filename, tempSet))
        return;
    
    for(int i = 0; i < tempSet.size(); i++){
        currentSet.push_back(tempSet[i]);
    }
    
    setErrorHandling(currentSet); //This is done a second time even though we know that tempSet is in the right format in order to add the appropriate number of duplicate files.
    
    
    if(outputMode != 2){
        cout << "\n" << filename << " union complete" << endl;
    }
}

void MultiSet::subtractMultiSet(string filename){ //Subtracts all items (and quantities) of the file from the current MultiSet
    vector<string> tempSet;
    if(!setInput(filename, tempSet))
        return;
    
    //SUBTRACTION LOGIC
    
    
    for(int i = 0; i < currentSet.size(); i++){
        for(int j = 0; j < tempSet.size(); j++){
            if(currentSet[i].substr(0, currentSet[i].find_last_of(" ")) == tempSet[j].substr(0, tempSet[j].find_last_of(" "))){
                
                string tempString = currentSet[i].substr(0, currentSet[i].find_last_of(" "));
                
                
                int tempInt1 = atoi (currentSet[i].substr(currentSet[i].find_last_of(" ") + 1, currentSet[i].length() - 1).c_str());
                int tempInt2 = atoi (tempSet[j].substr(tempSet[j].find_last_of(" ") + 1, tempSet[j].length() - 1).c_str());
                
                
                tempString.append(" ");
                tempString.append(to_string(tempInt1 - tempInt2));
                
                currentSet[i] = tempString;
                
                tempSet.erase(tempSet.begin() + j);
                
                break;
            }
        }
    
    }
    
    setErrorHandling(currentSet);
    
    //END SUBTRACTION LOGIC
    
    if(outputMode != 2){
        cout << "\n" << filename << " subtraction complete" << endl;
    }
}

void MultiSet::differenceMultiSet(string filename){ //Puts the difference (including quantity) of items from the current set and the file to the current set.
    vector<string> tempSet;
    if(!setInput(filename, tempSet))
        return;
    
    //DIFFERENCE LOGIC
    
    vector<string> tempSet2;
    
    
    for(int i = 0; i < currentSet.size(); i++){ 
        bool foundItInNewSet = false;
        for(int j = 0; j < tempSet.size(); j++){
            if(currentSet[i].substr(0, currentSet[i].find_last_of(" ")) == tempSet[j].substr(0, tempSet[j].find_last_of(" "))){
                
                string tempString = currentSet[i].substr(0, currentSet[i].find_last_of(" "));
                
                
                int tempInt1 = atoi (currentSet[i].substr(currentSet[i].find_last_of(" ") + 1, currentSet[i].length() - 1).c_str());
                int tempInt2 = atoi (tempSet[j].substr(tempSet[j].find_last_of(" ") + 1, tempSet[j].length() - 1).c_str());
                
                
                tempString.append(" ");
                tempString.append(to_string(tempInt1 - tempInt2));
                
                tempSet2.push_back(tempString);
                
                tempSet.erase(tempSet.begin() + j);
                
                foundItInNewSet = true;
                break;
            }
        }
        
        if(!foundItInNewSet)
            tempSet2.push_back(currentSet[i]);
        
    }
    
    for (int i = 0; i < tempSet.size(); i++){
        tempSet2.push_back(tempSet[i]);
    }
    
    setErrorHandling(tempSet2);
    
    currentSet = tempSet2;
        
    //END DIFFERENCE LOGIC
    
    if(outputMode != 2){
        cout << "\n" << filename << " difference complete" << endl;
    }
    
}

void MultiSet::intersectMultiset(string filename){ //Compares current multiset to the file and saves intersecting items (and quantities) to current multiset
    vector<string> tempSet;
    if(!setInput(filename, tempSet))
        return;
    
    //BEGIN INTERSECT LOGIC
    
    vector<string> tempSet2;
    
    
    for(int i = 0; i < currentSet.size(); i++){
        for(int j = 0; j < tempSet.size(); j++){
            if(currentSet[i].substr(0, currentSet[i].find_last_of(" ")) == tempSet[j].substr(0, tempSet[j].find_last_of(" "))){
                
                string tempString = currentSet[i].substr(0, currentSet[i].find_last_of(" "));
                
                
                int tempInt1 = atoi (currentSet[i].substr(currentSet[i].find_last_of(" ") + 1, currentSet[i].length() - 1).c_str());
                int tempInt2 = atoi (tempSet[j].substr(tempSet[j].find_last_of(" ") + 1, tempSet[j].length() - 1).c_str());
                
                
                tempString.append(" ");
                tempString.append(std::to_string(minimum(tempInt1, tempInt2)));
                
                tempSet2.push_back(tempString);
                
                tempSet.erase(tempSet.begin() + j);
                break;
            }
        }
        
    }
    
    setErrorHandling(tempSet2);
    
    currentSet = tempSet2;
    
    
    //END INTERSECT LOGIC
    
    if(outputMode != 2){
        cout << "\n" << filename << " intersection complete" << endl;
    }
}

void MultiSet::resetMultiSet(){
    currentSet.clear();
    
    if(outputMode != 2){
        cout << "\n" << "Reset completed" << endl;
    }
    
}

void MultiSet::outputMultiSet(string filename){ //Saves current multiset to file
    output.open(filename.c_str());
    if(output.fail()){
        cerr << "Sorry! File: \"" << filename << "\" couldn't be written!" << endl;
        return;
    }
    for(int i = 0; i < currentSet.size(); i++){
        output << currentSet[i] << "\n";
    }
    
    output.close();
    
    if(outputMode != 2){
        cout << "\nSave to " << filename << " completed" << endl;
    }
}

foundSettings MultiSet::findMultiSet(string itemName){ //Returns a foundSettings object which includes: 'numberFound' -- the number found, and 'truncationsUsed' -- the truncations (positive or negative) neccessary on the input string for the string to be found in the set, and finally 'stringGuess' -- the guessed string if the input was indeed close to an actual set member

    

    foundSettings results(0,0);
    
    for(int i = 0; i < currentSet.size(); i++){ //Check first for exact matches
            if(currentSet[i].substr(0, currentSet[i].find_last_of(" ")) == itemName){
                results.applySettings((stoi (currentSet[i].substr(currentSet[i].find_last_of(" ") + 1, currentSet[i].size()))), 0);
                return results;
            }
    }

    for(int j = 0; j <= CORRECTION_RANGE; j++){ //Next we truncate the string to look for a close match (Current Setting is set to only look for one character behind).
         for(int i = 0; i < currentSet.size(); i++){
            if(currentSet[i].substr(0, itemName.size() - j) == itemName.substr(0,itemName.size() - j)){ //We have a match, but...
                if(currentSet[i].find_last_of(" ") == itemName.size() - j){ //Check to make sure this is the full word and not just part of a word.
                    results.applySettings((stoi (currentSet[i].substr(itemName.size() - j, currentSet[i].size()))), j, currentSet[i].substr(0, itemName.size() - j));
                    return results;
                }
            }
        }
    }
    
    for(int j = 0; j <= CORRECTION_RANGE; j++){ //Still nothing? Now we check one more time for the other way around - look for a close match that's [one] character bigger
         for(int i = 0; i < currentSet.size(); i++){
            if(currentSet[i].substr(0, itemName.size()) == itemName){ //We have a match, but...
                if(currentSet[i].find_last_of(" ") == itemName.size() + j){ //Check to make sure this is the full word and not just part of a word.
                    results.applySettings((stoi (currentSet[i].substr(itemName.size() + j, currentSet[i].size()))), -j, currentSet[i].substr(0, itemName.size() + j));
                    return results;
                }
            }
        }
    }
    
    return results;
    
}

void MultiSet::insertMultiSet(string itemName, int itemQuantity){ //Inserts the item into the list with the designated quantity

    string tempString = itemName;

    currentSet.push_back((tempString.append(" ")).append(to_string(itemQuantity)));
    cout << currentSet[0];
    setErrorHandling(currentSet);
    
    if(outputMode != 2){
        cout << "\nItem " << itemName << " inserted; has count " << findMultiSet(itemName).numberFound << endl;
    }
}

void MultiSet::deleteMultiSet(string itemName){ //Deletes the item from the list, regardless of quantity
    if(findMultiSet(itemName).numberFound > 0){
        if(autoCorrectMode || findMultiSet(itemName).truncationsUsed == 0){
            for(int i = 0; i < currentSet.size(); i++){
                if(currentSet[i].substr(0, currentSet[i].find_last_of(" ")) == itemName){
                    currentSet.erase(currentSet.begin() + i);
                    break;
                }
            }
            if(outputMode != 2){
                cout << "\nItem " << itemName.substr(0,itemName.size() - findMultiSet(itemName).truncationsUsed) << " deleted" << endl;
            }
            return;
        }
    
        else{
            if(outputMode != 2)
                cout << "\nItem " << itemName << " not in multiset. Did you mean \"" << findMultiSet(itemName).stringGuess << "\"?" << endl;
            return;
        }
    
    }
    
    else{
        if(outputMode != 2){
            cout << "\nItem " << itemName << " not in multiset" << endl;
        
        }
        return;
        
    }
    
}

void MultiSet::reduceMultiSet(string itemName, int reduceQuantity){ //Reduces the designated item by the designated amount from the list
    if (findMultiSet(itemName).numberFound > 0){
        if(autoCorrectMode || findMultiSet(itemName).truncationsUsed == 0){
            currentSet.push_back(itemName + " " + to_string(-1 * reduceQuantity));
            
            int tempSize1 = currentSet.size() - 1;
            
            setErrorHandling(currentSet);
            
            if(tempSize1 != currentSet.size()){ //We reduced the item below or equal to zero and therefore deleted it from the set
                if(outputMode != 2){
                    cout << "\nItem " << itemName.substr(0,itemName.size() - findMultiSet(itemName).truncationsUsed) << " removed" << endl;
                }
                return;
            }
            
            if(outputMode != 2){
                cout << "\nItem " << itemName.substr(0,itemName.size() - findMultiSet(itemName).truncationsUsed) << " reduced to " << findMultiSet(itemName).numberFound << endl;
            }
            return;
        }
        
        else{
            if(outputMode != 2)
                cout << "\nItem " << itemName << " not in multiset. Did you mean \"" << findMultiSet(itemName).stringGuess << "\"?" << endl;
            return;
        }
    }
    else{
        if(outputMode != 2){
            cout << "\nItem " << itemName << " not in multiset" << endl;
        }
        return;
    }
}

void MultiSet::displayHelp(){
    cout << "\n" << HELP_MESSAGE << endl;
}

void MultiSet::maxMultiSet(string filename){ //Compares the input file to the current set and returns the maximum number for each item found
    vector<string> tempSet;
    if(!setInput(filename, tempSet))
        return;
    
    
    //MAXIMUM LOGIC
    
    vector<string> tempSet2;
    
    
    for(int i = 0; i < currentSet.size(); i++){ 
        bool foundItInNewSet = false;
        for(int j = 0; j < tempSet.size(); j++){
            if(currentSet[i].substr(0, currentSet[i].find_last_of(" ")) == tempSet[j].substr(0, tempSet[j].find_last_of(" "))){
                
                string tempString = currentSet[i].substr(0, currentSet[i].find_last_of(" "));
                
                
                int tempInt1 = atoi (currentSet[i].substr(currentSet[i].find_last_of(" ") + 1, currentSet[i].length() - 1).c_str());
                int tempInt2 = atoi (tempSet[j].substr(tempSet[j].find_last_of(" ") + 1, tempSet[j].length() - 1).c_str());
                
                
                tempString.append(" ");
                tempString.append(to_string(maximum(tempInt1, tempInt2)));
                
                tempSet2.push_back(tempString);
                
                tempSet.erase(tempSet.begin() + j);
                
                foundItInNewSet = true;
                break;
            }
        }
        
        if(!foundItInNewSet)
            tempSet2.push_back(currentSet[i]);
        
    }
    
    for (int i = 0; i < tempSet.size(); i++){
        tempSet2.push_back(tempSet[i]);
    }
    
    setErrorHandling(tempSet2);
    
    currentSet = tempSet2;
        
    //END MAXIMUM LOGIC
    
    if(outputMode != 2){
        cout << "Max completed" << endl;
    }
    
}

void MultiSet::toggleAutoCorrectMode(){ //Toggles autocorrect mode
    autoCorrectMode = !autoCorrectMode;
    if(outputMode != 2){
        cout << "\nAuto-Correct now turned ";
        if(autoCorrectMode){
            cout << "on" << endl;
        }
        else{
            cout << "off" << endl;
        }
    }
}

bool MultiSet::setInput(string filename, vector<string> & tempSet){ //Input Helper function (used by a pretty much all set operations. Returns true for success, false for failure
    input.open(filename.c_str());
    if(input.fail()){
        cerr << "Sorry! File: \"" << filename << "\" couldn't be read!" << endl;
        input.close();
        return false;
    }
    
    string tempLine;
    
    while( getline(input, tempLine)){   //This adds the chosen file into the current set.
        tempSet.push_back(tempLine);
    }
    
    setErrorHandling(tempSet); //This is done right away so that, if the test file is in the wrong format, we don't lose the data in the current set
    
    if(tempSet.empty()){
        input.close();
        return false;
    }
    
    input.close();
    return true;
}

void MultiSet::setErrorHandling(vector<string> & currentSet){ //A mutating helper function (Procedure?) that checks for errors in the input file format
    
    if(currentSet.size() == 0){ //First of all, we don't have to do anything if the set is empty!
        return;
    }
    
    for (int i = 0; i < currentSet.size(); i++){
        bool justCarriageReturn = false; //A test variable to see if there's an empty line in the set.
        if(currentSet[i].find(" ") == string::npos){ //If there's no spaces, we have either an empty line or a problem...
            if (currentSet[i].size() > 1){ //We have a problem
                cerr << "Error! The file isn't in the right format at line " << i + 1 << "! Make sure your items and how many of them there are seperated by a space!" << endl;
                currentSet.clear();
                return;
            }
            else{   //We have an empty line
                justCarriageReturn = true;
                currentSet.erase(currentSet.begin() + i);
                i -= 1;
            }
            
        }
        if(!justCarriageReturn){
            bool passedSpaceTest = true; //Used for case below
            if(currentSet[i].find_last_of(" ") == currentSet[i].size() - 1){ //This means that the space is the last character, which could be bad or couldn't be (If everything else is in the right format), so we just take off this space and run the line through the checker again.
                currentSet[i].erase(currentSet[i].length() - 1);
                passedSpaceTest = false;
            }
            else if(currentSet[i].find_first_of(" ") == 0){ //Likewise, having a space start the line can be a problem or it could just be a simple mistake, so we'll give the string the benefit of the doubt, take off the initial space, and run the string through the checker again.
                currentSet[i] = currentSet[i].substr(1, currentSet[i].length());
                passedSpaceTest = false;
            }
            if(currentSet[i].at(currentSet[i].find_last_of(" ") - 1) == ' '){ //This one makes sure that there is only one space between the item name and the number name.
                currentSet[i] = (currentSet[i].substr(0, currentSet[i].find_last_of(" ") - 2) + currentSet[i].substr(currentSet[i].find_last_of(" "), currentSet[i].length() - 1));
                passedSpaceTest = false;
                
            }
            if (passedSpaceTest){ //Alright! If we got here, the string is starting to look like we want it to!
                if(!isdigit((currentSet[i]).at(currentSet[i].length() - 1))){ //If the last character isn't a digit, we have a problem again...
                    cerr << "Error! The file isn't in the right format at line " << i + 1 << "! Make sure you specify how many of each item you have!" << endl;
                    currentSet.clear();
                    return;
                }
                
            }
            else{
                i -= 1;
            }
        }
        
    }
    
    //We got through most Error Handling!
    //Now that that's finally over and our strings are just how we want them, we still have to add up the numbers of like strings.
    for (int i = 0; i < currentSet.size(); i++){
        for(int j = i + 1; j < currentSet.size(); j++){ //So, we're going to check if the item is mentioned multiple times. We want to make it nice and convenient, so we'll add up the number of items into one place.
            if((currentSet[i].substr(0, currentSet[i].find_last_of(" "))) == (currentSet[j].substr(0, currentSet[j].find_last_of(" ")))){ //As mentioned above, we're looking to see if the name of the items are the same (but the number of those items doesn't have to be)e
                int tempInt1 = atoi (currentSet[i].substr(currentSet[i].find_last_of(" ") + 1, currentSet[i].length() - 1).c_str());
                int tempInt2 = atoi (currentSet[j].substr(currentSet[j].find_last_of(" ") + 1, currentSet[j].length() - 1).c_str());
                currentSet[i].erase(currentSet[i].find_last_of(" "), currentSet[i].length() - 1);
                currentSet[i].append(" ");
                currentSet[i].append(to_string(tempInt1 + tempInt2));
                currentSet.erase(currentSet.begin() + j);
                j -= 1;
            }
        }
    }
    
    //Finally, we have to check if the number of items is less than or equal to 0; if it is, then it shouldn't be displayed in the list!
    for (int u = 0; u < currentSet.size(); u++){
        if(atoi(currentSet[u].substr(currentSet[u].find_last_of(" ") + 1, currentSet[u].size()).c_str()) <= 0){
            currentSet.erase(currentSet.begin() + u);
            u--;
        }
    }
    
    return;
}

bool MultiSet::compareItemName(string itemName, int index){ //A helper function used quite often to compare the item names of set members without looking at the number of items (It's kind of ugly, hence it's wrapped up in this helper function
    if(currentSet[index].substr(0, currentSet[index].find_last_of(" ")) == itemName)
        return true;
    
    return false;
    
}

int MultiSet::minimum(int a, int b){
    if(a > b)
        return b;
    return a;
}

int MultiSet::maximum(int a, int b){
    if(a > b)
        return a;
    return b;
}

bool MultiSet::GetAutoCorrectMode(){
    return autoCorrectMode;
}

int MultiSet::GetSize(){
    return currentSet.size();
}