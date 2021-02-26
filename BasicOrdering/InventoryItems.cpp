#include "InventoryItems.h"

InventoryItems::InventoryItems()
{
	std::cout << "Inventory item created" << std::endl;
}

InventoryItems::~InventoryItems()
{
	std::cout << "Inventory item destroyed" << std::endl;
}

void InventoryItems::createInventoryItem(std::string itemName, unsigned int maxQuantity, unsigned int orderThreshold,
																			  double price,  int quantityInInventory)
{
	setItemName(itemName);
	setMaxQuantity(maxQuantity);
	setOrderThreshold(orderThreshold);
	setPrice(price);
	if (quantityInInventory != 0) { setQuantityInInventory(quantityInInventory); }
}

void InventoryItems::setItemName(std::string name)
{
	if (name.length() > 0) {
		this->m_itemName = name;
	}
}

void InventoryItems::setMaxQuantity(unsigned int maxQuantity)
{
	if (maxQuantity > 0) {
		this->m_maxQuantity = maxQuantity;
	}
}

void InventoryItems::setOrderThreshold(unsigned int orderThreshold)
{
	m_orderThreshold = orderThreshold;
}

void InventoryItems::setPrice(double price)
{
	if (price >= 0) {
		m_price = price;
	}
}

void InventoryItems::setQuantityInInventory(int onHand)
{
	if (onHand >= 0) {
		this->m_quantityInInventory = onHand;
	}
}

void InventoryItems::addToInventory(unsigned int amountToAdd)
{
	m_quantityInInventory += amountToAdd;
	if (m_quantityInInventory > m_maxQuantity) { std::cout << "You are over max quantity for: " << m_itemName << std::endl; }
}

void InventoryItems::removeFromInventory(unsigned int amountToRemove)
{
	if (amountToRemove <  m_quantityInInventory) {
		m_quantityInInventory -= amountToRemove;
	}
	else {
		m_quantityInInventory = 0;
		std::cout << "Attempted to remove more items from inventory than were in inventory" << std::endl;
	}
}

bool InventoryItems::checkOrderUpdates()
{
	std::cout << m_orderThreshold << " " << m_quantityInInventory << std::endl;
	if (this->m_quantityInInventory <= this->m_orderThreshold) {
		std::cout << "I need to be ordered" << std::endl;
		return true;
	}
	return false;
}

std::string InventoryItems::getItemName()
{
	return this->m_itemName;
}

int InventoryItems::getQuantityOnHand()
{
	return this->m_quantityInInventory;
}


unsigned int InventoryItems::getMaxQuantity()
{
	return this->m_maxQuantity;
}

unsigned int InventoryItems::getOrderThreshold()
{
	return this->m_orderThreshold;
}

double InventoryItems::getPrice()
{
	return this->m_price;
}
