/*Author: Jennifer Mendoza
* Description: item.cpp header file
* Group: Fandango
* Last Modified: 10/24/2016
*/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>

using namespace std;

class Item
{
	public:
		Item (string itemName);
		string getItemName();
		string getItemDesc();
		int getItemWeight();
		string name;
		string desc;
		int weight;
};

#endif

