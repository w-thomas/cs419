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

void Player::setStartLocation()
{
    currentX=0;
    currentY=0;
}

//save item object to backpack vector and delete from room vector
void Player::pickUpItem(string pickup, vector<Item> &roomItem)
{
    int vecSize;

    cout<<"Picked up "<<pickup<<endl;
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
    cout<<"Dropped "<<drop<<endl;

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

