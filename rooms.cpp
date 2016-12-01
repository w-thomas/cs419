/*Author: Jennifer Mendoza
 * Description: function definitions
 * Group: Fandango
 * Last Modified: 11/27/2016
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "rooms.hpp"
#include "player.hpp"
#include "item.hpp"
#include "feature.hpp"
#include "interface.hpp"



void createRoomObjects(Rooms *arrayGrid[][3])
{
    std::string line;
    std::string roomArr[17];
    std::string delimiter =":";
    //http://stackoverflow.com/questions/32766817/go-to-a-specific-line-in-file-and-read-it
    //read files in 1 at a time
    int a=1;

    for (int y=0;y<3;y++)
    {
        for (int x=0;x<5;x++)
        {
            int line_number(1);
            int atLine=1;
            std::string str;
            std::ostringstream convert;
            convert << a;
            str = convert.str();
            std::string filename="room"+str+".txt";
            std::ifstream file(filename.c_str());

            while (std::getline(file, line))
            {
                //saves each line in an array
                if (line_number == atLine)
                {
                    std::string s=line;
                    int pos = s.find(":");
                    std::string token = s.substr (pos+1);
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


Rooms::Rooms(std::string array[16])
{
    setName(array[0]);
    setLdesc(array[1]);
    setSdesc(array[2]);
    setFeature(array[3],array[4],array[5],array[6]);
    setFeature(array[7], array[8], array[9], array[10]);
    setNorth(array[11]);
    setSouth(array[12]);
    setEast(array[13]);
    setWest(array[14]);
    setItem(array[15]);
    setrsDesc(array[16]);
    hasVisited=false;

}
void Rooms::setName(std::string name)
{
    roomName=name;
}
void Rooms::setLdesc(std::string longDesc)
{
    Ldesc=longDesc;
}
void Rooms::setSdesc(std::string shortDesc)
{
    Sdesc=shortDesc;
}
void Rooms::setFeature(std::string f1, std::string fdesc, std::string req, std::string haveReq)
{
    Feature setroomFeature(f1, fdesc, req, haveReq);
    roomFeature.push_back(setroomFeature);
}

void Rooms::setNorth(std::string doorN)
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
void Rooms::setSouth(std::string doorS)
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
void Rooms::setEast(std::string doorE)
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
void Rooms::setWest(std::string doorW)
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
void Rooms::setItem(std::string roomItemName)
{
    if (roomItemName!="")
    {
        Item itemObj(roomItemName);
        roomItem.push_back(itemObj);
    }
}

void Rooms::setrsDesc(std::string reqDesc)
{
    rsDesc=reqDesc;
}

//gets information
std::string Rooms::getName()
{
    return roomName;
}
std::string Rooms::getLdesc()
{
    return Ldesc;
}
std::string Rooms::getSdesc()
{
    return Sdesc;
}

//displays room features to the user
void Rooms::getFeatures()
{
    std::vector<Feature>::iterator Iter;

    //Create ncurses window to print dialogue to:
    WINDOW *item_win;

    item_win = create_newwin(3, ((COLS * 80)/100)-2, (LINES/2)+5, 2, false);
    wbkgd(item_win, COLOR_PAIR(6));
    wprintw(item_win, "The following features are in the room: ");

    for (Iter = roomFeature.begin(); Iter != roomFeature.end(); ++Iter)
    {
        char * cstr = new char[Iter->name.length()+1];
        strcpy (cstr, Iter->name.c_str());
        // cout <<Iter->name<<endl;
        wprintw(item_win, cstr);
        wprintw(item_win, " "); 
        delete(cstr);
    }

    wrefresh(item_win);
    destroy_win(item_win);
}

//takes in the feature string and backpack. Checks to see if required item is in 
//backpack and returns appropriate feature description
//Calls class Feature function getDesc
std::string Rooms::getFeatureDesc(std::string lookFeature)
{
    std::string featureDesc; 

    std::vector<Feature>::iterator Iter;
    for (Iter = roomFeature.begin(); Iter != roomFeature.end(); ++Iter)
    {
        if(Iter->name.compare(lookFeature)==0)
        {
            featureDesc= Iter->getDesc();
        }			
    }

    return featureDesc;
}

//josh added for getting item description
std::string Rooms::getItemDesc(std::string lookItem)
{
    std::string itemDesc; 

    std::vector<Item>::iterator Iter;
    for (Iter = roomItem.begin(); Iter != roomItem.end(); ++Iter)
    {
        if(Iter->name.compare(lookItem)==0)
        {
            itemDesc= Iter->getItemDesc();
        }			
    }
    return itemDesc;
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

    //Create ncurses window to print dialogue to:
    WINDOW *item_win;

    item_win = create_newwin(3, ((COLS * 80)/100)-2, (LINES/2)+8, 2, false);
    wbkgd(item_win, COLOR_PAIR(6));

    if (roomItem.size()!=0)
    {	
        wprintw(item_win, "The following items are in the room: ");
        // cout<<"Items in this room"<<endl;
        for (size_t n=0; n<roomItem.size();n++)
        {
            char * cstr = new char[roomItem[n].getItemName().length()+1];
            strcpy (cstr, roomItem[n].getItemName().c_str());
            // cout <<Iter->name<<endl;
            wprintw(item_win, cstr);
            wprintw(item_win, " "); 
            delete(cstr);
            // cout<<n+1<<": "<<roomItem[n].getItemName()<<endl;
        }
    }
    else
    {
        wprintw(item_win, "There are no items here.");
        // cout<<"There are no items here."<<endl;
    }

    wrefresh(item_win);
    destroy_win(item_win);
}

bool Rooms::gethasVisited()
{
    return hasVisited;
}

//checks to see if item or feature user picks is valid
int Rooms::checkItems(std::string item)
{
    if (roomItem.size()!=0)
    {
        for (size_t n=0; n<roomItem.size();n++)
        {
            if(roomItem[n].getItemName().compare(item) == 0) 
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
    return 0;
}

int Rooms::checkFeature(std::string feature)
{
    for (size_t n=0; n<roomFeature.size();n++)
    {
        if(roomFeature[n].getFeatureName().compare(feature) == 0) 
        {
            return 1;
        }

    }
    return 0;
}	

//changed--now takes in player object to manipulate bool values
std::string Rooms::talkTo(std:: string person, Player& rick)
{
    std::string interactionDesc;
    //checks if the feature is in the room
    std::vector<Feature>::iterator Iter;
    for (Iter = roomFeature.begin(); Iter != roomFeature.end(); ++Iter)
    {
        if(Iter->name.compare(person)==0)
        {
            interactionDesc=Iter->getInteractDesc();
            //sets bool values to true when character is spoken to

            if (person=="Michonne")
            {
                rick.talkToMichonne=true;
            }
            else if(person=="Hershel")
            {
                rick.talkToHershel=true;
            }
        }

    }
    return interactionDesc;
}
//function to see if a feature is a person -- could be used elsewhere
int Rooms::personCheck(std:: string person, Player& rick)
{
    //checks if the feature is in the room
    int result = 0;
    std::vector<Feature>::iterator Iter;
    for (Iter = roomFeature.begin(); Iter != roomFeature.end(); ++Iter)
    {
        if(Iter->name.compare(person)==0)
        {
            //if in the room, checks to see if the person is a person
            if (Iter->checkPerson()==1)
            {
                result = 1;
            }
        }			
    }
    return result;
}
std::string Rooms::getrsDesc()
{
    return rsDesc;
}

//Needs a check to see if player is in correct room***
std::string Rooms::swing(std:: string sword, Player& rick)
{
    std::string interactionDesc="Swung sword!";
    //std::string notSword=sword+" can't be used with this action.";
    std::string notSword= "You don't have the sword.";
    std::vector<Item>::iterator Iter;

    //checks if the item is in the pack
    for (Iter = rick.backpack.begin(); Iter != rick.backpack.end(); ++Iter)
    {
        if(Iter->name.compare("sword")==0)
        {
            //if in the pack, checks to see if the item is a sword
            if (sword=="sword")
            {
                //need code here to see if player a walker is in the room
                //sets walker to true when walker has been killed
                if(rick.currentX == 3 && rick.currentY == 0 && rick.walker4==true)
				{
					interactionDesc="You have already killed the walker.";
				}
				else if(rick.currentX == 3 && rick.currentY == 0) {
                    interactionDesc = "You swing your sword and aim for the head. You slice through the walker's head! You have killed the walker."; 
                    rick.walker4=true;
                }

                return interactionDesc;
            }
        }
    }
    return notSword;
}

//Needs a check to see if player is in correct room***
std::string Rooms::shoot(std:: string gun, Player& rick)
{
    //std::string interactionDesc="Shot walker!";
    std::string interactionDesc;
    std::string notGun= "You cannot use this action here!";
    std::vector<Item>::iterator Iter;
    std::string missingItem;
    int haveGun=0;
    int haveBullets=0;

    //checks if the item is in the pack
    for (Iter = rick.backpack.begin(); Iter != rick.backpack.end(); ++Iter)
    {

        if(Iter->name.compare("gun")==0)
        {
            haveGun=1;
        }
        if(Iter->name.compare("bullets")==0)
        {
            haveBullets=1;

        }
    }
    //sets walker to true when walker has been killed
    if (haveGun==1 && haveBullets==0)
    {
        missingItem="Need bullets to shoot gun.";
        return missingItem;
    }
    else if(haveGun==0 && haveBullets==1)
    {
        missingItem="You have bullets, but you need a gun.";
        return missingItem;
    }
    else if(haveGun==0 && haveBullets==0)
    {
        missingItem="You don't have the gun or any bullets.";
        return missingItem;
    }
	else if (rick.currentX == 4 && rick.currentY == 1 && rick.walker10==true)
    {
		interactionDesc="You have shot the walkers already!";
        return interactionDesc;
    }
	else if (rick.walker10==true)
	{
		interactionDesc="You don't need this anymore.";
		return interactionDesc;
	}
    else if(rick.currentX == 4 && rick.currentY == 1) 
    {
        interactionDesc="You walk towards the walkers and aim your Colt Python .357 Magnum Revolver at a walker's head. You shoot and one by one they fall until you have 1 bullet left. You see one more walker. You shoot the last one, but missed its head. It falls to the ground and starts to crawl towards you. You walk up to it and use all your force to stomp on its head. The walkers are all dead!";
        rick.walker10=true;
        return interactionDesc;
    }
	else if (rick.walker10==false)
	{
		interactionDesc="You need to save your bullets!";
		return interactionDesc;
	}
	
    return notGun;
}


//works as 'heal'
std::string Rooms::healDaryl(std::string daryl, Player& rick)
{
    int haveMedkit=0;
    std::string interactionDesc;
    std::vector<Item>::iterator Iter;

    //search bag to see if medkit is in bag 
    for (Iter = rick.backpack.begin(); Iter != rick.backpack.end(); ++Iter)
    {
        //if player has medkit
        if(Iter->name.compare("medkit")==0)
        {
            haveMedkit=1;
            //check to see if player is in the room with Daryl
			if(rick.currentX == 3 && rick.currentY == 2 && rick.healDaryl==true)
            {
                interactionDesc = "You have already healed Daryl.";
				return interactionDesc;
            }
			else if(rick.healDaryl==true)
			{
				interactionDesc = "You don't need this anymore.";
				return interactionDesc;
			}
            else if(rick.currentX == 3 && rick.currentY == 2)
            {
                rick.healDaryl=true;
                interactionDesc="You take out the medkit and see a large bandage. You use this to apply a tourniquet on Daryl's left leg above his laceration. You wrap his leg with more bandages to stop the bleeding. After a few minutes, Daryl's blood loss has decreased. You help him up and head back towards the door to cell block C. Hershel is there and takes Daryl from you. You saved Daryl.";
                return interactionDesc;
            }
			else
			{
				interactionDesc = "You need to save your medical supplies.";
				return interactionDesc;
			}
        }
    }
		
    if (haveMedkit==0)
    {
        interactionDesc="You do not have the medkit in your pack.";
        return interactionDesc;
    }

    return interactionDesc;
}

std::string Rooms::pourGas(std:: string gas, Player& rick)
{
    std::string interactionDesc;
    std::string notGas= "You don't have the gas.";
    std::vector<Item>::iterator Iter;

    //checks if the item is in the pack
    for (Iter = rick.backpack.begin(); Iter != rick.backpack.end(); ++Iter)
    {
        if(Iter->name.compare("gas")==0)
        {
			
			if(rick.currentX == 4 && rick.currentY == 0 && rick.pouredGas==true)
			{
				interactionDesc="You have already poured the gas.";
				return interactionDesc;
			}
			else if (rick.pouredGas==true)
			{
				interactionDesc = "You don't need this anymore";
				return interactionDesc;
			}
			//sets poured gas bool to true when gas is poured in the correct room
			else if(rick.currentX == 4 && rick.currentY == 0) 
			{
				interactionDesc = "You open the container and walk around the car. You pour all 5 gallons on it!"; 
				rick.pouredGas=true;
				return interactionDesc;
			}
			else if(rick.pouredGas==false)
			{
				interactionDesc="You need to save the gas.";
				return interactionDesc;
			}
			
        }
    }
    return notGas;
}


std::string Rooms::lightMatch(std:: string matches, Player& rick)
{
    std::string interactionDesc;
    std::string notMatches= "The matches are not in your pack.";
    std::vector<Item>::iterator Iter;

	//checks if the item is in the pack
	for (Iter = rick.backpack.begin(); Iter != rick.backpack.end(); ++Iter)
	{
		if(Iter->name.compare("matches")==0)
		{
			//checks to see if the gas was poured before lighting match
			if (rick.pouredGas==true && rick.currentX == 4 && rick.currentY == 0)
			{

                scr_dump("virtual.dump");
                clear();
                refresh();

                fireAnimation();


                scr_restore("virtual.dump");
                doupdate();

				interactionDesc = "You take out a match and light it. You throw the lit match on the car. The fire spread fast and you run back inside the gate! After a few minutes, you see a large explosion! It's working! The walkers are heading towards the car! One by one, the walkers fall into the ditch. You'll need to clean that up, but that'll be for another day.\n \n Congratulations!!! You have completed The Walking Dead Game! You have saved your community from the walkers that were still left at the prison. The prison is now a safe place for everyone! You are now free to roam around the prison as you wish!";
                
				return interactionDesc;
			}
			//gas has not yet been poured in the correct room
			else if (rick.pouredGas==false && rick.currentX == 4 && rick.currentY == 0){
				interactionDesc="You need to pour gas first.";
				return interactionDesc;
			}
			else if(rick.pouredGas==true)
			{
				interactionDesc="You don't need this anymore.";
				return interactionDesc;
			}
			else
			{
				interactionDesc = "You need to save your matches!";
				return interactionDesc;
			}
		}
	}
	//user does not have the matches in their pack
    return notMatches;
}

