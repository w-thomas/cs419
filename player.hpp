/*Author: Jennifer Mendoza
* Description: player.cpp header file
* Group: Fandango
* Last Modified: 10/26/2016
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include<vector>
#include "item.hpp"
#include "rooms.hpp"

using namespace std;

class Player
{
	public:
		void setStartLocation();
		void pickUpItem(string pickup, vector<Item> &roomItem);
		void getBackpackContents();
		void dropItem(string drop, vector<Item> &roomItem);
		int currentX;
		int currentY;
		vector<Item> backpack;
};

#endif
