#ifndef __TEAM_H__
#define __TEAM_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

typedef struct PersonNode* Favorites;

struct Person {
	char* name;
	Favorites favorites;
};

struct PersonNode {
	struct Person* value;
    struct PersonNode* next;
    struct PersonNode* prev;
};

struct Team {
	char*              name;
	struct PersonNode* head;
    struct PersonNode* tail;
};

struct Team create_team(char* name, int population, struct Person* people);
struct Team create_test_team();
void   free_team(struct Team* team);
void   free_person(struct Person* person);
struct Person* add_person(struct Team* team, char* name, Favorites favorites);
struct Person* detach_person(struct Team* team, char* name);
struct Person* find_person(struct Team* team, char* name);
void   fprint_team(struct Team* team, FILE* stream);
char*  _strdup(char* s);
struct Team copy_team(struct Team* team);
Favorites create_favorites(struct Person* first_choice, ...);

void add_favorite(struct Person* fan, struct Person* favorite, int rank);
struct Person* pick_leader(struct Team* team);


#endif
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
