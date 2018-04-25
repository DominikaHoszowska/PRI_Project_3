/*Created by Dominika Hoszowska on 17.04.18.*/


#include <stdio.h>
#include <malloc.h>
#include "Menu.h"

BazaSamochodow bazaSamochodow;

int main(int argc,char *argv[]) {
    printf("PRI Projekt 3 Zadanie 3-1201\n"
                   "autor: Dominika Hoszowska\n"
                   "Program umozliwa tworzenie i edycje bazy samochodow\n");
    menu(&bazaSamochodow);
    return 0;
}