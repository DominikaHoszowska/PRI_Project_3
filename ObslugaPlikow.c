/*Created by Dominika Hoszowska on 17.04.18.*/
#include "ObslugaPlikow.h"
#include "Struktury.h"

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

void zapisDoPlikuTxt(char nazwa[],BazaSamochodow* bazaSamochodow)
{
    FILE *file;
    file=fopen(nazwa,"w");
    if(file==NULL)
    {
        printf("Nie mozna otworzyc pliku %s\n",nazwa);
        return;
    }
    sortowanieListyKatalogow(bazaSamochodow);
    ElListyBaza* katalog=bazaSamochodow->pierwszy_;
    while(katalog)
    {
        sortujKatalog(katalog->katalog_);
        ElListyKatalog* samochod=katalog->katalog_->pierwszy_;
        while(samochod)
        {
            wypiszSamochod(file,samochod->samochod_);
            samochod=samochod->nastepny_;
        }
        katalog=katalog->nastepny_;
    }
    fclose(file);
}
void zapisDoPlikuBin(char nazwa[],BazaSamochodow* bazaSamochodow)
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
void wypiszSamochod(FILE* file,Samochod* samochod)
{
    fprintf(file,"%s ",samochod->nazwa_);
    wypiszIdF(file,samochod->id_);
    fprintf(file," %d %s\n",samochod->przebieg_,samochod->dzial_->nazwa_);
}
void wypiszIdF(FILE* file,int id)
{
    if(id<10)
    {
        fprintf(file,"0000%-1d",id);
        return;
    }
    if(id<100)
    {
        fprintf(file,"000%-2d",id);
        return;
    }
    if(id<1000)
    {
        fprintf(file,"00%-3d",id);
        return;
    }
    if(id<10000)
    {
        fprintf(file,"0%-4d",id);
        return;
    }
    fprintf(file,"%-5d",id);

}