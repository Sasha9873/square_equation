#ifndef TEST_H
#define TEST_H

#include "main.h"

const int MAX_TEST_NAME_LEN = 20;
const int N_TESTS = 4;
const int MAX_ERROR_LEN = 1024;

typedef struct test_data
{
	double coeffs[N_COEFFS];
	double roots[MAX_N_ROOTS];
	int n_roots;
	const char name[MAX_TEST_NAME_LEN];

}test_data;


void print_all_info_about_error(const test_data* test, double* roots);

/**
 * Tests quadratic equation with given parameters a, b, c which is written in array coeffs. 
 * 
 * \param[in] test Struct with right answers to check with your own answers.  
 * 
 * \return Amount of wrong tests.
*/
int test_one_square_equation(const test_data* test);

/** 
 * Сhecks the equality of two numbers with the appropriate PRECISION.If the test was failed prints some information.
 * 
 * \param[in] x First number.
 * 
 * \param[in] y Second number.
 * 
 * \returns 1 if the test is right, 0 if the test was failed.
*/
bool two_numbers_are_close(double x, double y);

#endif