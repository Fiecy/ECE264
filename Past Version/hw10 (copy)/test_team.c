#include "team.h"

/*
struct Team create_test_team1() {
	struct Person people[] = {
	  { .name = "Anna"    ,.favorite = &people[0]},
	};
	return create_team("Team of 1 people", sizeof(people)/sizeof(people[0]), people);
}

struct Team create_test_team2() {
	struct Person people[] = {
	  { .name = "Anna"    ,.favorite = &people[1]},
	  { .name = "Liangts" ,.favorite = &people[1]},
	};
	return create_team("Team of 2 people", sizeof(people)/sizeof(people[0]), people);
}

struct Team create_test_team3() {
	struct Person people[] = {
	  { .name = "Anna"    ,.favorite = &people[2]},
	  { .name = "Liangts" ,.favorite = &people[1]},
	  { .name = "YL"      ,.favorite = &people[0]},
	};
	return create_team("group of 3 people", sizeof(people)/sizeof(people[0]), people);
}
*/

struct Team create_test_team() {
	struct Person people[] = {
	  { .name = "Anna"    , .favorites = create_favorites(&people[2], &people[3], &people[0], NULL)},
	  { .name = "Liangts" , .favorites = create_favorites(&people[0], NULL)},
	  { .name = "YL"      , .favorites = create_favorites(&people[3], &people[2], NULL)},
	  { .name = "Momo"    , .favorites = create_favorites(&people[1], NULL)},
	};
	return create_team("Normal test with 4 people", sizeof(people)/sizeof(people[0]), people);
}

int main(int argc, char *argv[]) {
    //  case 1: normal test - basic function
	fprintf(stdout, "case 1: normal test - basic function\n\n");  
       	struct Team team = create_test_team();
	fprint_team(&team, stdout);
	/*
	struct Person* add1_person2 = add_person(&team, "HEX", create_favorites(NULL));
	fprintf(stdout,"add person = %s", add1_person2->name);
	if (add1_person2->favorites == NULL) {
	  fprintf(stdout, ", favorite = none");
	}
	fprint_team(&team, stdout);
	*/
	struct Person testadd;
	testadd.name = "YL";
	struct Person testadd2;
	testadd2.name = "Anna";
	struct Person* add1_person = add_person(&team, "YFSB", create_favorites(&testadd, &testadd2, NULL));
	fprintf(stdout,"add person = %s favorite = %s second favorite = %s\n", add1_person->name, add1_person->favorites->value->name, add1_person->favorites->next->value->name);
	fprint_team(&team, stdout);
	//////////////////////
	fprintf(stdout, "add Liangts to YL's favorites\n");
	add_favorite(find_person(&team, "YL"), find_person(&team, "Liangts"), 2);
	fprintf(stdout, "YL's 2nd favorite is %s\n", team.head->next->next->value->favorites->next->value->name);
	fprint_team(&team, stdout);
	//////////////////////
	
	struct Person* detach1_person = detach_person(&team, "Momo");
	fprintf(stdout,"detached %s, favorite %s\n",detach1_person->name, detach1_person->favorites->value->name);
	fprint_team(&team, stdout);
	
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team.head->value->name, team.tail->value->name);
	fprintf(stdout, "team->head->favorites = %s, team->tail->favorites = %s\n", team.head->value->favorites->value->name, team.tail->value->favorites->value->name);
	fprintf(stdout, "team->head->favorites->next = %s\n", team.head->value->favorites->next->value->name);
	fprintf(stdout, "team->head->next = %s\n", team.head->next->value->name);
        if (team.head->next->value->favorites == NULL) {
	  fprintf(stdout, "team.head->next has no favorite\n");
	}
					
	free_team(&team);
		free_person(detach1_person);

	// case 2: copy_team
	fprintf(stdout, "\ncase 2: copy_team (team is not a NULL team)\n\n");

	struct Team team6 = create_test_team();
	fprint_team(&team6, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team6.head->value->name, team6.tail->value->name);
	
	struct Team newteam = copy_team(&team6);
	fprint_team(&newteam, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", newteam.head->value->name, newteam.tail->value->name);
	
	free_team(&team6);
	free_team(&newteam);

	// case 3: pick leader
/*		
    //  case 2: empty team	
	fprintf(stdout, "\ncase 2: empty team\n\n"); 						
	struct Team team2 = create_team("Some Empty Team", 0, NULL);
	fprint_team(&team2, stdout);

	assert(team2.head == NULL && team2.tail == NULL);
	fprintf(stdout,"team2.head & team2.tail == NULL\n");

	struct Person* detach2_person = detach_person(&team2, "Not in team");
	assert(detach2_person == NULL);
	fprintf(stdout,"detach a person not in team return NULL\n");

	struct Person* the2_person = find_person(&team2, "Not in team");
	assert(the2_person == NULL);
	fprintf(stdout,"find a person not in team return NULL\n");

	struct Person* add2_person = add_person(&team2, "YFSB", "YFSB");
	fprintf(stdout,"add person = %s favorite = %s\n", add2_person->name, add2_person->favorite->name);
	fprint_team(&team2, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team2.head->value->name, team2.tail->value->name);

	struct Person* the2_person2 = find_person(&team2, "YFSB");
	fprintf(stdout,"find_person = %s, favorite = %s\n",the2_person2->name, the2_person2->favorite->name);
	fprint_team(&team2, stdout);

	struct Person* detach2_person2 = detach_person(&team2, "YFSB");
	fprintf(stdout,"detached %s, favorite %s\n",detach2_person2->name, detach2_person2->favorite->name);
	fprint_team(&team2, stdout);

	assert(team2.head == NULL && team2.tail == NULL);
	fprintf(stdout,"team2.head & team2.tail == NULL\n");

	struct Person* add2_person2 = add_person(&team2, "YFSB", "YFSB");
	fprintf(stdout,"add person = %s favorite = %s\n", add2_person2->name, add2_person2->favorite->name);
	fprint_team(&team2, stdout);

	struct Person* add2_person3 = add_person(&team2, "YL", "YFSB");
	fprintf(stdout,"add person = %s favorite = %s\n", add2_person3->name, add2_person3->favorite->name);
	fprint_team(&team2, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team2.head->value->name, team2.tail->value->name);

	struct Person* add2_person4 = add_person(&team2, "Liangts", "YL");
	fprintf(stdout,"add person = %s favorite = %s\n", add2_person4->name, add2_person4->favorite->name);
	fprint_team(&team2, stdout);
		
	free_team(&team2);
	free_person(detach2_person2);

	//  case 3: create team of size 0, 1, 2, 3
	fprintf(stdout, "\ncase 3: create team of size 0, 1, 2, 3\n\n");
	struct Team team3_0 = create_team("Another Empty Team", 0, NULL);
	fprint_team(&team3_0, stdout);
	assert(team3_0.head == NULL && team3_0.tail == NULL);
	fprintf(stdout,"team3_0.head & team3_0.tail == NULL\n");
	free_team(&team3_0);	

	struct Team team3_1 = create_test_team1();
	fprint_team(&team3_1, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team3_1.head->value->name, team3_1.tail->value->name);
	free_team(&team3_1);

	struct Team team3_2 = create_test_team2();
	fprint_team(&team3_2, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team3_2.head->value->name, team3_2.tail->value->name);
	free_team(&team3_2);

	struct Team team3_3 = create_test_team3();
	fprint_team(&team3_3, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team3_3.head->value->name, team3_3.tail->value->name);
	free_team(&team3_3);

	//  case 4: create team of size 1, 2, 3 with operation
	fprintf(stdout, "\ncase 4: create team of size 1, 2, 3 with operation\n\n");	

	struct Team team4_1 = create_test_team1();
	fprint_team(&team4_1, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team4_1.head->value->name, team4_1.tail->value->name);

	struct Person* the4_1_person = find_person(&team4_1, "Not in team");
	assert(the4_1_person == NULL);
	fprintf(stdout,"find a person not in team return NULL\n");

	struct Person* the4_1_person2 = find_person(&team4_1, "Anna");
	fprintf(stdout,"find_person = %s, favorite = %s\n",the4_1_person2->name, the4_1_person2->favorite->name);
	fprint_team(&team4_1, stdout);

	struct Person* detach4_1_person = detach_person(&team4_1, "Not in team");
	assert(detach4_1_person == NULL);
	fprintf(stdout,"detach a person not in team return NULL\n");

	struct Person* detach4_1_person2 = detach_person(&team4_1, "Anna");
	fprintf(stdout,"detached %s, favorite %s\n",detach4_1_person2->name, detach4_1_person2->favorite->name);
	fprint_team(&team4_1, stdout);

	struct Person* detach4_1_person3 = detach_person(&team4_1, "Anna");
	assert(detach4_1_person3 == NULL);
	fprintf(stdout,"detach the Anna twice return NULL\n");
	fprint_team(&team4_1, stdout);

	struct Person* add4_1_person = add_person(&team4_1, "YFSB", "YFSB");
	fprintf(stdout,"add person = %s favorite = %s\n", add4_1_person->name, add4_1_person->favorite->name);
	fprint_team(&team4_1, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team4_1.head->value->name, team4_1.tail->value->name);

	free_team(&team4_1);
	free_person(detach4_1_person2);

	struct Team team4_2 = create_test_team2();
	fprint_team(&team4_2, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team4_2.head->value->name, team4_2.tail->value->name);
	free_team(&team4_2);

	struct Team team4_3 = create_test_team3();
	fprint_team(&team4_3, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team4_3.head->value->name, team4_3.tail->value->name);
	free_team(&team4_3);

    //  case 5: start with a full team and detach to empty
	fprintf(stdout, "case 5: start with a full team and detach to empty\n\n");  
	struct Team team5 = create_test_team();
	fprint_team(&team5, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team5.head->value->name, team5.tail->value->name);

	struct Person* detach5_person = detach_person(&team5, "Anna");
	fprintf(stdout,"detached %s, favorite %s\n",detach5_person->name, detach5_person->favorite->name);
	fprint_team(&team5, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team5.head->value->name, team5.tail->value->name);

	struct Person* detach5_person2 = detach_person(&team5, "Momo");
	fprintf(stdout,"detached %s, favorite %s\n",detach5_person2->name, detach5_person2->favorite->name);
	fprint_team(&team5, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team5.head->value->name, team5.tail->value->name);

	struct Person* detach5_person3 = detach_person(&team5, "YL");
	fprintf(stdout,"detached %s, favorite %s\n",detach5_person3->name, detach5_person3->favorite->name);
	fprint_team(&team5, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team5.head->value->name, team5.tail->value->name);

	struct Person* detach5_person4 = detach_person(&team5, "Liangts");
	fprintf(stdout,"detached %s, favorite %s\n",detach5_person4->name, detach5_person4->favorite->name);
	fprint_team(&team5, stdout);

	assert(team5.head == NULL && team5.tail == NULL);
	fprintf(stdout,"team5.head & team5.tail == NULL\n");

	struct Person* detach5_person5 = detach_person(&team5, "Anna");
	assert(detach5_person5 == NULL);
	fprintf(stdout,"detach the Anna twice return NULL\n");
	fprint_team(&team5, stdout);

	assert(team5.head == NULL && team5.tail == NULL);
	fprintf(stdout,"team5.head & team5.tail == NULL\n");
	free_team(&team5);
	free_person(detach5_person);
	free_person(detach5_person2);
	free_person(detach5_person3);
	free_person(detach5_person4);	
       
	//  case 6: copy_team (team is not a NULL team)
	fprintf(stdout, "\ncase 6: copy_team (team is not a NULL team)\n\n");

	struct Team team6 = create_test_team();
	fprint_team(&team6, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", team6.head->value->name, team6.tail->value->name);

	struct Team newteam = copy_team(&team6);
	fprint_team(&newteam, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", newteam.head->value->name, newteam.tail->value->name);

	struct Person* add6_person = add_person(&newteam, "YFSB", "YL");
	fprintf(stdout,"add person = %s favorite = %s\n", add6_person->name, add6_person->favorite->name);
	fprint_team(&newteam, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", newteam.head->value->name, newteam.tail->value->name);
	
	struct Person* the6_person = find_person(&newteam, "YFSB");
	fprintf(stdout,"find_person = %s, favorite = %s\n",the6_person->name, the6_person->favorite->name);
	fprint_team(&newteam, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", newteam.head->value->name, newteam.tail->value->name);

	struct Person* add6_person2 = add_person(&newteam, "Hex", "YFSB");
	fprintf(stdout,"add person = %s favorite = %s favorite'sfavorite = %s\n", add6_person2->name, add6_person2->favorite->name, add6_person2->favorite->favorite->name);
	fprint_team(&newteam, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", newteam.head->value->name, newteam.tail->value->name);

	struct Person* detach6_person = detach_person(&newteam, "Hex");
	fprintf(stdout,"detached %s, favorite %s\n",detach6_person->name, detach6_person->favorite->name);
	fprint_team(&newteam, stdout);
	fprintf(stdout, "team->head = %s, team->tail = %s\n", newteam.head->value->name, newteam.tail->value->name);
	
	free_team(&team6);
	free_team(&newteam);
	free_person(detach6_person);

	//  case 7: copy_team - empty team
	fprintf(stdout, "\ncase 7: copy_team - empty team\n\n");

	struct Team team7 = create_team("case 7: Empty Team", 0, NULL);
	fprint_team(&team7, stdout);
	assert(team7.head == NULL && team7.tail == NULL);
	fprintf(stdout,"team7.head & team7.tail == NULL\n");

	struct Team newteam2 = copy_team(&team7);
	fprint_team(&newteam2, stdout);
	assert(newteam2.head == NULL && newteam2.tail == NULL);
	fprintf(stdout,"newteam2.head & newteam2.tail == NULL\n");   

	free_team(&team7);
	free_team(&newteam2);    
*/		
	return EXIT_SUCCESS;	
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
