#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Person.h"

int index_of(char *str, char st);
char* print(char *string, int index);
char* print_before(char *str, int index);
Person* read(char* str);
void write(Person* head);

#endif
