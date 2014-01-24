#include "Person.h"
#include "parser.h"
#include <stdio.h>

int main()
{
    Person* Mike = Create("Mike","Desgrottes",17,"Derp");
    /*Person* jenny = Create("jennifer","Desgrottes",18,"derp");
    Person* Naika = read("Mike.zh");
    add_friend(Mike,jenny);
    info(Naika);
    info(Mike);
    info(jenny);
    destroy(Mike);
    destroy(jenny);
    destroy(Naika);*/
    write_to_dtb(Mike);
    return(0);
}