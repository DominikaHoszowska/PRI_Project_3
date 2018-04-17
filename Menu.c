/*Created by Dominika Hoszowska on 17.04.18.*/
#include <stdio.h>
#include"Menu.h"
void menu(BazaSamochodow* bazaSamochodow)
{
    printf("Menu:\n"
                   "1.Tworzenie nowego katalogu\n"
                   "2.Zmiana nazwy wybranego katalogu\n"
                   "3.Usuniecie katalogu\n"
                   "4.Dodanie samochodu\n"
                   "5.Edycja samochodu\n"
                   "6.Przenoszenie samochochodu miedzy katalogami\n"
                   "7.Wyświetlanie samochodów\n"
                   "8.Wyświetkanie listy katalogów\n"
                   "9.Wyświetlanie zawartosci wybranego katalogu\n"
                   "10.Wyjscie z programu\n");
    float n;
    while (!scanf("%f", &n) || n < 1 || n > 10 || n - (int) n != 0) {
        printf("Podaj dodatnia liczbe calkowita z przedzialu 1-10!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    switch ((int) n) {
        case 1:
            tworzenieKatalogu(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 2:
            zmianaNazwyKatalogu(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 3:
            usuniecieKatalogu(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 4:
            dodanieSamochodu(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 5:
            edycjaSamochodu(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 6:
            przenoszenieSamochodow(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 7:
            wyswietlanieSamochodow(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 8:
            wyswietlanieListyKatalogow(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 9:
            wyswietlanieKatalogu(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 10:
            zamykanie(bazaSamochodow);
            break;
    }
}
void tworzenieKatalogu(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
void zmianaNazwyKatalogu(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
void usuniecieKatalogu(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
void dodanieSamochodu(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
void edycjaSamochodu(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
void przenoszenieSamochodow(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
void wyswietlanieSamochodow(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
void wyswietlanieListyKatalogow(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
void wyswietlanieKatalogu(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
void zamykanie( BazaSamochodow* bazaSamochodow)
{
    printf("Czy na pewno chcesz opuscic program?\n"
                   "Jezeli tak wcisnij 1, a jezeli nie wcisnij 0\n");
    char znak;
    while ((!scanf("%c", &znak)) || znak > '1' || znak < '0') {
        if (znak != '\n') { printf("Wprowadz odpowiedni znak\n"); }
    }
    if (znak == '1') {
        return;
    }
    menu(bazaSamochodow);
}

