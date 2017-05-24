#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "mintf.h"

void mintf(const char *format, ...) {
	va_list myst;
	va_start(myst, format);
	double inputdouble;
	int inte;
	int deci;
	const char *inputstring;

	while (*format != '\0') {
		if (*format == '%'){
			format++;
			switch(*format) {
				case 'd':
					print_integer(va_arg(myst, int), 10, "");
				break;

				case 'x':
					print_integer(va_arg(myst, int), 16, "0x");
				break;

				case 'b':
					print_integer(va_arg(myst, int), 2, "0b");
				break;

				case '$':
					inputdouble = va_arg(myst, double);
					inte = (int)inputdouble;
					print_integer(inte, 10, "$");
					deci = (int)((inputdouble - inte) * 100);
					if (deci < 0) {
					deci = - deci;
					}
					print_integer(deci, 10, ".");
				break;

				case 's':
					inputstring = va_arg(myst, char*);
					while (*inputstring != '\0') {
						fputc(*inputstring, stdout);
						inputstring++;
					}
				break;

				case 'c':
					fputc(va_arg(myst, int), stdout);
				break;
				
				case '%':
					fputc('%', stdout);
				break;

				default:
					format--;
					fputc(*format, stdout);
					format++;
					fputc(*format, stdout);
					break;
			}
		}
		else {
		fputc(*format, stdout);
		}
		format++;
	}
	va_end(myst);
}


void print_integer(int n, int radix, char* prefix) {
	char allnum[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int dig = 0;
	char data[200] = "0";
	int j = 0;

	if (n < 0) {  // print a '-' if n is a negative number
	fputc('-', stdout);
	}

	while (n >= radix) {  // convert positive number
	data[dig] = allnum[n % radix];
	n = n / radix;
	dig++;
	}

	if (n > 0) {  // incase if n is less than radix
	data[dig] = allnum[n % radix];
	}

	while (n <= -radix) {  // convert negative number
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
