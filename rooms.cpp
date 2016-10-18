#include <iostream>
#include <string>
#include "rooms.h"
using namespace std;

Rooms::Rooms(string array[9])
{
	cout<<"check2"<<endl;
	setName(array[0]);
}
void Rooms::setName(string name)
{
	cout<<"check3"<<endl;
	roomName=name;
}
string Rooms::getName()
{
	return roomName;
}

