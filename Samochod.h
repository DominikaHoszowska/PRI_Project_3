/*Created by Dominika Hoszowska on 17.04.18.*/

#include "Panstwo.h"

#define DLUGOSC 15

#ifndef PRI_PROJECT_3_SAMOCHOD_H
#define PRI_PROJECT_3_SAMOCHOD_H
typedef struct
{
    char nazwa_[DLUGOSC+1];
    int przebieg_;
    int id_;
    Panstwo* dzial;
} Samochod;
#endif //PRI_PROJECT_3_SAMOCHOD_H
