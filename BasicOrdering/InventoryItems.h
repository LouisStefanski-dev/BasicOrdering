#pragma once
#include <string>
#include <iostream>
class InventoryItems
{
public:
	InventoryItems();
	~InventoryItems();

	void createInventoryItem(std::string itemName = "", unsigned int maxQuantity = 0, unsigned int orderThreshold = 0,
																	  double price = 0.0, int quantityInInventory = 0);
	//Set functions 
	void setItemName(std::string name);
	void setMaxQuantity(unsigned int maxQuantity);
	void setOrderThreshold(unsigned int orderThreshold);
	void setPrice(double price);
	void setQuantityInInventory(int onHand);

	//modify functions
	void addToInventory(unsigned int amountToAdd); //adds amountToAdd to current inventory value
	void removeFromInventory(unsigned int amountToRemove); //removes amountToRemove from current inventory value

	//check for update functions
	bool checkOrderUpdates(); //returns true if an item needs to be ordered according to order threshhold, false if it does not

	//get functions
	std::string getItemName();
	int getQuantityOnHand();
	unsigned int getMaxQuantity();
	unsigned int getOrderThreshold();
	double getPrice();

private:
	std::string			m_itemName;
	int					m_quantityInInventory;
	unsigned int	    m_maxQuantity;
	unsigned int		m_orderThreshold;
	double				m_price;
};

