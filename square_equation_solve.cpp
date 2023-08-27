#include "square_equation_solve.h"

/**
 * Reads one coefficient of the equation from the stdin.
 * \param[out] coeff Entered coefficient.
*/
int input_one_coeff(double* coeff);

/**
 * Solves linear equation with given parameters b, c which is written on two last places in array coeffs.  
 * \param[in] coeffs Array with coefficients of the equation, consists of N_COEFFS coefficients. In fact, function uses only two of them:
 *  b = coeffs[n_coeffs - 2], c = coeffs[n_coeffs - 1].
 * \param[in] n_coeffs Amount of coefficients.
 * \param[out] roots Root of the equation. Root (if it exists) will be in roots[0].
 * /return Amount of roots of the equation.
*/
int solve_linear_equation(const double* coeffs, int n_coeffs, double* roots);

/**
 * Clears stdin buffer.
*/
void clear_input_buffer();

/** 
 * Сhecks the equality of the number to zero with the appropriate PRECISION.
 * \param[in] num Number to check.
 * /returns True if the number are close to the zero with the PRECISION error, otherwise it returns False.
*/ 
bool close_to_zero(double num);


int input_one_coeff(double* coeff)
{
	assert(coeff);

	return scanf("%lf", coeff);
}

void clear_input_buffer()
{
	char symbol;
	while((symbol = getchar()) != '\n')
	{
		;
	}
}

void input_coeffs(double* coeffs, int n_coeffs)
{
	assert(coeffs);

	printf("Please write %d coeffs: ", n_coeffs);

	int i = 0;
	while(i < n_coeffs)  //enter while everything will be right
	{
		if(!input_one_coeff(&coeffs[i]))
		{
			clear_input_buffer();
			printf("You have writen something wrong.\n");
			printf("Please write only numbers!\n");
			i = -1;
		}

		++i;
	}
}

int solve_linear_equation(const double* coeffs, int n_coeffs, double* roots)
{
	assert(coeffs);
	assert(roots);

	assert(coeffs != roots);

	double b = coeffs[n_coeffs - 2], c = coeffs[n_coeffs - 1];

	if(b == 0) //b*x + c = 0 -> c = 0
	{
		if(c == 0)
			return INFINITE_ROOTS;

		return NO_ROOT;
	}

	roots[0] = -c / b;
	return ONE_ROOT;
}

bool close_to_zero(double num)
{
	//printf("\n%lf %lf %d\n", fabs(num), PRECISION, fabs(num) < PRECISION);
	if(fabs(num) < PRECISION)
		return true;
	return false;
}

int solve_square_equation(const double* coeffs, int n_coeffs, double* roots, int max_n_roots)
{
	assert(coeffs);
	assert(roots);

	assert (std::isfinite (coeffs[0]));
    assert (std::isfinite (coeffs[1]));
    assert (std::isfinite (coeffs[2]));

    assert (coeffs != roots);

	double a = coeffs[n_coeffs - 3], b = coeffs[n_coeffs - 2], c = coeffs[n_coeffs - 1];

	if(a == 0) //in square_equation (a*x^2 + b*x + c = 0) is a -> b*x = -c
		return solve_linear_equation(coeffs, n_coeffs, roots);
	
	//double descriminant = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];  //b*b - 4*a*c
	double descriminant = b*b - 4*a*c;

	if(close_to_zero(descriminant))
	{
		roots[0] = -b / (2*a);
		if(close_to_zero(roots[0]))
			roots[0] = 0;

		return ONE_ROOT;
	}

	if(descriminant < 0)
		return NO_ROOT;

	//printf("\ndescr = %lf\n", descriminant);

	assert(!close_to_zero(a));
	roots[0] = (-b - sqrt(descriminant)) / (2*a);
	roots[1] = (-b + sqrt(descriminant)) / (2*a);
	
	return TWO_ROOTS;
}


void print_roots(const double* roots, int n_roots)
{
	assert(roots);

	switch(n_roots)
	{
		case ONE_ROOT:
			printf("Your square equation has one root: %lf\n.", roots[0]);
			break;
		case TWO_ROOTS:
			printf("Your square equation has two roots: %lf and %lf\n.", roots[0], roots[1]);
			break;
		case NO_ROOT:
			printf("Your square equation has no one root.\n");
			break;
		case INFINITE_ROOTS:
			printf("Your square equation has infinite roots.\n");
			break;	
		default:
			printf("Something has gone wrong!\n");
	}
}

void docs()
{

}





