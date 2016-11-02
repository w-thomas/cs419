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
#include <vector>
#include "interface.hpp"

void Player::setStartLocation()
{
    currentX=0;
    currentY=0;
}

//save item object to backpack vector and delete from room vector
void Player::pickUpItem(string pickup, vector<Item> &roomItem)
{
    int vecSize;

    print_feedback("Picked up " + pickup);
    vecSize=roomItem.size();

    for (int i=0;i<vecSize;i++)
    {
        if (roomItem[i].getItemName()==pickup)
        {
            backpack.push_back(roomItem[i]);
            swap(roomItem[i],roomItem.back());
            roomItem.pop_back();
            break;
        }
    }	
}

//save item object to room vector and delete from backpack vector
void Player::dropItem(string drop, vector<Item> &roomItem)
{
    int vecSize;

    vecSize=backpack.size();
    print_feedback("Dropped " + drop);

    for (int i=0;i<vecSize;i++)
    {
        if (backpack[i].getItemName()==drop)
        {
            roomItem.push_back(backpack[i]);
            swap(backpack[i],backpack.back());
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

int Player::checkPack(string item)
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

