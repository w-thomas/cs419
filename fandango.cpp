/*
 * fandango.cpp -- base engine for Fandango Group's project (CMD1)
 * Last Modified -- 10/12/2016
 * Last Modified By -- Josh Gonzalez
 * Now Bugs --
 */

#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::istringstream;

class Location
{
    private:
        string name;
        string ldecr;
        string sdesr;
        bool n, s, e, w;

    public: 
        //getters
        void printName();
        void printLdescr();
        void printSdescr();
        void printIsDir(string direction);
};

void printIntro() {
    cout << "\n\n\nWe are in the midst of a worldwide zombie apocalypse.  I have managed to survive for almost one year.  I've lost many friends and family but have also gained a new family.  I trust them all with my life and they trust me with theirs.  I will need each one of them to help me continue on and make a life for ourselves in this new world.  We have managed to take over a state prison. It has all we need for survival: strong gates, access to a well, and a large yard for raising livestock and growing crops.  We now have a new enemy.  It is not the hoards of zombies.  It is a living man.  He wants to take what is ours but we have worked too hard for too long to let him take it from us.\n\n\n";
}

int checkWord(int level, string word, string parentWord) {
    int result = 0;
    const string l1[] = {"look", "go"}; 
    const string l2Look[] = {"at"}; 
    const string l2Go[] = {"n", "s", "e", "w"}; 
    const string l3Go[] = {"run", "walk"}; 
    int s1 = sizeof(l1) / sizeof(string);
    int s2Look = sizeof(l2Look) / sizeof(string);
    int s2Go = sizeof(l2Go) / sizeof(string);
    int s3Go = sizeof(l3Go) / sizeof(string);
    switch(level) {
        case 1:
            for(int i = 0; i < s1; ++i) {
                if(l1[i].compare(word) == 0) {
                    result = 1;
                }
            }
            break;
        case 2:
            if(parentWord.compare("look") == 0)
            {
            for(int i = 0; i < s2Look; ++i) {
                if(l2Look[i].compare(word) == 0) { return 1; }
                    }
            }
            else if(parentWord.compare("go") == 0) {
            for(int i = 0; i < s2Go; ++i) {
                if(l2Go[i].compare(word) == 0) { return 1; }
                    }
            }
            break;
        case 3:
            cout << "Level 3" << endl;
    }
    return result;
}

void parseCmd(string cmd) {
    int level = 1;
    istringstream iss(cmd); 
    string word;
    string parentWord ;
    while(iss >> word) {
        //debug 
        //cout << "Level: " << level << endl;
        //cout << "Calling check word on word: " << word << endl;
        //cout << "Passing parent word: " << parentWord << endl;
        int result = checkWord(level, word, parentWord);
        if(result == 0) {
            cout << "Invalid command: " << cmd << endl;
            break;
        }
        ++level;
        parentWord = word;
    }
    return;
}

void printHelp() {
    cout << "\n" << "Help\n\n";
    cout << "look : blah, blah, blah\n";
    cout << "look at <feature || object> : blah, blah, blah\n";
    cout << "go <direction> : blah, blah, blah\n";
    cout << "quit or q : blah, blah, blah\n";
    cout << "help or h : blah, blah, blah\n\n";
}

int main(int argc, char** argv) {
    printIntro();
    string cmd; 
    do {
        cout << "> ";
        getline(cin, cmd);
        if(cmd == "quit" || cmd == "q") { continue; }
        if(cmd == "help" || cmd == "h") { printHelp(); } 
        else {
            parseCmd(cmd);
        }
    }
    while((cmd != "q") && (cmd != "quit"));
}
