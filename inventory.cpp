#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;
// INVENTORY MANAGER

class Item;

class Inventory {
  private:
    vector<Item> items;  
  public:
    int getSize(){
      return items.size();
    }
    void addItem();
    void removeItem();
    void displayItems();
    void saveToFile();
    vector<Item> getItems(){return items;}
};

class Item {
  private: 
    string name;
    int quant;
    float price;
  
  public:  
    Item(string x, int y, float z){
      name = x;
      quant = y;
      price = z;
    }

    void decQuant(int amount){
      quant -= amount;
    }

    string getName(){
      return name;
    }

    int getQuant(){
      return quant;
    }

    float getPrice(){
      return price;
    }
};

void Inventory::addItem(){
  string name;
  int quant;
  float price;
  cout << "Adding Item" << "\n\n";
  cout << "Item name: ";
  cin.ignore();
  getline(cin, name);
  cout << "Item quant: ";
  cin >> quant;
  cout << "Item price (for each): ";
  cin >> price;
  Item newItem(name, quant, price);
  items.push_back(newItem);
}

void Inventory::displayItems(){
  cout << "Items" << endl << endl;
  cout << "index," <<  "name," << "quantity," << "price" << endl;
  int counter = 1;
  for (auto it = items.begin(); it != items.end(); ++it){
    cout << counter << "," << it->getName() << "," << it->getQuant() << "," << it->getPrice() << endl;
    counter++;
  }
}

void Inventory::removeItem(){
  cout << "Remove item" << endl << endl;
  int removeIndex;
  int removeQuant;
  displayItems();
  cout << "Vector length: " <<  getSize() << endl; //DB LINE
  cout << "Delete item by index" << endl;
  cout << "->: ";
  cin >> removeIndex;
  if (removeIndex < 1 || removeIndex > getSize()){
    cout << "Item not found.." << endl;
    return;
  }
  cout << "Removing Item: " << items.at(removeIndex-1).getName() << endl;
  cout << "How many would you like to remove: 0-" << items.at(removeIndex-1).getQuant() << endl;
  cout << "->: ";
  cin >> removeQuant;
  cout << "Removing " << removeQuant << " " << items.at(removeIndex-1).getName() << endl;
  if (removeQuant == items.at(removeIndex-1).getQuant()){
    items.erase(items.begin() + (removeIndex-1));
  } else {
    items.at(removeIndex-1).decQuant(removeQuant);
  }
  return;
}


void Inventory::saveToFile(){
  string filename;
  string content;
  cout << "Saving to file" << "\n\n";

  auto getSuffix = [](string filename){
    string suffix;
    for (int i = (filename.length()-1); i > (filename.length()-5); --i){
    	suffix += filename[i];
    }
    reverse(suffix.begin(), suffix.end());
    return suffix; 
  };

  do {
    cout << "Enter filename (.txt)" << endl;
    cout << "->: ";
    cin >> filename;
  } while (getSuffix(filename) != ".txt");

  if (items.empty()){
    cout << "Nothing to save" << endl;
    return;
  }

  ofstream TextFile(filename);


  for (auto it = items.begin(); it != items.end(); ++it){
    content += it->getName() + "," + to_string(it->getPrice()) + "," + to_string(it->getQuant()) + "\n";
  }

  cout << content << endl;

  TextFile << content;

  TextFile.close();
  items.clear();
  return;
}

int work_loop(){
  Inventory workinv; // DECLARING INVENTORY IN WORK LOOP
  bool running = true;
  while (running){
    int number;
    cout << endl;
    cout << "Commands:" << "\n" << "\n";
    cout << "1. Add item" << endl;
    cout << "2. Remove item" << endl;
    cout << "3. Display item" << endl;
    cout << "4. Sort items" << endl;
    cout << "5. Save to file" << endl;
    cout << "6. Load from file" << endl;
    cout << "7. Exit" << endl;
    cout << "" << endl;
    do {
      cout << "->: ";
      cin >> number;
    } while (number < 1 || number > 7);
    switch (number){
      case 1:
        workinv.addItem();
        break;
      case 2:
        workinv.removeItem();
        break;
      case 3:
        workinv.displayItems();
        break;
      case 4:
        //workinv.sortItems();
        break;
      case 5:
        workinv.saveToFile();
        break;
      case 6:
        //workinv.loadFromFile();
        break;
      case 7:
        running = false;
    }
  }
  return 0;
}

int main() {
  cout << "---- Inventory Manager ----" << endl;
  work_loop();
  return 0;
}
