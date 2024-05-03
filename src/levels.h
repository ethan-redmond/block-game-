// name: Darion and Ethan
// lab: AS04
// purpose: header file for levels

/**
* @file levels.h                                      *
* @brief header file for levels.c                     *
* @author Ethan, Darion                               *
* @date December 5th, 2023                            *
*/

/**
* @brief function calls creation of a window and displays the first level
* @param i: int of the current level
* @return void
*/
void display_level(int);

/**
* @brief function displays user win and provides keystroke interaction
* @param i: none
* @return void
*/
void win();

/**
* @brief function display why user lost and ends the game through keystroke functionality
* @param i: int (reason of loss)
* @return void
*/
void lose(int);

