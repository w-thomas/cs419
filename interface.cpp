#include "interface.hpp"

void start_interface() {
	initscr();
	raw();

//Testing for color Capabilities
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	
	/*Initializing Colors*/
	start_color();
	init_pair (0, COLOR_WHITE, COLOR_BLACK);
	init_pair (1, COLOR_CYAN, COLOR_BLACK);
  	init_pair (2, COLOR_WHITE, COLOR_BLUE);
  	init_pair (3, COLOR_WHITE, COLOR_BLACK);
  	init_pair (4, COLOR_WHITE, COLOR_RED);
  	init_pair (5, COLOR_BLACK, COLOR_GREEN);
  	init_pair (6, COLOR_RED, COLOR_WHITE);

  	wbkgd(stdscr, COLOR_PAIR(0));

	refresh();
	createDialogueWin();
	createDetailsWin();
	//noecho();
}

void end_interface() {
	endwin();
}

void createDialogueWin(){
	WINDOW *local_win;

	local_win = create_newwin((LINES/2)+2, (COLS * 80)/100, 1, 1, true);

	wbkgd(local_win, COLOR_PAIR(4));

	wrefresh(local_win);
}

void  createDetailsWin(){
	WINDOW *local_win;

	local_win = create_newwin((LINES/4), (COLS * 80)/100, (LINES/2)+4, 1, true);

	wbkgd(local_win, COLOR_PAIR(4));

	wrefresh(local_win);
}

void printString(std::string message) {

	WINDOW *local_win;

	local_win = create_newwin(LINES/2, (COLS*78)/100, 2, 2, false);

	wbkgd(local_win, COLOR_PAIR(6));

	char * cstr = new char[message.length()+1];
	strcpy (cstr, message.c_str());
	wprintw(local_win, cstr);

	wrefresh(local_win);

	destroy_win(local_win);

	delete(cstr);
}

// void printDetails(){

// }

WINDOW *create_newwin(int height, int width, int starty, int startx, bool border) {	
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);

	if(border){
	//box(local_win, 0 , 0);
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');	
	}

	return local_win;
}

void print_feedback(std::string feedback){
	char * cstr = new char[feedback.length()+1];
	strcpy (cstr, feedback.c_str());

	mvprintw(LINES - 4, 0, "                                                                     ");
	mvprintw(LINES - 4, 0, cstr);
	refresh();
}

std::string getInput() {
	char * input = new char[80];

	//This is hacky, but it "clears" the input line of last input by writing over
	//it with empty space.
	mvprintw(LINES - 2, 0, "Your input:                                                          ");

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

	local_win = create_newwin(LINES/2, (COLS*78)/100, 2, 2, false);

	wbkgd(local_win, COLOR_PAIR(5));

	mvwprintw(local_win, 2, 30, "Help");
	mvwprintw(local_win, 4, 4, "look : verbose description of current location");
	mvwprintw(local_win, 6, 4, "look at <feature || item> : description of feature or item");
	mvwprintw(local_win, 8, 4, "show pack : show contents of player's backpack");
	mvwprintw(local_win, 10, 4, "grab <item> : grab a room item and put it in backpack");
	mvwprintw(local_win, 12, 4, "go <direction> : navigate with directions n, s, e, and w");
	mvwprintw(local_win, 14, 4, "quit or q : quit the game");
	mvwprintw(local_win, 16, 4, "help or h : print this menu");
	wrefresh(local_win);


	destroy_win(local_win);
}


