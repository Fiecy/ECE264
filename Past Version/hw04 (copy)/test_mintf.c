#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include "mintf.h"

int main(int argc, char* argv[]) {

	mintf("768336");
	printf("\n");
	mintf("my favorite number is %d!", 768336);
	printf("\n");
	mintf("%d written in hex is %x", 768336, 768336);
	printf("\n");
	mintf("%d written in binary is %b", 768336, 768336);
	printf("\n");
	mintf("ch%usj%%iasu%");
	printf("\n");
	mintf("%s the cat has only %d lives left", "Orlicasta", 8);
	printf("\n");
return EXIT_SUCCESS;
}
