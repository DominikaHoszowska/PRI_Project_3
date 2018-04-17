#include <stdbool.h>
#include <memory.h>
#include <malloc.h>
#include "BazaSamochodow.h"


/*Created by Dominika Hoszowska on 17.04.18.*/

bool czyUnikalnyKatalog(BazaSamochodow* bazaSamochodow, char katalog[])
{
    ElListyBaza* elListyBaza=bazaSamochodow->pierwszy_;
    while (elListyBaza)
    {
        if(!strcmp(elListyBaza->katalog_->nazwa_,katalog))
        {
            return 0;
        }
        elListyBaza=elListyBaza->nastepny_;
    }
    return 1;
}
void stworzKatalog(BazaSamochodow* bazaSamochodow, char nazwa[]) {
    Katalog *katalog = (Katalog *) malloc(sizeof(Katalog));
    strcpy(katalog->nazwa_, nazwa);
    katalog->dlugosc_ = 0;
    katalog->pierwszy_ = NULL;
    katalog->ostatni_ = NULL;
    ElListyBaza *elListyBaza = (ElListyBaza *) malloc(sizeof(ElListyBaza));
    if(bazaSamochodow->dlugosc_) {
        ElListyBaza *ostatni = bazaSamochodow->ostatni_;
        ostatni->nastepny_ = elListyBaza;
        elListyBaza->poprzedni_ = bazaSamochodow->ostatni_;
        bazaSamochodow->dlugosc_++;
    }
    else
    {
        elListyBaza->poprzedni_=NULL;
        bazaSamochodow->pierwszy_=elListyBaza;
        bazaSamochodow->ostatni_=elListyBaza;

    }

    elListyBaza->nastepny_ = NULL;
    bazaSamochodow->ostatni_ = elListyBaza;
    bazaSamochodow->dlugosc_++;

}
