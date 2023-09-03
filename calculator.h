/*!\file
*/

#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <stdlib.h>
#include "work_with_double.h"
#include <string.h>


double get_num(char* str, int* cur_pos_in_str);
void syntax_error(char* str, int* cur_pos_in_str);
double get_expression(char* str, int* cur_pos_in_str, bool* is_num);

/**
 * Reads expression from the str starting from the current position(cur_pos_in_str). It should ends with '\n' or 'x', else it will 
 * be syntax error.
 * 
 * \param[in] str  String to read expression from.
 * 
 * \param[in] cur_pos_in_str  Position to read str from.
 * 
 * \return Value of the expression before ().
*/
double get_general(char* str, int* cur_pos_in_str, bool* is_num);
double get_mul_div(char* str, int* cur_pos_in_str, bool* is_num);
double get_parenthesis(char* str, int* cur_pos_in_str, bool* is_num);
void delete_spaces(char* str, int* cur_pos_in_str);

double get_number(char* str, int* cur_pos_in_str, bool* is_num);

#endif