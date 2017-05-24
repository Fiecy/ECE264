#include <stdio.h>
#include "hw02.h"

void print_integer(int n, int radix, char* prefix) {
	char allnum[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int dig = 0;
	char data[] = "0";
	int j = 0;

	if (n < 0) {  // print a '-' if n is a negative number
	fputc('-', stdout);
	}

	while (n > radix) {  // convert positive number
	data[dig] = allnum[n % radix];
	n = n / radix;
	dig++;
	}

	if (n > 0) {  // incase if n is less than radix
	data[dig] = allnum[n];
	}

	while (n < -radix) {  // convert negative number
	data[dig] = allnum[-(n % radix)];
	n = n / radix;
	dig++;
	}

	if (n < 0) {  // incase if n does not need to be converted
	data[dig] = allnum[-n];
	}

	while (prefix[j] != '\0') {  // print prefix
	fputc(prefix[j], stdout);
	j++;
	}

	for (int i = dig; i > -1; i--) {  // print the converted result
	fputc(data[i], stdout);
	}
}
