/*Created by Dominika Hoszowska on 17.04.18.*/

#ifndef PRI_PROJECT_3_MENU_H
#define PRI_PROJECT_3_MENU_H


#include <stdbool.h>
#include "BazaSamochodow.h"


void menu(BazaSamochodow* bazaSamochodow);
void tworzenieKatalogu(BazaSamochodow* bazaSamochodow);
void zmianaNazwyKatalogu( BazaSamochodow* bazaSamochodow);
void usuniecieKatalogu(BazaSamochodow* bazaSamochodow);
void dodanieSamochodu(BazaSamochodow* bazaSamochodow);
void edycjaSamochodu(BazaSamochodow* bazaSamochodow);
void przenoszenieSamochodow(BazaSamochodow* bazaSamochodow);
void wyswietlanieSamochodow(BazaSamochodow* bazaSamochodow);
void wyswietlanieListyKatalogow( BazaSamochodow* bazaSamochodow);
void wyswietlanieKatalogu( BazaSamochodow* bazaSamochodow);
void zamykanie(BazaSamochodow* bazaSamochodow);
bool sprawdzKatalog(char nazwa[],int dlugosc);
void usunWszystko(BazaSamochodow* bazaSamochodow);
void sortowanieListyKatalogow(BazaSamochodow* bazaSamochodow);
#endif /*PRI_PROJECT_3_MENU_H*/
