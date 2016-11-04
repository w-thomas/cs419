/*Author: Jennifer Mendoza
* Description: function definitions
* Group: Fandango
* Last Modified: 10/26/2016
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "item.hpp"

Item::Item(std::string itemName)
{
	int pos=1;
	int line_number(1);
	int atLine=1;
	std::string line;
	std::string filename=itemName+".txt";
	std::ifstream file(filename.c_str());
	
	while (std::getline(file, line))
	{
		//saves each line in an array
		if (line_number == atLine)
		{
			std::string s=line;
			int delimiter = s.find(":");
			std::string token = s.substr (delimiter+1);
			token.erase(token.length()-1);
			if (pos==1)
			{
				name=token;
			}
			if (pos==2)
			{
				desc=token;
			}
			if (pos==3)
			{
				int w;
				std::stringstream convert(token);
				convert >> w;
				weight=w;
			}
		}
		line_number++;
		atLine++;
		pos++;
	}
	
}

std::string Item::getItemName()
{
	return name;
}
std::string Item::getItemDesc()
{
	return desc;
}
int Item::getItemWeight()
{
	return weight;
}
