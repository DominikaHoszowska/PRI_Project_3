
/*Created by Dominika Hoszowska on 17.04.18.*/



#ifndef PRI_PROJECT_3_BAZASAMOCHODOW_H
#define PRI_PROJECT_3_BAZASAMOCHODOW_H


#include "Katalog.h"
struct ElListyBaza_t
{
    Katalog* katalog_;
    struct ElListyBaza_t* nastepny_;
    struct ElListyBaza_t* poprzedni_;

};

typedef struct ElListyBaza_t ElListyBaza;

typedef struct
{
    int dlugosc_;
    ElListyBaza* pierwszy_;
    ElListyBaza* ostatni_;
}BazaSamochodow;

bool czyUnikalnyKatalog(BazaSamochodow* bazaSamochodow,char katalog[]);
void stworzKatalog(BazaSamochodow* bazaSamochodow, char nazwa[]);
void zmianaNazwyKatalogu2(BazaSamochodow* bazaSamochodow,int nrElementu);
void zminaNazwyKatalogu(BazaSamochodow* bazaSamochodow,Katalog* katalog);
void usunWszystko(BazaSamochodow* bazaSamochodow);

#endif /*PRI_PROJECT_3_BAZASAMOCHODOW_H*/
