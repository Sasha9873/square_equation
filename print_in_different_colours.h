/*!\file
*/

#ifndef PRINT_DIFF_COLOURS_H
#define PRINT_DIFF_COLOURS_H


#include <stdio.h>
#include <assert.h>


/// Unix system only. To change text color. 
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/**
 * Writes string in red.
 * 
 * \param[in] str String to write in stdin in red.
*/
void print_red(const char* str);

/**
 * Writes string in green.
 * 
 * \param[in] str String to write in stdin in green.
*/
void print_green(const char* str);

/**
 * Writes string in blue.
 * 
 * \param[in] str String to write in stdin in blue.
*/
void print_blue(const char* str);

/**
 * Writes string in magenta.
 * 
 * \param[in] str String to write in stdin in magenta.
*/
void print_magenta(const char* str);

#endif
