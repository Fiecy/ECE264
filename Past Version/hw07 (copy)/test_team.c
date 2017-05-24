#include <stdio.h>
#include "team.h"

int main(int argc, char *argv[]) {
	char* names[] = {"Taukelina", "Apisai", "Monise", "Otinielu"};
	int favorites[] = {2, 2, 0, 1};
	struct Team team = create_team(4, names, favorites);
	struct Person* leader = pick_leader(&team);
	printf("There are %d people on the team.", team.population);
	printf("%s's favorite is %s.\n", team.people[0].name, team.people[0].favorite -> name);

	printf(" The leader shall be %s.\n", leader -> name);
	free_team(&team);
	return 0;
}
