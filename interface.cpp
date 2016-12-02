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
	{	
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	
	/*Initializing Colors*/
	start_color();
	init_pair (0, COLOR_WHITE, COLOR_BLACK);
	init_pair (1, COLOR_CYAN, COLOR_BLACK);
  	init_pair (2, COLOR_RED, COLOR_BLACK);
  	init_pair (3, COLOR_WHITE, COLOR_BLACK);
  	init_pair (4, COLOR_WHITE, COLOR_RED);
  	init_pair (5, COLOR_BLACK, COLOR_GREEN);
  	init_pair (6, COLOR_RED, COLOR_WHITE);

  	wbkgd(stdscr, COLOR_PAIR(0));

	refresh();
	createDialogueWin();
	createDetailsWin();
	createLastCommandwin();
	printLastGoodCommand(" ");
	//noecho();
}

void end_interface() {
	endwin();
}

void createDialogueWin(){
	WINDOW *local_win;

	// local_win = create_newwin((LINES/2)+2, (COLS * 80)/100, 1, 1, true);

	local_win = create_newwin((LINES/2)-5, COLS-2, 1, 1, true);


	wbkgd(local_win, COLOR_PAIR(4));

	wrefresh(local_win);
}

void  createDetailsWin(){
	WINDOW *local_win;

	// local_win = create_newwin((LINES/4), (COLS * 80)/100, (LINES/2)+4, 1, true);

	local_win = create_newwin((LINES/4)-3, COLS-2, (LINES/2)-3, 1, true);


	wbkgd(local_win, COLOR_PAIR(4));

	wrefresh(local_win);
}

void createLastCommandwin(){
	WINDOW *local_win;

	// local_win = create_newwin((LINES/4), (COLS * 80)/100, (LINES/2)+4, 1, true);

	local_win = create_newwin(4, COLS-2, (((LINES/2)-3) + ((LINES/4)-3)+2), 1, true);


	wbkgd(local_win, COLOR_PAIR(4));

	wrefresh(local_win);

}

void printString(std::string message) {

	WINDOW *local_win;

	// local_win = create_newwin(LINES/2, ((COLS * 80)/100)-2, 2, 2, false);

	local_win = create_newwin((LINES/2)-7, COLS-4, 2, 2, false);

	wbkgd(local_win, COLOR_PAIR(6));

	char * cstr = new char[message.length()+1];
	strcpy (cstr, message.c_str());
	wprintw(local_win, cstr);

	wrefresh(local_win);

	destroy_win(local_win);

	delete(cstr);
}

void printLastGoodCommand(std::string message){
	WINDOW *local_win;

	// local_win = create_newwin(LINES/2, ((COLS * 80)/100)-2, 2, 2, false);

	local_win = create_newwin(2, COLS-4, (((LINES/2)-3) + ((LINES/4)-3)+3), 2, false);

	wbkgd(local_win, COLOR_PAIR(6));

	char * cstr = new char[message.length()+1];
	strcpy (cstr, message.c_str());
	wprintw(local_win, "Last valid command: %s", cstr);

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

	mvprintw(LINES - 5, 2, "                                                                                                                                                      ");
	mvprintw(LINES - 4, 2, "                                                                                                                                                      ");
	mvprintw(LINES - 4, 2, cstr);
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
	attron(COLOR_PAIR(2));
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
		usleep(150000);
	}
	
	mvprintw(LINES - 20, COLS/2 - 11, "PRESS ANY KEY TO START");
	getch();
	curs_set(1);
	clear();
	refresh();
}


void fireAnimation() {
	
	int height = LINES;
	int width = COLS;
	int length = 102;

	curs_set(0);
	scrollok(stdscr, TRUE);
	
	for(int i = 10; i > 0; i--) {
		clear();
		attron(COLOR_PAIR(2));
		mvprintw(height - 10+i, width/2 - length/2, "      x    X      x              X                           X      X                                 ");
		mvprintw(height - 9+i, width/2 - length/2,  "                          x                 X               XXX                 X                     ");
		mvprintw(height - 8+i, width/2 - length/2,  " x   x       x          xX                                XXXXX    X                  X               ");
		mvprintw(height - 7+i, width/2 - length/2,  "   X                     X       X              X       XXXXXX          X              X              ");
		mvprintw(height - 6+i, width/2 - length/2,  "    X      XX     X   x  xX     X      XX       XX    XXXXXX             XX  X    X    XX     XX      ");
		mvprintw(height - 5+i, width/2 - length/2,  "   XX      XXX    XX    XXXX    XX    XXX      XXX    XXXXXX             XXX         XXX     XXX      ");
		mvprintw(height - 4+i, width/2 - length/2,  "  XXXX   XXXXXX  XXX   XXXXXX  XXXX  XXXXX   XXXXX   XXXXXXXXX  XXXXXX  XXXXX     X XXXXX   XXXX      ");
		mvprintw(height - 3+i, width/2 - length/2,  "  XXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXX XX    XXXXXXXX    XXXXXXXXX  XXXXXX    ");
		mvprintw(height - 2+i, width/2 - length/2,  " XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ");
		mvprintw(height - 1+i, width/2 - length/2,  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

		refresh();
		usleep(265000);
		clear();

		mvprintw(height - 10+i, width/2 - length/2, "          X                X                 X              X                                         ");
		mvprintw(height - 9+i, width/2 - length/2,  "X   X         X                                            XXX      X           X                     ");
		mvprintw(height - 8+i, width/2 - length/2,  "                        X                                XXXXX                          X             ");
		mvprintw(height - 7+i, width/2 - length/2,  "   X       X         X   X      X      X         X      XXXXXX            X   X    X    X     X   X   ");
		mvprintw(height - 6+i, width/2 - length/2,  "    X      XX      X     xX     X   X  XX      XXX    XXXXXX              XX           XX     XX      ");
		mvprintw(height - 5+i, width/2 - length/2,  "   XX      XXX    XX    XXXX    XX    XXX      XXX    XXXXXX     X       XXX         XXX     XXX      ");
		mvprintw(height - 4+i, width/2 - length/2,  "  XXXX   XXXXXX  XXX   XXXXXX  XXXX  XXXXX   XXXXX   XXXXXXXXX    XXXX  XXXXX     X XXXXX   XXXX      ");
		mvprintw(height - 3+i, width/2 - length/2,  "  XXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXX XX    XXXXXXXX    XXXXXXXXX  XXXXXX    ");
		mvprintw(height - 2+i, width/2 - length/2,  " XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ");
		mvprintw(height - 1+i, width/2 - length/2,  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");


		refresh();
		usleep(265000);
		clear();

		mvprintw(height - 10+i, width/2 - length/2, " x    x   X                X                 X                X                  X                    ");
		mvprintw(height - 9+i, width/2 - length/2,  "X             X                                             XXX     X                             X   ");
		mvprintw(height - 8+i, width/2 - length/2,  "                    X            X                       XXXXX                          X             ");
		mvprintw(height - 7+i, width/2 - length/2,  "   X        X             X             X         X     XXXXXX              X      X           X      ");
		mvprintw(height - 6+i, width/2 - length/2,  "    X      XX     X      xX     X      XX      XXX    XXXXXX        X      XX          XX     XX      ");
		mvprintw(height - 5+i, width/2 - length/2,  "   XX      XXX    XX    XXXX    XX    XXX      XXX    XXXXXX       XX    XXX         XXX     XXX      ");
		mvprintw(height - 4+i, width/2 - length/2,  "  XXXX   XXXXXX  XXX   XXXXXX  XXXX  XXXXX   XXXXX   XXXXXXXXX     XXX  XXXXX     X XXXXX   XXXX      ");
		mvprintw(height - 3+i, width/2 - length/2,  "  XXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXX XX  XXXXXXXXXX    XXXXXXXXX  XXXXXX    ");
		mvprintw(height - 2+i, width/2 - length/2,  " XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ");
		mvprintw(height - 1+i, width/2 - length/2,  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");


		refresh();
		usleep(265000);
	}

		for(int i = 10; i > 0; i--) {
		clear();
		attron(COLOR_PAIR(2));
		mvprintw(height - 10, width/2 - length/2, "      x    X      x              X                           X      X                                 ");
		mvprintw(height - 9, width/2 - length/2,  "                          x                 X               XXX                 X                     ");
		mvprintw(height - 8, width/2 - length/2,  " x   x       x          xX                                XXXXX    X                  X               ");
		mvprintw(height - 7, width/2 - length/2,  "   X                     X       X              X       XXXXXX          X              X              ");
		mvprintw(height - 6, width/2 - length/2,  "    X      XX     X   x  xX     X      XX       XX    XXXXXX             XX  X    X    XX     XX      ");
		mvprintw(height - 5, width/2 - length/2,  "   XX      XXX    XX    XXXX    XX    XXX      XXX    XXXXXX             XXX         XXX     XXX      ");
		mvprintw(height - 4, width/2 - length/2,  "  XXXX   XXXXXX  XXX   XXXXXX  XXXX  XXXXX   XXXXX   XXXXXXXXX  XXXXXX  XXXXX     X XXXXX   XXXX      ");
		mvprintw(height - 3, width/2 - length/2,  "  XXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXX XX    XXXXXXXX    XXXXXXXXX  XXXXXX    ");
		mvprintw(height - 2, width/2 - length/2,  " XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ");
		mvprintw(height - 1, width/2 - length/2,  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

		refresh();
		usleep(265000);
		clear();

		mvprintw(height - 10, width/2 - length/2, "          X                X                 X              X                                         ");
		mvprintw(height - 9, width/2 - length/2,  "X   X         X                                            XXX      X           X                     ");
		mvprintw(height - 8, width/2 - length/2,  "                        X                                XXXXX                          X             ");
		mvprintw(height - 7, width/2 - length/2,  "   X       X         X   X      X      X         X      XXXXXX            X   X    X    X     X   X   ");
		mvprintw(height - 6, width/2 - length/2,  "    X      XX      X     xX     X   X  XX      XXX    XXXXXX              XX           XX     XX      ");
		mvprintw(height - 5, width/2 - length/2,  "   XX      XXX    XX    XXXX    XX    XXX      XXX    XXXXXX     X       XXX         XXX     XXX      ");
		mvprintw(height - 4, width/2 - length/2,  "  XXXX   XXXXXX  XXX   XXXXXX  XXXX  XXXXX   XXXXX   XXXXXXXXX    XXXX  XXXXX     X XXXXX   XXXX      ");
		mvprintw(height - 3, width/2 - length/2,  "  XXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXX XX    XXXXXXXX    XXXXXXXXX  XXXXXX    ");
		mvprintw(height - 2, width/2 - length/2,  " XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ");
		mvprintw(height - 1, width/2 - length/2,  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");


		refresh();
		usleep(265000);
		clear();

		mvprintw(height - 10, width/2 - length/2, " x    x   X                X                 X                X                  X                    ");
		mvprintw(height - 9, width/2 - length/2,  "X             X                                             XXX     X                             X   ");
		mvprintw(height - 8, width/2 - length/2,  "                    X            X                       XXXXX                          X             ");
		mvprintw(height - 7, width/2 - length/2,  "   X        X             X             X         X     XXXXXX              X      X           X      ");
		mvprintw(height - 6, width/2 - length/2,  "    X      XX     X      xX     X      XX      XXX    XXXXXX        X      XX          XX     XX      ");
		mvprintw(height - 5, width/2 - length/2,  "   XX      XXX    XX    XXXX    XX    XXX      XXX    XXXXXX       XX    XXX         XXX     XXX      ");
		mvprintw(height - 4, width/2 - length/2,  "  XXXX   XXXXXX  XXX   XXXXXX  XXXX  XXXXX   XXXXX   XXXXXXXXX     XXX  XXXXX     X XXXXX   XXXX      ");
		mvprintw(height - 3, width/2 - length/2,  "  XXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXXXXX XXXXXXX XXXXXXXXXX XX  XXXXXXXXXX    XXXXXXXXX  XXXXXX    ");
		mvprintw(height - 2, width/2 - length/2,  " XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ");
		mvprintw(height - 1, width/2 - length/2,  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

		refresh();
		usleep(265000);
	}

	explosion();

}

void explosion() {
  char *screens[NUM_FRAMES], *p;
  int i, x, y, variation, rows, cols;
  int maxx, minx, maxy, miny, delay=1E6;
  double radius;

  //Make starting coordinates the middle of the screen.
  getmaxyx(stdscr, rows, cols);
  minx = -cols / 2;
  maxx = cols + minx - 1;
  miny = -rows / 2;
  maxy = rows + miny - 1;

    /* Generate animation frames */
  for (i = 0; i < NUM_FRAMES; i++) {
    p = screens[i] = (char*)malloc(cols * rows + 1);

    for (y = miny; y <= maxy; y++) {

      for (x = minx; x <= maxx; x++) {

        
        if (i == 0) {
          
          if (x == 0 && y == 0) {
          	*p++ = '*';
          }

          else {
          	*p++ = ' ';
          }

          continue;
        }

        //Expanding explosion for 7 frames
        if (i<8) {

          radius = sqrt(x*x + 4*y*y);

          if (radius < i*2) {

          	*p++ = '@';

          } else {

          	*p++ = ' ';
          }
          
          continue;
        }

        //Explosion
        //Credit for explosion shape calculation = Will's engineer coworker.
        //The idea is to use the cosine of the arctangent to create the angles in each quadrant
        //of the screen for the star shape.
        radius = sqrt(x*x + 4*y*y) * (0.5 + cos(16*atan2(y*2+0.01,x+0.01))*.3);
      
      	//-7 to exclude the inner area from the first 7 frames.
      	//This fills the screen with the initial "flash" you see during the first 20 frames which fill every area of screen. except the inner 
      	//Expanding explosion from the first frames.
        variation = i - radius - 7;
        if (variation < 0) { 
        	if (i < 19) {
        		*p++ = "%@W#H=+~-:."[i-8];
        	} 

        	else {
        		*p++ = ' ';
        	}
        }

        else if (variation < 20) {
        	*p++ = " .:[HIOMW#%$&@08O=+-"[variation];
        }

        else {
        	*p++ = ' ';	
        } 
      }
    }

    /* Terminate the text string for this frame */
    *p = '\0';
  }

  curs_set(0); 
  for (i=0; i<NUM_FRAMES; i++) {
  	attron(COLOR_PAIR(2));
    erase();
    mvaddstr(0,0,screens[i]);
    refresh();
    usleep(delay);
    delay=33333; 
  }
}





