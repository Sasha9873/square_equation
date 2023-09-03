/*!\file
*/

#include "calculator.h"


double get_number(char* str, int* cur_pos_in_str, bool* is_num)
{    
	//or change str instead of ptr --> str not const

	delete_spaces(str, cur_pos_in_str);

	char* ptr = NULL;
	double val = 0;

	val = strtod(&(str[*cur_pos_in_str]), &ptr);

	if(ptr == &str[*cur_pos_in_str])
		*is_num = 0;
	else
		*is_num = 1;

	*cur_pos_in_str = strlen(str) - strlen(ptr);


	delete_spaces(str, cur_pos_in_str);

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

void syntax_error(char* str, int* cur_pos_in_str)
{
	printf("You have syntax error! Your last string: %s current symbol  = \"%c\"\n", str, str[*cur_pos_in_str]);
}

double get_general(char* str, int* cur_pos_in_str, bool* is_num)
{
	double val = 0;
	val = get_expression(str, cur_pos_in_str, is_num);

	printf("%p is_num = %d    %d %d\n", is_num, *is_num, str[*cur_pos_in_str] == 'x', is_close_to_zero(val));

	if(str[*cur_pos_in_str] == 'x' && is_close_to_zero(val) && !(*is_num))
	{
		printf("lll\n");
		if((*cur_pos_in_str - 1 >= 0) && str[*cur_pos_in_str - 1] == '-')  //-x or -x^2
			return -1;
		else if((*cur_pos_in_str - 1 >= 0) && str[*cur_pos_in_str - 1] == '+') //+x or +x^2
			return 1;

		return 1; //x or x^2
	}

	if(str[*cur_pos_in_str] == '\n' || str[*cur_pos_in_str] == 'x')
		return val;
	else
		syntax_error(str, cur_pos_in_str);

	return val;
}

double get_num(char* str, int* cur_pos_in_str, bool* is_num)
{
	//printf("aaa cur_pos_in_str = %d str[cur_pos_in_str] = %c\n", *cur_pos_in_str, str[*cur_pos_in_str]);

	delete_spaces(str, cur_pos_in_str);

	double val = 0;
	int k = 0;

	while(str[*cur_pos_in_str] >= '0' && str[*cur_pos_in_str] <= '9')
	{
		val = val*10 + (str[*cur_pos_in_str] - '0');
		++(*cur_pos_in_str);
		++k;
	}

	if(!k)
		syntax_error(str, cur_pos_in_str);

	//printf("now val = %d\n", val);

	delete_spaces(str, cur_pos_in_str);

	return val;
}

double get_expression(char* str, int* cur_pos_in_str, bool* is_num)
{
	//clear_tabs(str, cur_pos_in_str, is_num);

	double val = get_mul_div(str, cur_pos_in_str, is_num);

	while(str[*cur_pos_in_str] == '+' || str[*cur_pos_in_str] == '-')
	{
		char op = str[*cur_pos_in_str];
		++(*cur_pos_in_str);

		double val2 = get_mul_div(str, cur_pos_in_str, is_num);

		if(op == '+')
			val += val2;
		else
			val -= val2;
	}

	return val;
}

double get_mul_div(char* str, int* cur_pos_in_str, bool* is_num)
{
	double val = get_parenthesis(str, cur_pos_in_str, is_num);

	while(str[*cur_pos_in_str] == '*' || str[*cur_pos_in_str] == '/')
	{
		char op = str[*cur_pos_in_str];
		++(*cur_pos_in_str);

		double val2 = get_parenthesis(str, cur_pos_in_str, is_num);

		if(op == '*')
			val *= val2;
		else if(!is_close_to_zero(val2))
			val /= val2;
		else
			printf("You have division by 0!\n");
	}

	return val;
}

double get_parenthesis(char* str, int* cur_pos_in_str, bool* is_num)
{
	if(str[*cur_pos_in_str] == '(')
	{
		++(*cur_pos_in_str);

		double val = get_expression(str, cur_pos_in_str, is_num);

		if(str[*cur_pos_in_str] == ')')
			++(*cur_pos_in_str);
		else
			syntax_error(str, cur_pos_in_str);
		return val;
	}
	else
		return get_number(str, cur_pos_in_str, is_num);
}

void delete_spaces(char* str, int* cur_pos_in_str)
{
	while(str[*cur_pos_in_str] == ' ')
	{
		//printf("----\n");
		++(*cur_pos_in_str);
	}

	//printf("sym : \"%c\"\n", str[*cur_pos_in_str]);
}