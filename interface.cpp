#include "interface.hpp"

void start_interface() {
	initscr();
	raw();
	//noecho();
}

void end_interface() {
	endwin();
}

void printString(std::string message) {
	char * cstr = new char[message.length()+1];
	strcpy (cstr, message.c_str());
	printw(cstr);
	//getch();

	delete(cstr);
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 			* for the vertical and horizontal
					 			* lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

std::string getInput(){
	char * input = new char[80];

	mvprintw(LINES - 2, 0, "Your input: ");

	getstr(input);

	std::string inString(input);

	delete(input);

	return inString;

}


