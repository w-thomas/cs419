#include <ncurses.h>
#include <stdio.h>
#include <string>
#include <string.h>

void test_function();
void test_two();
void test_three(std::string test);

int main()
{	

	test_function();

	test_two();

	test_three("this is a test");

	endwin();

	return 0;

}

void test_function(){
	initscr();
	raw();
	noecho();
	mvprintw(12,40,"read this now");
	getch();

}

void test_two(){
	refresh();
	mvprintw(20, 60, "2nd message");
	getch();
}

void test_three(std::string test) {
	refresh();
	char * cstr = new char[test.length()+1];
	strcpy (cstr, test.c_str());
	printw(cstr);
	getch();
}
