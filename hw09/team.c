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
		// add favorite
		for (int j = 0; j < population; j++) {
			curr->value->favorite = find_person(&team, people[j].favorite->name);
			curr = curr->next;
		}
		assert(team.head->prev == NULL);
		assert(team.tail->next == NULL);
	}		
	return team;
}

struct Person* add_person( struct Team* team, char* name, char* favorite_name) {	
	if (team->head == NULL) { // NULL team
		team->head = malloc(sizeof(struct PersonNode));
		team->tail = team->head;
		team->tail->next = NULL;
		team->head->prev = NULL;
		team->head->value = malloc(sizeof(struct Person));
		team->head->value->name = _strdup(name);
		team->head->value->favorite = find_person(team, favorite_name);
	}
	else { // not NULL
		struct PersonNode* temp = team->tail;
		team->tail = malloc(sizeof(struct PersonNode));
		temp->next = team->tail;
		team->tail->prev = temp;
		team->tail->next = NULL;

		team->tail->value = malloc(sizeof(struct Person));
		team->tail->value->name = _strdup(name);
		team->tail->value->favorite = find_person(team, favorite_name);
	}	
	assert(team->tail != NULL);
	assert(team->tail->next == NULL);
	return team->tail->value;
}

void free_team(struct Team* team) {
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
	while (newhold != NULL) {
		newhold->value->favorite = find_person(&newteam, hold->value->favorite->name);
		hold = hold->next;
		newhold = newhold->next;
	}
	return (newteam);
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
