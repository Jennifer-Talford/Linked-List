#include "Inventory.h"
#include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <string>


// These are the functions that are specific to Inventory Data 
//and that call the Linked List for help


//read data from the created file so that it can be placed in the list
void createList(LinkedList<Inventory> list)
{
	Item item;				//structure variable
	Inventory object;		//class object
	fstream infile;
	string filename;
	cout << "what is the filename from which to read?\n";
	cin >> filename;
	//infile.open(filename, ios::in | ios::binary);
	infile.open(filename, ios::in);
	while (infile)
	{
		//infile.read(reinterpret_cast<char*>(&item), sizeof(item));
		infile >> item.itemName >> item.itemNumber >> item.numOfItems;
		//just to check that data got in
		cout << "item information\n";
		cout << item.itemName << " " << item.itemNumber << " " << item.numOfItems << endl;
		object.setItemData(item);   //set item to the class object
		list.appendNode(object);	//append object to the list
	}
	infile.close();
}
const Inventory Inventory::operator = (const Inventory & item)
{
	Data.itemName = item.Data.itemName;
	Data.itemNumber = item.Data.itemNumber;
	Data.numOfItems = item.Data.numOfItems;
	return *this;
}

bool Inventory::operator < (const Inventory & item)
{
	bool status;
	
	if (Data.itemName < item.Data.itemName)
		status = true;
	else
		status = false;
	return status;
}
bool Inventory:: operator > (const Inventory &item)
{
	bool status;

	if (Data.itemName > item.Data.itemName)
		status = true;
	else
		status = false;
	return status;
}
bool Inventory::operator == (const Inventory &item)
{
	bool status;

	if (Data.itemName == item.Data.itemName)
		status = true;
	else
		status = false;
	return status;
}
bool Inventory :: operator !=(const Inventory &item)
{
	bool status;
	if (item.Data.itemName != Data.itemName)
		status = true;
	else
		status = false;
	return status;
}

ostream& operator<<(ostream& strm, const Inventory & item)
{
	strm << item.Data.itemName << " " << item.Data.itemNumber << " " << item.Data.numOfItems << endl;
	return strm;
}
istream& operator >> (istream & strm, Inventory &item)
{
	//Prompt the user for the Data items
	cout << " Item Name: ";
	strm >> item.Data.itemName;
	cout << " Item Number: ";
	strm >> item.Data.itemNumber;
	cout << " number of items:";
	strm >> item.Data.numOfItems;
	return strm;
}
