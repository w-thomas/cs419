/*Author: Jennifer Mendoza
 * Description: function definitions
 * Group: Fandango
 * Last Modified: 11/16/2016
 */
#include <iostream>
#include "player.hpp"
#include "item.hpp"
#include <algorithm>
#include <vector>
#include "interface.hpp"
#include "rooms.hpp"

void Player::setStartLocation()
{
    currentX=0;
    currentY=0;
	setBools();
}

//save item object to backpack vector and delete from room vector
void Player::pickUpItem(std::string pickup, std::vector<Item> &roomItem)
{
    int vecSize;
	bool canPickUp=true;
	//limits the size of backpack to 3 items
	if (backpack.size()!=3)
	{
		//player cannot pick up keys if walker is still alive
		if(pickup=="keys")
		{
			if (walker4==false)
			{
				canPickUp=false;
			}
		}
		//player cannot pickup medkit if hershel was not talked to
		else if(pickup=="medkit")
		{
			if (talkToHershel==false)
			{
				canPickUp=false;
			}
		}
		//player cannot pickup sword if michonne was not talked to
		else if(pickup=="sword")
		{
			if (talkToMichonne==false)
			{
				canPickUp=false;
			}
		}
		//if conditions are met, player can pick up item
		if (canPickUp==true)
		{
			print_feedback("Picked up " + pickup);
			vecSize=roomItem.size();

			for (int i=0;i<vecSize;i++)
			{
				if (roomItem[i].getItemName()==pickup)
				{
					backpack.push_back(roomItem[i]);
					std::swap(roomItem[i],roomItem.back());
					roomItem.pop_back();
					break;
				}
			}	
		}
		else
		{
			print_feedback("Cannot pick up " + pickup);
		}
	}
	//player cannot pick up a 4th item
	else
	{
		print_feedback("Your backpack is full. Cannot grab "+pickup +".");
	}
}

//save item object to room vector and delete from backpack vector
void Player::dropItem(std::string drop, std::vector<Item> &roomItem)
{
    int vecSize;

    vecSize=backpack.size();
    print_feedback("Dropped " + drop);

    for (int i=0;i<vecSize;i++)
    {
        if (backpack[i].getItemName()==drop)
        {
            roomItem.push_back(backpack[i]);
            std::swap(backpack[i],backpack.back());
            backpack.pop_back();
            break;
        }
    }	
}

void Player::getBackpackContents()
{
    if (backpack.size()!=0)
    {
    	//Hacky but gets around text not going away. Temp fix for now
    	print_feedback("                                                                      ");

    	mvprintw(LINES-5, 0, "Your backpack contains:");
    	//Move cursor to output position
    	move(LINES-4, 0);

        for (size_t n=0; n<backpack.size();n++)
        {
        	printItems("[");
        	printItems(backpack[n].getItemName());
        	printItems("] ");
        }
        	refresh();
    }
    else{
    	print_feedback("Your backpack is empty");
    }

}

int Player::checkPack(std::string item)
{
    if(backpack.size()!=0)
    {
        for (size_t n=0; n<backpack.size();n++)
        {
            if(backpack[n].getItemName().compare(item) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

//set initial boolean values to false for mini missions
void Player::setBools()
{
	walker4=false;
	talkToMichonne=false;
	walker10=false;
	talkToHershel=false;
	healDaryl=false;
}



