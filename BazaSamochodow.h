
/*Created by Dominika Hoszowska on 17.04.18.*/



#ifndef PRI_PROJECT_3_BAZASAMOCHODOW_H
#define PRI_PROJECT_3_BAZASAMOCHODOW_H


#include "Katalog.h"

typedef struct
{
    Katalog* katalog_;
    Katalog* nastepny_;
    Katalog* poprzedni_;

}ElListyBaza;

typedef struct
{
    int dlugosc_;
    ElListyBaza* pierwszy_;
    ElListyBaza* ostatni;
}BazaSamochodow;
#endif /*PRI_PROJECT_3_BAZASAMOCHODOW_H*/
