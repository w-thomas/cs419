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

void printIntro() {
    cout << "\n\n\nWe are in the midst of a worldwide zombie apocalypse.  I have managed to survive for almost one year.  I've lost many friends and family but have also gained a new family.  I trust them all with my life and they trust me with theirs.  I will need each one of them to help me continue on and make a life for ourselves in this new world.  We have managed to take over a state prison. It has all we need for survival: strong gates, access to a well, and a large yard for raising livestock and growing crops.  We now have a new enemy.  It is not the hoards of zombies.  It is a living man.  He wants to take what is ours but we have worked too hard for too long to let him take it from us.\n\n\n";
}

int checkWord(int level, string word) {
    int result = 0;
    const string l1[] = {"look", "go"}; 
    const string l2[] = {"n", "s", "e", "w", "at"}; 
    const string l3[] = {"run", "walk"}; 
    int s1 = sizeof(l1) / sizeof(string);
    int s2 = sizeof(l2) / sizeof(string);
    int s3 = sizeof(l3) / sizeof(string);
    switch(level) {
        case 1:
            for(int i = 0; i < s1; ++i) {
                if(l1[i].compare(word) == 0) {
                    result = 1;
                }
            }
        case 2:
            for(int i = 0; i < s2; ++i) {
                if(l2[i].compare(word) == 0) {
                    result = 1;
                }
            }
        case 3:
            for(int i = 0; i < s3; ++i) {
                if(l3[i].compare(word) == 0) {
                    result = 1;
                }
            }
    }
    return result;
}

void parseCmd(string cmd) {
    int level = 1;
    //cout << cmd << endl << "Length: " << cmd.length() << endl;
    istringstream iss(cmd); 
    string word;
    while(iss >> word) {
        int result = checkWord(level, word);
        if(result == 0) {
            cout << "Invalid command: " << cmd << endl;
            break;
        }
        ++level;
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
