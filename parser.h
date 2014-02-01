#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Person.h"

typedef struct dtb List;

struct dtb{
    char* value;
    List *next;
};
int index_of(char *str, char st);
char* print(char *string, int index);
char* print_before(char *str, int index);
Person* read(char* str);
void write(Person* head);
List* get_end_list(List *list);
void write_to_dtb(Person *head);
int contains(List* list,Person* person);
char* lookup(List* list, Person* person);
void list_person();
char* trim( char *s );
int look_up_file(Person* head);
void free_f(Person* head);
void free_l(List* list);
#endif
