/*Created by Dominika Hoszowska on 17.04.18.*/
#ifndef PRI_PROJECT_3_SAMOCHOD_H
#define PRI_PROJECT_3_SAMOCHOD_H
#include <stdbool.h>
#include "Struktury.h"
#include "Katalog.h"
#define DLUGOSC 15

void wprowadzanieNazwy(char nazwa_[]);
bool sprawdzNazwe(char nazwa[], int dlugosc);
void wprowadzaniePrzebiegu(int*);
void wprowadzanieId(int* id,BazaSamochodow* bazaSamochodow);
void wyswietlSamochod(Samochod*);
void wypiszId(int );
void edycjaSamochoduS(Samochod*,BazaSamochodow*);
void przeniesSamochod(Samochod*,Katalog*);


#endif /*PRI_PROJECT_3_SAMOCHOD_H*/
