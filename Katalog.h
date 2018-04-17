#include "Samochod.h"

/*Created by Dominika Hoszowska on 17.04.18.*/

typedef struct
{
    Samochod samochod_;
    Samochod* nastepny_;
    Samochod* poprzedni_;

}ElListyKatalog;

typedef struct
{
    int dlugosc_;
    ElListyKatalog* pierwszy_;
    ElListyKatalog* ostatni_;
}Katalog;

#ifndef PRI_PROJECT_3_KATALOG_H
#define PRI_PROJECT_3_KATALOG_H

#endif /*PRI_PROJECT_3_KATALOG_H*/
