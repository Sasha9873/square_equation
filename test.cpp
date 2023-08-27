#include "square_equation_solve.h"

const int MAX_TEST_NAME_LEN = 20;
const int N_TESTS = 4;

typedef struct test_data
{
	double coeffs[N_COEFFS];
	double roots[MAX_N_ROOTS];
	int n_roots;
	const char name[MAX_TEST_NAME_LEN];

}test_data;

/**
 * Tests quadratic equation with given parameters a, b, c which is written in array coeffs. 
 * \param[in] test Struct with right answers to check with your own answers.  
 * /return Amount of wrong tests.
*/
int test_one_square_equation(const test_data* test);

/** 
 * Сhecks the equality of two numbers with the appropriate PRECISION.If the test was failed prints some information.
 * \param[in] x First number.
 * \param[in] y Second number.
 * /returns 1 if the test is right, 0 if the test was failed.
*/
bool two_numbers_are_close(double x, double y);

bool two_numbers_are_close(double x, double y)
{
	assert(std::isfinite(x));
	assert(std::isfinite(y));

	if(fabs(x - y) < PRECISION)
		return true;
	return false;
}

int test_one_square_equation(const test_data* test) //returns 1 if the test is ok
{
	assert(test);
	assert(test->coeffs);
	assert(test->roots);
	assert(test->name);

	for(int i = 0; i < N_COEFFS; ++i)
		assert(std::isfinite(test->coeffs[i]));

	for(int i = 0; i < MAX_N_ROOTS; ++i)
		assert(std::isfinite(test->roots[i]));

	double roots[MAX_N_ROOTS];
	assert(roots);

	int n_roots = solve_square_equation(test->coeffs, N_COEFFS, roots, MAX_N_ROOTS);

	switch(test->n_roots)
	{
		case ONE_ROOT:
			if(!two_numbers_are_close(test->roots[0], roots[0]) || n_roots != test->n_roots)
			{
				printf("FAILED: test name: %s\n a = %lf b = %lf c = %lf\n program_x1 = %lf program_x2 = %lf\n right_x1 = %lf right_x2 = %lf.\n\n", 
					test->name, test->coeffs[0], test->coeffs[1], test->coeffs[2], roots[0], roots[1], test->roots[0], test->roots[1]);

				return 0;
			}
			return 1;

		case TWO_ROOTS:
			if(!two_numbers_are_close(test->roots[0], roots[0]) || !two_numbers_are_close(test->roots[1], roots[1]) || n_roots != test->n_roots)
			{
				printf("FAILED: test name: %s\n a = %lf b = %lf c = %lf\n program_x1 = %lf program_x2 = %lf\n right_x1 = %lf right_x2 = %lf.\n\n", 
					test->name, test->coeffs[0], test->coeffs[1], test->coeffs[2], roots[0], roots[1], test->roots[0], test->roots[1]);

				return 0;
			}
			return 1;

		case NO_ROOT:
			if(n_roots != test->n_roots)
			{
				printf("FAILED: test name: %s\n a = %lf b = %lf c = %lf\n program_x1 = %lf program_x2 = %lf\n right_x1 = %lf right_x2 = %lf.\n\n", 
					test->name, test->coeffs[0], test->coeffs[1], test->coeffs[2], roots[0], roots[1], test->roots[0], test->roots[1]);

				return 0;
			}
			return 1;

		case INFINITE_ROOTS:
			if(n_roots != test->n_roots)
			{
				printf("FAILED: test name: %s\n a = %lf b = %lf c = %lf\n program_x1 = %lf program_x2 = %lf\n right_x1 = %lf right_x2 = %lf.\n\n", 
					test->name, test->coeffs[0], test->coeffs[1], test->coeffs[2], roots[0], roots[1], test->roots[0], test->roots[1]);

				return 0;
			}
			return 1;

		default:
			printf("Test has wrong amount of roots!\n");
	}

	return 0;
}

int test_square_equation()
{
	int n_right_tests = 0;

									//a  b   c     x1 x2
	test_data all_tests[N_TESTS] = { {0, 0,  0,    0, 0, .n_roots = INFINITE_ROOTS, "Infinite roots"}, 
									 {0, 2,  5, -2.5, 0, .n_roots = ONE_ROOT, "One root"},
									 {2, 3,  5,    0, 0, .n_roots = NO_ROOT, "No root"},
									 {1, 0, -4,   -2, 2, .n_roots = TWO_ROOTS, "Two roots"} };

	assert(all_tests);

	for (int i = 0; i < N_TESTS; ++i)
	{
		n_right_tests += test_one_square_equation(&all_tests[i]);
	}

	if(n_right_tests == N_TESTS)
		printf("OK\n");
		
	return N_TESTS - n_right_tests;
}