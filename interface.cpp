/*
 * Interface.cpp -- ncurses based screen layout for Fandango's CMD1
 * Created by Will Thomas
 */

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

	local_win = create_newwin(LINES/2, ((COLS * 80)/100)-2, 2, 2, false);

	wbkgd(local_win, COLOR_PAIR(6));

	char * cstr = new char[message.length()+1];
	strcpy (cstr, message.c_str());
	wprintw(local_win, cstr);

	wrefresh(local_win);

	destroy_win(local_win);

	delete(cstr);
}

void printItems(std::string item) {

	char * cstr = new char[item.length()+1];
	strcpy (cstr, item.c_str());

	printw(cstr);

	delete(cstr);
}

void print_feedback(std::string feedback){
	char * cstr = new char[feedback.length()+1];
	strcpy (cstr, feedback.c_str());

	mvprintw(LINES - 5, 0, "                                                                     ");
	mvprintw(LINES - 4, 0, "                                                                     ");
	mvprintw(LINES - 4, 0, cstr);
	refresh();

	delete(cstr);
}

void clearFeedback(){
	mvprintw(LINES-4, 0, "                                                                         ");
	refresh();
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
	mvprintw(LINES - 2, 2, "Your input:                                                          ");

	mvprintw(LINES - 2, 2, "Your input: ");

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
	mvwprintw(local_win, 14, 4, "drop <item> : take item from the backback and leave it in the room");
	mvwprintw(local_win, 16, 4, "quit or q : quit the game");
	mvwprintw(local_win, 18, 4, "help or h : print this menu");
	wrefresh(local_win);


	destroy_win(local_win);
}

void titleAnimation() {
	int titlesize = 111;
	// int j = 0;

	//curs_set(0);
	curs_set(0);
	attron(COLOR_PAIR(1));
	mvprintw(LINES - 6, COLS/2 - titlesize/2, "  ___________.__              __      __       .__   __   .__                 ________                    .___ ");
	mvprintw(LINES - 5, COLS/2 - titlesize/2, "  \\__    ___/|  |__   ____   /  \\    /  \\____  |  | |  | _|__| ____    ____   \\______ \\   ____ _____    __| _/ ");
	mvprintw(LINES - 4, COLS/2 - titlesize/2, "    |    |   |  |  \\_/ __ \\  \\   \\/ /   |__  \\ |  | |  |/ /  |/    \\  / __ \\   |    |  \\_/ __  \\__  \\  / __ |  ");
	mvprintw(LINES - 3, COLS/2 - titlesize/2, "    |    |   |   Y  \\  ___/   \\        / / __ \\|  |_|    <|  |   |  \\/ /_/  >  |    `   \\  ___/ / __ \\/ /_/ |  ");
	mvprintw(LINES - 2, COLS/2 - titlesize/2, "    |____|   |___|  \\___  >    \\__/\\  / (____  /____/__|_ \\__|___|   \\___  /  /_______   \\___  >____  |____ |  ");
	mvprintw(LINES - 1, COLS/2 - titlesize/2, "                   \\/   \\/          \\/       \\/          \\/       \\ /_____/           \\/     \\/     \\/     \\/    ");
	attroff(COLOR_PAIR(1));
	scrollok(stdscr, TRUE);
	
	for(int i = 0; i < (LINES-20); i++)
	{
		scroll(stdscr);
		refresh();
		usleep(175000);
	}
	
	mvprintw(LINES - 20, COLS/2 - 11, "PRESS ANY KEY TO START");
	getch();
	curs_set(1);
	clear();
	refresh();
}








