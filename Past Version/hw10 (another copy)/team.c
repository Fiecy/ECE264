#include "team.h"

int _counter(struct Team* team, char* name) {  // counter
	int count = 0;
	struct PersonNode* hold = team->head;
	while (hold != NULL) {
	  if (hold->value->favorites != NULL) {
		if (strcmp(name, hold->value->favorites->value->name) == 0) {  // if name = first choice, count++
			count++;
		}
	  }
		hold = hold->next;
	}
	return count;
}

void _cleanNULL(struct Team* team) {
	struct PersonNode* hold = team->head;
	Favorites hold_f = hold->value->favorites;
	Favorites freefav = NULL;
	while (hold != NULL) {  // every person in team
		hold_f = hold->value->favorites;
		while (hold_f != NULL) {  // every favorite of each person
			if (hold_f->value == NULL) {  // if kicked
				freefav = hold_f;
				if (hold_f->prev == NULL && hold_f->next == NULL) {  // reform linked list
					hold->value->favorites = NULL;
				}
				else if (hold_f->prev == NULL) {
					hold->value->favorites = hold_f->next;
					hold_f->next->prev = NULL;
				}
				else if (hold_f->next == NULL) {
					hold->prev->next = NULL;
				}
				else {
					hold_f->next->prev = hold_f->prev;
					hold_f->prev->next = hold_f->next;
				}
			}
			hold_f = hold_f->next;
			if (freefav != NULL) {  // free kicked node
				free(freefav);
				freefav = NULL;
			}
		}
		hold = hold->next;
	}
}

void _kick(struct Team* team, char* name) {  // kick out a person from favorite list
	struct PersonNode* hold = team->head;
	Favorites hold_f = hold->value->favorites;
	Favorites freefav = NULL;
	while (hold != NULL) {  // every person in team
		hold_f = hold->value->favorites;
		while (hold_f != NULL) {  // every favorite of each person
			if (strcmp(name, hold_f->value->name) == 0) {  // if kicked
				freefav = hold_f;
				if (hold_f->prev == NULL && hold_f->next == NULL) {  // reform linked list
					hold->value->favorites = NULL;
				}
				else if (hold_f->prev == NULL) {
					hold->value->favorites = hold_f->next;
					hold_f->next->prev = NULL;
				}
				else if (hold_f->next == NULL) {
					hold->prev->next = NULL;
				}
				else {
					hold_f->next->prev = hold_f->prev;
					hold_f->prev->next = hold_f->next;
				}
			}
			hold_f = hold_f->next;
			if (freefav != NULL) {  // free kicked node
				free(freefav);
				freefav = NULL;
			}
		}
		hold = hold->next;
	}
}

struct Team create_team(char* name, int population, struct Person* people) {
	struct Team team;
	team.name = _strdup(name);
	team.head = NULL;
	team.tail = NULL;
	// return NULL directly if population = 0
	if (population > 0) {
		struct PersonNode* hold = NULL;
		struct PersonNode* curr = NULL;
		team.head = malloc(sizeof(struct PersonNode));
		curr = team.head;
		curr->value = malloc(sizeof(struct Person));
		curr->value->name = _strdup(people[0].name);
		// build and connect Nodes and add value->name
		for (int i = 0; i < population - 1; i++) {
			curr->next = malloc(sizeof(struct PersonNode));
			curr->next->value = malloc(sizeof(struct Person));
			curr->next->value->name = _strdup(people[i+1].name);
			hold = curr;
			curr = curr->next;
			hold->next = curr;
			curr->prev = hold;
		}
		team.tail = curr;
		team.head->prev = NULL;
		team.tail->next = NULL;
		curr = team.head;
		// add favorite [need modify]
		Favorites curr_f = NULL;
		//Favorites hold_f = NULL;
		for (int j = 0; j < population; j++) {
			//curr->value->favorite = find_person(&team, people[j].favorite->name);
			curr->value->favorites = people[j].favorites;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (people[j].favorites != NULL) {  // if first_choice != NULL
				curr->value->favorites->value = find_person(&team, people[j].favorites->value->name);  // value of first choice
				curr_f = curr->value->favorites;
				//hold_f = curr_f;
				while (people[j].favorites->next != NULL) {  // if there is a second_choice
					people[j].favorites = people[j].favorites->next;
					curr_f->next = people[j].favorites;
					curr_f->next->value = find_person(&team, people[j].favorites->value->name);
					curr_f = curr_f->next;
				}
				curr_f->next = NULL;
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			curr = curr->next;
		}
		assert(team.head->prev == NULL);
		assert(team.tail->next == NULL);
	}		
	return team;
}

struct Person* add_person( struct Team* team, char* name, Favorites favorites) {	
	if (team->head == NULL) { // NULL team
		team->head = malloc(sizeof(struct PersonNode));
		team->tail = team->head;
		team->tail->next = NULL;
		team->head->prev = NULL;
		team->head->value = malloc(sizeof(struct Person));
		team->head->value->name = _strdup(name);
		team->head->value->favorites->value = find_person(team, favorites->value->name);  // Need Modify(done)
		if (team->head->value->favorites != NULL) {
			team->head->value->favorites->prev = NULL;
			team->head->value->favorites->next = NULL;
		}
	}
	else { // not NULL
		struct PersonNode* temp = team->tail;
		team->tail = malloc(sizeof(struct PersonNode));
		temp->next = team->tail;
		team->tail->prev = temp;
		team->tail->next = NULL;

		team->tail->value = malloc(sizeof(struct Person));
		team->tail->value->name = _strdup(name);
		team->tail->value->favorites = favorites;
		Favorites curr_f = team->tail->value->favorites;
		if (favorites != NULL) {
			curr_f->value = find_person(team, favorites->value->name);
			while (favorites->next != NULL) {  // if there is a second_choice
				favorites = favorites->next;
				curr_f->next = favorites;
				curr_f->next->value = find_person(team, favorites->value->name);
				curr_f = curr_f->next;
			}
			curr_f->next = NULL;
		}
		//team->tail->value->favorites = find_person(team, favorite_name);                // Need Modify(done)
	}	
	assert(team->tail != NULL);
	assert(team->tail->next == NULL);
	return team->tail->value;
}

void free_team(struct Team* team) {                                                       // Need Modify(done)
    struct PersonNode* hold = team->head;
	while (team->head != NULL) {
		hold = team->head;
		team->head = team->head->next;
	  	free_person(hold->value);
		free(hold);
	}
	team->tail = NULL;
	free(team->name);
}

void free_person(struct Person* person) {                                                 // Need Modify[free favorites] (done)
	Favorites hold_f = person->favorites;
	while (person->favorites != NULL) {
		hold_f = person->favorites;
		person->favorites = person->favorites->next;
		free(hold_f);
	}
  	free(person->name);
    free(person);
}

struct Person* find_person(struct Team* team, char* name) {                               // do not need Modify
	struct Person* the_person = NULL;
	if (team->head != NULL) { // return NULL if there is no person in the team
		struct PersonNode* temp_Node = team->head;
		while (temp_Node != NULL) {
			if (strcmp(temp_Node->value->name, name) == 0) {
				the_person = temp_Node->value;
				break;
			}
			temp_Node = temp_Node->next;
		}
	}
	return the_person;
}

struct Person* detach_person(struct Team* team, char* name) {                                            // do not need modify
	struct Person* d_person = NULL;	
	if (team->head != NULL) { // return NULL if there is no person in the team
		struct PersonNode* d_Node = team->head;
		while (d_Node != NULL) {
			if (strcmp(d_Node->value->name, name) == 0) {
				d_person = d_Node->value;
				if (d_Node == team->head && d_Node == team->tail) {	// the only person in the team
					team->head = NULL;
					team->tail = NULL;
				}
				else if (d_Node == team->tail) { // tail of the team
					d_Node->prev->next = NULL;
					team->tail = d_Node->prev;
				}
				else if (d_Node == team->head) { // head of the team
					d_Node->next->prev = NULL;
					team->head = d_Node->next;
				}
				else { // middle of the team
					d_Node->prev->next = d_Node->next;
					d_Node->next->prev = d_Node->prev;
				}
				free(d_Node);
				return d_person;
			}
			d_Node = d_Node->next;
		}
	}	
    return d_person;
}


void fprint_team(struct Team* team, FILE* stream) {                                             // Need Modify[add leader]

	fprintf(stream, "%s\n", team->name);
	struct Person* leader = NULL;
	if (team->head != NULL) {
		leader = pick_leader(team);
	}
	if (leader != NULL) {
		fprintf(stream, "- leader:  %s\n", leader->name);
	}
	else {
		fprintf(stream, "- leader:  none\n");
	}
	if (team->head == NULL) {
    	fprintf(stream, "- members: (none)\n");
	}
	else {
		int p_len = 0;
		int n_len = 0;
		struct PersonNode* temp = team->head;
		
		while (temp != NULL) {
			if (p_len < strlen(temp->value->name)) {
				p_len = strlen(temp->value->name);
			}
			temp = temp->next;
		}
		temp = team->head;		
		while (temp != NULL) {
			if (temp == team->head) {
    			fprintf(stream, "- members: %s", temp->value->name);
			}
			else {
				fprintf(stream, "           %s", temp->value->name);
			}
			n_len = strlen(temp->value->name);
			for (int i = n_len; i < p_len + 1; i++) {
			fprintf(stream, " ");
			}
			if (temp->value->favorites != NULL) {
				fprintf(stream, "(favorite: %s)\n", temp->value->favorites->value->name);
			}
			else {
				fprintf(stream, "(favorite: none)\n");
			}
			temp = temp->next;
		}		
	}

}

char* _strdup(char* s) {
	return strcpy(malloc(sizeof(*s) * strlen(s) + 1), s);
}

struct Team copy_team(struct Team* team) {
	struct Team newteam;
	newteam.name = _strdup(team->name);
	newteam.head = NULL;
	newteam.tail = NULL;
	if (team->head == NULL) {
		return (newteam);
	}
	// initialize a NULL team
	newteam.head = malloc(sizeof(struct PersonNode));
	newteam.head->value = malloc(sizeof(struct Person));
	newteam.head->value->name = _strdup(team->head->value->name);
	newteam.tail = newteam.head;
	newteam.head->prev = NULL;
	newteam.tail->next = NULL;
	// use loop to create the team
	struct PersonNode* hold = team->head->next;
	struct PersonNode* newhold = newteam.tail;
	while (hold != NULL) {
		newteam.tail = malloc(sizeof(struct PersonNode));
		newteam.tail->value = malloc(sizeof(struct Person));
		newteam.tail->value->name = _strdup(hold->value->name);
		newhold->next = newteam.tail;
		newteam.tail->prev = newhold;
		newteam.tail->next = NULL;
		newhold = newteam.tail;
		hold = hold->next;
	}
	newhold = newteam.head;  // newhold go back to head of newteam and create favorite
	hold = team->head;
	Favorites hold_p = NULL;  // old team
	Favorites curr_f = NULL;  // new team
	Favorites hold_f = curr_f;  // new team
	while (newhold != NULL) {  // Need Modify
		hold_p = hold->value->favorites;
		curr_f = newhold->value->favorites;
		hold_f = curr_f;
		if (hold_p == NULL) {
			newhold->value->favorites = NULL;
		}
		else {
			newhold->value->favorites = malloc(sizeof(struct PersonNode));
			curr_f = newhold->value->favorites;
			curr_f->prev = NULL;
			curr_f->next = NULL;
			curr_f->value = find_person(&newteam, hold_p->value->name);
			//hold_p = hold_p->next;
			while (hold_p->next != NULL) {
				hold_p = hold_p->next;
				hold_f = curr_f;
				curr_f->next = malloc(sizeof(struct PersonNode));
				curr_f = curr_f->next;
				curr_f->prev = hold_f;
				hold_f->next = curr_f;
				curr_f->next = NULL;
				curr_f->value = find_person(&newteam, hold_p->value->name);
				//hold_f = curr_f;
			}
		}
//		newhold->value->favorite = find_person(&newteam, hold->value->favorite->name);
		hold = hold->next;
		newhold = newhold->next;
	}
	return (newteam);
}


Favorites create_favorites(struct Person* first_choice, ...) {                                              // Favorites malloced and linked
	va_list mylist;  // va_arg(mylist, struct Person*);
	va_start(mylist, first_choice);
	Favorites favorites = NULL;
	if (first_choice == NULL) {  // return NULL directly if first_choice == NULL
		return NULL;
	}
	favorites = malloc(sizeof(struct PersonNode));
	favorites->prev = NULL;
	favorites->next = NULL;
	Favorites hold = favorites;  // hold pointer
	Favorites curr = favorites;  // current operation
	curr->value = first_choice;
	struct Person* fav = va_arg(mylist, struct Person*);  // create a Person* for value
	while (fav != NULL) {
		hold = curr;
		curr->next = malloc(sizeof(struct PersonNode));
		curr = curr->next;
		curr->value = fav;
		hold->next = curr;  // connect node
		curr->prev = hold;
		curr->next = NULL;  // tail = NULL
		fav = va_arg(mylist, struct Person*);
	}
	va_end(mylist);
	assert(favorites == NULL || favorites->prev == NULL);
	return favorites;
}

void add_favorite(struct Person* fan, struct Person* favorite, int rank) {  // contains malloc(done)
	if (fan->favorites == NULL) {  // favorites is NULL
		fan->favorites = malloc(sizeof(struct PersonNode));
		fan->favorites->value = favorite;
		fan->favorites->prev = NULL;
		fan->favorites->next = NULL;
	}
	else  {  // not NULL
		Favorites favorites = malloc(sizeof(struct PersonNode));
		favorites->value = favorite;
		Favorites hold = fan->favorites;
		int count = 1;
		if (rank >= 0) {  // rank is positive or 0
			for (int i = 0; i < rank-1; i++) {
				hold = hold->next;
			}
		}
		else {  // rank is negative
			while (hold->next != NULL) {
				count++;
				hold = hold->next;
				printf("count = %i\n", count);
			}
			for (int i = rank+1; i < 0; i++) {
				hold = hold->prev;
			}
		}
		if (rank == 0 || rank == -(count+1)) {  // head of favorites
			fan->favorites->prev = favorites;
			favorites->next = fan->favorites;
			favorites->prev = NULL;
			fan->favorites = favorites;
		}
		else {
			if (hold->next == NULL) {  // tail of favorites
				hold->next = favorites;
				favorites->prev = hold;
				favorites->next = NULL;
			}
			else {
				favorites->next = hold->next;
				favorites->prev = hold;
				hold->next->prev = favorites;
				hold->next = favorites;
			}
		}
	}
}
/*
int _counter(struct Team* team, char* name) {  // counter
	int count = 0;
	struct PersonNode* hold = team->head;
	while (hold != NULL) {
		if (strcmp(name, hold->value->favorites->value->name) == 0) {  // if name = first choice, count++
			count++;
		}
		hold = hold->next;
	}
	return count;
}

void _kick(struct Team* team, char* name) {  // kick out a person from favorite list
	struct PersonNode* hold = team->head;
	Favorites hold_f = hold->value->favorites;
	Favorites freefav = NULL;
	while (hold != NULL) {  // every person in team
		hold_f = hold->value->favorites;
		while (hold_f != NULL) {  // every favorite of each person
			if (strcmp(name, hold_f->value->name) == 0) {  // if kicked
				freefav = hold_f;
				if (hold_f->prev == NULL && hold_f->next == NULL) {  // reform linked list
					hold->value->favorites = NULL;
				}
				else if (hold_f->prev == NULL) {
					hold->value->favorites = hold_f->next;
					hold_f->next->prev = NULL;
				}
				else if (hold_f->next == NULL) {
					hold->prev->next = NULL;
				}
				else {
					hold_f->next->prev = hold_f->prev;
					hold_f->prev->next = hold_f->next;
				}
			}
			hold_f = hold_f->next;
			if (freefav != NULL) {  // free kicked node
				free(freefav);
				freefav = NULL;
			}
		}
		hold = hold->next;
	}
}
*/
struct Person* pick_leader(struct Team* team) {
	struct Person* leader = NULL;
	struct Person* leader_temp = NULL;
	struct Team teamL = copy_team(team);
	int count_max = 0;
	int count_min = 9999;
	int count_all = 0;
	int count_temp = 0;
	struct PersonNode* hold = teamL.head;
	Favorites hold_f = hold->value->favorites;
	_cleanNULL(&teamL);
	while (hold != NULL) {
		hold_f = hold->value->favorites;
		if (hold->value->favorites != NULL) {
			count_all++;
			count_temp = _counter(&teamL, hold_f->value->name);
			if (count_temp > count_max) {
				count_max = count_temp;
				leader_temp = hold_f->value;
			}
			if (count_temp < count_min) {
				count_min = count_temp;
			}
		}
		hold = hold->next;
	}
	if (count_all == 0) {  // if team is empty, return NULL directly
		free_team(&teamL);
		return NULL;
	}
	if ((count_max * 2) > count_all) {  // leader picked
		leader = find_person(team, leader_temp->name);
	}
	else {                             // no leader, kick person
		struct Person holdk[10];
		int j = 0;
		hold = teamL.head;
		while (hold != NULL) {
			hold_f = hold->value->favorites;
			if (hold->value->favorites != NULL) {
				count_temp = _counter(&teamL, hold->value->favorites->value->name);
				if (count_temp == count_min) {
					holdk[j].name = hold->value->favorites->value->name;
					printf("holds = %s\n", hold->value->favorites->value->name);
					printf("real holds = %s\n", holdk[j].name);
					j++;
				}
			}
			hold = hold->next;
		}
		
		for (int k = 0; k < j; k++) {
		printf("kicked %s\n", holdk[k].name);
			_kick(&teamL, holdk[k].name);
		}
	
		leader_temp = pick_leader(&teamL);	// go to next round
		leader = find_person(team, leader_temp->name);
	}

	free_team(&teamL);
	return leader;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
