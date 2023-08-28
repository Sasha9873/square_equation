#include "test.h"

bool two_numbers_are_close(double x, double y)
{
	assert(std::isfinite(x));
	assert(std::isfinite(y));

	if(fabs(x - y) < PRECISION)
		return true;
	return false;
}

void print_all_info_about_error(const test_data* test, double* roots)
{
	char string_with_error[MAX_ERROR_LEN];

	sprintf(string_with_error, "FAILED: test name: %s\n a = %f\n b = %f\n c = %f\n\n program_x1 = %f\n program_x2 = %f\n\n right_x1 = %f\n right_x2 = %f.\n\n", 
		test->name, test->coeffs[0], test->coeffs[1], test->coeffs[2], roots[0], roots[1], test->roots[0], test->roots[1]);
				
	print_red(string_with_error);
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
				print_all_info_about_error(test, roots);

				return 0;
			}
			return 1;

		case TWO_ROOTS:
			if(!two_numbers_are_close(test->roots[0], roots[0]) || !two_numbers_are_close(test->roots[1], roots[1]) || n_roots != test->n_roots)
			{
				print_all_info_about_error(test, roots);

				return 0;
			}
			return 1;

		case NO_ROOT:
			if(n_roots != test->n_roots)
			{
				print_all_info_about_error(test, roots);

				return 0;
			}
			return 1;

		case INFINITE_ROOTS:
			if(n_roots != test->n_roots)
			{
				print_all_info_about_error(test, roots);

				return 0;
			}
			return 1;

		default:
			print_red("Test has wrong amount of roots!\n");
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
		print_green("\nOK\n");
		
	return N_TESTS - n_right_tests;
}