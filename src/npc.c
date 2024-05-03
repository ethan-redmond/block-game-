//name: Darion and Ethan
//lab: AS04
//purpose: handles npc movements and interactions

/**
* @file npc.c                                         *
* @brief def on functions in '.h' file                *
* @author Ethan, Darion                               *
* @date December 4th, 2023                            *
*/

#include<stdio.h>
#include<curses.h>
#include<unistd.h>
#include<stdlib.h>
#include"movement.h"
#include"npc.h"
 
NPC addNpc(int x, int y){
  // use NPC struct to init npc
  NPC n;
  n.x = x;
  n.y = y;
  mvaddch(n.y, n.x, 'x');
  refresh();
  return n;
}

 
void moveNpc(NPC* n, Player p, int memb, int* blocks_h){
  // checks to see if player intercepts npc 
  if((n->x == p.x)&&(n->y == p.y)){
    npc_hit(memb, blocks_h);
  }
  // starting pos for npc
  int corner = 4;
  // reach end of path 4
  if((n->x >5) && (n->x <= 32) && (n->y == 3)){
    corner = 1;
  }
  // reach end of path 1
  else if((n->x == 5) && (n->y >=3) && (n->y<16)){
    corner = 2;
  }
  // reach end of path 2
  else if((n->x >= 5) && (n->x <32) && (n->y == 16)){
    corner = 3;
  }
  // move npc left until new corner
  if(corner == 1){ 
   if((n->x > 5) && (n->y == 3)){
     mvaddch(n->y, n->x, ' ');
     n->x -= 1;
     mvaddch(n->y, n->x, 'x');
     refresh();
    }
    // reach end of path, switch corner 
    else if((n->x == 5) && (n->y == 3)){
     corner = 2;
    }
  }
  // move npc down until new corner
  else if(corner == 2){
    if((n->x == 5) && (n->y < 16)){
      mvaddch(n->y, n->x, ' ');
      n->y += 1;
      mvaddch(n->y, n->x, 'x');
      refresh();
    }
    // reach end of path, switch corner
    else if((n->x == 5) && (n->y == 16)){
     corner = 3;
    }
  }
  // move npc right until new corner
  else if(corner == 3){
    if((n->x < 32) && (n->y == 16)){
      mvaddch(n->y, n->x, ' ');
      n->x += 1;
      mvaddch(n->y, n->x, 'x');
      refresh();
    }
    // reach end of path, switch corner
    else if((n->x == 32) && (n->y == 16)){
      corner = 4;
    }
  }
  // move npc up until new corner
  else if(corner == 4){
    if((n->x == 32) && (n->y > 3)){
      mvaddch(n->y, n->x, ' ');
      n->y -= 1;
      mvaddch(n->y, n->x, 'x');
      refresh();
    }
    // reach end of path, switch corner
    else if((n->x == 32) && (n->y == 3)){
      corner = 1;
    }
  }
}

void npc_hit(int memb,int* blocks_h){
	char ch;
  // total blocks left
	int block_num = memb - *blocks_h;
 	while(1){
    move(25,20);
    // instruction displayed
		printw("single click 't' to talk");
		refresh();
	  ch = getch();
    // instruction cleared
    move(25,20);
    printw("                             ");
    // if t, talk to npc about how many blocks are on screen
		if(ch == 't'){
			move(25,20);
      // npc text to character
			printw("# blocks left of screen: %i",block_num);
			getch();
      // npc text erase
			move(25,20);
			printw("                                ");
    }
		break;
  }
}


