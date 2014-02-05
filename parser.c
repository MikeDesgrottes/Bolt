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
*       ---- Find a way to add list of friend to a person's personal .zh file.
*       
*
*
*
*
*
*/


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
// This function print everything after, but not including , index. Don't forget to free it.
char* print(char *string, int index)
{
    int count =0;
    int i = index +1;
    size_t len = strlen(string) -1;
    char *tmp = malloc(sizeof(char)*500);
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
// print everything before the character at index. Don't forget to free it.
char* print_before(char *str, int index)
{
    int i = 0;
    char* msg = malloc(sizeof(char)*500);
    for(i=0;i<index;i++)
    {
        msg[i] = str[i];
        //printf("%c -> %i\n",msg[i],index); <--- for testing purposes.
    }
    msg[index] = '\0';
    //printf("%s: ",msg); <-- for testing purposes.
    return msg;
}
// this function read a file and create a struct of person from it. DOn't forget to free it.
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
        char* fname = trim(print(result[0],index_of(result[0],'=')));
        char* lname = trim(print(result[1],index_of(result[1],'=')));
        char* description = trim(print(result[3],index_of(result[3],'=')));
        char* age = print(result[2],index_of(result[2],'='));// the trim function just take ou the newline character from string.
        head->fname = fname;
        head->lname = lname;
        head->description = description;
        head->age = atoi(age);
        head->lfriends = NULL;
        //printf("%s\n",result[0]);
        //fclose(fp);
        //free(fname);
        //free(lname);
        free(age);
        //free(description);
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
    snprintf(msg,1024,"%s%s%s%s",head->fname,"_",head->lname,".zh");
    FILE *f = fopen(msg,"w");
    fprintf(f,"First name=%s\nLast name=%s\nage=%i\ndescription=%s\n",tmp->fname,tmp->lname,tmp->age,tmp->description);
    fclose(f);
    
}
// don't forget to free this. To prevent memory leaks
List* get_end_list(List *list)
{
    List *tmp = malloc(sizeof(List));
    tmp = list;
    if(tmp != NULL){
		if(tmp->next == NULL)
		{
			return NULL;
		}
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
    }else
    {
		return NULL;
	}
    return tmp;
}
/* This function take the name of the head and append it to the linked list LIST
 * 
 * 
 * */
void write_to_dtb(Person *head)
{
    FILE* fp = fopen("dtb.zh","a");
    char name[1024];
    if(fp == NULL)
    {
        puts("error!");
    }else
    {
        if(look_up_file(head))// to avoid dupicate in the file.
        {
            puts("found");
            return;
        }else
        {
            snprintf(name,1024,"%s%s%s",head->fname,"_",head->lname);
            //printf("%s",name);
            fprintf(fp,"%s\n",name);
            //printf("Printing..-> %s\n",head->fname);
        }
    }
    write(head);
    fclose(fp);
    //printf("%s\n",LIST->next->value);
   /* if(!contains(LIST,head))
    {
        puts("Hello");
    }*/
}
// return 1 if the person's first name is found in the linked list LIST else return 0.
int contains(List* list,Person* person)
{
    List* tmp = list;
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
            //printf("%s\n",tmp->value);
            tmp = tmp->next;
        }
        if(person->fname == tmp->value)
        {
            //printf("%s\n",tmp->value);
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

int look_up_file(Person* head)
{
    FILE* fp = fopen("dtb.zh","r");
    char* tmp = malloc(sizeof(char)*1024);
    char name[1024];
    snprintf(name,1024,"%s%s%s",head->fname,"_",head->lname);
    size_t len = strlen(head->fname) + strlen(head->lname) +1;
    while(fgets(tmp, 1024,fp) != NULL)
    {
        if(strncmp(tmp,name,len) ==0)
        {
            //puts(tmp);
            free(tmp);
            return 1;
        }    
    }
    free(tmp);
    fclose(fp);
    return 0;
}

void list_person(List* LIST)
{
    List* tmp = LIST->next;
    if(LIST == NULL || tmp == NULL)
    {
		return;
	}
    while(tmp->next != NULL)
    {
        printf("%s\n",tmp->value);
        tmp = tmp->next;
    }
    printf("%s\n",tmp->value);
}
// don't forget to free. To prevent memory leaks.
char* trim(char *s)
{
    char* msg = malloc(sizeof(char) * strlen(s));
    strncpy(msg,s,strlen(s)-1);
    msg[strlen(s)] = '\0';
    free(s);
    return msg;
}
void free_f(Person* head)
{
	if(head->lfriends == NULL)
	{
		
	    free(head);
	}else
	{
		friends *tmp = head->lfriends;
		friends* next;
		while(tmp != NULL)
		{
			if(tmp->next != NULL)
			{
				free(tmp);
			}else
			{
				next = tmp->next;
				free(tmp);
				tmp = next;
			}
		}
	    free(head);
	}
	
	//free(head);
}
void free_fr(Person* head)
{
	if(head->lfriends == NULL)
	{
		
	    free(head);
	}else
	{
		friends *tmp = head->lfriends;
		friends* next;
		while(tmp != NULL)
		{
			if(tmp->next != NULL)
			{
				free(tmp);
			}else
			{
				next = tmp->next;
				free(tmp);
				tmp = next;
			}
		}
		free(head->fname);
		free(head->lname);
		free(head->description);
	    free(head);
	}
	
	//free(head);
}
void free_l(List* list)
{
	List* tmp = list;
	if(tmp)
	{
		return;
	}else if(tmp->next == NULL)
	{
		free(tmp);
		return;
	}else
	{
		List* tmp2;
		while(tmp)
		{
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
		}
	}
}
void list_all_person()
{
	FILE* fp = fopen("dtb.zh","r");
	char *tmp = malloc(sizeof(char) *1024);
	char* lname;
	char* fname;
	if(fp)
	{
	    printf("This is the list of all people in the databse:\n");
		while(fgets(tmp,1024,fp) != 0)
		{
			fname = print_before(tmp,index_of(tmp,'_'));
			lname = print(tmp,index_of(tmp,'_'));
			printf("\t%s %s",fname,lname);
			
		}
	}
	free(tmp);
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
