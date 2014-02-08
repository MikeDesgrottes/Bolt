#ifndef PERSON_H_
#define PERSON_H_

#include <string.h>
#include <stdlib.h>

typedef struct fri friends;
typedef struct Per Person;
struct Per{
    char *fname;
    char *lname;
    char gender;
    int age;
    char *description;
    friends *lfriends;
};
struct fri{
    char* name;
    friends *next;
};
/* Prototype of the functions of Person. name are pretty self-explainitory*/
Person* Create(char *fname, char *lname, int age, char *description,char gender);
friends* get_end(Person *p);
void add_friend(Person *head, Person *friend);
void list_friends(Person *head);
int count_friend(Person *head);
void destroy(void *head);
void info(Person *head);
char* get_friends(Person* head);
void delete_friend(Person* head,Person* del);
int isfriends(Person* head,Person* friend);
#endif
