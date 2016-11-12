/*Author: Jennifer Mendoza
* Description: player.cpp header file
* Group: Fandango
* Last Modified: 11/4/2016
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include<vector>
#include "item.hpp"
#include "rooms.hpp"


class Player
{
	public:
		void setStartLocation();
		void pickUpItem(std::string pickup, std::vector<Item> &roomItem);
		void getBackpackContents();
		int checkPack(std::string item);
		void dropItem(std::string drop, std::vector<Item> &roomItem);
		int currentX;
		int currentY;
		std::vector<Item> backpack;
};

#endif
