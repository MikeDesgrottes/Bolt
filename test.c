#include "Person.h"
#include "parser.h"
#include <stdio.h>

void user_input()
{
    char input;
    char name[1024];
    char lname[1024];
    int age;
    char description[1024];
    char file[1024];
    Person *tmp = NULL;
    init();
    while(input != 'x')
    {
        input = fgetc(stdin);
        if(input == 'c')
        {
            printf("Please enter your first name:");
            scanf("%1023s",name);
            printf("Please enter your last name:");
            scanf("%1023s",lname);
            printf("Please enter your age: ");
            scanf("%i",&age);
            printf("Please write a shor description of you: ");
            scanf("%1023s",description);
            printf("Creating File....\n");
            tmp = Create(name,lname,age,description);
            write(tmp);
            write_to_dtb(tmp);
            continue;
        }
        
        if(input == 'r')
        {
            printf("Please enter the file path: ");
            scanf("%1023s",file);
            //printf("%s\n",file);
            info(read(file));
            //input = NULL;
            continue;
            
        }else if(input == 'l')
        {
			list_person();
		}
    }
}
int main()
{
    Person* Mike = Create("Mike","Desgrottes",17,"Derp");
    Person* jenny = Create("jennifer","Desgrottes",18,"derp");
    Person* Naika = read("Mike.zh");
    add_friend(Mike,jenny);
    info(Naika);
    info(Mike);
    info(jenny);
    //destroy(Mike);
    //destroy(jenny);
    //destroy(Naika);
    //init();
    write_to_dtb(Mike);
    //write_to_dtb(Mike);
    list_person();
    //user_input();
    
    return(0);
}
