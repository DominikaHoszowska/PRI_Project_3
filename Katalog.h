#include <stdbool.h>
#include "Samochod.h"


#define DLUGOSC 15

/*Created by Dominika Hoszowska on 17.04.18.*/
#ifndef PRI_PROJECT_3_KATALOG_H
#define PRI_PROJECT_3_KATALOG_H
typedef struct
{
    Samochod* samochod_;
    struct ElListyKatalog* nastepny_;
    struct ElListyKatalog* poprzedni_;

}ElListyKatalog;

typedef struct
{
    char nazwa_[DLUGOSC+1];
    int dlugosc_;
    ElListyKatalog* pierwszy_;
    ElListyKatalog* ostatni_;
}Katalog;
void usunCalyKatalog(Katalog* katalog);
void dodajSamochod(Katalog* katalog);
void wprowadzanieNazwy(char nazwa_[]);
bool sprawdzNazwe(char nazwa[], int dlugosc);

#endif /*PRI_PROJECT_3_KATALOG_H*/
