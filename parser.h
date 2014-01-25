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
List* Create_list();
void init();
int contains(List* list,Person* person);
char* lookup(List* list, Person* person);
void list_person();
#endif
