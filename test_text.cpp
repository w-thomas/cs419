// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
//create Rooms class with all different components

class Rooms
{
	public:
		Rooms(string array[9])
		{
			cout<<"check2"<<endl;
			setName(array[0]);
		}
		void setName(string name)
		{
			cout<<"check3"<<endl;
			roomName=name;
		}
		string getName()
		{
			return roomName;
		}

	
	private:
		string roomName;
		string Ldesc;

};
//save contexts of txt files into arrays within rooms class
int main () {
	string line;
	string roomArr[9];
	string delimiter =":";
	vector<Rooms> roomList;
	//http://stackoverflow.com/questions/32766817/go-to-a-specific-line-in-file-and-read-it
	for (int a=1; a<3;a++)
	{	
		stringstream ss;
		ss<<a;
		string str=ss.str();
		string filename="room"+str+".txt";

		ifstream file(filename.c_str());
		unsigned int line_number(1);
			int atLine=1;
			while (std::getline(file, line))
			{
					if (line_number == atLine)
					{
						string s=line;
						int pos = s.find(":");
						string token = s.substr (pos+1);
						roomArr[atLine-1]=token;
					}      
					line_number++;
					atLine++;
			}
			cout<<"file "<<a<<endl;
			for (int i=0; i<atLine-1;i++)
			{
				cout<<"room "<<i<<" array:"<<roomArr[i]<<endl;
			}
			cout<<"check1"<<endl;
		//Insert call to constructor to create objects here. Objects are created as files are read
		Rooms temp(roomArr);
		roomList.push_back(temp);
	}
	cout<<roomList[1].getName()<<endl;
	return 0;
}