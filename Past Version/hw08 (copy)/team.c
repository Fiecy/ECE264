#include "team.h"

struct Team create_team(char* name, int population, struct Person* people) {
	struct Team team;
	team.name = name;
	if (population != 0) {
	int i = 0;
	struct PersonNode* new_node = NULL;
	team.head = NULL;
	team.tail = NULL;
	for (i = 0; i < population; i++) {
	  //malloc new_node
	  new_node = malloc(sizeof(struct PersonNode));//////////////////////////
	  new_node->value = malloc(sizeof(struct Person));///////////////////////
	  //	  new_node->value->favorite = malloc(sizeof(struct Person));/////////////
	  new_node->value->name = people[i].name;
	  //link new_node
	  if (team.head == NULL) {
	    team.head = new_node;
	    team.tail = new_node;
	  }
	  else {
	    team.tail->next = new_node;
	    new_node->prev = team.tail;
	    team.tail = new_node;
	  }	 
	  new_node++;  // pointer + 1
	}
	int j = 0;
	struct PersonNode* hold_node = team.head;
	struct PersonNode* temp_node = hold_node->next;
	struct PersonNode* hold_in = team.head;
	struct PersonNode* temp_in = hold_in->next;
	while (hold_node != team.tail) {
	  //find favorite
	  hold_in = team.head;
	  temp_in = hold_in->next;
	  while (hold_in != team.tail) {
	  if (strcmp(people[j].favorite->name, hold_in->value->name) == 0) {
	    hold_node->value->favorite = hold_in->value;///////CHANGE NEEDED
	  }
	    hold_in = temp_in;
	    if (hold_in != team.tail) {
	      temp_in = hold_in->next;
	    }
	}
	  if (strcmp(people[j].favorite->name, hold_in->value->name) == 0) {
	    hold_node->value->favorite = hold_in->value;///////CHANGE NEEDED
	  }
		j++;

	  	hold_node = temp_node;
		if (hold_node != team.tail) {
	        temp_node = hold_node->next;
		}
	}
	//last favorite
	hold_in = team.head;
	temp_in = hold_in->next;
	while (hold_in != team.tail) {
	  if (strcmp(people[j].favorite->name, hold_in->value->name) == 0) {
	    hold_node->value->favorite = hold_in->value;///////CHANGE NEEDED
	  }
	    hold_in = temp_in;
	    if (hold_in != team.tail) {
	      temp_in = hold_in->next;
	    }
	}
	  if (strcmp(people[j].favorite->name, hold_in->value->name) == 0) {
	    hold_node->value->favorite = hold_in->value;///////CHANGE NEEDED
	  }

	}
	else {
	  team.head = NULL;
	  team.tail = NULL;
	}

	return team;
}

struct Person* add_person( struct Team* team, char* name, char* favorite_name) {
    struct Person* new_person = malloc(sizeof(struct Person));///////////////////////////////////////
    new_person->name = name;
  if (team->head != NULL) {
    struct PersonNode* add_hold = team->head;
    struct PersonNode* add_temp = add_hold->next;
    while (add_hold != team->tail) {
      if (strcmp(favorite_name, add_hold->value->name) == 0) {
	new_person->favorite = add_hold->value;///////CHANGE NEEDED
	printf("new_person->name = %s\n",new_person->name);
      }
      add_hold = add_temp;
      if (add_hold != team->tail) {
	add_temp = add_hold->next;
      }
    }
    if (strcmp(favorite_name, add_hold->value->name) == 0) {
      new_person->favorite = add_hold->value;///////CHANGE NEEDED
    }
    
    struct PersonNode* add_Node = malloc(sizeof(struct PersonNode));/////////////////////////////////
    add_Node->value = new_person;
    
    if (team->head == NULL) {
      team->head = add_Node;
      team->tail = add_Node;
    }
    else {
      team->tail->next = add_Node;
      add_Node->prev = team->tail;
      team->tail = add_Node;
    }	
  }
  else {////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    new_person->favorite = new_person;
    struct PersonNode* add_Node = malloc(sizeof(struct PersonNode));/////////////////////////////////
    add_Node->value = new_person;
    
    if (team->head == NULL) {
      team->head = add_Node;
      team->tail = add_Node;
    }
    else {
      team->tail->next = add_Node;
      add_Node->prev = team->tail;
      team->tail = add_Node;
    }	
  }/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return new_person;
}

void free_team(struct Team* team) {
  if (team->head != NULL) {
        struct PersonNode* hold = team->tail;
	struct PersonNode* temp = hold->prev;
	while (hold != team->head) {
	  	free_person(hold->value);
		free(hold);
	  	hold = temp;
		if (hold != team->head) {
	        temp = hold->prev;
		}
	}
	free_person(hold->value);
	free(hold);
  }
}

void free_person(struct Person* person) {
  // free(person->favorite);
    free(person);
}

struct Person* find_person(struct Team* team, char* name) {
    struct Person* the_person = NULL;

    if (team->head != NULL){
    struct PersonNode* find_hold = team->head;
    struct PersonNode* find_temp = find_hold->next;
	while (find_hold != team->tail) {
	  if (strcmp(name, find_hold->value->name) == 0) {
	    the_person = find_hold->value;
	  }
	    find_hold = find_temp;
	    if (find_hold != team->tail) {
	      find_temp = find_hold->next;
	    }
	}
	  if (strcmp(name, find_hold->value->name) == 0) {
	    the_person = find_hold->value;
	  }
    }
	  return the_person;
}

struct Person* detach_person(struct Team* team, char* name) {
  struct Person* d_person = NULL;
  if (team->head != NULL) {
    struct PersonNode* d_hold = team->head;
    struct PersonNode* d_temp = d_hold->next;
    struct PersonNode* d_excu = NULL;
    while (d_hold != team->tail) {
      if (strcmp(name, d_hold->value->name) == 0) {
	d_excu = d_hold;
	break;
      }
      d_hold = d_temp;
      if (d_hold != team->tail) {
	d_temp = d_hold->next;
      }
    }
    if (strcmp(name, d_hold->value->name) == 0) {
      d_excu = d_hold;
    }
    d_excu->next->prev = d_excu->prev;
    d_excu->prev->next = d_excu->next;
    d_person = d_excu->value;
    free(d_excu);
  }
    return d_person;
}

void   fprint_team(struct Team* team, FILE* stream) {
  fprintf(stream, "%s\n", team->name);
  if (team->head == NULL) {
    fprintf(stream, "- members: (none)\n");
  }
  else {
    fprintf(stream, "- members: %-12s(favorite: %s)\n", team->head->value->name, team->head->value->favorite->name);
    if (team->head != team->tail){
      struct PersonNode* p_hold = team->head->next;
      struct PersonNode* p_temp = p_hold->next;
      while (p_hold != team->tail) {
	fprintf(stream, "           %-12s(favorite: %s)\n", p_hold->value->name, p_hold->value->favorite->name); 
	p_hold = p_temp;
	if (p_hold != team->tail) {
	  p_temp = p_hold->next;
	}
      }
    fprintf(stream, "           %-12s(favorite: %s)\n", p_hold->value->name, p_hold->value->favorite->name); 
    }
  }

}




