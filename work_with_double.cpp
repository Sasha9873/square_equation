/*!\file
*/

#include "work_with_double.h"

bool is_close_to_zero(double num)
{
	//printf("\n%lf %lf %d\n", fabs(num), PRECISION, fabs(num) < PRECISION);
	if(fabs(num) < PRECISION)
		return true;
	return false;
}