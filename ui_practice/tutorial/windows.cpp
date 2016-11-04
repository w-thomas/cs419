#include <ncurses.h>

int main(int argc, char const *argv[])
{
	WINDOW *test_win;
	int offsetx, offsety, width, height;

	initscr();
	cbreak();

	height = LINES;
	width = COLS;

	offsety = (LINES - height)/4;
	offsetx = (COLS - width)/4;

	refresh();

	test_win = newwin(height, width, 0, 0);

	box(test_win, 0, 0);

	wrefresh(test_win);

	getch();

	endwin();

	return 0;
}