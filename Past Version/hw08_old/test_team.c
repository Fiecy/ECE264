#include "team.h"

struct Team create_test_team() {
	struct Person people[] = {
	  { .name = "Anna"    ,.favorite = &people[1]},
	  { .name = "Liangts" ,.favorite = &people[1]},
	  { .name = "YL"      ,.favorite = &people[0]},
	  { .name = "Momo"    ,.favorite = &people[2]},
	};
	return create_team("TAs", sizeof(people)/sizeof(people[0]), people);
}

int main(int argc, char *argv[]) {
  //case 1: normal test
	struct Team team = create_test_team();
		fprint_team(&team, stdout);

	struct Person* add_a_person = add_person(&team, "YFSB", "Momo");
	printf("add person = %s favorite = %s\n", add_a_person->name, add_a_person->favorite->name);
	fprint_team(&team, stdout);
	struct Person* the_person = find_person(&team, "YL");
	printf("find_person = %s, favorite = %s\n",the_person->name, the_person->favorite->name);
	fprint_team(&team, stdout);
	struct Person* detach_a_person = detach_person(&team, "Liangts");
	printf("detached %s, favorite %s\n",detach_a_person->name, detach_a_person->favorite->name);
	fprint_team(&team, stdout);
	struct Person* detach_a_person2 = detach_person(&team, "YFSB");
	printf("detached %s, favorite %s\n",detach_a_person2->name, detach_a_person2->favorite->name);
	fprint_team(&team, stdout);
	
	free_team(&team);
	free_person(detach_a_person);
	free_person(detach_a_person2);
  //case 2: NULL team	
	
	team = create_team("Some Empty Team", 0, NULL);
	fprint_team(&team, stdout);
	
	add_a_person = add_person(&team, "YFSB", "YFSB");
	printf("add person = %s favorite = %s\n", add_a_person->name, add_a_person->favorite->name);
	fprint_team(&team, stdout);

	detach_a_person = detach_person(&team, "YFSB");
	printf("detached %s, favorite %s\n",detach_a_person->name, detach_a_person->favorite->name);
	fprint_team(&team, stdout);
	
	add_a_person = add_person(&team, "Anna", "YFSB");
	printf("add person = %s favorite = %s\n", add_a_person->name, add_a_person->favorite->name);
	fprint_team(&team, stdout);
	
	add_a_person = add_person(&team, "Momo", "Anna");
	printf("add person = %s favorite = %s\n", add_a_person->name, add_a_person->favorite->name);
	fprint_team(&team, stdout);
	

	free_team(&team);
	free_person(detach_a_person);


	return EXIT_SUCCESS;
	
}
