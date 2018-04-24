/*Created by Dominika Hoszowska on 17.04.18.*/
#include <memory.h>
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
    FILE *file;
    file=fopen(nazwa,"wb");
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
            wypiszSamochodB(file,samochod->samochod_);
            samochod=samochod->nastepny_;
        }
        katalog=katalog->nastepny_;
    }
    fclose(file);
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
void wypiszSamochodB(FILE* file,Samochod* samochod)
{
    fwrite(samochod->nazwa_, sizeof(char), sizeof(samochod->nazwa_),file);
    fwrite(&samochod->id_, sizeof(int), 1,file);
    fwrite(&samochod->przebieg_, sizeof(int), 1,file);
    fwrite(samochod->dzial_->nazwa_, sizeof(char), sizeof(samochod->dzial_->nazwa_),file);
    fprintf(file,"\n");
}
void odczytZPlikuT(char nazwa[],BazaSamochodow* bazaSamochodow)
{
    FILE *file;
    file=fopen(nazwa,"r");
    if(file==NULL)
    {
        printf("Nie mozna otworzyc pliku %s\n",nazwa);
        return;
    }
    char samochod[4*DLUGOSC];
    char* wynik;
    while (!feof(file))
    {
        wynik="";
        wynik=fgets(samochod,4*DLUGOSC,file);
        int r=rozmiar(samochod);
        dodajSamochodf(bazaSamochodow,samochod,r);
    }
    fclose(file);


}
void odczytZPlikuBin(char nazwa[],BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
int rozmiar(char napis[])
{
    int r=0;
    while(napis[r]!='\n')
    {
        r++;
    }
    return r+1;
}
void dodajSamochodf(BazaSamochodow* bazaSamochodow,char napis[],int rozmiar)
{
    int i=rozmiar-1;
    napis[i]='\000';
    while(napis[i]!=32)
    {
        i--;
    }
    int dlugoscKat=rozmiar-i-2;
    if(dlugoscKat>DLUGOSC)
    {
        return;
    }
    char katalog[DLUGOSC+1];
    strcpy(katalog,&napis[i+1]);
    int j;
    for (j=rozmiar-1;j>i;j--)
    {
        napis[j]='\000';
    }
    i--;
    while (napis[i]!=32)
    {
        i--;
    }
    int przebieg=zamienNaLiczbe(&napis[i+1],j-i-1);
    if(przebieg<0)
    {
        return;
    }
    for(;j>i;j--)
    {
        napis[j]='\000';
    }
    i--;
    while (napis[i]!=32)
    {
        i--;
    }
    int id=zamienNaLiczbe(&napis[i+1],j-i-1);
    if(id<0 || !czyUnikalneId(id,bazaSamochodow))
    {
        return;
    }
    for(;j>=i;j--)
    {
        napis[j]='\000';
    }
    if(!sprawdzNazwe(napis,i))
    {
        return;
    }
    if(!czyIstniejeKatalog(bazaSamochodow,&katalog,rozmiar))
    stworzKatalog(bazaSamochodow,katalog);
    stworzSamochod(bazaSamochodow,katalog,napis,id,przebieg);
}
int zamienNaLiczbe(char liczba[],int rozmiar)
{
    int wynik=0;
    int d=1;
    rozmiar--;
    for(;rozmiar>=0;rozmiar--)
    {
        if(liczba[rozmiar]<'0'||liczba[rozmiar]>'9')
        {
            return -1;
        }
        wynik+=(liczba[rozmiar]-'0')*d;
        d*=10;
    }
    return wynik;
}