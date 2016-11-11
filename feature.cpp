/*Author: Jennifer Mendoza
* Description: function definitions
* Group: Fandango
* Last Modified: 11/11/2016
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "feature.hpp"
#include "item.hpp"

Feature::Feature(std::string f1, std::string fdesc, std::string setisPerson, std::string interact)
{
	name=f1;
	desc=fdesc;
	setPerson(setisPerson);
	interactionDesc=interact;
}

//checks to see if the required item is in backpack
//returns either main description or unique description
std::string Feature::getDesc()
{
//	std::string featureDesc = "The feature you selected is not in the room.\n"; 
//	std::vector<Item>::iterator Iter;
//	for (Iter = checkBackpack.begin(); Iter != checkRoom.end(); ++Iter)
//	{
//		if(Iter->name.compare(dependency)==0)
//		{
//			return featureDesc;
//		}			
//	}
	return desc;
}

std::string Feature::getFeatureName()
{
	return name;
}

//sets the bool for isPerson from room text file
void Feature::setPerson(std::string setisPerson)
{
	if(setisPerson=="True")
	{
		isPerson=true;
	}
	else
	{
		isPerson=false;
		
	}
}
//a check to see if the feature is a person
int Feature::checkPerson()
{
	if (isPerson==true)
	{
		return 1;
	}
	else{
		return 0;
	}
}

//gets the special description for interacting with the feature
std::string Feature::getInteractDesc()
{
	return interactionDesc;
}

