#include <stdio.h>
#include "team.h"

int main(int argc, char *argv[]) {
  
	char* names1[] = {"YiLi", "YFSB", "Nana"};
	int favorites1[] = {2, 1, 0};
	struct Team team1 = create_team(3, names1, favorites1);
	struct Person* leader1 = pick_leader(&team1);
	printf("There are %d people on the team.\n", team1.population);
	printf("%s's favorite is %s.\n", team1.people[0].name, team1.people[0].favorite -> name);

	printf("The leader shall be %s.\n", leader1 -> name);
	free_team(&team1);
		
	char* names2[] = {"YiLi", "YFSB", "Nana", "Laji", "test_a_long_string_alsdjfoiuiokwqna,msndoijcvhz"};
	int favorites2[] = {2, 2, 1, 1, 4};
	struct Team team2 = create_team(5, names2, favorites2);
	struct Person* leader2 = pick_leader(&team2);
	printf("There are %d people on the team.\n", team2.population);
	printf("%s's favorite is %s.\n", team2.people[4].name, team2.people[4].favorite -> name);
	
	printf("The leader shall be %s.\n", leader2 -> name);
	free_team(&team2);
	
	char* names3[] = {"YiLi", "YFSB", "Nana", "Doubi"};
	int favorites3[] = {3, 2, 2, 1};
	struct Team team3 = create_team(4, names3, favorites3);
	struct Person* leader3 = pick_leader(&team3);
	printf("There are %d people on the team.\n", team3.population);
	printf("%s's favorite is %s.\n", team3.people[3].name, team3.people[3].favorite -> name);

	printf("The leader shall be %s.\n", leader3 -> name);
	free_team(&team3);
	
	char* names4[] = {"YiLi"};
	int favorites4[] = {0};
	struct Team team4 = create_team(1, names4, favorites4);
	struct Person* leader4 = pick_leader(&team4);
	printf("There are %d people on the team.\n", team4.population);
	printf("%s's favorite is %s.\n", team4.people[0].name, team4.people[0].favorite -> name);

	printf("The leader shall be %s.\n", leader4 -> name);
	free_team(&team4);
	
	return 0;
}
