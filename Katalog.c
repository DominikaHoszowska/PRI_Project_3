
#include <malloc.h>
#include <memory.h>
#include "Katalog.h"

/*Created by Dominika Hoszowska on 17.04.18.*/

void usunCalyKatalog(Katalog* katalog)
{
    /*TODO*/
}
void dodajSamochod(Katalog* katalog)
{
    if(katalog->dlugosc_)
    {
        Samochod* samochod=(Samochod*) malloc(sizeof(Samochod));
        wprowadzanieNazwy(samochod->nazwa_);
        ElListyKatalog* element=(ElListyKatalog*)malloc(sizeof(ElListyKatalog));
        element->samochod_=samochod;
        
    }

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

