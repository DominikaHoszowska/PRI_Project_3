
#ifndef PRI_PROJECT_3_KATALOG_H
#define PRI_PROJECT_3_KATALOG_H

#include <stdbool.h>
#include "Struktury.h"
#include "Samochod.h"

#define DLUGOSC 15

/*Created by Dominika Hoszowska on 17.04.18.*/


void usunCalyKatalog(Katalog* katalog);
void dodajSamochod(Katalog* katalog, BazaSamochodow* bazaSamochodow);
void wprowadzanieNazwy(char nazwa_[]);
bool sprawdzNazwe(char nazwa[], int dlugosc);
void wprowadzaniePrzebiegu(int*);
void wprowadzanieId(int* id,BazaSamochodow* bazaSamochodow);
bool czyUnikalneId(int id, BazaSamochodow* bazaSamochodow);
void wyswietlKatalog(Katalog*);
#endif /*PRI_PROJECT_3_KATALOG_H*/
