/*Author: Jennifer Mendoza
* Description: player.cpp header file
* Group: Fandango
* Last Modified: 11/16/2016
*/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include<vector>
#include "item.hpp"



class Player
{
	public:
		void setStartLocation();
		void setBools();
		void pickUpItem(std::string pickup, std::vector<Item> &roomItem);
		void getBackpackContents();
		int checkPack(std::string item);
		void dropItem(std::string drop, std::vector<Item> &roomItem);
		int currentX;
		int currentY;
		std::vector<Item> backpack;
		
		
		//bools for item pickup
		bool walker4;
		bool talkToMichonne;
		bool walker10;
		bool talkToHershel;
		bool healDaryl;
};

#endif
