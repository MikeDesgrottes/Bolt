#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Person.h"
#include "parser.h"
/*--------------------Project Zehav.1.0.0.----------------
* This is the first version of zParser. The parser to project Zeha.
*
**TODO: Implement a data structure for wich zParser will store information <--- See Person.c and Person.h for the solution
*       Add feature to use .txt file to store information from data structure to the file
*
*
**
*
*
*
*
*/
List *LIST;
// Initialize the global variable LIST.
void init()
{
	LIST = malloc(sizeof(List));
	LIST->value = "";
	LIST->next = NULL;
}

// create a list
List* Create_list()
{
    List* tmp = malloc(sizeof(List));
    tmp->value = "";
    tmp->next = NULL;
    return tmp;
}
// find the index of a character in a string. if the character is not found return -1.
int index_of(char *str, char st)
{
    int i=0;
    size_t len = strlen(str);
    for(i=0;i<=len;i++)//loop through the string
    {
        if(str[i]==st)
            return i;
            
        if(i==len && str[i] != st)// if it's the last character and it does not match the character return -1;
            return -1;
    }
}
// This function print everything after, but not including , index.
char* print(char *string, int index)
{
    int count =0;
    int i = index +1;
    size_t len = strlen(string) -1;
    char *tmp = malloc(sizeof(char)*index);
    for(;i<=len;i++)
    {
        //printf("%i\n",i); <-- for testing purposes. 
        //printf("%c\n",string[i]);
        tmp[count] = string[i];
        count = count +1;
        
    }
    //printf("%s\n",tmp); <-- for testing purposes/
    return (tmp);
}
// print everything before the character at index.
char* print_before(char *str, int index)
{
    int i = 0;
    char* msg = malloc(sizeof(char)*index);
    for(i=0;i<index;i++)
    {
        msg[i] = str[i];
        //printf("%c -> %i\n",msg[i],index); <--- for testing purposes.
    }
    msg[index] = '\0';
    //printf("%s: ",msg); <-- for testing purposes.
    return msg;
}
// this function read a file and create a struct of person from it.
Person* read(char* str)
{
    Person *head = malloc(sizeof(Person));
    FILE *fp = fopen(str,"r");
    char result[1024][1024];
    int count = 0;
    if(fp!=NULL)
    {
        while(fgets(result[count],1024,fp) != NULL)
        {
            //printf("%s\n",result[count]); <-- this and those 2 line sbelow are for testing purpose.
            //printf("%s: ",print_before(result[count],index_of(result[count],'=')));
            //printf("%s",print(result[count],index_of(result[count],'=')));
            count++;
        }
        head->fname = print(result[0],index_of(result[0],'='));
        head->lname = print(result[1],index_of(result[1],'='));
        head->age = atoi(print(result[2],index_of(result[2],'=')));
        head->description = print(result[3],index_of(result[3],'='));
        head->lfriends = NULL;
        //printf("%s\n",result[0]);
        fclose(fp);
    }
    else
    {
        printf("Error! file is Null");
        exit(1);
    }
    return head;
}
// Create a file from a Person structure.
void write(Person* head)
{
    Person *tmp = head;
    char msg[1024];
    snprintf(msg,1024,"%s%s%s%s",head->fname," ",head->lname,".zh");
    FILE *f = fopen(msg,"w");
    fprintf(f,"First name=%s\nLast name=%s\nage=%i\ndescription=%s\n",tmp->fname,tmp->lname,tmp->age,tmp->description);
    fclose(f);
    
}

List* get_end_list(List *list)
{
    List *tmp = malloc(sizeof(List));
    tmp = list;
    if(tmp->next == NULL)
    {
		return NULL;
	}
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    return tmp;
}
/* This function take the first name of the head and append it to the linked list LIST
 * 	TODO: Do not store only the first name. Store both the first name and the last name.
 * 
 * 
 * */
void write_to_dtb(Person *head)
{
    //init();
    List *tmp = get_end_list(LIST);
    List *tmp2 = malloc(sizeof(List));
    tmp2->next = NULL;
    tmp2->value = head->fname;
    if(tmp == NULL)
    {
        //puts("work!");
        LIST->next = tmp2;
    }else
    {
        if(!contains(LIST,head))
        {
            tmp->next = tmp;
            puts("Hello");
        }else
        {
            puts("Person already in the database!!");
        }
    }
    printf("%s\n",LIST->next->value);
   /* if(!contains(LIST,head))
    {
        puts("Hello");
    }*/
}
// return 1 if the person's first name is found in the linked list LIST else return 0.
int contains(List* list,Person* person)
{
    List* tmp = LIST;
    if(tmp==NULL)
    {
        return 0;
    }else if(person == NULL)
    {
        puts("Person does not exist!");
    }else
    {
        while(tmp->next != NULL)
        {
            if(person->fname == tmp->value)
                return 1;
            printf("%s\n",tmp->value);
            tmp = tmp->next;
        }
        if(person->fname == tmp->value)
        {
            printf("%s\n",tmp->value);
            return 1;
        }
    }
    return 0;
}
char* lookup(List* list, Person* person)
{
    if(contains(list,person))
    {
        return person->fname;
    }else
    {
        return NULL;
    }
}
/*int main()
{
   Person* Mike = Create("Mike","Desgrottes",17,"Derp");
   Person* jenny = Create("jennifer","Desgrottes",18,"derp");
   Person* Naika = read("Mike.zh");
   add_friend(Mike,jenny);
   info(Naika);
   info(Mike);
   info(jenny);
   
   return(0);
}
*/
