#include "team.h"

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
/*
struct Person* add_person( struct Team* team, char* name, Favorites favorites) {	
	if (team->head == NULL) { // NULL team
		team->head = malloc(sizeof(struct PersonNode));
		team->tail = team->head;
		team->tail->next = NULL;
		team->head->prev = NULL;
		team->head->value = malloc(sizeof(struct Person));
		team->head->value->name = _strdup(name);
		team->head->value->favorite = find_person(team, favorite_name);  // Need Modify
	}
	else { // not NULL
		struct PersonNode* temp = team->tail;
		team->tail = malloc(sizeof(struct PersonNode));
		temp->next = team->tail;
		team->tail->prev = temp;
		team->tail->next = NULL;

		team->tail->value = malloc(sizeof(struct Person));
		team->tail->value->name = _strdup(name);
		team->tail->value->favorite = find_person(team, favorite_name);  // Need Modify
	}	
	assert(team->tail != NULL);
	assert(team->tail->next == NULL);
	return team->tail->value;
}
*/
void free_team(struct Team* team) {  // Need modify [free favorite]
    struct PersonNode* hold = team->head;
	Favorites hold_f = hold->value->favorites;
	while (team->head != NULL) {
		hold = team->head;
		team->head = team->head->next;
		while (hold->value->favorites != NULL) {
			hold_f = hold->value->favorites;
			hold->value->favorites = hold->value->favorites->next;
			free(hold_f);
		}
	  	free_person(hold->value);
		free(hold);
	}
	team->tail = NULL;
	free(team->name);
}

void free_person(struct Person* person) {
  	free(person->name);
    free(person);
}

struct Person* find_person(struct Team* team, char* name) {
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
/*
struct Person* detach_person(struct Team* team, char* name) {
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
*/
/*
void fprint_team(struct Team* team, FILE* stream) {

	fprintf(stream, "%s\n", team->name);
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
    		fprintf(stream, "- members: %s", temp->value->name);
			n_len = strlen(temp->value->name);
			for (int i = n_len; i < p_len + 1; i++) {
			fprintf(stream, " ");
			}
			fprintf(stream, "(favorite: %s)\n", temp->value->favorite->name);
			temp = temp->next;
		}		
	}

}
*/
char* _strdup(char* s) {
	return strcpy(malloc(sizeof(*s) * strlen(s) + 1), s);
}
/*
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
	while (newhold != NULL) {
		newhold->value->favorite = find_person(&newteam, hold->value->favorite->name);
		hold = hold->next;
		newhold = newhold->next;
	}
	return (newteam);
}
*/

Favorites create_favorites(struct Person* first_choice, ...) {  // Favorites malloced
	va_list mylist, mylist2;  // va_arg(mylist, struct Person*);
	va_start(mylist, first_choice);
	va_copy(mylist2, mylist);
	Favorites favorites = NULL;
	if (first_choice == NULL) {  // return NULL directly if first_choice == NULL
		return favorites;
	}
	favorites = malloc(sizeof(Favorites));
	favorites->prev = NULL;
	favorites->next = NULL;
	Favorites hold = favorites;  // hold pointer
	Favorites curr = favorites;  // current operation
	struct Person* fav = first_choice;  // create a Person* for value
	curr->value = fav;
	while (va_arg(mylist, struct Person*) != NULL) {
		hold = curr;
		curr->next = malloc(sizeof(Favorites));
		curr = curr->next;
		fav = va_arg(mylist2, struct Person*);
		curr->value = fav;
		hold->next = curr;  // connect node
		curr->prev = hold;
		curr->next = NULL;  // tail = NULL
	}
	va_end(mylist);
	va_end(mylist2);
	return favorites;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
