//name: Darion and Ethan
//lab: AS04
//purpose: h file for movement.h

/**
* @file movement.h                                    *
* @brief header file for movement.c                   *
* @author Ethan, Darion                               *
* @date December 4th, 2023                            *
*/ 

/**
*@brief struct for the player object
*/
typedef struct {
  int x; /**< the x coord of the player*/ 
  int y; /**< the y coord of the player*/
}Player;

/**
* @brief function adds a player to the game 
* @param x,y: int coords for the player
* @return p: Player struct 
*/
Player addPlayer(int, int);

/**
* @brief function handles the player movement and checks border 
* @param p: is the struct player
* @param inc_x,inc_y: int increment of the direction of player movement in x or y direction
* @param b: is a void pointer to the struct Char
* @param memb: is a int of the numbers of elements in struct Char
* @param blocks_h: int* to the number of blocks that have been hit
* @return p: struct Player 
*/
Player movePlayer(Player p, int, int, void*, int, int*);

/**
* @brief function handles keystroke inputs and calling actions/functions accordingly
* @param level: int number of the level
* @return void
*/
void keystroke(int);

/**
* @brief function ensures player stays within border
* @param p: is the struct player
* @param inc_x,inc_y: int increment of the direction of player movement in x or y direction
* @return 1,0: int; 1 if the player is in the border, 0 if the player is out of the border
*/
int bordercheck(Player p, int, int);

/**
@ brief display a message to end the game ex: [y\n]
@ return void
*/
void quit_screen();

/**
*@ brief pauses game until keystroke is given
*@ return void
*/
void pause_screen();

/**
* @brief function checks for player collision with char game object and inits interactions
* @param p: is the struct player
* @param b: is a void pointer to the struct Char
* @param inc_x,inc_y: int increment of the direction of player movement in x or y direction
* @param memb: int of the number struct Char elements
* @param blocks_h: int* to the number of blocks that have been hit
* @return void
*/
void block_checker(Player p, void*, int, int, int, int*);

/**
* @brief this function computes the keystroke interaction with a struct Char game object
* @param nowx,nowy: int of the players position after the keystroke is finished
* @param symbol: type Char of the symbol of the character that is being interacted with 
* @return 1,0: int 1 if there is a valid interaction, int 0 if there is a invalid interaction
*/
int block_hit(int, int, char);


