/*
 * fandango.cpp -- base engine for Fandango Group's project (CMD1)
 * Last Modified -- 10/4/2016
 * Last Modified By -- Josh Gonzalez
 * Now Bugs --
 */

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::getline;

void printIntro() {
    cout << "\n\n\nWe are in the midst of a worldwide zombie apocalypse.  I have managed to survive for almost one year.  I've lost many friends and family but have also gained a new family.  I trust them all with my life and they trust me with theirs.  I will need each one of them to help me continue on and make a life for ourselves in this new world.  We have managed to take over a state prison. It has all we need for survival: strong gates, access to a well, and a large yard for raising livestock and growing crops.  We now have a new enemy.  It is not the hoards of zombies.  It is a living man.  He wants to take what is ours but we have worked too hard for too long to let him take it from us.\n\n\n";
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
        if(cmd == "help" || cmd == "h") { printHelp(); } 
    }
    while((cmd != "q") && (cmd != "quit"));
}
