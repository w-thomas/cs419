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
#include "player.hpp"

using namespace std;



void moveRoom(Rooms *arrayGrid[][3], int &x,int &y, string dir);


int main () {

	Rooms *roomGrid[5][3];
	Player player1;
	string direction;
	string end;
	//keeps track of the player's current position
	player1.setStartLocation();

	//creates array of objects
	createRoomObjects(roomGrid);

	//test program for player movement
	while(end.compare("y") != 0)
	{	
		
		cout<<"You are in: "<<roomGrid[player1.currentX][player1.currentY]->getName()<<endl;
		cout<<"Which direction?"<<endl;
		cin>>direction;
		moveRoom(roomGrid, player1.currentX, player1.currentY, direction);
		
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
