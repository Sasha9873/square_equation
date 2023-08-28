#include "print_in_different_colours.h"

void print_red(const char* str)
{
	assert(str);

	printf(ANSI_COLOR_RED "%s\n" ANSI_COLOR_RESET, str);
}

void print_green(const char* str)
{
	assert(str);

	printf(ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET, str);
}