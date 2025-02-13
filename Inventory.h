#pragma once
#ifndef  INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
using namespace std;




class Inventory;      // forward declaration

struct Item
{
	string itemName;
	int itemNumber = 0;
	int numOfItems = 0;
};


// function Prototypes for Overloaded Stream Operators
ostream& operator<<(ostream&, const Inventory&);
istream& operator >> (istream&, Inventory&);


//The Inventory class holds a structure of inventory items
//for a given company

class Inventory
{
private:
	Item Data;

public:

	//Constructors
	Inventory()
	{
		Data.itemName = "";
		Data.itemNumber = 0;
		Data.numOfItems = 0;
	};


	Inventory(struct Item i)
	{
		Data.itemName = i.itemName;
		Data.itemNumber = i.itemNumber;
		Data.numOfItems = i.numOfItems;

	};
	// Mutator function
	void setItemData(struct Item i)
	{

		Data.itemName = i.itemName;
		Data.itemNumber = i.itemNumber;
		Data.numOfItems = i.numOfItems;

	};
	int getStock(struct Item i)
	{
		return i.numOfItems;
	};
	Item getItemData() const
	{
		Data;
		return Data;
	};
	~Inventory()
	{};

	// Overloaded operator functions
	const Inventory operator = (const Inventory&);
	bool operator < (const Inventory&);
	bool operator > (const Inventory&);
	bool operator == (const Inventory&);
	bool operator != (const Inventory&);

	//friends 
	friend ostream& operator << (ostream&, const Inventory&);
	friend istream& operator >> (istream&, Inventory&);




};

#endif
