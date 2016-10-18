//Rooms header file
#ifndef ROOMS_H
#define ROOMS_H
#include <iostream>
#include <string>

using namespace std;

class Rooms
{
	public:
		//constructor
		Rooms(string array[9]);
		//functions to get object information
		void setName(string name);
		string getName();

	private:
		string roomName;
		string Ldesc;

};

#endif