/*Created by Dominika Hoszowska on 17.04.18.*/
#include "Samochod.h"

#define DLUGOSC 15
typedef struct
{
    Samochod samochod;
    Samochod* nastepny;
    Samochod* poprzedni;
}ElListySamochody;
typedef struct
{
    char nazwa[DLUGOSC+1];
    ElListySamochody* pierwszy;
    int dlugosc;

}Panstwo;

#ifndef PRI_PROJECT_3_PANSTWO_H
#define PRI_PROJECT_3_PANSTWO_H

#endif //PRI_PROJECT_3_PANSTWO_H
