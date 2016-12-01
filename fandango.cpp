/*
 * fandango.cpp -- base engine for Fandango Group's project (CMD1)
 * Last Modified -- 11/11/2016
 * Last Modified By -- Jen Mendoza - changed line 132 
 * Known Issues  --
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "rooms.hpp"
#include "player.hpp"
#include "interface.hpp"

#define MAX_X 5
#define MAX_Y 3

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::istringstream;
using std::vector;

int checkRoomItems(Rooms *arrayGrid[][MAX_Y], Player *player, string item) {
    int result = arrayGrid[player->currentX][player->currentY]->checkItems(item);
    return result;
}

int checkPlayerPack(Player *player, string item) {
    int result = player->checkPack(item);
    return result;
}

//checks direction and if valid, updates player's current position
void moveRoom(Rooms *arrayGrid[][MAX_Y], Player *player, int &x,int &y, string dir)
{
    if ((dir.compare("n") == 0)&&(arrayGrid[x][y]->getNorth()==true))
    {
        //constraint -- entering room 5 from south -- must have killed the walkers
        if(player->currentX == 4 &&  player->currentY == 1) {
            if(!(player->walker10)) {
                print_feedback("There are too many walkers in front of the gate.  You need to shoot them in the head...don't miss.  There aren't a lot of bullets.");
                return;
            }
        }
        y--;
    }
    else if ((dir.compare("s") == 0)&&(arrayGrid[x][y]->getSouth()==true))
    {
        //constraint -- entering room 13 from south -- must have keys or already unlocked the cell
        if(player->currentX == 2 &&  player->currentY == 1 && (!(arrayGrid[player->currentX][player->currentY+1]->hasVisited))) {
            int result = player->checkPack("keys");
            if(result == 0) {
                print_feedback("This cell is locked. You need the keys.");
                return;
            }
        }
        //constraint -- entering room 9 from north -- must have flashlight or lamp must be in 9
        if(player->currentX == 3 &&  player->currentY == 0) {
            int light0 = player->checkPack("flashlight");
            int light1 = player->checkPack("lantern");
            int light2 = arrayGrid[player->currentX][player->currentY+1]->checkItems("lantern");
            if(light0 == 0 && light1 == 0 && light2 == 0) {
                print_feedback("It's too dark. You need light to enter the hallway.");
                return;
            }
        }
        y++;
    }
    else if ((dir.compare("e") == 0)&&(arrayGrid[x][y]->getEast()==true))
    {
        //constraint -- entering room 9 from west -- must have flashlight or lamp must be in 9
        if(player->currentX == 2 &&  player->currentY == 1) {
            int light0 = player->checkPack("flashlight");
            int light1 = player->checkPack("lantern");
            int light2 = arrayGrid[player->currentX+1][player->currentY]->checkItems("lantern");
            //if(result == 0) {
            if(light0 == 0 && light1 == 0 && light2 == 0) {
                print_feedback("It's too dark. You need light to continue down the hallway.");
                return;
            }
        }
        //constraint -- entering room 15 from west -- must heal Daryl
        if(player->currentX == 3 &&  player->currentY == 2) {
            if(!(player->healDaryl)) {
                print_feedback("Daryl's not gonna make it.  We can't leave him here.  He's needs first aid.");
                return;
            }
        }
        x++;
    }
    else if ((dir.compare("w") == 0)&&(arrayGrid[x][y]->getWest()==true))
    {
        x--;
    }
    else
    {
        print_feedback("There is no door in that direction.");
        return;
    }
    //if hasVisited give short description else give long and set hasVisited true
    if(arrayGrid[player->currentX][player->currentY]->gethasVisited()) {
        printString(arrayGrid[player->currentX][player->currentY]->getSdesc());
    } 
    else {
        //set hasVisited to true and print long form desc
        arrayGrid[player->currentX][player->currentY]->hasVisited = true;
        printString(arrayGrid[player->currentX][player->currentY]->getLdesc());
    }

    //print features in the room
    //I'm moving this message to inside the getFeatures function - Will T.
    //cout << "The following features are in the room: " << endl;
    arrayGrid[player->currentX][player->currentY]->getFeatures();

    //print items in the room
    arrayGrid[player->currentX][player->currentY]->getItem();
}

void printIntro() {
    printString("I am Rick Grimes. When the world was still normal, I was a father, husband, and deputy for the King County Sheriff's department. The world has been turned upside down. We are in the midst of a worldwide zombie apocalypse. The people who die now become zombies. Our group calls them walkers. They can only be stopped with a major injury to the skull. The apocalypse started 14 long months ago. I've lost many friends and family but have also gained a new family. I trust them all with my life and they trust me with theirs - I've become their leader. We need each other to make a life for ourselves in this new world. We have had some good fortune too. We found and took over a state prison off of State Route 178. It has all we need for survival: strong gates both inside and outside, access to a well, and a large yard for raising livestock and growing crops. It was a difficult task but we cleared the walkers from most of the prison. We still find them inside the prison from time to time but that is becoming more rare as the days go by. My group is starting to feel safe again but I know we can't get complacent. We are forever one moment away from it all falling apart. The biggest challenge is maintaining the outside perimeter chain link fencing. The walkers are attracked to us and they form large hoards. These hoards lean against the fence. We clear the fence constantly but there are just so many of them. If they breach the outer perimeter, all of our work clearing the perimeter will have been wasted. More of us will die and we will need to clear the prison again or leave quickly and find somewhere else. We must protect this prison. It is our best chance for survival.");
}

//takes the game board instance, player instance, and valid (parsed) command
//executes dynamic commands using class functions, static commands hard-coded using local functions
//library of commmands are static in some cases and dynamic in others
void executeCmd(Rooms *arrayGrid[MAX_X][MAX_Y], Player *player, string cmd) {

    //strip first word for dynamic commands
    istringstream iss(cmd);
    string word;
    iss >> word;

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
        printString(arrayGrid[player->currentX][player->currentY]->getLdesc());
    }
    else if(cmd.compare("show pack") == 0) {
        player->getBackpackContents();
    }
    else if(cmd.compare("swing sword") == 0) {
        printString(arrayGrid[player->currentX][player->currentY]->swing("sword", (*player)));
    }
    else if(cmd.compare("shoot gun") == 0) {
        printString(arrayGrid[player->currentX][player->currentY]->shoot("gun", (*player)));
    }
    else if(cmd.compare("heal") == 0) {
        printString(arrayGrid[player->currentX][player->currentY]->healDaryl("Daryl", (*player)));
    }
    else if(cmd.compare("pour gas") == 0) {
        printString(arrayGrid[player->currentX][player->currentY]->pourGas("gas", (*player)));
    }
    else if(cmd.compare("light matches") == 0) {

        printString(arrayGrid[player->currentX][player->currentY]->lightMatch("matches", (*player)));
    }

    //dynamic commands
    else if(word.compare("grab") == 0) {
        //get next word
        iss >> word;
        player->pickUpItem(word, arrayGrid[player->currentX][player->currentY]->roomItem); 
    }
    else if(word.compare("talk") == 0) {
        //get next word
        iss >> word; //word is now "to"
        iss >> word; //word is now a character's name
        printString(arrayGrid[player->currentX][player->currentY]->talkTo(word, (*player))); 
    }
    else if(word.compare("drop") == 0) {
        //get next word
        iss >> word;
        player->dropItem(word, arrayGrid[player->currentX][player->currentY]->roomItem); 
    }
    else if(word.compare("look") == 0) {
        //get next word
        iss >> word;
        if(word.compare("at") == 0) {
            //get next word
            iss >> word;
            //check to see if it is a feature or item
            int result;
            result = arrayGrid[player->currentX][player->currentY]->checkFeature(word);
            if(result) {
                string str = arrayGrid[player->currentX][player->currentY]->getFeatureDesc(word);
                print_feedback(str);
            }
            else {
                //is an item not a feature
                //string str = "is an item not a feature";
                string str = arrayGrid[player->currentX][player->currentY]->getItemDesc(word);
                print_feedback(str);
            }
        }
    }
    else {
        print_feedback("debug: command not found in command library, parsed but not executed!!");
        return;
    }
}

//takes the game board instance, player instance, level in the command tree, current word and parent word
//checks arrays for each level and acceptable parents to those words 
//checks class object vectors to see if items, features are in the room or possesion of the player
//returns int to parseCmd().  Returns 0 if word at level is allowed, else returns 1
//prints message to user if items, features are not in the room or in possesion of the player
int checkWord(Rooms *arrayGrid[MAX_X][MAX_Y], Player *player, int level, string word, string parentWord) {
    int result = 0;
    string str;
    int i;
    const string l1[] = {"look", "go", "show", "talk", "swing", "shoot", "pour", "light", "grab", "drop", "heal"}; 
    const string l10[] = {"at"}; 
    const string l11[] = {"n", "s", "e", "w"}; 
    const string l12[] = {"pack"}; 
    const string l13[] = {"to"}; 
    const string l14[] = {"sword"}; 
    const string l15[] = {"gun"}; 
    const string l16[] = {"gas"}; 
    const string l17[] = {"matches"}; 
    int s1 = sizeof(l1) / sizeof(string);
    int s10 = sizeof(l10) / sizeof(string);
    int s11 = sizeof(l11) / sizeof(string);
    int s12 = sizeof(l12) / sizeof(string);
    int s13 = sizeof(l13) / sizeof(string);
    int s14 = sizeof(l14) / sizeof(string);
    int s15 = sizeof(l15) / sizeof(string);
    int s16 = sizeof(l16) / sizeof(string);
    int s17 = sizeof(l17) / sizeof(string);
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
                result = checkRoomItems(arrayGrid, player, word);
                if(result != 1) {
                    str = word;
                    str = str + " is not in the room";
                    //cout << str;
                    printString(str);
                }
            }
            if(parentWord.compare("drop") == 0) {
                result = checkPlayerPack(player, word);
                if(result != 1) {
                    print_feedback(word + " is not in the backpack...");
                }
            }
            if(parentWord.compare("talk") == 0) {
                for(i = 0; i < s13; ++i) {
                    if(l13[i].compare(word) == 0) {
                        result = 1;
                    }
                }
            }
            if(parentWord.compare("swing") == 0) {
                for(i = 0; i < s14; ++i) {
                    if(l14[i].compare(word) == 0) {
                        result = 1;
                    }
                }
            }
            if(parentWord.compare("shoot") == 0) {
                for(i = 0; i < s15; ++i) {
                    if(l15[i].compare(word) == 0) {
                        result = 1;
                    }
                }
            }
            if(parentWord.compare("pour") == 0) {
                for(i = 0; i < s16; ++i) {
                    if(l16[i].compare(word) == 0) {
                        result = 1;
                    }
                }
            }
            if(parentWord.compare("light") == 0) {
                for(i = 0; i < s17; ++i) {
                    if(l17[i].compare(word) == 0) {
                        result = 1;
                    }
                }
            }
            break;
        case 3:
            if(parentWord.compare("at") == 0) {
                result = arrayGrid[player->currentX][player->currentY]->checkFeature(word);
                if(result == 1) { break; }
                result = arrayGrid[player->currentX][player->currentY]->checkItems(word);
                if(result == 1) { break; }
                else { result = 0; }
            }
            if(parentWord.compare("to") == 0) {
                    result = arrayGrid[player->currentX][player->currentY]->personCheck(word, (*player));
                    if(result == 1) { break; }
                    else { result = 0; }
                }
            break;
    }
    return result;
}

//takes the game board instance, player instance, and command string from user
//strips off words and sends them to checkWord
//returns int to main().  Returns 0 if any word fails checkWord, else returns 1
//prints to console a message if the command is invalid
//continues until the entire command string has been parsed or a word is invalid
int parseCmd(Rooms *arrayGrid[MAX_X][MAX_Y], Player *player, string cmd) {
    int level = 1;
    //check if this is an allowed single word command
    bool singleOK  = false;
    if((cmd.compare("look") == 0) || (cmd.compare("heal") == 0)) {
        singleOK = true;
        return 1;
    }
    istringstream iss(cmd); 
    istringstream orig(cmd); 
    string word;
    string next;
    orig >> next; //get ahead of word by one word
    string parentWord ;
    while(iss >> word) {
        orig >> next;
        int result = checkWord(arrayGrid, player, level, word, parentWord);
        if(result == 0) {
            print_feedback("Invalid command: " + cmd);
            return 0;
        }
        //validate there is a word following "talk to" and "look at"
        if((next.compare("to") == 0) || (next.compare("at") == 0)) {
            if(!(orig >> next))
            {
                print_feedback("Invalid command: " + cmd);
                return 0;
            }
        }
        ++level;
        parentWord = word;
    }
    //single word command was not allowed
    if(level == 2 && singleOK == false) {
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

    scr_dump("virtual.dump");
    clear();
    refresh();

    titleAnimation();


    scr_restore("virtual.dump");
    doupdate();



    //start game
    printIntro();
    print_feedback("Press any key to continue.");
    noecho();
    getch();
    echo();
    clearFeedback();
    //print out long from desc of starting room
    printString(board[rick->currentX][rick->currentY]->getLdesc());

    //print features in the starting room
    //cout << "The following features are in the room: " << endl;
    board[rick->currentX][rick->currentY]->getFeatures();
    //print items in the starting room
    board[rick->currentX][rick->currentY]->getItem();
    //set starting room to hasVisited
    board[rick->currentX][rick->currentY]->hasVisited = true;
    int result;                 //return value of parse (is entire cmd valid?)
    string cmd;                 //entire command that the user supplies 




    do {
        cmd = getInput();


        print_feedback("                                                                                                                                                   ");
        if(cmd == "quit" || cmd == "q") { continue; }
        if(cmd == "help" || cmd == "h") { printHelp(); } 
        else {
            result = parseCmd(board, rick, cmd);
            if(result == 1) { 
                //keep the last good command and print this somewhere for user navigation
                string lastCmd = cmd;
                //debug: print_feedback(cmd);
                executeCmd(board, rick, cmd); 
            }
        }
    }
    while((cmd != "q") && (cmd != "quit"));

    end_interface();

    return 0;
}


