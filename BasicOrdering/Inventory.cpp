#include "Inventory.h"

Inventory::Inventory()
{
	std::cout << "Inventory created" << std::endl;
}

Inventory::~Inventory()
{
	for (int i = 0; i < m_inventory.size(); i++) {
		deleteInventoryItem(i);
	}
	std::cout << "Inventory destroyed" << std::endl;
}

void Inventory::createNewInventoryItem(std::string itemName, unsigned int maxQuantity, unsigned int orderThreshold,
																			 double price, int quantityInInventory)
{
	InventoryItems* newItem = new InventoryItems;
	newItem->createInventoryItem(itemName, maxQuantity, orderThreshold, price, quantityInInventory);
	m_inventory.emplace_back(newItem);
}

void Inventory::deleteInventoryItem(int posInVector)
{
	delete m_inventory.at(posInVector);
	m_inventory.erase(m_inventory.begin() + posInVector);
}

InventoryItems* Inventory::getItem(int posInVector)
{
	return m_inventory.at(posInVector);
}
