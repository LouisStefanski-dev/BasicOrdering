#include <iostream>
#include "Inventory.h"

//TODO:
//		Add MySql server functions

int main() {
	Inventory myInventory;
	myInventory.createNewInventoryItem("egg", 5, 2, 2.1, 0);
	return 0;
}