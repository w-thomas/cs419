#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <ncurses.h>
#include <stdio.h>
#include <string>
#include <string.h>


void start_interface();
void end_interface();

void printString(std::string message);

WINDOW *create_newwin(int height, int width, int starty, int startx);

std::string getInput();

#endif