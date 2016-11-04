/*Author: Jennifer Mendoza
* Description: item.cpp header file
* Group: Fandango
* Last Modified: 10/24/2016
*/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>


class Item
{
	public:
		Item (std::string itemName);
		std::string getItemName();
		std::string getItemDesc();
		int getItemWeight();
		std::string name;
		std::string desc;
		int weight;
};

#endif

