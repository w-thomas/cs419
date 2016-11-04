/*Author: Jennifer Mendoza
* Description: rooms.cpp header file
* Group: Fandango
* Last Modified: 11/4/2016
*/
#ifndef ROOMS_HPP
#define ROOMS_HPP
#include <iostream>
#include <string>
#include <vector>
#include "item.hpp"
#include "feature.hpp"

using namespace std;

class Rooms
{
	public:
		//constructor
		Rooms(std::string array[16]);
		//functions to set object information
		void setName(std::string);
		void setLdesc(std::string);
		void setSdesc(std::string);
		void setFeature1(std::string, std::string, std::string, std::string);
		void setFeature2(std::string, std::string, std::string, std::string);
		void setNorth(std::string);
		void setSouth(std::string);
		void setEast(std::string);
		void setWest(std::string);
		void setItem(std::string);
		std::vector<Feature> roomFeature;
		
		//get object information
		std::string getName();
		std::string getLdesc();
		std::string getSdesc();
		void getFeatures();
		std::string getFeatureDesc(std::string lookFeature, std::vector<Item> &checkBackpack);
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


	private:
		std::string roomName;
		std::string Ldesc;		
		std::string Sdesc;
		bool north;
		bool south;
		bool east;
		bool west;




		

};


void createRoomObjects(Rooms *arrayGrid[][3]);



#endif
