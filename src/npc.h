//name: Darion and Ethan
//lab: AS04
//purpose: h file for npc.c 

/**
* @file npc.h                                         *
* @brief header file for npc.c                        *
* @author Ethan, Darion                               *
* @date December 4th, 2023                            *
*/

/**
* @brief this the npc structre that hold x.y coords
*/
typedef struct{
  int x; /**< x coord of the npc*/
  int y; /**< y coord of the npc*/
}NPC;

/**
* @brief display a npc to the screen and sets its x,y coords
* @param x,y: ints of the npc coords
* @return struct NPC with the npc information, displays npc to the screen 
*/
NPC addNpc(int, int);

/**
* @brief moves the npc in square and checks for collisions
* @param n: is struct NPC pointer 
* @param p: is struct Player 
* @param memb: int of the number of struct Char game objects
* @param blocks_h: int* to the number of blocks that have had a valid interaction
* @return void
*/
void moveNpc(NPC* n, Player , int, int*);

/**
* @brief this function determines if collision with player, if so display number of blocks on screen
* @param memb: int of the number of struct Char game objects
* @param blocks_h: int* to the number of blocks that have had a valid interaction
* @return displays npc message of how many blocks there are left to interact with 
*/
void npc_hit(int ,int*);
