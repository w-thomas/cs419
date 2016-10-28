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
#include "item.hpp"

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

	//test display items in room
	roomGrid[0][0]->getItem();

	//test pick up item
	player1.pickUpItem(roomGrid[0][0]->roomItem[0]);

	//test display backpack contents
	player1.getBackpackContents();
	
	//test program for player movement & hasVisited boolean
	while(end.compare("y") != 0)
	{	
		
		cout<<"You are in: "<<roomGrid[player1.currentX][player1.currentY]->getName()<<endl;
		if (roomGrid[player1.currentX][player1.currentY]->gethasVisited()==false)
		{
			cout<<roomGrid[player1.currentX][player1.currentY]->getLdesc()<<endl;
		}
		else
		{
			cout<<roomGrid[player1.currentX][player1.currentY]->getSdesc()<<endl;
		}
		roomGrid[player1.currentX][player1.currentY]->hasVisited=true;
		cout<<"Which direction?"<<endl;
		cin>>direction;
		moveRoom(roomGrid, player1.currentX, player1.currentY, direction);
		
		cout<<"End test?"<<endl;
		cin>>end;
	}
	return 0;
}

//checks direction and if valid, updates player's current position
//set up to be a 5x3 grid
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
