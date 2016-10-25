/*Author: Jennifer Mendoza
* Description: testing program
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



void moveRoom(Rooms *arrayGrid[][3], int &x,int &y, string dir);


int main () {

	Rooms *roomGrid[3][3];
	int x=0;
	int y=0;
	string direction;
	string end;
	//keeps track of the player's current position
	Rooms *currentRoom[x][y];

	//creates array of objects
	createRoomObjects(roomGrid);

	//test program for player movement
	while(end.compare("y") != 0)
	{	
		currentRoom[x][y]=roomGrid[x][y];

		cout<<"You are in: "<<currentRoom[x][y]->getName()<<endl;
		cout<<"Which direction?"<<endl;
		cin>>direction;
		moveRoom(roomGrid, x, y, direction);
		
		cout<<"End test?"<<endl;
		cin>>end;
	}
	return 0;
}

//checks direction and if valid, updates player's current position
//set up to be a 3x3 grid
void moveRoom(Rooms *arrayGrid[][3], int &x,int &y, string dir)
{
	if ((dir.compare("n") == 0)&&(arrayGrid[x][y]->getNorth()==true))
	{
		y--;
	}
	else if ((dir.compare("s") == 0)&&(arrayGrid[x][y]->getSouth()==true))
	{
		y++;
	}
	else if ((dir.compare("e") == 0)&&(arrayGrid[x][y]->getEast()==true))
	{
		x++;
	}
	else if ((dir.compare("w") == 0)&&(arrayGrid[x][y]->getWest()==true))
	{
		x--;
	}
	else
	{
		cout<<"There is no door in that direction."<<endl;
	}

	
	
}
