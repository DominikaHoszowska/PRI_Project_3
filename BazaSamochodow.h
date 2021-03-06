
/*Created by Dominika Hoszowska on 17.04.18.*/



#ifndef PRI_PROJECT_3_BAZASAMOCHODOW_H
#define PRI_PROJECT_3_BAZASAMOCHODOW_H


#include "Struktury.h"
#include "Katalog.h"
#include "Menu.h"
bool czyUnikalnyKatalog(BazaSamochodow* bazaSamochodow, char katalog[]);
void stworzKatalog(BazaSamochodow* bazaSamochodow, char nazwa[]);
void zmianaNazwyKatalogu2(BazaSamochodow* bazaSamochodow,int nrElementu);
void zminaNazwyKatalogu(BazaSamochodow* bazaSamochodow,Katalog* katalog);
void usunWszystko(BazaSamochodow* bazaSamochodow);
void usuniecieKatalogu2(BazaSamochodow* bazaSamochodow,int nrElementu);
Katalog* zwrocNtyKatalog(BazaSamochodow* bazaSamochodow, int nrElementu);
void wyswietlSamochodyPrzebieg2(BazaSamochodow* bazaSamochodow,int przebieg);
void wyswietlSamochody(Katalog*);
void wyswietlSamochodyNazwa2(BazaSamochodow* bazaSamochodow, char nazwa[]);
void wyswietlSamochodyID2(BazaSamochodow*,int);
bool czyIstniejeKatalog(BazaSamochodow* bazaSamochodow,char nazwa[],int dlugosc);
void stworzSamochod(BazaSamochodow*,char[],char[],int,int);
Katalog* zwrocKatalog(BazaSamochodow*,char[]);
#endif /*PRI_PROJECT_3_BAZASAMOCHODOW_H*/
