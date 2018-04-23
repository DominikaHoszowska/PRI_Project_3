/*Created by Dominika Hoszowska on 17.04.18.*/
#include "ObslugaPlikow.h"
#include "stdio.h"
#define DLUGOSC 15

int sprawdzNazwePilku(char nazwa[],int dlugosc)/* 0-bledna nazwa, 1- txt 0-bin*/
{
    int i=0;
    while(nazwa[i]!='.'&& i<dlugosc)
    {
        i++;
    }
    if(i!=dlugosc-4)
    {
        return 0;
    }
    if(nazwa[dlugosc-3]=='t'&& nazwa[dlugosc-2]=='x'&& nazwa[dlugosc-1]=='t')
    {
        return 1;
    }
    if(nazwa[dlugosc-3]=='u'&& nazwa[dlugosc-2]=='l'&& nazwa[dlugosc-1]=='a')
    {
        return 2;
    }
    return 0;
}

void zapisDoPlikuTxt(char nazwa[])
{
    printf("TXT\n");
    FILE *file;
    file=fopen(nazwa,"w");
    if(file==NULL)
    {
        printf("Nie mozna otworzyc pliku %s\n",nazwa);
        return;
    }
    fprintf(file,"hurra");
    fclose(file);
}
void zapisDoPlikuBin(char nazwa[])
{
    char haslo[DLUGOSC + 1] = "";
    int sn = 0;
    int c;
    while ((c = getchar()) != EOF  && c!=' '&& sn < DLUGOSC) {
        if (!(sn == 0 && c == '\n')) {
            if (c == '\n') {
                break;
            }
            haslo[sn] =(char)c;
            sn++;
        }
    }
    /*TODO*/
}