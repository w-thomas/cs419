// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//create Rooms class with all different components

class Rooms
{
	string roomName;
	string Ldesc;

};
//save contexts of txt files into arrays within rooms class
int main () {
string line;
string rooms[15];
string delimiter =":";
//http://stackoverflow.com/questions/32766817/go-to-a-specific-line-in-file-and-read-it
      ifstream file("room1.txt");

        unsigned int line_number(1);
        const unsigned int requested_line_number(2);
        while (std::getline(file, line))
        {
                if (line_number == requested_line_number)
                {
					string s=line;
					int pos = s.find(":");
					string token = s.substr (pos+1);
					rooms[1]=token;
				}
                line_number++;
        }
		cout<<"room[1] array:"<<rooms[1]<<endl;
  return 0;
}