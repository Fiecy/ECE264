#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int a;
	int count;
	char* name[]= {"alex", "12345678", "09"};
	char* temp;
	char* temp2;
	for (i = 0; i < 4; i++) {
		count = 0;
		temp = name[i];
		while (*temp != '\0') {
			count++;
			temp++;
		}

		a = sizeof(char*) * count;
		printf(" a = %d \n", a);
	}
	
	temp2 = *name;
	printf("temp2 = %s\n", temp2);
	temp2 = *(name + 1);
	printf("temp2 = %s\n", temp2);

	return 0;
}
