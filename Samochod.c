#include <stdio.h>
#include <memory.h>
#include "Samochod.h"

/*Created by Dominika Hoszowska on 17.04.18.*/
void wprowadzanieNazwy(char nazwa_[]) {
    printf("Podaj nazwe samochodu\n");
    char nazwa[DLUGOSC + 1] = "";
    int sn = 0;
    int c;
    while ((c = getchar()) != EOF && sn < DLUGOSC) {
        if (!(sn == 0 && c == '\n')) {
            if (c == '\n') {
                break;
            }

            nazwa[sn] =(char)c;
            sn++;

    }}
    nazwa[sn]='\000';
    if (!sprawdzNazwe(nazwa, sn)) {
        printf("Bledna nazwa\n");
        return wprowadzanieNazwy(nazwa_);
    }
    else {

        strncpy(nazwa_, nazwa, DLUGOSC + 1);
    }
}

bool sprawdzNazwe(char nazwa[], int dlugosc) {
    bool spr = 1;
    if ((nazwa[0] >= 'A' && nazwa[0] <= 'Z' )|| (nazwa[0]>='a' && nazwa[0]<='z')){
        if(nazwa[0]>='a' && nazwa[0]<='z')
        {
            nazwa[0]-=('a'-'A');

        }
        int i = 1;
        for (; i < dlugosc; i++) {
            if (!((nazwa[i] >= 'A' && nazwa[i] <= 'Z') || (nazwa[i] >= 'a' && nazwa[i] <= 'z') ||
                  (nazwa[i] >= '0' && nazwa[i] <= '9')||nazwa[i]==' ')) {
                spr = 0;
            }
            else {
                if ((((nazwa[i - 1] >= 'A' && nazwa[i - 1] <= 'Z') || (nazwa[i - 1] >= 'a' && nazwa[i - 1] <= 'z')) &&
                     nazwa[i] >= '0' && nazwa[i] <= '9') ||
                    (((nazwa[i] >= 'A' && nazwa[i] <= 'Z') || (nazwa[i] >= 'a' && nazwa[i] <= 'z')) &&
                     nazwa[i - 1] >= '0' && nazwa[i - 1] <= '9')) {
                    spr = 0;
                }
            }
        }
    }
    else {
        spr = 0;
    }
    return spr;
}
void wprowadzaniePrzebiegu(int *przebieg_) {
    float n;
    printf("Wprowadz przebieg\n");

    while (!scanf("%f", &n) || n < 1 || n - (int) n != 0 || n > 999999) {
        printf("Podaj prawidlową liczbe\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

    }
    *przebieg_ = (int) n;
}

void wprowadzanieId(int* id,BazaSamochodow* bazaSamochodow) {
    float n;
    printf("Wprowadz Id\n");

    while (!scanf("%f", &n) || n < 1 || n - (int) n != 0 || n > 99999) {
        printf("Podaj dodatnia liczbe calkowita!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    if (!(czyUnikalneId((int) n,bazaSamochodow))) {
        printf("Ten numer nie jest unikalny.\n");
        wprowadzanieId(id, bazaSamochodow);
    }
    else
    {
        *id=(int)n;
    }

}
void wyswietlSamochod(Samochod* samochod)
{

    printf("|%-15s|",samochod->nazwa_);
    wypiszId(samochod->id_);
    printf("%-5d\n%-15s",samochod->przebieg_," ");
}
void wypiszId(int id)
{
    if(id<10)
    {
        printf("0000%-1d|",id);
        return;
    }
    if(id<100)
    {
        printf("000%-2d|",id);
        return;
    }
    if(id<1000)
    {
        printf("00%-3d|",id);
        return;
    }
    if(id<10000)
    {
        printf("0%-4d|",id);
        return;
    }
    printf("%-5d|",id);

}
void edycjaSamochoduS(Samochod* samochod,BazaSamochodow* bazaSamochodow)
{
    printf("Co chcesz zmienic?\n"
                   "1-Nazwa\n"
                   "2-Przebieg\n"
                   "3-Id\n"
                   "4-Powrot do menu\n");
    float n;

    while (!scanf("%f", &n) || n < 1 || n > 4 || n - (int) n != 0) {
        printf("Podaj dodatnia liczbe calkowita z przedzialu 1-4!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    switch ((int) n) {
        case 1:
            wprowadzanieNazwy(samochod->nazwa_);
            break;

        case 2:
            wprowadzaniePrzebiegu(&samochod->przebieg_);
            break;

        case 3:
            wprowadzanieId(&samochod->id_,bazaSamochodow);
            break;

        case 4:
            break;
    }

}
