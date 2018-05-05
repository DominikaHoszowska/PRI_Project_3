/*Created by Dominika Hoszowska on 17.04.18.*/

#ifndef PRI_PROJECT_3_OBSLUGAPLIKOW_H
#define PRI_PROJECT_3_OBSLUGAPLIKOW_H

#include <stdio.h>
#include "BazaSamochodow.h"

int sprawdzNazwePilku(char nazwa[], int dlugosc);/* 0-bledna nazwa, 1- txt 0-bin*/
void zapisDoPlikuTxt(char nazwa[],BazaSamochodow*);
void wypiszSamochod(FILE*,Samochod*);
void zapisDoPlikuBin(char nazwa[],BazaSamochodow*);
void wypiszSamochodB(FILE *file, Samochod *samochod, char haslo[], int rozmiarHasla) ;
void wypiszIdF(FILE* file,int id);
void szyfruj(char wynik[],char dane[], int rozmiar, char haslo[], int rozmiarhasla);
int zwrocRozmiar(char nazwa[]);
int ustawHaslo(char haslop[]);
void odczytZPlikuT(char[],BazaSamochodow*);
void odczytZPlikuBin(char[],BazaSamochodow*);
int rozmiar(char[]);
void dodajSamochodf(BazaSamochodow* bazaSamochodow,char napis[],int rozmiar);
int zamienNaLiczbe(char liczba[],int rozmiar);
int odczytajhaslo(char tekst[],char haslo[]);
bool wczytajhaslo(char haslo[],int rozmiarhasla);
#endif /*PRI_PROJECT_3_OBSLUGAPLIKOW_H*/
