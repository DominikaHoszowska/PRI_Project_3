/*Created by Dominika Hoszowska on 17.04.18.*/

#ifndef PRI_PROJECT_3_OBSLUGAPLIKOW_H
#define PRI_PROJECT_3_OBSLUGAPLIKOW_H

#include <stdio.h>
#include "BazaSamochodow.h"

int sprawdzNazwePilku(char nazwa[], int dlugosc);/* 0-bledna nazwa, 1- txt 0-bin*/
void zapisDoPlikuTxt(char nazwa[],BazaSamochodow*);
void wypiszSamochod(FILE*,Samochod*);
void zapisDoPlikuBin(char nazwa[],BazaSamochodow*);
void wypiszSamochodB(FILE*,Samochod*);
void wypiszIdF(FILE* file,int id);
void odczytZPlikuT(char[],BazaSamochodow*);
void odczytZPlikuBin(char[],BazaSamochodow*);
int rozmiar(char[]);
void dodajSamochodf(BazaSamochodow* bazaSamochodow,char napis[],int rozmiar);
int zamienNaLiczbe(char liczba[],int rozmiar);
#endif /*PRI_PROJECT_3_OBSLUGAPLIKOW_H*/
