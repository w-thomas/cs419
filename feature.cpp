/*Author: Jennifer Mendoza
* Description: function definitions
* Group: Fandango
* Last Modified: 11/4/2016
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "feature.hpp"
#include "item.hpp"

Feature::Feature(std::string f1, std::string fdesc, std::string req, std::string haveReq)
{
	name=f1;
	desc=fdesc;
	dependency=req;
	reqDesc=haveReq;
}

//checks to see if the required item is in backpack
//returns either main description or unique description
std::string Feature::getDesc(std::vector<Item> &checkBackpack)
{
	std::vector<Item>::iterator Iter;
	for (Iter = checkBackpack.begin(); Iter != checkBackpack.end(); ++Iter)
	{
		if(Iter->name.compare(dependency)==0)
		{
			return reqDesc;
		}			
	}
	return desc;
}

std::string Feature::getFeatureName()
{
	return name;
}

