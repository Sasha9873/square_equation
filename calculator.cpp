#include "calculator.h"

int main()
{
	char* str = (char*)calloc(100, sizeof(char));
	if(!str)
		return 1;

	fgets(str, 99, stdin);

	int pos = 0;
	printf("%.3f\n", get_general(str, &pos));

	free(str);

	return 0;
}