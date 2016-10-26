/*Author: Jennifer Mendoza
* Description: function definitions
* Group: Fandango
* Last Modified: 10/24/2016
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "rooms.hpp"

using namespace std;

void createRoomObjects(Rooms *arrayGrid[][3])
{
	string line;
	string roomArr[9];
	string delimiter =":";
	//vector contains all Rooms objects
	//http://stackoverflow.com/questions/32766817/go-to-a-specific-line-in-file-and-read-it
	//read files in 1 at a time
	int a=1;
	
	for (int y=0;y<3;y++)
	{
		for (int x=0;x<3;x++)
		{
			int line_number(1);
			int atLine=1;
			string str;
			ostringstream convert;
			convert << a;
			str = convert.str();
			string filename="room"+str+".txt";
			ifstream file(filename.c_str());
			
			while (std::getline(file, line))
			{
				//saves each line in an array
				if (line_number == atLine)
				{
					string s=line;
					int pos = s.find(":");
					string token = s.substr (pos+1);
					token.erase(token.length()-1);
					roomArr[atLine-1]=token;

				}
			
				line_number++;
				atLine++;
			}
			arrayGrid[x][y]= new Rooms(roomArr);
			a++;
		}
	}
}


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
	}
	else
	{
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

