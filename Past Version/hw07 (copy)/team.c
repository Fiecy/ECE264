#include <stdlib.h>
#include "team.h"

struct Team create_team(int population, char* names[], int* favorites) {
//	struct Person member;
	struct Team output;
	int i;
	output.population = population;
	output.people = malloc(sizeof(struct Person) * population);
	for (i = 0; i < population; i++) {
		output.people[i].favorite = malloc(sizeof(struct Person));
		(output.people[i].favorite -> name) = *(names + favorites[i]);
		(output.people[i].name) = *(names + i);
	}
	return (output);
}

void free_team(struct Team* team) {
	for (int k = 0; k < team->population; k++) {
	free(team->people[k].favorite);
	}
	free(team->people); 
}
/*
struct Person* pick_leader(struct Team* team) {



}
*/
