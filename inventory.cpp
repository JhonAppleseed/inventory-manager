#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
// INVENTORY MANAGER

class Item;

class Inventory {
  private:
    vector<Item> items;  
  public:  
    void addItem();
    void removeItem();
    void displayItems();
    vector<Item> getItems(){
      return items;
    }
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
  if (items.empty()){
    cout << "Items is empty.." << endl;
    return;
  }
  for (Item& item : items){
    cout << item.getName() << endl;
    cout << item.getQuant() << endl;
    cout << item.getPrice() << endl;
    cout << "" << endl;
  }
}

void Inventory::removeItem(){
  cout << "Remove item" << endl << endl;
  cout << "Items: " << endl;
  int counter = 1;
  int removeIndex;
  int removeQuant;
    cout << "name," << "quantity," << "price" << endl;
  for (auto it = items.begin(); it != items.end(); ++it){
    cout << counter << ". ";
    cout << it->getName() << "," << it->getQuant() << "," << it->getPrice() << "\n";
    counter++;
  }
  cout << "->: ";
  cin >> removeIndex;
  cout << "Removing Item: " << items.at(removeIndex -1).getName() << endl;
  if (!(1 < removeIndex || removeIndex > items.size())){
    return;
  }
  cout << "How many would you like to remove - 0-" << items.at(removeIndex-1).getQuant() << endl;
  cout << "->: ";
  cin >> removeQuant;
  cout << "Removing " << removeQuant << endl;
  // (removeIndex - 1) is item position
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
        break;
        //workinv.saveToFile();
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
