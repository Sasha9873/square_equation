/*!\file
*/

#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <stdlib.h>
#include "work_with_double.h"


double get_num(char* str, int* pos);
void syntax_error(char* str, int* pos);
double get_expression(char* str, int* pos);
double get_general(char* str, int* pos);
double get_mul_div(char* str, int* pos);
double get_parenthesis(char* str, int* pos);
void delete_spaces(char* str, int* pos);

#endif