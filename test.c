#include "Person.h"
#include "parser.h"
#include <stdio.h>

/*void user_input()
{
    char input;
    char name[1024];
    char lname[1024];
    int age;
    char description[1024];
    char file[1024];
    Person *tmp = NULL;
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
            printf("Done..\n");
            tmp = Create(name,lname,age,description);
            write(tmp);
            //write_to_list(tmp);
            continue;
        }
        
        if(input == 'r')
        {
			
            printf("Please enter the file path: ");
            scanf("%1023s",file);
            Person* temp = read(file);
            //printf("%s\n",file);
            //info(read(file));
            //input = NULL;
            info(temp);
            free_fr(temp);
            continue;
            
        }else if(input == 'l')
        {
            printf("Do you wish to see the list of a friend or the list of people?\n Please press f for freind and p for list of people:");
            char tmp;
            while(tmp != 'x')
            {
				tmp = fgetc(stdin);
				if(tmp == 'p')
				{
					list_all_person();
					break;
				}else if(tmp == 'f')
				{
				    // TODO: add a feature wich let you list all of a particualr person's friends.
				}
			}
		}
    }
    free_f(tmp);
}*/
int main()
{
    Person* Mike = Create("Mike","Desgrottes",17,"Derp",'M');
    write(Mike);
    write_to_dtb(Mike);
    return(0);
}
