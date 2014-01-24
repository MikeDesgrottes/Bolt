#include "Person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* TODO: Implement a function that will allow the user to delete a friend.
*        Implement a function that will return an array of friends of a particulat Person.
*        Implement a function that make adding friends vice versa. Use recursive function to do this
* The code below implement the list of function to create,add,list Person
*Author: Mike Desgrottes
* you can do whatever you want with the code but i need to know the change you've made.
*/
void add_friend(Person *head,Person *friend);
char* concat(char* f, char* s)
{
    char* result = strcat(f,s);
    return result;
}
Person* Create(char *fname, char*lname, int age, char *description)// This function creates a new Person from allocated memory. It set the attribute to the input given from the parameter.
{
    Person *tmp = malloc(sizeof(Person));// allocate memory of size person 
    tmp->fname = fname;
    tmp->lname = lname;
    tmp->age = age;
    tmp->description = description;
    tmp->lfriends = NULL;
    return tmp;
}

friends* get_end(Person *p)// This function get the last Person in your list of friend.
{
    Person *tmp = p;// This temporary variable allows us to directly access the pointer which the user pass in as the parameter.
    if(tmp->lfriends == NULL)// check to  see if the Person have any friend or not
        return NULL;
    friends *tmp2 = tmp->lfriends;// assign temporary variable to the first friend of the person.
    while(tmp2->next != NULL)// while this is not the linked list do the following.
    {
        
        tmp2 = tmp2->next; //increment tmp2
    }
    
    return tmp2;// return the last friends
}
/* The reason why there are so many if\else statement is 
*  because i was setting up a contengency plan for all scenario and switch was not possible
*  Please remember if you are changing how the friends structure are named remember to do it 
*  for every case.
*/
void add_friend(Person *head,Person *friend)//This function works like append. it add your new friend to the last element.
{
    friends *tmp = get_end(head);// get the last friend in the linked list of friends
    friends *tmp2 = malloc(sizeof(friends));
    friends *temp = malloc(sizeof(friends));
    memset(temp,0,sizeof(friends));
    friends* tmp3 = get_end(friend);/* allocate some memory on the heap for this Friends */
    if(tmp == NULL)//check to see if Person does not have any friends
    {
        if(tmp3 == NULL)
        {
			temp->name = head->fname;
			temp->next = NULL;
			friend->lfriends = temp;
			tmp2->name = friend->fname;
			tmp2->next = NULL;
            head->lfriends = tmp2;
			
		}else
		{
			if(tmp->name = tmp3->name)
			{
			}else{
            tmp2->name = friend->fname;
            tmp2->next = NULL;
            head->lfriends = tmp2;// add friends to the head because this is his first friend.
            temp->name = head->fname;
            temp->next = NULL;
            tmp3->next = temp;
            printf("%s\n",head->lfriends->name);
            list_friends(friend);
			}
		}
	}
    else{
		if(tmp3==NULL)
		{
			temp->name = head->fname;
			temp->next = NULL;
			friend->lfriends = temp;
			tmp2->name = friend->fname;
			tmp2->next = NULL;
			tmp->next = tmp2;
		}else
		{
			if(tmp->name == tmp3->name)
			{
            
			}else
			{
				tmp2->name = friend->fname;
				tmp2->next = NULL;
				printf("%s\n",tmp2->name);
				tmp->next = tmp2;
				temp->name = head->fname;
				temp->next = NULL;
            tmp3->next = temp;
				printf("%s\n",tmp->next->name);
    
			}
        }
    }
}

void list_friends(Person *head)
{
    friends* tmp = head->lfriends;
    if(tmp == NULL)
    {
        printf("No friends yet\n\n");
    } else if(tmp!=NULL)
    {
        printf("%s %s's friend(s) are: ",head->fname,head->lname);
        while(tmp != NULL)
        {
            printf("%s\n",tmp->name);
            //puts("Hello World\n");
            tmp = tmp->next;
        }
        printf("\n");
    }
    
    
}
/*char* get_friends(Person* head)
{
    friends* tmp = head->lfriends;
    if(tmp == NULL)
    {
        return NULL
    } else
    {
        printf("%s %s's friend(s) are: ",head->fname,head->lname);
        while(tmp != NULL)
        {
            //printf("%s\n",tmp->name);
            
            tmp = tmp->next;
        }
    }
}*/
int count_friend(Person *head)
{
    int count =0;
    friends *tmp = head->lfriends;
    while(tmp->next != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}
void info(Person* head)
{
    printf("First name: %s\nLast name: %s\nage: %i\ndescriptiong: %s\n",head->fname,head->lname,head->age,head->description);
    list_friends(head);
}
void destroy(void *head)
{
    free(head);
}
