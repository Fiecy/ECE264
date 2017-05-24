#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "hw02.h"

int main(int argc, char* argv[]) {

	print_integer(07334, 10, "");

	print_integer(-6427, 16, "");
	
	print_integer(981237, 2, "$");

	print_integer(-0x9123123, 27, "ohhhh");

	print_integer(-2, 36, "Y");

	return EXIT_SUCCESS;
}
