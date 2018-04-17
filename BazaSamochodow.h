//
// Created by dominika on 17.04.18.
//

#ifndef PRI_PROJECT_3_BAZASAMOCHODOW_H
#define PRI_PROJECT_3_BAZASAMOCHODOW_H

#include "Katalog.h"

typedef struct
{
    Katalog* katalog;
    Katalog* nastepny;
    Katalog* poprzedni;

}ElListyBaza;

typedef struct
{
    int dlugosc;
    ElListyBaza* Pierwszy;
}Baza;
#endif //PRI_PROJECT_3_BAZASAMOCHODOW_H
