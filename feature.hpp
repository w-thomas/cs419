/*Description: feature.cpp header file
* Group: Fandango
* * Last Modified: 10/30/2016
* */
#ifndef FEATURE_HPP
#define FEATURE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "item.hpp"

using namespace std;

class Feature
{
	public:
		Feature (string f1, string fdesc, string req, string haveReq);
		string name;
		string getDesc(vector<Item> &checkBackpack);
		string getFeatureName();
		
	private:
		string desc;
		string dependency;
		string reqDesc;
		
};

#endif
