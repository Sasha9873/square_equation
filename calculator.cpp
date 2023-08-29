#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*double get_number(const char* str, int* index)
{    
		//or change str instead of ptr --> str not const
	char* ptr = NULL;

	double val = 0;
	val = strtod(str, &ptr);

	*index += strlen(str) - strlen(ptr);

	while(str[*index] == ' ')
		++(*index);

	printf("c = \'%c\' %d\n", str[*index], *index);
		
	return val;
}*/

double get_number(char** str, int* index)
{    
	char* ptr = NULL;
	printf("%p \n", *str);

	double val = 0;
	val = strtod(*str, &ptr);

	*index = 0;
	*str = ptr;

	printf("%p c = %s ptr = %s %d\n", *str, *str, ptr, *index);
		
	return val;
}

int main()
{
	char* str = (char*)calloc(100, sizeof(char));

	fgets(str, 99, stdin);

	printf("%s", str);

	printf("strlen = %d\n", strlen(str));
	str[strlen(str)] = '\0';

	int index = 0;

	double val = get_number(&str, &index);

	printf("val = %f\n", val);

	//char str[30] = "20.30300 This is test";
	char *ptr;
   	double ret;

   	const char* str2 = str;
   	ret = strtod(str2, &ptr);
   	printf("The number(double) is %lf\n", ret);
   	printf("String part is |%s|", ptr);

	return 0;
}
