#pragma once

#include <vector>
#include <iostream>

#include "InventoryItems.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void createNewInventoryItem(std::string itemName = "", unsigned int maxQuantity = 0, unsigned int orderThreshold = 0,
																		 double price = 0.0, int quantityInInventory = 0);
	void deleteInventoryItem(int posInVector);
	InventoryItems* getItem(int posInVector);
private:
	std::vector<InventoryItems*> m_inventory; //NOTE: does not use a smart pointer, instead the pointer is deleted from the heap in the deleteInventoryItem function
											  //      if deleteInventoryItem is not called at the end of the inventory objects life cycle the inventory objects deconstructor will
											  //      loop through all elements in m_inventory and call deleteInventoryItem for each item
};

