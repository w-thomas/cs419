/*Description: feature.cpp header file
* Group: Fandango
* * Last Modified: 11/11/2016
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
		Feature (std::string f1, std::string fdesc, std::string isPerson, std::string interact);
		std::string name;
		std::string getDesc();
		std::string getFeatureName();
		void setPerson(std::string setisPerson);
		int checkPerson();
		std::string getInteractDesc();
		
	private:
		std::string desc;
		std::string dependency;
		std::string interactionDesc;
		bool isPerson;
		
};


#endif
