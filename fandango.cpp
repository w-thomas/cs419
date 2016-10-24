/*
 * fandango.cpp -- base engine for Fandango Group's project (CMD1)
 * Last Modified -- 10/12/2016
 * Last Modified By -- Josh Gonzalez
 * Now Bugs --
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "rooms.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::istringstream;
using std::vector;

void printIntro() {
    cout << "\n\n\nWe are in the midst of a worldwide zombie apocalypse.  I have managed to survive for almost one year.  I've lost many friends and family but have also gained a new family.  I trust them all with my life and they trust me with theirs.  I will need each one of them to help me continue on and make a life for ourselves in this new world.  We have managed to take over a state prison. It has all we need for survival: strong gates, access to a well, and a large yard for raising livestock and growing crops.  We now have a new enemy.  It is not the hoards of zombies.  It is a living man.  He wants to take what is ours but we have worked too hard for too long to let him take it from us.\n\n\n";
}

int checkDir(string direction) {
    int pos = 0;
    /*
    if(direction.compare("n") == 0) { pos = 5; }
    else if(direction.compare("s") == 0) { pos = 6; }
    else if(direction.compare("e") == 0) { pos = 7; }
    else if(direction.compare("w") == 0) { pos = 8; }

    if(r[pos].compare("True") == 0) {
        return 1;
    }
    cout << "There is no door to the " << direction << endl;
    return 0;
    */
    return 1;
}

void executeCmd(string cmd) {
    cout << "calling executeCmd()" << endl;
}

int checkWord(int level, string word, string parentWord) {
    int result = 0;
    int i;
    int j;
    const string l1[] = {"look", "go"}; 
    const string l10[] = {"at"}; 
    const string l11[] = {"n", "s", "e", "w"}; 
    const string l20[] = {"me", "you"}; 
    const string l21[] = {"run", "walk"}; 
    int s1 = sizeof(l1) / sizeof(string);
    int s10 = sizeof(l10) / sizeof(string);
    int s11 = sizeof(l11) / sizeof(string);
    int s20 = sizeof(l20) / sizeof(string);
    int s21 = sizeof(l21) / sizeof(string);
    switch(level) {
        case 1:
            for(i = 0; i < s1; ++i) {
                if(l1[i].compare(word) == 0) {
                    result = 1;
                }
            }
            break;
        case 2:
            if(parentWord.compare("look") == 0) {
                for(i = 0; i < s10; ++i) {
                    if(l10[i].compare(word) == 0) {
                        result = 1;
                    }
                }
            }
            if(parentWord.compare("go") == 0) {
                for(i = 0; i < s11; ++i) {
                    if(l11[i].compare(word) == 0) {
                        result = checkDir(word);
                    }
                }
            }
            break;
        case 3:
            for(i = 0; i < s10; ++i) {
                if(l10[i].compare(parentWord) == 0) {
                    for(j = 0; j < s20; ++j) {
                        if(l20[j].compare(word) == 0) {
                            result = 1;
                            break;
                        }
                    }
                }
            }
            for(i = 0; i < s11; ++i) {
                if(l11[i].compare(parentWord) == 0) {
                    for(j = 0; j < s21; ++j) {
                        if(l21[j].compare(word) == 0) {
                            result = 1;
                            break;
                        }
                    }
                }
            }
            break;
    }
    return result;
}

int parseCmd(string cmd) {
    int level = 1;
    //check if this is a single word command
    bool singleOK  = true;
    if(cmd.compare("go") == 0) {
        singleOK = false;
    }
    istringstream iss(cmd); 
    string word;
    string parentWord ;
    while(iss >> word) {
        int result = checkWord(level, word, parentWord);
        if(result == 0) {
            cout << "Invalid command: " << cmd << endl;
            return 0;
        }
        ++level;
        parentWord = word;
    }
    //check to see if it single command
    if(level != 1 && singleOK == false) {
        cout << "Invalid command: " << cmd << endl;
        return 0;
    }
    return 1; 
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
    //instantiate 
    vector<Rooms> r;
    createRoomObjects(r);
    //test start
    vector<Rooms>:: iterator i;
    for(i = r.begin(); i != r.end(); ++i) {
        cout << (*i).getName() << endl;
        cout << (*i).getNorth() << endl;
        cout << (*i).getSouth() << endl;
        cout << (*i).getEast() << endl;
        cout << (*i).getWest() << endl;
        cout << (*i).getLdesc() << endl;
    }
    cout << r[0].getName() << endl;
    cout << r[1].getName() << endl;
    cout << r[1].getSouth() << endl;
    //test end
    int result;
    //printIntro();
    string cmd; 
    /*
    do {
        cout << "> ";
        getline(cin, cmd);
        if(cmd == "quit" || cmd == "q") { continue; }
        if(cmd == "help" || cmd == "h") { printHelp(); } 
        else {
            result = parseCmd(cmd);
            if(result == 1) { executeCmd(cmd); }
        }
    }
    while((cmd != "q") && (cmd != "quit"));
    */
}
