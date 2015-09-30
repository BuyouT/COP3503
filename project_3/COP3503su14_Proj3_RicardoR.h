#ifndef COP3503su14_Proj3_RicardoR
#define COP3503su14_Proj3_RicardoR
#include "tinyxml2.h"
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;
using namespace tinyxml2;

const int MAX_STRINGS = 1000;

class Ingredient {
	private:
		string foodSet[MAX_STRINGS];
		string unitSet[MAX_STRINGS];
		int quantitySet[MAX_STRINGS];
		int numStrings;
	public:
		Ingredient();
		void ingredientCheck(int, string, string);
		void printIngredient();
		void reduceIngredient(int, string, string);
		string* getFoodset();
		string* getUnitset();
		int* getQuantityset();
		int getNumstrings();
		void Add(Ingredient&);
};


class Equipment {
	private:
		string equipmentSet[MAX_STRINGS];
		int numStrings;
	public:
		Equipment();
		void equipmentCheck(string);
		void printEquipment();
		void removeEquipment(string);
		string* getEquipments();
		int getNumstrings();
};

class Preparation {
	private:
		string stepSet[MAX_STRINGS];
		int numStrings;
	public:
		Preparation();
		void stepCheck(string);
		void printStep();
		void stepRemove(string);
};


class Recipe {
	private:
		XMLDocument doc;
		Ingredient ingredient;
		Equipment equipment;
		Preparation preparation;
		string title;
	public:
		Recipe();
		string getTitle();
		void setTitle(string);
		void printTitle();
		void inputRecipe(string);
		void printRecipe();
		void printIngredient();
		void printEquipment();
		void printStep();
		void printRecipe(string);
		void ingredientCheck(int, string, string);
		void equipmentCheck(string);
		void stepCheck(string);
		void removeEquipment(string);
		void reduceIngredient(int, string, string);
		Ingredient getIngredients();
		Equipment getEquipment();
};

class Inventory {
	private:
		XMLDocument doc;
		Ingredient ingredient;
		Equipment equipment;
	public:
		Inventory();
		void inputInventory(string);
		void subtractInventory(string);
		void ingredientCheck(int, string, string);
		void equipmentCheck(string);
		void printIngredient();
		void printEquipment();
		void removeEquipment(string);
		void reduceIngredient(int, string, string);
		Ingredient getIngredients();
		Equipment getEquipment();
};

class RecipeSet {
	private:
		Inventory inventory;
		vector<Recipe*> recipelist;
		vector<Recipe*> menulist;
	public:
		RecipeSet();
		int getSize();
		void addRecipe(Recipe*);
		void addMenu(string input);
		void eraseRecipe(string);
		void resetMenu();
		void printMenu();
		void printIngredient();
		void printEquipment();
		void printRecipe(string);
		void subtractShoppingingredient(Inventory&);
		void printShoppingingredient();
		void subtractShoppingequipment(Inventory&);
		void printShoppingequipment();
		void outputShoppingingredient(string);
		void outputShoppingequipment(string);
		Recipe* getRecipe(int);
		Recipe* getMenu(int);
};

#endif