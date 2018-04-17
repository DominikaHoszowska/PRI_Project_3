#include <stdbool.h>
#include "Samochod.h"


#define DLUGOSC 15

/*Created by Dominika Hoszowska on 17.04.18.*/

typedef struct
{
    Samochod samochod_;
    Samochod* nastepny_;
    Samochod* poprzedni_;

}ElListyKatalog;

typedef struct
{
    char nazwa_[DLUGOSC+1];
    int dlugosc_;
    ElListyKatalog* pierwszy_;
    ElListyKatalog* ostatni_;
}Katalog;
void usunCalyKatalog(Katalog* katalog);
#ifndef PRI_PROJECT_3_KATALOG_H
#define PRI_PROJECT_3_KATALOG_H
#endif /*PRI_PROJECT_3_KATALOG_H*/
