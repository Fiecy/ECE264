#include <stdlib.h>
#include "team.h"

struct Team create_team(int population, char* names[], int* favorites) {
//	struct Person member;
	struct Team output;
	int i = 0;
	output.population = population;
	output.people = malloc(sizeof(struct Person) * population);///////
	for (i = 0; i < population; i++) {
		output.people[i].favorite = malloc(sizeof(struct Person));////////
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

struct Person* pick_leader(struct Team* team) {
	int l = 0;
	int m = 0;
	int leader_hold = 0;
	int leader_now = 0;
	int t_leader = 0;

	for (l = 0; l < team->population; l++) {
		for (m = 0; m < team->population; m++) {
			if (team->people[m].favorite->name == team->people[l].name) {
				leader_now++;
			}
		}

		if (leader_now > leader_hold) {
		leader_hold = leader_now;
		t_leader = l;
		}
	}

	return (&team->people[t_leader]);
}

