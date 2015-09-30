#include "COP3503su14_Proj3_RicardoR.h"

Recipe::Recipe() {
  title = "";
}

void Recipe::inputRecipe (string name) {
	//Declarations and stuff
  int fourthintquantity = 1;
  string fourthvaluefood = "";
  string fourthvalueunit = "";
  string fourthvalueequipment = "";
  string thirdvaluestep = "";

  doc.LoadFile(name.c_str());

	if (doc.Error()) {
		cerr << "No such file was found" << endl;
    return;
	}

  XMLElement * root = doc.RootElement();

  XMLNode * next = root -> FirstChild();
  while (next != NULL) {
    string noextras = next -> Value();
    if (noextras == "title") {
      title = next -> FirstChild() -> Value();
    }

    else {
    }
    string value = next -> Value();
    if (value == "ingredientlist") {
      XMLNode * secondnext = next -> FirstChild();
      while (secondnext != NULL) {
        string secondvalue = secondnext -> Value();
        if (secondvalue == "ingredient") {
          XMLNode * thirdnext = secondnext -> FirstChild();
          while (thirdnext != NULL) {
            string thirdvalue = thirdnext -> Value();
            if (thirdvalue == "quantity") {
              string fourthvalue = thirdnext -> FirstChild() -> Value();
              stringstream s_fourthvalue(fourthvalue);
              s_fourthvalue >> fourthintquantity;
            } 

            if (thirdvalue == "fooditem") {
              fourthvaluefood = thirdnext -> FirstChild() -> Value();
            }
            

            if (thirdvalue == "unit") {
              fourthvalueunit = thirdnext -> FirstChild() -> Value();
            }


            thirdnext = thirdnext -> NextSibling();
          
          }            
            
          ingredient.ingredientCheck(fourthintquantity, fourthvaluefood, fourthvalueunit); //adds ingredients
          fourthintquantity = 1;
          fourthvaluefood = "";
          fourthvalueunit = "";
        }

        secondnext = secondnext -> NextSibling();
        
      }
    }

    else if (value == "preparation") {
      XMLNode * secondnext = next -> FirstChild();
      while (secondnext != NULL) {
        string secondvalue = secondnext -> Value();
        if (secondvalue == "step") {
          XMLNode * thirdnext = secondnext -> FirstChild();
          while (thirdnext != NULL) {           
            string thirdvaluestep = thirdnext -> Value();
            if(thirdvaluestep == "equipment") {
              fourthvalueequipment = thirdnext->FirstChild()->Value(); 
              equipment.equipmentCheck(fourthvalueequipment); //adds equipment       
            }

            thirdnext = thirdnext -> NextSibling();
            preparation.stepCheck(thirdvaluestep);
            thirdvaluestep = "";
            preparation.stepCheck(fourthvalueequipment);
            fourthvalueequipment = "";    
            
          } 
          

        }

        secondnext = secondnext -> NextSibling();

      }    

    }

    next = next -> NextSibling();
  }
  
}

void Recipe::setTitle(string input) {
  title = input;
}

void Recipe::printTitle() {
  cout << title << endl;
}

void Recipe::printIngredient() {
  ingredient.printIngredient();
}

void Recipe::printEquipment() {
  equipment.printEquipment();
}
 
void Recipe::printStep() {
  preparation.printStep();
}

void Recipe::printRecipe(string word) {
  if (word == title) {
    cout << "Current recipe:" << endl;
    printTitle();
    cout << "Ingredients: " << endl;
    printIngredient();
    cout << "Equipment: " << endl;
    printEquipment();
    cout << "Preparation: " << endl;
    printStep();
  }
  
}

void Recipe::ingredientCheck(int quantity, string food, string unit) {
  ingredient.ingredientCheck(quantity, food, unit);
}

void Recipe::equipmentCheck(string stuff) {
  equipment.equipmentCheck(stuff);
}

void Recipe::stepCheck(string step) {
  preparation.stepCheck(step);
}

string Recipe::getTitle() {
  return title;
}

void Recipe::removeEquipment(string word){
  equipment.removeEquipment(word);
}

void Recipe::reduceIngredient(int quantity, string food, string unit) {
  ingredient.ingredientCheck(quantity, food, unit);
}

Ingredient Recipe::getIngredients() {
  return ingredient;
}

Equipment Recipe::getEquipment() {
  return equipment;
}

//////////////////////////INGREDIENTSTUFF/////////////////////////////////

Ingredient::Ingredient(){
  numStrings = 0;
}

void Ingredient::ingredientCheck(int quantity, string food, string unit) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i) {
    if (foodSet[i] == food && unitSet[i] == unit) {
      quantitySet[i] += quantity;
      ++found;
    }
  }
  if (found == 0){
    quantitySet[numStrings] = quantity;
    foodSet[numStrings] = food;
    unitSet[numStrings] = unit;
    ++numStrings;
  }

  if (numStrings == MAX_STRINGS) {
    cout << "Set is too big" << endl;
  }
}

void Ingredient::Add(Ingredient& in) {
  string tempString;
  string secondString;
  int tempQuant;
  for (int i = 0; i < in.getNumstrings(); ++i) {
    tempString = in.getFoodset()[i];
    secondString = in.getUnitset()[i];
    tempQuant = in.getQuantityset()[i];
    ingredientCheck(tempQuant, tempString, secondString);
  }
}

void Ingredient::printIngredient() {
  //cout << numStrings << endl;
  for (int i = 0; i < numStrings; ++i) {
    if (foodSet[i] != "") {
      if (quantitySet[i] == 0 && unitSet[i] == "") {
        cout << "   " << foodSet[i] << endl;
      }

      else if (quantitySet[i] == 1) {
        cout << "   " << foodSet[i] << " " << unitSet[i] << endl;
      }

      else if (unitSet[i] == "") {
        cout << "   " << quantitySet[i] << " " << foodSet[i] << endl;
      }

      else {
        cout << "   " << quantitySet[i] << " " << foodSet[i] << " " << unitSet[i] << endl;  
      }     
    }     
  }  
}

void Ingredient::reduceIngredient(int quantity, string food, string unit) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i) {
    if (foodSet[i] == food && unitSet[i] == unit) {
      quantitySet[i] -= quantity;
      ++found;
      if (quantitySet[i] <= 0) {
        foodSet[i] = "";
        --i;  
      }
    }
  }

  if (found == 0) {
    cout << food << " is not in the set" << endl;
  }
}

string* Ingredient::getFoodset() {
  return foodSet;
}

string* Ingredient::getUnitset() {
  return unitSet;
}

int* Ingredient::getQuantityset() {
  return quantitySet;
}

int Ingredient::getNumstrings() {
  return numStrings;
}

////////////////////////EQUIPMENTSTUFF///////////////////////////
Equipment::Equipment(){
  numStrings = 0;
}

void Equipment::equipmentCheck(string equipment) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i) {
    if (equipmentSet[i] == equipment) {
      ++found;
    }
  }
  if (found == 0){
    equipmentSet[numStrings] = equipment;
    ++numStrings;
  }

  if (numStrings == MAX_STRINGS) {
    cout << "Set is too big" << endl;
  }
}


void Equipment::printEquipment() {
  for (int i = 0; i < numStrings; ++i) {
    if (equipmentSet[i] != "") {
      cout << "   " << equipmentSet[i] << endl;
    }    
  }  
}

void Equipment::removeEquipment(string word) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i){
    if (equipmentSet[i] == word){
      equipmentSet[i] = "";
      --i;
      ++found;
    }
  } 

  if (found == 0) {
    cout << word << " is not in the set" << endl;
  }
}

string* Equipment::getEquipments() {
  return equipmentSet;
}

int Equipment::getNumstrings() {
  return numStrings;
}

///////////////////////PREPARATIONSTUFF//////////////////////////
Preparation::Preparation() {
  numStrings = 0;
}

void Preparation::stepCheck(string step) {
  int found = 0;
  for (int i = 0; i < numStrings; ++i) {
    if (stepSet[i] == step) {
      ++found;
    }
  }
  if (found == 0){
    stepSet[numStrings] = step;
    ++numStrings;
  }

  if (numStrings == MAX_STRINGS) {
    cout << "Set is too big" << endl;
  }
}

void Preparation::printStep() {
  for (int i = 0; i < numStrings; ++i) {
    if (stepSet[i] != "equipment") {
      cout << "   " << stepSet[i] << endl;
    }    
  } 
}

////////////////////////////RECIPESET//////////////////////////////

RecipeSet::RecipeSet() {
  
}

int RecipeSet::getSize() {
  return menulist.size();
}

void RecipeSet::addRecipe(Recipe* inputRecipe) {
  int found = 0;
  for (int i = 0; i < recipelist.size(); ++i) {
    if (recipelist[i]->getTitle() == inputRecipe->getTitle()) {
      cout << "Recipe already exists." << endl;
      ++found;
    }
  }
  if (found == 0){
    recipelist.push_back(inputRecipe);
  }
}

void RecipeSet::addMenu(string input) {
  int found = 0;
  for (int i = 0; i < recipelist.size(); ++i) {
    if (recipelist[i]->getTitle() == input) {
      menulist.push_back(recipelist[i]);
    }
  }
 
}

void RecipeSet::eraseRecipe(string inputRecipe) {
  for (int i = 0; i < menulist.size(); ++i) {
    if (menulist[i]->getTitle() == inputRecipe) {
      menulist.erase(menulist.begin()+i);
    }
  }
}

void RecipeSet::resetMenu() {
  menulist.clear(); 
}

void RecipeSet::printMenu() {
  for (int i = 0; i < menulist.size(); ++i) {
    cout << menulist[i]->getTitle() << endl;
  }
}

void RecipeSet::printIngredient() {
  for (int i = 0; i < menulist.size(); ++i) {
    menulist[i]->printIngredient();
  }
}

void RecipeSet::printEquipment() {
  for (int i = 0; i < menulist.size(); ++i) {
    menulist[i]->printEquipment();
  }
}

void RecipeSet::printRecipe(string word) {
  int found = 0;
  for (int i = 0; i < menulist.size(); ++i) {
    if (menulist[i]->getTitle() == word) {
      menulist[i]->printRecipe(word);
    }
  }
}

void RecipeSet::subtractShoppingingredient(Inventory& stuff) {
  Ingredient fun = stuff.getIngredients();
  string *names = fun.getFoodset();
  string *units = fun.getUnitset();
  int *quants = fun.getQuantityset();
  int numnum2 = fun.getNumstrings();
  for (int i = 0; i < menulist.size(); ++i) {
    for (int j = 0; j < numnum2; ++j) {
      int foodset_size = menulist[i]->getIngredients().getFoodset()->size(); // How many arrays are returned from getFoodset()
      int unitset_size = menulist[i]->getIngredients().getUnitset()->size(); // How many arrays are returned from getUnitset()

      for (int k = 0; k < foodset_size; k++) {
        if (menulist[i]->getIngredients().getFoodset()[k] == names[j]) {
          for (int l = 0; l < unitset_size; l++) {
            if (menulist[i]->getIngredients().getUnitset()[l] == units[j]) {
              menulist[i]->getIngredients().getQuantityset()[i] -= quants[j];
              if (menulist[i]->getIngredients().getQuantityset()[i] <= 0) {
                menulist[i]->getIngredients().getFoodset()[i] = "";
                --i;
              }
            }
          }
        }
      }
    } 
  } 
}

// void RecipeSet::printShoppingingredient() {
//   subtractShoppingingredient();
//   printIngredient();
// }

void RecipeSet::subtractShoppingequipment(Inventory& stuff) {
  Equipment fun = stuff.getEquipment();
  string *names = fun.getEquipments();
  int numnum2 = fun.getNumstrings();
  for (int i = 0; i < menulist.size(); ++i) {
    for (int j = 0; j < numnum2; ++j) {
      int foodset_size = menulist[i]->getEquipment().getEquipments()->size(); // How many arrays are returned from getEquipment()
      for (int k = 0; k < foodset_size; k++) {
        if (menulist[i]->getEquipment().getEquipments()[k] == names[j]) {
          menulist[i]->getEquipment().getEquipments()[i] = "";
          --i;
        }
      }
    } 
  } 
}

// void RecipeSet::printShoppingequipment() {
//   subtractShoppingequipment();
//   printIngredient();
// }

void RecipeSet::outputShoppingingredient(string out) {
  ofstream output;
  // subtractShoppingequipment();
  output.open(out.c_str());
  for (int i = 0; i < menulist.size(); ++i) {
    output << menulist[i];
  }
}

void RecipeSet::outputShoppingequipment(string out) {
  ofstream output;
  // subtractShoppingingredient();
  output.open(out.c_str());
  for (int i = 0; i < menulist.size(); ++i) {
    output << menulist[i];
  }
}

Recipe* RecipeSet::getRecipe(int index) {
  if (index > recipelist.size()) {
    cout << "Out of bounds" << endl;
    return NULL;
  }

  else {
    return recipelist[index];
  }
}

Recipe* RecipeSet::getMenu(int index) {
  if (index > menulist.size()) {
    cout << "Out of bounds" << endl;
    return NULL;
  }

  else {
    return menulist[index];
  }
}
/////////////////////////////////INVENTORY//////////////////////////////
Inventory::Inventory() {

}

void Inventory::inputInventory (string name) {
  //Declarations and stuff
  int fourthintquantity = 1;
  string fourthvaluefood = "";
  string fourthvalueunit = "";
  string thirdvalueequipment = "";


  doc.LoadFile(name.c_str());

  if (doc.Error()) {
    cerr << "No such file was found" << endl;
    return;
  }

  XMLElement * root = doc.RootElement();

  XMLNode * next = root -> FirstChild();
  while (next != NULL) {
    string value = next -> Value();
    if (value == "ingredientlist") {
      XMLNode * secondnext = next -> FirstChild();
      while (secondnext != NULL) {
        string secondvalue = secondnext -> Value();
        if (secondvalue == "ingredient") {
          XMLNode * thirdnext = secondnext -> FirstChild();
          while (thirdnext != NULL) {
            string thirdvalue = thirdnext -> Value();
            if (thirdvalue == "quantity") {
              string fourthvalue = thirdnext -> FirstChild() -> Value();
              stringstream s_fourthvalue(fourthvalue);
              s_fourthvalue >> fourthintquantity;
            } 

            if (thirdvalue == "fooditem") {
              fourthvaluefood = thirdnext -> FirstChild() -> Value();
            }
            

            if (thirdvalue == "unit") {
              fourthvalueunit = thirdnext -> FirstChild() -> Value();
            }


            thirdnext = thirdnext -> NextSibling();
          
          }            
            
          ingredient.ingredientCheck(fourthintquantity, fourthvaluefood, fourthvalueunit); //adds ingredients
          fourthintquantity = 1;
          fourthvaluefood = "";
          fourthvalueunit = "";
        }

        secondnext = secondnext -> NextSibling();
        
      }
    }

    else if (value == "equipmentlist") {
      XMLNode * secondnext = next -> FirstChild();
      while (secondnext != NULL) {
        string secondvalue = secondnext -> Value();
        if (secondvalue == "equipment") {
          XMLNode * thirdnext = secondnext -> FirstChild();
          while (thirdnext != NULL) {           
            string thirdvalueequipment = thirdnext -> Value();
            thirdnext = thirdnext -> NextSibling();
            equipment.equipmentCheck(thirdvalueequipment);
            thirdvalueequipment = "";
          } 
        }

        secondnext = secondnext -> NextSibling();

      }    

    }

    next = next -> NextSibling();
  } 
}

void Inventory::subtractInventory (string name) {
  //Declarations and stuff
  int fourthintquantity = 1;
  string fourthvaluefood = "";
  string fourthvalueunit = "";
  string thirdvalueequipment = "";


  doc.LoadFile(name.c_str());

  if (doc.Error()) {
    cerr << "No such file was found" << endl;
  }

  XMLElement * root = doc.RootElement();
  XMLNode * next = root -> FirstChild();
  while (next != NULL) {
    string value = next -> Value();
    if (value == "ingredientlist") {
      XMLNode * secondnext = next -> FirstChild();
      while (secondnext != NULL) {
        string secondvalue = secondnext -> Value();
        if (secondvalue == "ingredient") {
          XMLNode * thirdnext = secondnext -> FirstChild();
          while (thirdnext != NULL) {
            string thirdvalue = thirdnext -> Value();
            if (thirdvalue == "quantity") {
              string fourthvalue = thirdnext -> FirstChild() -> Value();
              stringstream s_fourthvalue(fourthvalue);
              s_fourthvalue >> fourthintquantity;
            } 
            if (thirdvalue == "fooditem") {
              fourthvaluefood = thirdnext -> FirstChild() -> Value();
            }            

            if (thirdvalue == "unit") {
              fourthvalueunit = thirdnext -> FirstChild() -> Value();
            }
            thirdnext = thirdnext -> NextSibling();          
          }            
          ingredient.reduceIngredient(fourthintquantity, fourthvaluefood, fourthvalueunit); //adds ingredients
          fourthintquantity = 1;
          fourthvaluefood = "";
          fourthvalueunit = "";
        }
        secondnext = secondnext -> NextSibling();        
      }
    }

    else if (value == "equipmentlist") {
      XMLNode * secondnext = next -> FirstChild();
      while (secondnext != NULL) {
        string secondvalue = secondnext -> Value();
        if (secondvalue == "equipment") {
          XMLNode * thirdnext = secondnext -> FirstChild();
          while (thirdnext != NULL) {           
            string thirdvalueequipment = thirdnext -> Value();
            thirdnext = thirdnext -> NextSibling();
            equipment.removeEquipment(thirdvalueequipment);
            thirdvalueequipment = "";
          } 
        }
        secondnext = secondnext -> NextSibling();
      }    
    }
    next = next -> NextSibling();
  }
}

void Inventory::ingredientCheck(int quantity, string food, string unit) {
  ingredient.ingredientCheck(quantity, food, unit);
}

void Inventory::equipmentCheck(string stuff) {
  equipment.equipmentCheck(stuff);
}

void Inventory::printIngredient() {
  ingredient.printIngredient();
}

void Inventory::printEquipment() {
  equipment.printEquipment();
}

void Inventory::removeEquipment(string word){
  equipment.removeEquipment(word);
}

void Inventory::reduceIngredient(int quantity, string food, string unit) {
  ingredient.reduceIngredient(quantity, food, unit);
}

Ingredient Inventory::getIngredients() {
  return ingredient;
}

Equipment Inventory::getEquipment() {
  return equipment;
}


