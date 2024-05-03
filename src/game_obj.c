// name: Darion and Ethan
// lab: AS04
// purpose: code for game objects

/**
 * @file game_obj.c 
 * @brief def on functions in '.h' file 
 * @author Ethan, Darion
 * @date December 4th 2023
 */
#include<stdio.h>
#include<curses.h>
#include<unistd.h>
#include"game_obj.h"
	
void setter2(int x, int y, char symbol, struct Char* c,int idx, int color){
  // creates symbol and color
	rect(x,y,symbol,color); 
  // sets x, y, symbol, color, active status
	c[idx].x = x;
	c[idx].y = y;     
	c[idx].symbol = symbol;
  c[idx].color = color;
  c[idx].active = 1;
}

void pre_setter(int level,struct Char* c){
  // level 1
	if(level == 1){
    //green block
		setter2(10,10,'G',c,0, 1);		
	}
  // level 2
	if(level == 2){
    // x and y coords for symbols
    int y[10] = {10,10,11,6,18,8,16,15,3};
    int x[10] = {10,22,14,2,34,18,4,12,37};
    // set green block
    setter2(x[0],y[0],'G', c ,0, 1);
    // set blue blocks
  	for(int i =1; i<9; i++){
      setter2(x[i],y[i],'B',c, i, 2);
    }
	}
  // level 3
	if(level == 3){
    // x and y coords for symbols
    int y[17] = {10,10,11,6,18,8,16,15,3,6,9,12,15,11,4,2,18};
    int x[17] = {10,22,14,2,34,18,4,12,37,11,34,19,4,31,25,14,15};
    // green block
    setter2(x[0],y[0],'G',c ,0, 1);
    // blue blocks
  	for(int i =1; i<9; i++){
      setter2(x[i],y[i],'B', c, i, 2);
      // red blocks
      for(int i =9; i<17;i++){
        setter2(x[i],y[i],'R', c , i, 3);
      }
    } 
  }
}

void createWindow(){
  // create window
  WINDOW *w;
  w = newwin(20, 40, 0, 0);
  refresh();
  // create border
  wborder(w, '|','|','-','-','+','+', '+', '+'); 
  wrefresh(w);
}

void rect(int x,int y, char symbol, int color){
  start_color();
  //1=green,2=blue,3=red
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_BLACK, COLOR_BLACK);
  // initialize inputted color
  attron(COLOR_PAIR(color));
  // create object
  mvaddch(y, x, symbol);
  // deinitialize inputted color
  attroff(COLOR_PAIR(color));
}
