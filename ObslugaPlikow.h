/*Created by Dominika Hoszowska on 17.04.18.*/

#ifndef PRI_PROJECT_3_OBSLUGAPLIKOW_H
#define PRI_PROJECT_3_OBSLUGAPLIKOW_H

#include <stdio.h>
#include "BazaSamochodow.h"

int sprawdzNazwePilku(char nazwa[], int dlugosc);/* 0-bledna nazwa, 1- txt 0-bin*/
void zapisDoPlikuTxt(char nazwa[],BazaSamochodow*);
void wypiszSamochod(FILE*,Samochod*);
void zapisDoPlikuBin(char nazwa[],BazaSamochodow*);
void wypiszIdF(FILE* file,int id);

#endif /*PRI_PROJECT_3_OBSLUGAPLIKOW_H*/
