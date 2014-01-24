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

int index_of(char *str, char st)
{
    int i=0;
    size_t len = strlen(str);
    for(i=0;i<=len;i++)
    {
        if(str[i]==st)
            return i;
            
        if(i==len && str[i] != st)
            return -1;
    }
}

char* print(char *string, int index)
{
    int count =0;
    int i = index +1;
    size_t len = strlen(string) -1;
    char *tmp = malloc(sizeof(char)*index);
    for(;i<=len;i++)
    {
        //printf("%i\n",i);
        //printf("%c\n",string[i]);
        tmp[count] = string[i];
        count = count +1;
        
    }
    //printf("%s\n",tmp);
    return (tmp);
}

char* print_before(char *str, int index)
{
    int i = 0;
    char* msg = malloc(sizeof(char)*index);
    for(i=0;i<index;i++)
    {
        msg[i] = str[i];
        //printf("%c -> %i\n",msg[i],index);
    }
    msg[index] = '\0';
    //printf("%s: ",msg);
    return msg;
}
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
            //printf("%s\n",result[count]);
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

void write(Person* head)
{
    Person *tmp = head;
    char msg[1024];
    snprintf(msg,1024,"%s%s%s%s",head->fname," ",head->lname,".zh");
    FILE *f = fopen(msg,"w");
    fprintf(f,"First name=%s\nLast name=%s\nage=%i\ndescription=%s\n",tmp->fname,tmp->lname,tmp->age,tmp->description);
    fclose(f);
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