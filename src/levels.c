// name: Darion and Ethan
// lab: AS04
// purpose: contains code for levels

/**
* @file levels.c                                      *
* @brief def on functions in '.h' file                *
* @author Ethan, Darion                               *
* @date December 4th, 2023                                *
*/

#include<stdlib.h>
#include <curses.h>
#include <stdio.h>
#include <unistd.h>
#include "levels.h"
#include "game_obj.h"
#include "movement.h"

void display_level(int i) {
  // call levels and create associated windows, start init of keystroke
  // level 1
  if (i == 1) {
    createWindow();
    keystroke(1);
  }
  // level 2
  if (i == 2) {
    createWindow();
    keystroke(2);
  }
  // level 3
  if (i == 3) {
    createWindow();
    keystroke(3);
  }
  // if i = 4, game has been won
  if (i == 4){
    win();
  }
}

void win(){
  int ch;
  // display win message out of bounds
  move(21, 14);
  printw("You WIN!");
  move(22, 14);
  printw("Press 'W' to exit");
  // check for char, if W then exit
  while(1){
    ch= getch();
    if(ch == 'W'){
      endwin();
      clear();
      exit(1);
    }
  }
}

void lose(int reason){
  int ch;
  // display lose message out of bounds
  move(21, 14);
  printw("You LOSE");
  move(22, 7);
  // check reason for loss
  if(reason == 0){
    printw("Failed to collect blue blocks!");
  }
  else{
    printw("You hit a red block!");
  }
  // print message out of bounds
  move(23, 14);
  printw("Press 'L' to exit");
  // loop for char, if L then exit
  while(1){
    ch= getch();
    if(ch == 'L'){
      endwin();
      clear();
      exit(1);
    }
  }
}
