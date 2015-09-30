#include "COP3503su14_Proj3_RicardoR.h"

  
int main(int argc, char ** argv) {
	//Classes
  RecipeSet recipeset;
  Recipe *recipe = new Recipe();
  Inventory inventory;
  //Declarations
  string inFileName;
	string outFileName;
  string titleString;
	string tempString;
  string line;
  string hold;
  string stuff;
  int number = 0;
  bool NORMAL(true);
  bool VERBOSE(true);
  bool SILENT(true);
  int option = -1;

  if (argc > 1) {

  	for(int n = 1; n < argc; n++) {
			if(argv[n] == string("-s")){
        VERBOSE = 0;
        NORMAL = 0;
        SILENT = 1;    
	    } 

	    if (argv[n] == string("-v")) {
		    VERBOSE = 1;
		    NORMAL = 0;
		    SILENT = 0;
	  	}

      if (argv[n] == string("-r")) {
        if (inFileName == argv[n]) {
          recipe = new Recipe();
          recipe->inputRecipe(inFileName);
          recipeset.addRecipe(recipe); 
        }
      }


      if (argv[n] == string("-i")) {
        if (inFileName == argv[n]) {
          inventory.inputInventory(inFileName);
        }
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
      cout << "1. Input recipe file <filename>" << endl;
      cout << "2. Input inventory file <filename>" << endl;
      cout << "3. Subtract inventory file <filename>" << endl;
      cout << "4. Add <recipe name>" << endl;
      cout << "5. Remove <recipe name>" << endl;
      cout << "6. Reset current menu list to empty set" << endl;
      cout << "7. Output menu <filename>" << endl;
      cout << "8. Print current menu list to the console in formatted plain text" << endl;
      cout << "9. Print <recipe name>" << endl;
      cout << "10. Increase <ingredient inventory item>" << endl;
      cout << "11. Reduce <ingredient inventory item>" << endl;
      cout << "12. Insert <equipment inventory item>" << endl;
      cout << "13. Delete <equipment inventory item>" << endl;
      cout << "14. Print ingredient inventory" << endl;
      cout << "15. Print equipment inventory" << endl;
      cout << "16. Print ingredient list" << endl;
      cout << "17. Print ingredient shopping list" << endl;
      cout << "18. Output ingredient shopping list" << endl;
      cout << "19. Print equipment list" << endl;
      cout << "20. Print equipment shopping list" << endl;
      cout << "21. Output equipment shopping list <file>" << endl;
      cout << "22. Help" << endl;
      cout << ">" << flush;
    } 

    else if (NORMAL) {
      cout << ">" << flush;
    } 

    cin >> option;
    if (option == 1) {
      if (VERBOSE || NORMAL){
        cout << "Input recipe file: " << flush;
      }  
      cin >> inFileName;
      if (VERBOSE || NORMAL) {
        cout << "Input recipe file is " << inFileName << endl;  
      }
      recipe = new Recipe();
      recipe->inputRecipe(inFileName);
      recipeset.addRecipe(recipe);     

    }

    else if (option == 2) {
      if (VERBOSE || NORMAL){
        cout << "Input inventory file: " << flush;
      }  
      cin >> inFileName;
      if (VERBOSE || NORMAL) {
        cout << "Input inventory file is " << inFileName << endl;  
      }
      inventory.inputInventory(inFileName);
    } 

    else if (option == 3) {
      if (VERBOSE || NORMAL){
        cout << "Subtract inventory file: " << flush;
      }  
      cin >> inFileName;
      if (VERBOSE || NORMAL) {
        cout << "Subtract inventory file is " << inFileName << endl;  
      }
      
      inventory.subtractInventory(inFileName);
    }

    else if (option == 4) {
      if (VERBOSE || NORMAL) {
        cout << "Add a title: " << flush;  
      }
      cin.ignore();
      getline(cin, tempString);
      recipeset.addMenu(tempString);
    } 

    else if (option == 5) {
      if (VERBOSE || NORMAL) {
        cout << "Remove recipe title: " << flush;
      }
      cin.ignore();
      getline(cin, tempString);
      recipeset.eraseRecipe(tempString);
    }

    else if (option == 6) {
      if (VERBOSE || NORMAL) {
        cout << "Reset completed" << endl;
      } 
      recipeset.resetMenu();
    }

    else if (option == 7) {
      if (VERBOSE || NORMAL) {
        cout << "Output file name: " << flush;
      }  
      
    }

    else if (option == 8) {
      cout << "Current menu:" << endl;
      recipeset.printMenu();
    }

    else if (option == 9) {
      cout << "Input title: " << endl;
      cin.ignore();
      getline(cin, tempString);
      recipeset.printRecipe(tempString);
    }

    else if (option == 10) {
      if (VERBOSE || NORMAL) {
        cout << "Increase: " << endl;
      }
      cout << "Input foodItem: " << endl;
      cin.ignore();
      getline(cin, tempString);
      cout << "Input quantity: " << endl;
      cin >> number;
      cout << "Input unit (if no unit are not wanted to be added just input no): " << endl;
      cin >> line;
      if (line == "no") {
        line = "";
      }
      inventory.ingredientCheck(number, tempString, line);
    }

    else if (option == 11) {
      if (VERBOSE || NORMAL) {
        cout << "Reduce: " << endl;
      }
      cout << "Input foodItem: " << endl;
      cin.ignore();
      getline(cin, tempString);
      cout << "Input quantity: " << endl;
      cin >> number;
      cout << "Input unit: " << endl;
      cin >> line;
      if (line == "no") {
        line = "";
      }
      inventory.reduceIngredient(number, tempString, line);
      
    }

    else if (option == 12) {
      if (VERBOSE || NORMAL) {
        cout << "Insert: " << flush;
      }
      cin.ignore();
      getline(cin, tempString);
      inventory.equipmentCheck(tempString);
    }

    else if (option == 13) {
     	if (VERBOSE || NORMAL) {
        cout << "Delete: " << flush;
      }
      cin.ignore();
      getline(cin, tempString);
      inventory.removeEquipment(tempString);
    }

    else if (option == 14) {
      if (VERBOSE || NORMAL) {
        cout << "Ingredient inventory: " << endl;
      }
      inventory.printIngredient();
    }

    else if (option == 15) {
      if (VERBOSE || NORMAL) {
        cout << "Equipment inventory: " << endl;
      }
      inventory.printEquipment();
    }

    else if (option == 16) {
      if (VERBOSE || NORMAL) {
        cout << "Ingredient list: " << endl;
      }
      // Ingredient bigList;
      // for (int i = 0; i < recipeset.getSize() ; ++i) {
      //   bigList.Add(recipeset.getMenu(i)->getIngredients());
      // }
      // bigList.printIngredient();
      recipeset.printIngredient();
    }

    else if (option == 17) {
      if (VERBOSE || NORMAL) {
        cout << "Ingredient Shopping list: " << endl;
      }
      // recipeset.printShoppingingredient();
    }

    else if (option == 18) {
      if (VERBOSE || NORMAL) {
        cout << "Output ingredient Shopping list name: " << endl;
      }
      cin >> outFileName;
      // recipeset.outputShoppingingredient(outFileName);
    }

    else if (option == 19) {
      if (VERBOSE || NORMAL) {
        cout << "Equipment list: " << endl;
      }
      recipeset.printEquipment();
    }

    else if (option == 20) {
      if (VERBOSE || NORMAL) {
        cout << "Equipment Shopping list: " << endl;
      }
      // recipeset.printShoppingequipment();
    }

    else if (option == 21) {
      if (VERBOSE || NORMAL) {
        cout << "Output ingredient Shopping list completed" << endl;
      }
      // recipeset.outputShoppingequipment(outFileName);
    }

    else if (option == 22) {
			cout << "0. Exit" << endl;
			cout << "1. Input recipe file <filename>" << endl;
			cout << "2. Input inventory file <filename>" << endl;
			cout << "3. Subtract inventory file <filename>" << endl;
			cout << "4. Add <recipe name>" << endl;
			cout << "5. Remove <recipe name>" << endl;
			cout << "6. Reset current menu list to empty set" << endl;
			cout << "7. Output menu <filename>" << endl;
			cout << "8. Print current menu list to the console in formatted plain text" << endl;
			cout << "9. Print <recipe name>" << endl;
			cout << "10. Increase <ingredient inventory item>" << endl;
			cout << "11. Reduce <ingredient inventory item>" << endl;
			cout << "12. Insert <equipment inventory item>" << endl;
			cout << "13. Delete <equipment inventory item>" << endl;
			cout << "14. Print ingredient inventory" << endl;
			cout << "15. Print equipment inventory" << endl;
			cout << "16. Print ingredient list" << endl;
			cout << "17. Print ingredient shopping list" << endl;
			cout << "18. Output ingredient shopping list" << endl;
			cout << "19. Print equipment list" << endl;
			cout << "20. Print equipment shopping list" << endl;
			cout << "21. Output equipment shopping list <file>" << endl;
			cout << "22. Help" << endl;
    }

    else if (option > 22) {
      cerr << "Please enter a number between 0 and 22" << endl;
    }

    else {
      cerr << "You are now exiting" << endl;
    }

  }
  return 0;  
}