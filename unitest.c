#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "Person.h"
int test_Create()
{
    Person *mike = Create("Mike","Desgrottes",17,"Derp",'M');
    if(mike->fname == "Mike" && mike->lname == "Desgrottes" && mike->age == 17 && mike->description == "Derp" && mike->gender == 'M')
    {
        return 0;
    }else
    {
        info(mike);
        return 1;
    }
}
int test_add_friend()
{
    Person *tmp = Create("tmp","asdg",23,"adgasg",'M');
    Person *tmp1 = Create("tmp1","qwer",2534,"adgga",'F');
    add_friend(tmp,tmp1);
    if(tmp->lfriends->name == "tmp1" && tmp1->lfriends->name == "tmp")
    {
        return 0;
    }else
    {
        info(tmp);
        info(tmp1);
        write(tmp1);
        write(tmp);
        return 1;
    }
}
int main ()
{
    int x = test_Create();
    int j = test_add_friend();
    if(x== 0 && j == 0)
    {
        puts("Test failed");
    }
}
