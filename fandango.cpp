/*
 * fandango.cpp -- base engine for Fandango Group's project (CMD1)
 * Last Modified -- 10/26/2016
 * Last Modified By -- Josh Gonzalez
 * Known Issues  --
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "rooms.hpp"
#include "player.hpp"
#include "interface.hpp"

#define MAX_X 3
#define MAX_Y 3

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::istringstream;
using std::vector;

int checkItems(Rooms *arrayGrid[][MAX_Y], Player *player, string item) {
    int result = arrayGrid[player->currentX][player->currentY]->checkItems(item);
    return result;
}

//checks direction and if valid, updates player's current position
void moveRoom(Rooms *arrayGrid[][MAX_Y], Player *player, int &x,int &y, string dir)
{
    if ((dir.compare("n") == 0)&&(arrayGrid[x][y]->getNorth()==true))
    {
        y--;
    }
    else if ((dir.compare("s") == 0)&&(arrayGrid[x][y]->getSouth()==true))
    {
        y++;
    }
    else if ((dir.compare("e") == 0)&&(arrayGrid[x][y]->getEast()==true))
    {
        x++;
    }
    else if ((dir.compare("w") == 0)&&(arrayGrid[x][y]->getWest()==true))
    {
        x--;
    }
    else
    {
        cout<<"There is no door in that direction."<<endl;
        return;
    }
    //if !(arrayGrid[player->currentX][player->currentY]->getVisited()) {need code for printing long desc if player has not already been in that room } 
    //cout << arrayGrid[player->currentX][player->currentY]->getSdesc() << endl;
    printString(arrayGrid[player->currentX][player->currentY]->getSdesc());

    cout << "The following features are in the room: " << endl;
    if(arrayGrid[player->currentX][player->currentY]->getFeature1().compare("") != 0) {
        cout << arrayGrid[player->currentX][player->currentY]->getFeature1() << endl;
    }
    if(arrayGrid[player->currentX][player->currentY]->getFeature2().compare("") != 0) {
        cout << arrayGrid[player->currentX][player->currentY]->getFeature2() << endl;
    }
    //print items in the room
    cout << "The following items are in the room: " << endl;
    arrayGrid[player->currentX][player->currentY]->getItem();
}

void printIntro() {
    printString("We are in the midst of a worldwide zombie apocalypse.  I have managed to survive for almost one year.  I've lost many friends and family but have also gained a new family.  I trust them all with my life and they trust me with theirs.  I will need each one of them to help me continue on and make a life for ourselves in this new world.  We have managed to take over a state prison. It has all we need for survival: strong gates, access to a well, and a large yard for raising livestock and growing crops.  We now have a new enemy.  It is not the hoards of zombies.  It is a living man.  He wants to take what is ours but we have worked too hard for too long to let him take it from us.");
}

void executeCmd(Rooms *arrayGrid[MAX_X][MAX_Y], Player *player, string cmd) {
    //strip first word for dynamic commands
    istringstream iss(cmd);
    string word;
    iss >> word;
    //cout << word;

    //static commands
    if(cmd.compare("go n") == 0) {
        moveRoom(arrayGrid, player, player->currentX, player->currentY, "n");
    }
    else if(cmd.compare("go s") == 0) {
        moveRoom(arrayGrid, player, player->currentX, player->currentY, "s");
    }
    else if(cmd.compare("go e") == 0) {
        moveRoom(arrayGrid, player, player->currentX, player->currentY, "e");
    }
    else if(cmd.compare("go w") == 0) {
        moveRoom(arrayGrid, player, player->currentX, player->currentY, "w");
    }
    else if(cmd.compare("look") == 0) {
        printString(arrayGrid[player->currentX][player->currentY]->getSdesc());
    }
    else if(cmd.compare("show pack") == 0) {
        player->getBackpackContents();
    }
    else if(word.compare("grab") == 0) {
        //get next word
        iss >> word;
        cout << word <<  endl;
    }
    else {
        cout << "command not found in command library!!" << endl; //should never get here
        return;
    }
    /*
     * should I hard code all commands, set up an array to iterate, or re-use some of the parse code maybe?
     */
}

int checkWord(Rooms *arrayGrid[MAX_X][MAX_Y], Player *player, int level, string word, string parentWord) {
    int result = 0;
    int i;
    int j;
    const string l1[] = {"look", "go", "show", "grab"}; 
    const string l10[] = {"at"}; 
    const string l11[] = {"n", "s", "e", "w"}; 
    const string l12[] = {"pack"}; 
    const string l20[] = {"me", "you"}; 
    const string l21[] = {"run", "walk"}; 
    int s1 = sizeof(l1) / sizeof(string);
    int s10 = sizeof(l10) / sizeof(string);
    int s11 = sizeof(l11) / sizeof(string);
    int s12 = sizeof(l12) / sizeof(string);
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
                        result = 1;
                    }
                }
            }
            if(parentWord.compare("show") == 0) {
                for(i = 0; i < s12; ++i) {
                    if(l12[i].compare(word) == 0) {
                        result = 1;
                    }
                }
            }
            if(parentWord.compare("grab") == 0) {
                result = checkItems(arrayGrid, player, word);
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

int parseCmd(Rooms *arrayGrid[MAX_X][MAX_Y], Player *player, string cmd) {
    int level = 1;
    //check if this is an allowed single word command
    bool singleOK  = true;
    if(cmd.compare("go") == 0) {
        singleOK = false;
    }
    istringstream iss(cmd); 
    string word;
    string parentWord ;
    while(iss >> word) {
        int result = checkWord(arrayGrid, player, level, word, parentWord);
        if(result == 0) {
            print_feedback("Invalid command: " + cmd);
            return 0;
        }
        ++level;
        parentWord = word;
    }
    //single word command was not allowed
    if(level != 1 && singleOK == false) {
        print_feedback("Invalid command: " + cmd);
        return 0;
    }
    return 1; 
}

int main(int argc, char** argv) {
    //instantiate game state
    Rooms *board[MAX_X][MAX_Y]; //create a playing surface
    createRoomObjects(board);   //setup the board
    Player *rick = new Player();//put a player on the board
    rick->setStartLocation();   //maybe we should call a constructor for this

    start_interface();

    //start game
    printIntro();
    int result;                 //return value of parse (is entire cmd valid?)
    string cmd; 
    do {
        cmd = getInput();
        if(cmd == "quit" || cmd == "q") { continue; }
        if(cmd == "help" || cmd == "h") { printHelp(); } 
        else {
            result = parseCmd(board, rick, cmd);
            if(result == 1) { executeCmd(board, rick, cmd); }
        }
    }
    while((cmd != "q") && (cmd != "quit"));

    end_interface();

    return 0;
}
