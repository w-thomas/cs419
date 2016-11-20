/*Author: Jennifer Mendoza
* Description: rooms.cpp header file
* Group: Fandango
* Last Modified: 11/13/2016
*/
#ifndef ROOMS_HPP
#define ROOMS_HPP
#include <iostream>
#include <string>
#include <vector>
#include "item.hpp"
#include "feature.hpp"
#include "player.hpp"


class Rooms
{
	public:
		//constructor
		Rooms(std::string array[16]);
		std::string talkTo(std::string person, Player& rick);
		std::string swing(std::string sword, Player& rick);
		std::string shoot(std::string gun, Player& rick);
		std::string healDaryl(std::string daryl, Player& rick);
		
		//functions to set object information
		void setName(std::string name);
		void setLdesc(std::string longDesc);
		void setSdesc(std::string shortDesc);
		void setFeature(std::string f1, std::string fdesc, std::string req, std::string haveReq);
		void setNorth(std::string doorN);
		void setSouth(std::string doorS);
		void setEast(std::string doorE);
		void setWest(std::string doorW);
		void setItem(std::string roomItemName);
		void setrsDesc(std:: string reqDesc);
		std::vector<Feature> roomFeature;
		
		//get object information
		std::string getName();
		std::string getLdesc();
		std::string getSdesc();
		void getFeatures();
		std::string getFeatureDesc(std::string lookFeature);
        std::string getItemDesc(std::string lookItem);
		bool getNorth();
		bool getSouth();
		bool getEast();
		bool getWest();
		void getItem();
		bool gethasVisited();
		int checkFeature(std::string feature);
        int checkItems(std::string item);
		std::vector<Item> roomItem;
		bool hasVisited;
		std::string getrsDesc();
        int personCheck(std:: string person, Player& rick);


	private:
		std::string roomName;
		std::string Ldesc;		
		std::string Sdesc;
		bool north;
		bool south;
		bool east;
		bool west;
		std::string rsDesc;
		

};


void createRoomObjects(Rooms *arrayGrid[][3]);



#endif
