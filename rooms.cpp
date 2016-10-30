/*Author: Jennifer Mendoza
* Description: function definitions
* Group: Fandango
* Last Modified: 10/26/2016
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "rooms.hpp"
#include "item.hpp"

using namespace std;

void createRoomObjects(Rooms *arrayGrid[][3])
{
	string line;
	string roomArr[10];
	string delimiter =":";
	//vector contains all Rooms objects
	//http://stackoverflow.com/questions/32766817/go-to-a-specific-line-in-file-and-read-it
	//read files in 1 at a time
	int a=1;
	
	for (int y=0;y<3;y++)
	{
		for (int x=0;x<5;x++)
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


Rooms::Rooms(string array[10])
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
	setItem(array[9]);
	hasVisited=false;

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
void Rooms::setItem(string roomItemName)
{
	if (roomItemName!="")
	{
		Item itemObj(roomItemName);
		roomItem.push_back(itemObj);
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
void Rooms::getItem()
{
	if (roomItem.size()!=0)
	{
		cout<<"Items in this room"<<endl;
		for (size_t n=0; n<roomItem.size();n++)
		{
			cout<<n+1<<": "<<roomItem[n].getItemName()<<endl;
		}
	}
	else
	{
		cout<<"There are no items here."<<endl;
	}
}
bool Rooms::gethasVisited()
{
	return hasVisited;
}

int Rooms::checkItems(string item)
{
	if (roomItem.size()!=0)
	{
		for (size_t n=0; n<roomItem.size();n++)
		{
            if(roomItem[n].getItemName().compare(item) == 0) {
                return 1;
            }
		}
	}
	else
	{
		return 0;;
	}
    return 0;
}

