
#include "Samochod.h"

/*Created by Dominika Hoszowska on 17.04.18.*/

typedef struct
{
    Samochod samochod;
    Samochod* nastepny;
    Samochod* poprzedni;

}ElListyKatalog;

typedef struct
{
    int dlugosc;
    ElListyKatalog* Pierwszy;
}Katalog;

#ifndef PRI_PROJECT_3_KATALOG_H
#define PRI_PROJECT_3_KATALOG_H

#endif /*PRI_PROJECT_3_KATALOG_H*/
