//name: Darion and Ethan
//lab: AS04
//purpose: splash screen code

/**
* @file splash.c                                      *
* @brief def on functions in '.h' file                *
* @author Ethan, Darion                               *
* @date December 4th, 2023                            *
*/

#include<stdio.h>
#include<curses.h>
#include<unistd.h>
#include"splash.h"
#include"levels.h"
#include"game_obj.h"

void splash(){
  initscr();
  // display title with ascii characters
  printw(" _____       _____  _____  _____\n"); 
  printw("|     | ___ | __  ||  |  ||   | |\n");
  printw("|  |  ||___||    -||  |  || | | |\n");
  printw("|_____|     |__|__||_____||_|___|\n");
  // display and format instructions
  printw("\n\n\nYou are 'o'!\n\n\n");
  printw("RULES:\n");
  printw("1. Use the arrows to move\n2. Get to the green 'G\n");
  printw("3. Collect the blue B's\n4. Avoid the red R's\n");
  printw("\n\nPress any character to continue\n");
  //get character to continue
  getch();
}

