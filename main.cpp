#include "main.h"

int main(int argc, char const *argv[])
{
	if(argc < 2)  //no flags
	{
		double coeffs[N_COEFFS];
		double roots[MAX_N_ROOTS];

		input_coeffs(coeffs, N_COEFFS);
		int n_roots = solve_square_equation(coeffs, N_COEFFS, roots, MAX_N_ROOTS);
		print_roots(roots, n_roots);

		return 0;
	}

	char flag[MAX_FLAG_LEN];

    strcpy(flag, argv[1]);

    if(!strcmp(flag, "--help") || !strcmp(flag, "-h"))
    {
        docs();
        return 0;
    }	

    if(!strcmp(flag, "--test") || !strcmp(flag, "-t"))
    {
        int n_wrong_tests = test_square_equation();
        printf("Amount of wrong tests is %d.\n", n_wrong_tests);
        return 0;
    }	

	print_red("You have writen something wrong.\n");
	printf("Please read documentation:\n");

	docs();

	return 0;
}