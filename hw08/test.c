#include <stdio.h>
#include <stdlib.h>

int main() {
	char* s = malloc(sizeof(*s) * 5);
	char j = 'A';
	int i = 0;
	for (i = 0; i < 5; i++){
		s[i] = j++;
	}
	for (i = 0; i < 5; i++) {
	printf("s[%d] = %c", i, s[i]);
	}
	free(s);
	char* t = malloc(sizeof(*t)*1);
	t[0] = 'A';
	t[1] = 'B';
	free(t);
	free(t);
	return 0;
}
