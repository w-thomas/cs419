#include "interface.hpp"

void start_interface() {
	initscr();
	raw();
	refresh();
	createDialogueWin();
	//noecho();
}

void end_interface() {
	endwin();
}

void createDialogueWin(){
	WINDOW *local_win;

	local_win = create_newwin((LINES/2)+2, 70, 1, 1, true);

	wrefresh(local_win);
}

void printString(std::string message) {

	WINDOW *local_win;

	local_win = create_newwin(LINES/2, 68, 2, 2, false);

	char * cstr = new char[message.length()+1];
	strcpy (cstr, message.c_str());
	wprintw(local_win, cstr);
	//getch();
	wrefresh(local_win);

	destroy_win(local_win);

	delete(cstr);
}

WINDOW *create_newwin(int height, int width, int starty, int startx, bool border) {	
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);

	if(border){
	//box(local_win, 0 , 0);
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');	
	}

	return local_win;
}

std::string getInput() {
	char * input = new char[80];

	//This is hacky, but it "clears" the input line of last input by writing over
	//it with empty space.
	mvprintw(LINES - 2, 0, "Your input:                                                       ");

	mvprintw(LINES - 2, 0, "Your input: ");

	getstr(input);

	std::string inString(input);

	delete(input);

	return inString;
}

void destroy_win(WINDOW *local_win) {	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	
	//wrefresh(local_win);
	delwin(local_win);
}

void printDescLong(){
	//TODO:
	//Print room desc object
}

void printHelp() {
	//TODO:
	//convert and print help text
	WINDOW *local_win;

	local_win = create_newwin(LINES/2, 68, 2, 2, false);
	mvwprintw(local_win, 2, 30, "Help");
	mvwprintw(local_win, 4, 4, "Look: blah blah blah");
	mvwprintw(local_win, 6, 4, "Look at <featur || object>: blah blah blah");
	wrefresh(local_win);
	   //  cout << "\n" << "Help\n\n";
    // cout << "look : blah, blah, blah\n";
    // cout << "look at <feature || object> : blah, blah, blah\n";
    // cout << "go <direction> : blah, blah, blah\n";
    // cout << "quit or q : blah, blah, blah\n";
    // cout << "help or h : blah, blah, blah\n\n";
	destroy_win(local_win);
}


