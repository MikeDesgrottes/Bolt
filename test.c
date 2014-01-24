#include "Person.h"
#include <stdio.h>

int main()
{
    Person *head = Create("Mike","Desgrottes",17,"derp");
    Person *new = Create("Jennifer","Desgrottes",18,"derp");
    Person *new2 = Create("Mikelee","Desgrottes",17,"derp");
    add_friend(head,new);
    add_friend(new,new2);
    //printf("%s\n",head->lfriends->name);
    list_friends(head);
    list_friends(new);
    info(head);
    destroy(head);
    destroy(new);
    destroy(new2);
    return(0);
}