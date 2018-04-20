
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

}
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

            nazwa[sn] = c;
            sn++;
        }
    }
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
    if (nazwa[0] >= 'A' && nazwa[0] <= 'Z') {

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
