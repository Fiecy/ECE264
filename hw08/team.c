#include "team.h"

struct Team create_team(char* name, int population, struct Person* people) {
	struct Team team;
	team.name = name;
	team.head = NULL;
	team.tail = NULL;

	if (population > 0) {
		int i = 0;
		struct PersonNode* hold = NULL;
		struct PersonNode* curr = NULL;
		team.head = malloc(sizeof(struct PersonNode));
		curr = team.head;
		curr->value = malloc(sizeof(struct Person));
		curr->value->name = _strdup(people[0].name);

		for (i = 0; i < population - 1; i++) {
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
		for (i = 0; i < population; i++) {
			curr->value->favorite = find_person(&team, people[i].favorite->name);
			curr = curr->next;
		}

		assert(team.head->prev == NULL);
		assert(team.tail->next == NULL);
	}		
	return team;
}

struct Person* add_person( struct Team* team, char* name, char* favorite_name) {	

	if (team->head == NULL) {
		team->head = malloc(sizeof(struct PersonNode));
		team->tail = team->head;
		team->tail->next = NULL;
		team->head->prev = NULL;

		team->head->value = malloc(sizeof(struct Person));
		team->head->value->name = _strdup(name);
		team->head->value->favorite = find_person(team, favorite_name);
	}
	else {
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
}

void free_person(struct Person* person) { 
  	free(person->name);
    free(person);
}

struct Person* find_person(struct Team* team, char* name) {
	struct Person* the_person = NULL;

	if (team->head != NULL) {
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

	if (team->head != NULL) {
		struct PersonNode* d_Node = team->head;
		while (d_Node != NULL) {
			if (strcmp(d_Node->value->name, name) == 0) {
				d_person = d_Node->value;
				if (d_Node == team->head && d_Node == team->tail) {
					team->head = NULL;
					team->tail = NULL;
				}
				else if (d_Node == team->tail) {
					d_Node->prev->next = NULL;
					team->tail = d_Node->prev;
				}
				else if (d_Node == team->head) {
					d_Node->next->prev = NULL;
					team->head = d_Node->next;
				}
				else {
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
		int i;
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
			for (i = n_len; i < p_len + 1; i++) {
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


