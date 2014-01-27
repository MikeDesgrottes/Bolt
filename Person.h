#ifndef PERSON_H_
#define PERSON_H_

#include <string.h>
#include <stdlib.h>

typedef struct fri friends;
typedef struct Per Person;
struct Per{
    char *fname;
    char *lname;
    int age;
    char *description;
    friends *lfriends;
};
struct fri{
    char* name;
    friends *next;
};
Person* Create(char *fname, char *lname, int age, char *description);
friends* get_end(Person *p);
void add_friend(Person *head, Person *friend);
void list_friends(Person *head);
int count_friend(Person *head);
void destroy(void *head);
void info(Person *head);
char* get_friends(Person* head);
char* trim(char* s);
#endif
