/*Created by Dominika Hoszowska on 17.04.18.*/


#include <stdio.h>
#include <malloc.h>
#include "Menu.h"

int main(int argc,char *argv[]) {
    printf("PRI Projekt 3 Zadanie 3-1201\n"
                   "autor: Dominika Hoszowska\n"
                   "Program umozliwa tworzenie i edycje bazy samochodow\n");
    BazaSamochodow* bazaSamochodow;
    bazaSamochodow=(BazaSamochodow*)malloc(sizeof(BazaSamochodow));
    if(argc==1)
            menu(bazaSamochodow);
    else if(argv[1]=="zapisz" && argv[2]=="plik.txt")
    {

    } else
    return 0;
}