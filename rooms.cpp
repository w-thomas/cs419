#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "rooms.hpp"
using namespace std;

void createRoomObjects(vector<Rooms>& roomObjects1)
{
	string line;
	string roomArr[9];
	string delimiter =":";
	//vector contains all Rooms objects
	//http://stackoverflow.com/questions/32766817/go-to-a-specific-line-in-file-and-read-it
	//read files in 1 at a time
	for (int a=1; a<3;a++)
	{	
		stringstream ss;
		ss<<a;
		string str=ss.str();
		string filename="room"+str+".txt";

		ifstream file(filename.c_str());
		unsigned int line_number(1);
			int atLine=1;
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
			//display's array contents for testing
/*			cout<<"file "<<a<<endl;
			for (int i=0; i<atLine-1;i++)
			{
				cout<<"room "<<i<<" array:"<<roomArr[i]<<endl;
			}
			cout<<"check1"<<endl;
		Insert call to constructor to create objects here. Objects are created as files are read
*/		Rooms temp(roomArr);
		roomObjects1.push_back(temp);
	}
	//retrieves object information in vector
//	cout<<roomList[1].getName()<<endl;

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

