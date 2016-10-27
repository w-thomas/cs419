/*Author: Jennifer Mendoza
* Description: function definitions
* Group: Fandango
* Last Modified: 10/26/2016
*/
#include <iostream>
#include "player.hpp"
#include "item.hpp"
#include "rooms.hpp"
#include <algorithm>

void Player::setStartLocation()
{
	currentX=0;
	currentY=0;
}

void Player::pickUpItem(Item pickup)
{
	backpack.push_back(pickup);
	cout<<"in pickup: "<<backpack[0].getItemName()<<endl;
//	roomPickUp->roomItem.erase(std::remove(roomPickUp->roomItem.begin(), roomPickUp->roomItem.end(), 8), roomPickUp->roomItem.end());
}

void Player::getBackpackContents()
{
	if (backpack.size()!=0)
	{
		cout<<"Your backpack contains: "<<endl;
		for (size_t n=0; n<backpack.size();n++)
		{
			cout<<n+1<<": "<<backpack[n].getItemName()<<endl;
		}
	}
	else{
		cout<<"Your backpack is empty."<<endl;
	}
}
