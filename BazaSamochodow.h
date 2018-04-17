
/*Created by Dominika Hoszowska on 17.04.18.*/



#ifndef PRI_PROJECT_3_BAZASAMOCHODOW_H
#define PRI_PROJECT_3_BAZASAMOCHODOW_H


#include "Katalog.h"

typedef struct
{
    Katalog* katalog_;
    struct ElListyBaza* nastepny_;
    struct ElListyBaza* poprzedni_;

}ElListyBaza;

typedef struct
{
    int dlugosc_;
    struct ElListyBaza* pierwszy_;
    struct ElListyBaza* ostatni_;
}BazaSamochodow;

bool czyUnikalnyKatalog(BazaSamochodow* bazaSamochodow,char katalog[]);
void stworzKatalog(BazaSamochodow* bazaSamochodow, char nazwa[]);
#endif /*PRI_PROJECT_3_BAZASAMOCHODOW_H*/
