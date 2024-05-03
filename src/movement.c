//name: Darion and Ethan
//lab: AS04
//purpose: handles movement and character interaction,
//         as well as pause and quit screens.

/**
* @file movement.c                                    *
* @brief def on functions in '.h' file                *
* @author Ethan, Darion                               *
* @date December 4th, 2023                            *
*/

#include<stdio.h>
#include<curses.h>
#include<unistd.h>
#include<stdlib.h>
#include"movement.h"
#include"splash.h"
#include"game_obj.h"
#include"levels.h"
#include"npc.h"

Player addPlayer(int x, int y){
  // use Player struct to init player
  Player p;
  p.x = x;
  p.y = y;
  mvaddch(p.y, p.x, 'o');
  refresh();
  return p;
}

Player movePlayer(Player p, int inc_x, int inc_y,void* b,int memb, int *blocks_h) {
  // init Char struct
  struct Char* c;
  c =(struct Char*)b;
  // check o is within borders
  if (bordercheck(p,inc_x,inc_y)==1){
    // check if o is interacting with game_obj
	  block_checker(p,c,inc_x,inc_y,memb, blocks_h);
  // check for removed blocks that are active, redraws erased active blocks
	for(int i=0;i<memb;i++){
		if((c[i].flag ==1)&&(c[i].active ==1)){
			rect(c[i].x,c[i].y,c[i].symbol,c[i].color);
			refresh();
		}
	}
    // clear old position with space
    mvaddch(p.y, p.x, ' ');  
    p.x += inc_x;
    p.y += inc_y;
    // add new o in new position
    mvaddch(p.y, p.x, 'o');   
  }
  return p;
}
int block_hit(int nowx ,int nowy,char symbol){
	char ch;
	while(1){
    // blue object interaction
		if(symbol=='B'){
			move(25,20);
      // instruction message displayed to screen
			printw("double click 'u' to pick up");
			ch = getch();
			move(25,20);
      // clear instruction
			printw("                             ");
      // blue block is picked up
		  if(ch == 'u'){
			  return(1);
		  }
      // blue block is not picked up
		  else if (ch != 'u'){
			  return(0);
		  }
	  }
    // advancing to the next level through green
		else if(symbol =='G'){
			move(25,20);
      // display instructions
			printw("double click 'n' to move to next level");
			ch = getch();
			move(25,20);
      // clear instructions
			printw("                                        ");
      // next level
			if(ch == 'n'){
				return(1);
			}
      // object ignored
			else if (ch != 'n'){
				return(0); 
			}
		}
    // red object hit
		else if(symbol =='R'){
			move(25,20);
      // print instruction
			printw("single click 'j' to skip over block");
			ch = getch();
			move(25,20);
      // clear instruction
			printw("                                        ");
      // skip red object
			if(ch == 'j'){
				return(0);
			}
      // red block is hit and game ends
			else if (ch != 'j'){
				return(1);
			}
		}
	}	
}

void block_checker(Player p, void*b, int inc_x,int inc_y,int memb, int *blocks_h){
  // init red_block to 0 for levels 1 and 2
  int red_count = 0;
  // init Char struct
	struct Char* c;
	c = (struct Char *)b;
  // if on level 3, init red_count to 8 to account for uncollectable blocks
  if(memb == 17){
    red_count = 8;
  }
  // loop through interaction possibilities
	for(int i=0;i<memb;i++){
    // check to see if block is active
		if(c[i].active==1){
      // if interaction of any kind occurs, increment hit block value
			if(((p.y+inc_y) == c[i].y)&&((p.x+inc_x) == c[i].x)){
        // check for collision and no keyboard action
				if(block_hit((p.x+inc_x),(p.y+inc_y),c[i].symbol)==0){
          // char flaged to be re-displayed to screen
					c[i].flag = 1; 
					move(30,30);
				}
				else if(block_hit((p.x+inc_x),(p.y+inc_y),c[i].symbol)==1){
					move(30,30);
					(*blocks_h)++;
          // if R is hit, lose game
        	if(c[i].symbol == 'R'){
            lose(1);
        	}
          // if G is hit premature to collecting all blue, lose game
        	else if((c[i].symbol == 'G') && (*blocks_h != (memb-red_count))){
          	lose(0);
        	}
          // else, set active status to 0
        	c[i].active = 0;
				}
      }
	  }
  }
}

int bordercheck(Player p, int inc_x, int inc_y){
  // check x 
  if(((p.x + inc_x)>=39)||((p.x +inc_x)<=0)){
    return(0);
  }
  // check y
  else if(((p.y+inc_y)>=19)||((p.y+inc_y)<=0)){
    return(0);
  }
  // if 1 is returned, o is in the border
  return(1);
}

void keystroke(int level){
  // init blocks hit to 0, red_count to 0 for levels 1 and 2
	int ch, memb, blocks_h =0, red_count = 0;
  // set cursor to invisible, noecho to screen and keypad TRUE
	noecho();
	curs_set(0);
  keypad(stdscr, TRUE);
  // set number of blocks in levels
	if(level ==1){
		memb = 1;
	}
  else if(level ==2){
		memb = 9;
	}
  else if(level ==3){
		memb = 17;
    // set red_count to 8 to account for uncollectable blocks
    red_count = 8;
	}
  // init struct Char and preset levels
	struct Char c[memb];
	pre_setter(level,c);
  // init player
  Player p = addPlayer(20, 10);
  // init NPC 
  NPC n = addNpc(31, 3);
  // loop for keystrokes and input
  while (1) {
    ch = getch();
    refresh();
    // move up and move npc
    if (ch == KEY_UP) {
      p = movePlayer(p, 0, -1, c, memb,&blocks_h);
      moveNpc(&n,p,memb,&blocks_h);
    }
    // move down and move npc
    else if (ch == KEY_DOWN) {
      p = movePlayer(p, 0, 1, c, memb, &blocks_h);
      moveNpc(&n,p,memb,&blocks_h);
      
    }    
    // move right and move npc
    else if (ch == KEY_RIGHT) {
      p = movePlayer(p, 1, 0, c, memb, &blocks_h);
      moveNpc(&n, p, memb, &blocks_h);
    }
    // move left and move npc
    else if (ch == KEY_LEFT) {
      p = movePlayer(p, -1, 0,c, memb, &blocks_h);
      moveNpc(&n,p,memb,&blocks_h);
    }
    // call pause screen
    else if (ch == 'p') {
      pause_screen();
    }
    // call quit screen
    else if (ch == 'q') {
      quit_screen();
    }
    // increment level
    if(blocks_h == (memb-red_count)){
      level++;
      display_level(level);
    }
  }
}

void pause_screen(){
  int ch;
  // position out of bounds and display messages
  move(20, 14);
  printw("Game Paused");
  move(22, 11);
  printw("Press 'p' to Resume");
  // check for p, if p unpause and set message to blank
  while(1){
    ch = getch();
    if(ch == 'p'){
      move(20,14);
      printw("           ");
      move(22, 11);
      printw("                   ");
      break;
    }
    else{
      continue;
    }
  }
}

void quit_screen(){
  int ch;
  // move and display message
  move(21, 14);
  printw("quit? [y/n]");
  // loop for y or n input, if y then quit, if n then continue
  while(1){
    ch= getch();
    if(ch == 'y'){
      endwin();
      clear();
      exit(1);
    }
    else if(ch == 'n'){
      move(21,14);
      // set text to blank
      printw("           ");
      break;
    }
    else{
      continue;
    }
  }
}
