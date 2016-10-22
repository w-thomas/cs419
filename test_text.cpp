// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "rooms.hpp"
using namespace std;



//save contexts of txt files into arrays within rooms class
int main () {
	vector<Rooms> roomList;
	createRoomObjects(roomList);
	cout<<roomList[0].getName()<<endl;
	cout<<"done"<<endl;
	return 0;
}