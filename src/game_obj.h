// name: Darion and Ethan
// lab: AS04
// purpose: header file for game objects

/**
* @file game_obj.h                   *
* @brief header file for game_obj.c  *                
* @author Ethan, Darion              *                 
* @date December 4th, 2023           *                     
*/

/**
* @brief structure for character game objects
*/
struct Char{
	int x;
	int y;
	char symbol;
  int color;
  int active;
  int flag;
};

/**
* @brief creates the game window
* @param none
* @return displays the screen 
*/
void createWindow();

/**
* @brief used to display the blocks to the screen 
* @param x,y are the coords of the objects
* @param symbol is the visual of the objects being displayed
* @param color is the number of the color to be set
* @return displays object to the screen
*/
void rect(int, int, char, int);

/**
* @brief this function calls rect and sets information to the struct char array
* @param x,y are the coord of the objects
* @param symbol is the visual of the object being displayed
* @param c is a pointer to the struct Char array
* @param idx is the index of the Char array
* @param color is the number of the color to be set
* @return void
*/
void setter2(int, int, char, struct Char* ,int, int);

/**
* @brief this function will set the struct Char array with info for the correct level
* @param int number of the current level
* @param c is a pointer to the struct Char array
* @return void 
*/
void pre_setter(int, struct Char*);
