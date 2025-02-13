#include "Inventory.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

int main ()
{
	bool looper = false;
	int size = 10;
	int partcount = 0;
	string choice;
	LinkedList<Inventory> list;

	Inventory tempInventory;
	struct Item temp;
	string tempitemName = "";
	string objectname = "";
	int objectunitnumber;
	int objectnumber;
	int tempitemNumber = 0;
	int tempnumOfItems = 0;

	while (looper == false)
	{

		//Write a menu driven inventory maintenance program using a linked list.Each node of the list should contain three data fields:
		//the item name, the item number and the number of units in stock. Initially the list should be empty.
		//A menu should be developed which allows the programmer to perform the following operations :

		//Lets user enter choice from menu
		cout << "Please select one of the following options, by typing in its corresponding letter, to continue: " << endl;
		cout << "R - Read an existing data(see above) and put it in the list." << endl;
		cout << "I - Insert a new item in the list – user must enter item name, item number and number of units." << endl;
		cout << "U - update the number of units of a given item." << endl;
		cout << "D - Delete an existing item – user must enter an item number only to do this." << endl;
		cout << "P - Print all of the items in stock and the number of units of each." << endl;
		cout << "W - Write a new list back to the file." << endl;
		cout << "Q - quit" << endl;
		cin >> choice;

		//Checking user selection
		//This allows user to add amount from item selected

		//Read an existing data(see above) and put it in the list
		if (choice == "R" && "r")
		{
			string linerec;
			ifstream fileread("Inventory.txt");
			// ! at beginning means NOT. So file is looped through until it is NOT at end of file (EOF)
			while (!fileread.eof())      //if not at end of file, continue reading numbers
			{
				getline(fileread, linerec);
				for (int index = 0; index < linerec.size(); index++)
				{
					for (int numOfSpaces = 0; numOfSpaces < 3; numOfSpaces++)
					{
						if (linerec != " " && numOfSpaces == 0)
						{
							tempitemName += linerec[index];
						}
						else if (linerec != " " && numOfSpaces == 1)
						{
							tempitemNumber += linerec[index];
						}
						else if (linerec != " " && numOfSpaces == 2)
						{
							tempnumOfItems += linerec[index];
						}
					}
					temp.itemName = tempitemName;
					temp.itemNumber = tempitemNumber;
					temp.numOfItems = tempnumOfItems;

					tempInventory.setItemData(temp);
					list.appendNode(tempInventory);
				}
			}
		}
		//Insert a new item in the list – user must enter item name, item number and number of units
		if (choice == "I" && "i")
		{
			cout << "Please type in item name: ";
			cin >> tempitemName;
			cout << endl << "Please enter item number: ";
			cin >> tempitemNumber;
			cout << endl << "Please enter how many items there are: ";
			cin >> tempnumOfItems;

			temp.itemName = tempitemName;
			temp.itemNumber = tempitemNumber;
			temp.numOfItems = tempnumOfItems;

			tempInventory.setItemData(temp);
			list.appendNode(tempInventory);

			looper = false;
		}
		//update the number of units of a given item
		if (choice == "U" && "u")
		{
			cout << "Please type out name of item you wish to alter the value of: ";
			list.displayList();
			cin >> objectname;

			if (tempitemName == objectname);
				{
				list.findNode(tempInventory);
				cout << endl << "Please enter how many total items you wish to add: ";
				cin >> objectunitnumber;
				tempnumOfItems + objectunitnumber;

				temp.itemNumber = tempnumOfItems;
				tempInventory.setItemData(temp);
				list.appendNode(tempInventory);
				}
			if (tempitemName != objectname)
			{
				cout << "Invalid entry. Please enter valid item name.";
			}
			looper = false;
		}
		//Delete an existing item – user must enter an item number only to do this
		if (choice == "D" && "d")
		{
			cout << "Please enter item number: ";
			cin >> objectnumber;


			if (tempitemNumber == objectnumber);
			{
				temp.itemNumber = tempitemNumber;
				tempInventory.setItemData(temp);
				list.deleteNode(tempInventory);
			}
			if (tempitemNumber != objectnumber)
			{
				cout << "Invalid entry. Please enter valid item number.";
			}
			looper = false;
		}
		//Print all of the items in stock and the number of units of each
		if (choice == "P" && "p")
		{
			cout << "The following is a list of all the items, their item number, and number of units of each: " << endl;
			list.displayList();
			
			looper = false;
		}
		//Write a new list back to the file
		if (choice == "W" && "w")
		{
			cout << "Please type in item name: ";
			cin >> tempitemName;
			cout << endl << "Please enter item number: ";
			cin >> tempitemNumber;
			cout << endl << "Please enter how many items there are: ";
			cin >> tempnumOfItems;

			temp.itemName = tempitemName;
			temp.itemNumber = tempitemNumber;
			temp.numOfItems = tempnumOfItems;

			tempInventory.setItemData(temp);
			list.insertNode(tempInventory);
			looper = false;
		}
		//Exits out of program per user choice
		if (choice == "Q" && "q")
		{
			cout << "Thank you for using the program.";
			looper = true;
		}
		else
		{
			cout << "Invalid response. Please enter valid option. ";
			looper = false;
		}
	}
	return 0;
}



