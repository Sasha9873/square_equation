/*!\file
*/

#ifndef WORK_WITH_DOUBLE_H
#define WORK_WITH_DOUBLE_H

#include <stdbool.h>
#include <math.h>

static const double PRECISION = 10e-4; /// double compare accuracy

/** 
 * Сhecks the equality of the number to zero with the appropriate PRECISION.
 * 
 * \param[in] num Number to check.
 * 
 * \returns True if the number are close to the zero with the PRECISION error, otherwise it returns False.
*/ 
bool is_close_to_zero(double num);

#endif