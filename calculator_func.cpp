/*!\file
*/

#include "calculator.h"


double get_number(char* str, int* pos)
{    
	delete_spaces(str, pos);

		//or change str instead of ptr --> str not const
	char* ptr = NULL;
	double val = 0;
	val = strtod(&(str[*pos]), &ptr);
	*pos = strlen(str) - strlen(ptr);
	while(str[*pos] == ' ')
		++(*pos);
	//printf("c = \'%c\' %d val = %f\n", str[*pos], *pos, val);
	
	delete_spaces(str, pos);

	return val;
}

/*double get_number(char** str, int* index)
{    
	char* ptr = NULL;
	printf("%p \n", *str);

	double val = 0;
	val = strtod(*str, &ptr);

	*index = 0;
	*str = ptr;

	printf("%p c = %s ptr = %s %d\n", *str, *str, ptr, *index);

	return val;
}*/

void syntax_error(char* str, int* pos)
{
	printf("You have syntax error! Your last string: %s, current symbol  = \"%c\"\n", str, str[*pos]);
}

double get_general(char* str, int* pos)
{
	double val = get_expression(str, pos);

	if(str[*pos] == '$')
		++(*pos);
	else
		syntax_error(str, pos);

	return val;
}

double get_num(char* str, int* pos)
{
	//printf("aaa pos = %d str[pos] = %c\n", *pos, str[*pos]);

	delete_spaces(str, pos);

	double val = 0;
	int k = 0;

	while(str[*pos] >= '0' && str[*pos] <= '9')
	{
		val = val*10 + (str[*pos] - '0');
		++(*pos);
		++k;
	}

	if(!k)
		syntax_error(str, pos);

	//printf("now val = %d\n", val);

	delete_spaces(str, pos);

	return val;
}

double get_expression(char* str, int* pos)
{
	//clear_tabs(str, pos);

	double val = get_mul_div(str, pos);

	while(str[*pos] == '+' || str[*pos] == '-')
	{
		char op = str[*pos];
		++(*pos);

		double val2 = get_mul_div(str, pos);

		if(op == '+')
			val += val2;
		else
			val -= val2;
	}

	return val;
}

double get_mul_div(char* str, int* pos)
{
	double val = get_parenthesis(str, pos);

	while(str[*pos] == '*' || str[*pos] == '/')
	{
		char op = str[*pos];
		++(*pos);

		double val2 = get_parenthesis(str, pos);

		if(op == '*')
			val *= val2;
		else if(!is_close_to_zero(val2))
			val /= val2;
		else
			printf("You have division by 0!\n");
	}

	return val;
}

double get_parenthesis(char* str, int* pos)
{
	if(str[*pos] == '(')
	{
		++(*pos);

		double val = get_expression(str, pos);

		if(str[*pos] == ')')
			++(*pos);
		else
			syntax_error(str, pos);
		return val;
	}
	else
		return get_number(str, pos);
}

void delete_spaces(char* str, int* pos)
{
	while(str[*pos] == ' ')
	{
		//printf("----\n");
		++(*pos);
	}

	//printf("sym : \"%c\"\n", str[*pos]);
}