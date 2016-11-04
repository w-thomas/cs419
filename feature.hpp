/*Description: feature.cpp header file
* Group: Fandango
* * Last Modified: 11/4/2016
* */
#ifndef FEATURE_HPP
#define FEATURE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "item.hpp"



class Feature
{
	public:
		Feature (std::string f1, std::string fdesc, std::string req, std::string haveReq);
		std::string name;
		std::string getDesc(std::vector<Item> &checkBackpack);
		std::string getFeatureName();
		
	private:
		std::string desc;
		std::string dependency;
		std::string reqDesc;
		
};

#endif
