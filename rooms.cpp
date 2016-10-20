#include <iostream>
#include <string>
#include "rooms.hpp"
using namespace std;

Rooms::Rooms(string array[9])
{
	setName(array[0]);
	setLdesc(array[1]);
	setSdesc(array[2]);
	setFeature1(array[3]);
	setFeature2(array[4]);
	setNorth(array[5]);
	setSouth(array[6]);
	setEast(array[7]);
	setWest(array[8]);
}
void Rooms::setName(string name)
{
	roomName=name;
}
void Rooms::setLdesc(string longDesc)
{
	Ldesc=longDesc;
}
void Rooms::setSdesc(string shortDesc)
{
	Sdesc=shortDesc;
}
void Rooms::setFeature1(string f1)
{
	feature1=f1;
}
void Rooms::setFeature2(string f2)
{
	feature2=f2;
}
void Rooms::setNorth(string doorN)
{
	if(doorN=="True")
	{
		north=true;
		cout<<"set true"<<endl;
	}
	else
	{
		cout<<"set false"<<endl;
		north=false;
		
	}
}
void Rooms::setSouth(string doorS)
{
	if (doorS=="True")
	{
		south=true;
	}
	else
	{
		south=false;
	}
}
void Rooms::setEast(string doorE)
{
	if (doorE=="True")
	{
		east=true;
	}
	else
	{
		east=false;
	}
}
void Rooms::setWest(string doorW)
{
	if (doorW=="True")
	{
		west=true;
	}
	else
	{
		west=false;
	}
}
string Rooms::getName()
{
	return roomName;
}
string Rooms::getLdesc()
{
	return Ldesc;
}
string Rooms::getSdesc()
{
	return Sdesc;
}
string Rooms::getFeature1()
{
	return feature1;
}
string Rooms::getFeature2()
{
	return feature2;
}
bool Rooms::getNorth()
{
	return north;
}
bool Rooms::getSouth()
{
	return south;
}
bool Rooms::getWest()
{
	return west;
}
bool Rooms::getEast()
{
	return east;
}

