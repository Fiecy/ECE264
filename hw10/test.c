#include <stdio.h>
#include <stdlib.h>
struct PersonNode {
	char* name;
	struct PersonNode* prev;
	struct PersonNode* next;
};


typedef struct PersonNode* Favorites;

struct Person {
	char* name;
	Favorites favorites;
};


int main() {
	struct PersonNode Node_A;
	struct Person PersonA;
	Node_A.name = "ABC";
	Favorites favorite = malloc(sizeof(Favorites));
	PersonA.favorites = malloc(sizeof(Favorites));
	favorite->name = Node_A.name;
	PersonA.favorites->name = Node_A.name;
	printf("Node_A.name = %s\n", Node_A.name);
	printf("favorite->name = %s\n", favorite->name);
	printf("PersonA.favorites->name = %s\n", PersonA.favorites->name);

	free(favorite);
	free(PersonA.favorites);
	return 0;
}
