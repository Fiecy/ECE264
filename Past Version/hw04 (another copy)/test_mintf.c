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
	mintf("Chance of coalescent cloudburst: 0.375%\n");
	mintf("Chance of coalescent cloudburst: 0.375%%");
	printf("\n");
	mintf("%s the cat has only %d lives left", "Orlicasta", 8);
	printf("\n");
	mintf("Orlicasta's shoes cost %$.", 768.336);
	printf("\n");
	mintf("Orlicasta's bank balance is %$.\n", -768.336);
	mintf("Excess parameters are ignored: %d\n", 768336, 768337, 768338);
	mintf("Insufficient parameters may lead to undefined behavior: %d %d %d\n", 768336);
	mintf("Mismatched parameters may lead to undifined behavior: %d\n", "Orlicasta");
	mintf("%c%c%c%c64\n\n", 'E', 'C', 'E', '2');
	mintf("HelloWorld, drop rate of %s is %b%%! Hail %c%c%c %x%d!", "ECE264", 4, 'E', 'C', 'E', 38, 4);
return EXIT_SUCCESS;
}
