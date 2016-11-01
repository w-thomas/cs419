/*Author: Jennifer Mendoza
* Description: rooms.cpp header file
* Group: Fandango
* Last Modified: 10/30/2016
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
		Rooms(string array[16]);
		//functions to set object information
		void setName(string);
		void setLdesc(string);
		void setSdesc(string);
		void setFeature1(string, string, string, string);
		void setFeature2(string, string, string, string);
		void setNorth(string);
		void setSouth(string);
		void setEast(string);
		void setWest(string);
		void setItem(string);
		vector<Feature> roomFeature;
		
		//get object information
		string getName();
		string getLdesc();
		string getSdesc();
		void getFeatures();
		string getFeatureDesc(string lookFeature, vector<Item> &checkBackpack);
		bool getNorth();
		bool getSouth();
		bool getEast();
		bool getWest();
		void getItem();
		bool gethasVisited();
		int checkFeature(string feature);
        int checkItems(string item);
		vector<Item> roomItem;
		bool hasVisited;


	private:
		string roomName;
		string Ldesc;		
		string Sdesc;
		bool north;
		bool south;
		bool east;
		bool west;




		

};


void createRoomObjects(Rooms *arrayGrid[][3]);



#endif
