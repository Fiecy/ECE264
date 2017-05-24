/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include "smintf.h"

char* smintf(const char *format, ...){
        va_list myst, myst1, myst2;
	va_start(myst, format);
	va_copy(myst1, myst);  // first loop
	va_copy(myst2, myst);  // second loop
	int element_num;  // use for malloc
	const char* format_copy = format;  // hold the initial pointer of format
	char* s;  // return char*

	char allnum[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int dig = 0;
	char data[200] = "0";
	int i = 0;
	//	int j = 0;
	int count = 0;  // count num
	//	char out_p[200] = "0";  // return
	int neg = 0;
	int n = 0;
	int radix = 10;
	double inputdouble = 0;
	int inte = 0;
	int deci = 0;
	char *inputstring;
	
	//  count the size of malloc
	while (*format_copy != '\0') {
		if (*format_copy == '%'){  // find the %
		  format_copy++;
			switch(*format_copy) {  // determine what is next to the %
				case 'd':
				  dig = 0;
				  count = 0;
				  neg = 0;
				  n = va_arg(myst1, int);
				  radix = 10;
				  if (n < 0) {  // print a '-' if n is a negative number
				    neg = 1;
				  }

				  while (n >= radix) {  // convert positive number
				    //	data[dig] = allnum[n % radix];
				    n = n / radix;
				    dig++;
				  }
				  while (n <= -radix) {  // convert negative number
				    //	data[dig] = allnum[-(n % radix)];
				    n = n / radix;
				    dig++;
				  }
				  // count num
				  count = dig + neg + 1;  // no '0' no +1
				  element_num += count;
				  break;
				  
				case 'x':
				  dig = 0;
				  count = 0;
				  neg = 0;
				  n = va_arg(myst1, int);
				  radix = 16;
				  if (n < 0) {  // print a '-' if n is a negative number
				    neg = 1;
				  }

				  while (n >= radix) {  // convert positive number
				    //	data[dig] = allnum[n % radix];
				    n = n / radix;
				    dig++;
				  }
				  while (n <= -radix) {  // convert negative number
				    //	data[dig] = allnum[-(n % radix)];
				    n = n / radix;
				    dig++;
				  }
				  // count num
				  count = dig + neg + 1 + 2;  // no '0' no +1
				  element_num += count;				
				break;
				
				case 'b':
				  dig = 0;
				  count = 0;
				  neg = 0;
				  n = va_arg(myst1, int);
				  radix = 2;
				  if (n < 0) {  // print a '-' if n is a negative number
				    neg = 1;
				  }
				  while (n >= radix) {  // convert positive number
				    //	data[dig] = allnum[n % radix];
				    n = n / radix;
				    dig++;
				  }
				  while (n <= -radix) {  // convert negative number
				    //	data[dig] = allnum[-(n % radix)];
				    n = n / radix;
				    dig++;
				  }
				  // count num
				  count = dig + neg + 1 + 2;  // no '0' no +1
				  element_num += count;	
				break;
				
				case '$':
					inputdouble = va_arg(myst1, double);  // print a $ sign with 2 digit after the '.'
					inte = (int)inputdouble;

				  dig = 0;
				  count = 0;
				  neg = 0;
				  n = inte;
				  radix = 10;
				  if (n < 0) {  // print a '-' if n is a negative number
				    neg = 1;
				  }
				  while (n >= radix) {  // convert positive number
				    //	data[dig] = allnum[n % radix];
				    n = n / radix;
				    dig++;
				  }
				  while (n <= -radix) {  // convert negative number
				    //	data[dig] = allnum[-(n % radix)];
				    n = n / radix;
				    dig++;
				  }
				  // count num
				  count = dig + neg + 1 + 1;  // no '0' no +1
				  element_num += count;	

					deci = (int)(inputdouble * 100 - inte * 100);
					if (deci < 0) {  // print -abc.def instead of -abc.-def
					deci = - deci;
					}
					element_num++;
					if (deci <= 9) {  // print abc.0d instead of abc.d
					element_num++;
					}
					//  deci part
				  dig = 0;
				  count = 0;
				  neg = 0;
				  n = deci;
				  radix = 10;
				  while (n >= radix) {  // convert positive number
				    //	data[dig] = allnum[n % radix];
				    n = n / radix;
				    dig++;
				  }
				  while (n <= -radix) {  // convert negative number
				    //	data[dig] = allnum[-(n % radix)];
				    n = n / radix;
				    dig++;
				  }
				  // count num
				  count = dig + 1;  // no '0' no +1
				  element_num += count;	
				break;
				
				case 's':
					inputstring = va_arg(myst1, char*);  // print a string
					while (*inputstring != '\0') {
						element_num++;
						inputstring++;
					}
				break;
				
				case 'c':
					element_num++;  // print a character
				break;
					
				case '%':
					element_num++;  // print one % instead of two
				break;
				
			        case '\0':
				        element_num++; // if % at the end of string
					format_copy--;
				break;
			
				default:  // print the case that is not listed above as what it is
					format_copy--;
					element_num++;
					format_copy++;
					element_num++;
					break;
			}
		}
		else {  // if there is no %, print directly
		element_num++;
		}
		format_copy++;
	}

	// malloc
	s = malloc(sizeof(char) * (element_num + 1));
	
	// initialize again
	format_copy = format;
	element_num = 0;

	// get content
	while (*format_copy != '\0') {
		if (*format_copy == '%'){  // find the %
			format_copy++;
			switch(*format_copy) {  // determine what is next to the %
				case 'd':
				  dig = 0;
				  i = 0;
				  n = va_arg(myst2, int);
				  radix = 10;
				  if (n < 0) {  // print a '-' if n is a negative number
				    neg = 1;
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
				  // return string
				  if (neg == 1){
				    s[element_num++] = '-';
				  }
				  for (i = dig; i > - 1; i--) {  // print the converted result
				    s[element_num++] = data[i];
				  }
				  //	  free(hold[num_hold]);
				break;
		       	
				case 'x':
				  dig = 0;
				  i = 0;
				  n = va_arg(myst2, int);
				  radix = 16;
				  if (n < 0) {  // print a '-' if n is a negative number
				    neg = 1;
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
				  // return string
				  if (neg == 1){
				    s[element_num++] = '-';
				  }
				    s[element_num++] = '0';
				    s[element_num++] = 'x';
				  for (i = dig; i > - 1; i--) {  // print the converted result
				    s[element_num++] = data[i];
				  }
				break;
				
				case 'b':
				  dig = 0;
				  i = 0;
				  n = va_arg(myst2, int);
				  radix = 2;
				  if (n < 0) {  // print a '-' if n is a negative number
				    neg = 1;
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
				  // return string
				  if (neg == 1){
				    s[element_num++] = '-';
				  }
				    s[element_num++] = '0';
				    s[element_num++] = 'b';
				  for (i = dig; i > - 1; i--) {  // print the converted result
				    s[element_num++] = data[i];
				  }
				break;
				
				case '$':
				  inputdouble = va_arg(myst2, double);  // print a $ sign with 2 digit after the '.'
				  inte = (int)inputdouble;
				  //  print inte part with $
				  dig = 0;
				  i = 0;
				  n = inte;
				  radix = 10;
				  if (n < 0) {  // print a '-' if n is a negative number
				    neg = 1;
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
				  // return string
				  if (neg == 1){
				    s[element_num++] = '-';
				  }
				    s[element_num++] = '$';
				  for (i = dig; i > - 1; i--) {  // print the converted result
				    s[element_num++] = data[i];
				  }
				  
				  //  print '.'
				  deci = (int)(inputdouble * 100 - inte * 100);
				  if (deci < 0) {  // print -abc.def instead of -abc.-def
				    deci = - deci;
				  }
				  s[element_num++] = '.';
				  if (deci <= 9) {  // print abc.0d instead of abc.d
				    s[element_num++] = '0';
				  }
				  //  print deci part
				  dig = 0;
				  i = 0;
				  n = deci;
				  radix = 10;

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
				  // return string
				  for (i = dig; i > - 1; i--) {  // print the converted result
				    s[element_num++] = data[i];
				  }
				break;
				
				case 's':
					inputstring = va_arg(myst2, char*);  // print a string
					while (*inputstring != '\0') {
						s[element_num++] = *inputstring;
						inputstring++;
					}
				break;
				
				case 'c':
					s[element_num++] = va_arg(myst2, int);  // print a character
				break;
				
				case '%':
					s[element_num++] = '%';  // print one % instead of two
				break;
				
			        case '\0':
				        s[element_num++] = '%'; // if % at the end of string
					format_copy--;
				break;
		      	
				default:  // print the case that is not listed above as what it is
					format_copy--;
					s[element_num++] = *format_copy;
					format_copy++;
					s[element_num++] = *format_copy;
					break;
			}
		}
		else {  // if there is no %, print directly
		s[element_num++] = *format_copy;
		}
		format_copy++;
	}

	s[element_num] = '\0';  // end of string mark
	//va_end
	va_end(myst1);
	va_end(myst2);
	va_end(myst);
	return s; //return a char* 
}

// Bonus option only:
// void mintf(const char *format, ...);
