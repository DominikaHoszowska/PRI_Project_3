/*Created by Dominika Hoszowska on 17.04.18.*/
#ifndef PRI_PROJECT_3_MENU_H
#define PRI_PROJECT_3_MENU_H
struct BazaSamochodow;
void menu(struct BazaSamochodow* bazaSamochodow);
void tworzenieKatalogu(struct BazaSamochodow* bazaSamochodow);
void zmianaNazwyKatalogu(struct BazaSamochodow* bazaSamochodow);
void usuniecieKatalogu(struct BazaSamochodow* bazaSamochodow);
void dodanieSamochodu(struct BazaSamochodow* bazaSamochodow);
void edycjaSamochodu(struct BazaSamochodow* bazaSamochodow);
void przenoszenieSamochodow(struct BazaSamochodow* bazaSamochodow);
void wyswietlanieSamochodow(struct BazaSamochodow* bazaSamochodow);
void wyswietlanieListyKatalogow(struct BazaSamochodow* bazaSamochodow);
void wyswietlanieKatalogu(struct BazaSamochodow* bazaSamochodow);
void zamykanie(struct BazaSamochodow* bazaSamochodow);
#endif /*PRI_PROJECT_3_MENU_H*/
