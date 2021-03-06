/*Created by Dominika Hoszowska on 17.04.18.*/

#ifndef PRI_PROJECT_3_MENU_H
#define PRI_PROJECT_3_MENU_H

#include <stdbool.h>
#include "Struktury.h"
#include "BazaSamochodow.h"
#include "ObslugaPlikow.h"
void menu(BazaSamochodow* );
void tworzenieKatalogu(BazaSamochodow* );
void zmianaNazwyKatalogu( BazaSamochodow* );
void usuniecieKatalogu(BazaSamochodow* );
void dodanieSamochodu(BazaSamochodow* );
void edycjaSamochodu(BazaSamochodow* );
void przenoszenieSamochodow(BazaSamochodow* );
void wyswietlanieSamochodow(BazaSamochodow* );
void wyswietlanieListyKatalogow( BazaSamochodow* );
void wyswietlanieKatalogu( BazaSamochodow* );
void wyswietlWszystkieSamochody(BazaSamochodow*);
void wyswietlSamochodyPrzebieg(BazaSamochodow*);
void wyswietlSamochodyId(BazaSamochodow*);
void wyswietlSamochodNazwa(BazaSamochodow*);
int zamykanie(BazaSamochodow* );
bool sprawdzKatalog(char nazwa[],int dlugosc);
void sortowanieListyKatalogow(BazaSamochodow*);
void zapisDoPliku(BazaSamochodow*);
void odczytZPliku(BazaSamochodow*);
#endif /*PRI_PROJECT_3_MENU_H*/
