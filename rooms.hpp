/*Author: Jennifer Mendoza
* Description: rooms.cpp header file
* Group: Fandango
* Last Modified: 10/24/2016
*/
#ifndef ROOMS_HPP
#define ROOMS_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rooms
{
	public:
		//constructor
		Rooms(string array[9]);
		//functions to get object information
		void setName(string);
		void setLdesc(string);
		void setSdesc(string);
		void setFeature1(string);
		void setFeature2(string);
		void setNorth(string);
		void setSouth(string);
		void setEast(string);
		void setWest(string);
		string getName();
		string getLdesc();
		string getSdesc();
		string getFeature1();
		string getFeature2();
		bool getNorth();
		bool getSouth();
		bool getEast();
		bool getWest();

	private:
		string roomName;
		string Ldesc;
		string Sdesc;
		string feature1;
		string feature2;
		bool north;
		bool south;
		bool east;
		bool west;

};

void createRoomObjects(Rooms *arrayGrid[][3]);
#endif