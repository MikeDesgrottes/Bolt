#include "Person.h"
#include "parser.h"
#include <stdio.h>

void user_input()
{
    char input = fgetc(stdin);
    char* name[1024];
    int age;
    char* description[1024];
    while(input != 'x')
    {
        if(input == 'c')
        {
            puts("Create");
            exit(0);
        }
    }
}
int main()
{
    /*Person* Mike = Create("Mike","Desgrottes",17,"Derp");
    Person* jenny = Create("jennifer","Desgrottes",18,"derp");
    Person* Naika = read("Mike.zh");
    add_friend(Mike,jenny);
    info(Naika);
    info(Mike);
    info(jenny);
    //destroy(Mike);
    //destroy(jenny);
    //destroy(Naika);
    init();
    write_to_dtb(Mike);
    //write_to_dtb(Mike);
    list_person();*/
    user_input();
    return(0);
}