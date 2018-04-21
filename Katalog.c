
#include <malloc.h>
#include <memory.h>
#include "Katalog.h"
#include "Struktury.h"

/*Created by Dominika Hoszowska on 17.04.18.*/

void usunCalyKatalog(Katalog* katalog)
{
    /*TODO*/
}
void dodajSamochod(Katalog* katalog,BazaSamochodow* bazaSamochodow)
{


    Samochod* samochod=(Samochod*) malloc(sizeof(Samochod));
    wprowadzanieNazwy(samochod->nazwa_);
    wprowadzaniePrzebiegu(&samochod->przebieg_);
    wprowadzanieId(&samochod->id_,bazaSamochodow);
    samochod->dzial_=katalog;
    ElListyKatalog* element=(ElListyKatalog*)malloc(sizeof(ElListyKatalog));
    element->samochod_=samochod;
    element->nastepny_=NULL;
    if(!katalog->dlugosc_)
    {
        element->poprzedni_=NULL;
        katalog->pierwszy_=element;

    }
    else
    {
        element->poprzedni_=katalog->ostatni_;
        katalog->ostatni_->nastepny_=element;
        katalog->ostatni_=element;
    }
    katalog->ostatni_=element;
    katalog->dlugosc_++;
    bazaSamochodow->iloscSamochodow_++;

}

bool czyUnikalneId(int id, BazaSamochodow* bazaSamochodow) {

    ElListyBaza* katalog=bazaSamochodow->pierwszy_;
    while(katalog)
    {
        ElListyKatalog* samochod=katalog->katalog_->pierwszy_;
        while (samochod)
        {
            if(samochod->samochod_->id_==id)
            {
                return 0;
            }
            samochod=samochod->nastepny_;
        }
        katalog=katalog->nastepny_;
    }

    return 1;

}
void wyswietlKatalog(Katalog* katalog)
{
    sortujKatalog(katalog);
    printf("%-15s", katalog->nazwa_);
    ElListyKatalog* samochod=katalog->pierwszy_;
    while(samochod)
    {
        wyswietlSamochod(samochod->samochod_);
        samochod=samochod->nastepny_;
    }
}
void edycjaSamochoduK(Katalog* katalog,BazaSamochodow* bazaSamochodow)
{
    printf("Ktory samochod chcesz zmienic?\n");
    Samochod* samochod=wyborSamochodu(katalog);
    edycjaSamochoduS(samochod,bazaSamochodow);
}
Samochod* zwrocNtySamochod(Katalog* katalog,int n)
{
    int i;
    ElListyKatalog* elem=katalog->pierwszy_;
    for(i=1;i<n;i++)
    {
        elem=elem->nastepny_;
    }
    return elem->samochod_;
}
Samochod* wyborSamochodu(Katalog* katalog)
{
    ElListyKatalog* samochodE=katalog->pierwszy_;
    int i=1;
    while (samochodE)
    {
        printf("%d.",i);
        printf("%-15s|",samochodE->samochod_->nazwa_);
        wypiszId(samochodE->samochod_->id_);
        printf("%-5d\n",samochodE->samochod_->przebieg_);
        samochodE=samochodE->nastepny_;
        i++;
    }
    float n;
    while (!scanf("%f", &n) || n < 1 || n > i-1|| n - (int) n != 0) {
        if (n != '\n') {
            printf("Podaj dodatnia liczbe calkowita z przedzialu 1-%d!\n", i-1);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
    return zwrocNtySamochod(katalog,(int)n);
}
void przeniesSamochod(Samochod*samochod,Katalog* katalog1,Katalog* katalog2 )
{
    ElListyKatalog* elem=katalog1->pierwszy_;
    while(elem->samochod_!=samochod)
    {
        elem=elem->nastepny_;
    }
    if(elem->poprzedni_)
    elem->poprzedni_->nastepny_=elem->nastepny_;
    else
    {
        katalog1->pierwszy_=elem->nastepny_;
    }
    if(elem->nastepny_)
    elem->nastepny_->poprzedni_=elem->poprzedni_;
    else
    {
        katalog1->ostatni_=elem->poprzedni_;
    }
    elem->poprzedni_=katalog2->ostatni_;
    if(katalog2->ostatni_)
    katalog2->ostatni_->nastepny_=elem;
    else{
        katalog2->pierwszy_=elem;
    }
    elem->nastepny_=NULL;
    katalog2->ostatni_=elem;
    elem->samochod_->dzial_=katalog2;
    katalog1->dlugosc_--;
    katalog2->dlugosc_++;

}
void sortujKatalog(Katalog*katalog)
{
    ElListyKatalog* elem;
    ElListyKatalog* elemNast;
    int i,j;
    bool zamiana;
    for(i=0;i<katalog->dlugosc_;i++)
    {
        zamiana=0;
        elem=katalog->pierwszy_;
        elemNast=elem->nastepny_;
        for(j=0;j<katalog->dlugosc_-1;j++)
        {
            if(strcmp(elem->samochod_->nazwa_,elemNast->samochod_->nazwa_)>0)
            {
                zamiana=1;
                Samochod* pomoc;
                pomoc=elem->samochod_;
                elem->samochod_=elemNast->samochod_;
                elemNast->samochod_=pomoc;
            }
            elem=elem->nastepny_;
            elemNast=elemNast->nastepny_;
        }
        if(!zamiana)
        {
            i=katalog->dlugosc_;
        }
    }

}