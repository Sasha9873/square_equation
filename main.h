/*!\file
*/

#ifndef SYMBOL
#define SYMBOL

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "square_equation_solve.h"
#include "print_in_different_colours.h"

const int N_COEFFS = 3;         /// amount of coefficients in the equation
const int MAX_FLAG_LEN = 10;    /// max length of the flag writing after ./main
const int MAX_N_ROOTS = 2;      /// max amoutn of roots in the equation 
const double PRECISION = 10e-4; /// double compare accuracy


/// It is used in return statements. Value depends on amount of roots.
enum number_of_roots
{
	INFINITE_ROOTS = -1,
	NO_ROOT        =  0,
	ONE_ROOT       =  1,
	TWO_ROOTS      =  2,
};


/**
 * Reads coefficients of the equation from the stdin.
 * 
 * \param[in] n_coeffs Amount of coefficients.
 * 
 * \param[out] coeffs Array with coefficients of the equation, consists of n_coeffs coefficients.
*/
void input_coeffs(double* coeffs, int n_coeffs);


/**
 * Solves quadratic equation with given parameters a, b, c which is written on three last places in array coeffs. AT the end clears buffer.
 * 
 * \param[in] coeffs Array with coefficients of the equation, consists of N_COEFFS coefficients. In fact, function uses only three of them:
 *  a = coeffs[n_coeffs - 3], b = coeffs[n_coeffs - 2], c = coeffs[n_coeffs - 1].
 * 
 * \param[in] n_coeffs Amount of coefficients.
 * 
 * \param[in] n_roots Max amount of roots.
 * 
 * \param[out] roots Roots of the equation. First root (if it exists) will be in roots[0], second one (if it exists) will be in roots[1].
 * 
 * \return Amount of roots of the equation.
*/
int solve_square_equation(const double* coeffs, int n_coeffs, double* roots, int n_roots);


/**
 * Prints roots: two, one, no one or infinite.
 * 
 * \param[in] roots Roots of the equation. 
 * 
 * \param[in] n_roots Max amount of roots.
*/
void print_roots(const double* roots, int n_roots);


void docs();


/**
 * Tests quadratic equation with given parameters a, b, c which is written in array coeffs.   
 * 
 * \return Amount of wrong tests.
*/
int test_square_equation();


#endif

