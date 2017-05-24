#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include "mintf.h"

int main(int argc, char* argv[]) {
	mintf("try print 0: ");
	print_integer( 0, 10, "");
	mintf("\ntry INT_MAX in radix 36: ");
	print_integer( INT_MAX, 36, "");
	mintf("\ntry INT_MIN in radix 18: ");
	print_integer( INT_MIN, 18, "");
	mintf("\nalksLSKD$#^%jaks%*@!\n");
	mintf("input %d = output %d\n", 521, 521);
	mintf("%d = %x\n", 724, 724);
	mintf("%d = %b\n", 521, 521);
	mintf("%%a and %a have the same output\n");
	mintf("%s is my name\n", "YL521");
	mintf("Tuition fee cost about %$, so expensive.\n", 16987.6543);
	mintf("Tuition fee cost about %$, so expensive.\n", -123.08);
	mintf("%s bank balance is %$.\n", "YL's", -16987.6543);
	mintf("Excess parameters are ignored: %d\n", -543, 321, -94875);
	mintf("Parameters not enough: %d %d %d\n", 521724);
	mintf("Parameters of different type %x\n", "Y&Z");
	mintf("%c%c%c%c64\n\n", 'E', 'C', 'E', '2');
	mintf("HelloWorld, drop rate of %s is %b%%! Hail %c%c%c %x%d!\n", "ECE264", 4, 'E', 'C', 'E', 38, 4);
	mintf("INT_MAX in %%b = %b\n", INT_MAX);
	mintf("INT_MIN in %%b = %b\n", INT_MIN);
return EXIT_SUCCESS;
}
