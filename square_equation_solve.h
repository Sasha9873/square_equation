#ifndef SQUARE_EQUATION_SOLVE_H
#define SQUARE_EQUATION_SOLVE_H
/*!\file
*/
#include "main.h"
#include "print_in_different_colours.h"


/**
 * Reads one coefficient of the equation from the stdin.
 * 
 * \param[out] coeff Entered coefficient.
*/
int input_one_coeff(double* coeff);

/**
 * Solves linear equation with given parameters b, c which is written on two last places in array coeffs.  
 * \param[in]    coeffs Array with coefficients of the equation, consists of N_COEFFS coefficients. In fact, function uses only two of them:
 *  b = coeffs[n_coeffs - 2], c = coeffs[n_coeffs - 1].
 * 
 * \param[in]    n_coeffs Amount of coefficients.
 * 
 * \param[out]   roots Root of the equation. Root (if it exists) will be in roots[0].
 * 
 * \return Amount of roots of the equation.
*/
int solve_linear_equation(const double* coeffs, int n_coeffs, double* roots);

/**
 * Clears stdin buffer.
*/
void clear_input_buffer();

/** 
 * Сhecks the equality of the number to zero with the appropriate PRECISION.
 * 
 * \param[in] num Number to check.
 * 
 * \returns True if the number are close to the zero with the PRECISION error, otherwise it returns False.
*/ 
bool close_to_zero(double num);

#endif