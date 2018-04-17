#include "Panstwo.h"

/*Created by Dominika Hoszowska on 17.04.18.*/


typedef struct
{
    Panstwo panstwo;
    Panstwo* nastepny;
    Panstwo* poprzedni;

}ElListyPanstwa;

typedef struct
{
    int dlugosc;
    ElListyPanstwa* Pierwszy;
}Katalog;
#ifndef PRI_PROJECT_3_KATALOG_H
#define PRI_PROJECT_3_KATALOG_H

#endif //PRI_PROJECT_3_KATALOG_H
