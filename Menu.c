/*Created by Dominika Hoszowska on 17.04.18.*/
#include <stdio.h>
#include <memory.h>
#include "Menu.h"
#include "Struktury.h"

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
                   "10.Zapis do pliku tekstowego\n"
                   "11.Odczyt z pliku tekstowego\n"
                   "12.Zapis do pliku binarnego\n"
                   "13.Odczyt z pliku binarnego\n"
                   "14.Wyjscie z programu\n");
    float n;
    while (!scanf("%f", &n) || n < 1 || n > 14 || n - (int) n != 0) {
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
            zapisDoPliku(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 11:
            odczytZPliku(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 12:
            zapisDoPlikuBin(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 13:
            odczytZPlikuBin(bazaSamochodow);
            menu(bazaSamochodow);
            break;
        case 14:
            zamykanie(bazaSamochodow);
            break;
    }
}
void tworzenieKatalogu(BazaSamochodow* bazaSamochodow)
{
    printf("Podaj nazwe katalogu\n");
    char katalog[DLUGOSC + 1] = "";
    int sn = 0;
    int c;
    while ((c = getchar()) != EOF && sn < DLUGOSC) {
        if (!(sn == 0 && c == '\n')) {
            if (c == '\n') {
                break;
            }
            katalog[sn] = c;
            sn++;
        }
    }
    if(!sprawdzKatalog(katalog,sn))
    {
        printf("Bledna nazwa\n");
        tworzenieKatalogu(bazaSamochodow);
    }
    else
    {
        if(!czyUnikalnyKatalog(bazaSamochodow,katalog))
        {
            printf("Nazwa nie jest unikalna\n");
            tworzenieKatalogu(bazaSamochodow);
        }
        else
        {
            stworzKatalog(bazaSamochodow,katalog);
        }}


}
bool sprawdzKatalog(char nazwa[],int dlugosc)
{
    bool spr = 1;
    if (nazwa[0] >= 'A' && nazwa[0] <= 'Z') {

        int i = 1;
        for (; i < dlugosc; i++) {
            if (!(nazwa[i] >= 'a' && nazwa[i] <= 'z')) {
                spr = 0;
            }
        }
    } else {
        spr = 0;
    }
    return spr;
}

void zmianaNazwyKatalogu(BazaSamochodow* bazaSamochodow)
{
    if(bazaSamochodow->dlugosc_)
    {
        printf("Ktora nazwe chcesz zmienic?\n");
        wyswietlanieListyKatalogow(bazaSamochodow);
        printf("%d.Powrot do menu\n",bazaSamochodow->dlugosc_+1);
        float n;

        while (!scanf("%f", &n) || n < 1 || n > bazaSamochodow->dlugosc_+1 || n - (int) n != 0) {
            if (n != '\n') {
                printf("Podaj dodatnia liczbe calkowita z przedzialu 1-%d!\n", bazaSamochodow->dlugosc_+1);
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
        if(n!=bazaSamochodow->dlugosc_+1)
        {
            zmianaNazwyKatalogu2(bazaSamochodow,n);
        }
    }
    else
    {
        printf("Baza jest pusta\n");
    }


}
void usuniecieKatalogu(BazaSamochodow* bazaSamochodow)
{
    if(bazaSamochodow->dlugosc_) {
        printf("Ktory katalog chcesz usunac?\n");
        wyswietlanieListyKatalogow(bazaSamochodow);
        printf("%d.Powrot do menu\n", bazaSamochodow->dlugosc_ + 1);
        float n;

        while (!scanf("%f", &n) || n < 1 || n > bazaSamochodow->dlugosc_ + 1 || n - (int) n != 0) {
            if (n != '\n') {
                printf("Podaj dodatnia liczbe calkowita z przedzialu 1-%d!\n", bazaSamochodow->dlugosc_ + 1);
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
        if(n!=bazaSamochodow->dlugosc_+1)
        {
            usuniecieKatalogu2(bazaSamochodow,n);
        }

    }
    else
    {
        printf("Baza jest pusta\n");
    }
}
void dodanieSamochodu(BazaSamochodow* bazaSamochodow)
{
    if(bazaSamochodow->dlugosc_)
    {
        printf("Do którego katalogu chcesz dodac samochod?\n");
        wyswietlanieListyKatalogow(bazaSamochodow);
        printf("%d.Powrot do menu\n",bazaSamochodow->dlugosc_+1);
        float n;

        while (!scanf("%f", &n) || n < 1 || n > bazaSamochodow->dlugosc_+1 || n - (int) n != 0) {
            if (n != '\n') {
                printf("Podaj dodatnia liczbe calkowita z przedzialu 1-%d!\n", bazaSamochodow->dlugosc_+1);
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
        if(n!=bazaSamochodow->dlugosc_+1)
        {
            Katalog* katalog=zwrocNtyKatalog(bazaSamochodow,n);
            dodajSamochod(katalog,bazaSamochodow);

        }
    }
    else
    {
        printf("Baza jest pusta. Musisz najpierw dodac katalog\n");
    }}
void edycjaSamochodu(BazaSamochodow* bazaSamochodow)
{
    if(bazaSamochodow->dlugosc_)
    {
        printf("Z którego katalogu chcesz zmienić samochod?\n");
        wyswietlanieListyKatalogow(bazaSamochodow);
        printf("%d.Powrot do menu\n",bazaSamochodow->dlugosc_+1);
        float n;

        while (!scanf("%f", &n) || n < 1 || n > bazaSamochodow->dlugosc_+1 || n - (int) n != 0) {
            if (n != '\n') {
                printf("Podaj dodatnia liczbe calkowita z przedzialu 1-%d!\n", bazaSamochodow->dlugosc_+1);
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
        if(n!=bazaSamochodow->dlugosc_+1)
        {
            Katalog* katalog=zwrocNtyKatalog(bazaSamochodow,(int)n);
            edycjaSamochoduK(katalog,bazaSamochodow);
        }
    }
    else
    {
        printf("Baza jest pusta. Musisz najpierw dodac katalog i samochody\n");
    }}
void przenoszenieSamochodow(BazaSamochodow* bazaSamochodow)
{
    if(bazaSamochodow->dlugosc_)
    {
        printf("Z którego katalogu chcesz przeniesc samochod?\n");
        wyswietlanieListyKatalogow(bazaSamochodow);
        float n;

        while (!scanf("%f", &n) || n < 1 || n > bazaSamochodow->dlugosc_ || n - (int) n != 0) {
            if (n != '\n') {
                printf("Podaj dodatnia liczbe calkowita z przedzialu 1-%d!\n", bazaSamochodow->dlugosc_);
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }

            Katalog* katalog1=zwrocNtyKatalog(bazaSamochodow,(int)n);
        printf("Ktory samochod chcesz przeniesc\n");

        Samochod* samochod=wyborSamochodu(katalog1);
        printf("Do którego katalogu chcesz przeniesc samochod?\n");
        wyswietlanieListyKatalogow(bazaSamochodow);

        while (!scanf("%f", &n) || n < 1 || n > bazaSamochodow->dlugosc_ || n - (int) n != 0) {
            if (n != '\n') {
                printf("Podaj dodatnia liczbe calkowita z przedzialu 1-%d!\n", bazaSamochodow->dlugosc_);
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
        Katalog* katalog2=zwrocNtyKatalog(bazaSamochodow,(int)n);
        przeniesSamochod(samochod,katalog1,katalog2);

    }
    else
    {
        printf("Baza jest pusta. Musisz najpierw dodac katalog i samochody\n");
    }
}
void wyswietlanieSamochodow(BazaSamochodow* bazaSamochodow)
{
    printf("1.Wyswietl wszystkie samochody\n"
            "2.Wyswietl samochody z zadanym przebiegiem\n"
            "3.Wyswietl samochod z zadanym Id\n"
            "4.Wyswietl samochody z wybranego katalogu\n"
            "5.Wyswiet samochodu w zadanej nazwie\n"
            "6.Powrot do menu\n");
    float n;
    while (!scanf("%f", &n) || n < 1 || n > 14 || n - (int) n != 0) {
        printf("Podaj dodatnia liczbe calkowita z przedzialu 1-10!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    switch ((int) n) {
        case 1:
           wyswietlWszystkieSamochody(bazaSamochodow);
            break;
        case 2:
            wyswietlSamochodyPrzebieg(bazaSamochodow);
            break;
        case 3:
            wyswietlSamochodyId(bazaSamochodow);
            break;
        case 4:
            wyswietlanieKatalogu(bazaSamochodow);
            break;
        case 5:
            wyswietlSamochodNazwa(bazaSamochodow);
            break;
        case 6:
            menu(bazaSamochodow);
            break;

    }


}
void wyswietlanieListyKatalogow(BazaSamochodow* bazaSamochodow)
{
    sortowanieListyKatalogow(bazaSamochodow);
    ElListyBaza* element=bazaSamochodow->pierwszy_;
    int i=1;
    while(element)
    {
        printf("%d.%s\n",i,element->katalog_->nazwa_);
        element=element->nastepny_;
        i++;
    }

}
void wyswietlanieKatalogu(BazaSamochodow* bazaSamochodow)
{
    if(bazaSamochodow->dlugosc_)
    {
        printf("Ktory katalog chcesz zobaczyc?\n");
        wyswietlanieListyKatalogow(bazaSamochodow);
        printf("%d.Powrot do menu\n",bazaSamochodow->dlugosc_+1);
        float n;

        while (!scanf("%f", &n) || n < 1 || n > bazaSamochodow->dlugosc_+1 || n - (int) n != 0) {
            if (n != '\n') {
                printf("Podaj dodatnia liczbe calkowita z przedzialu 1-%d!\n", bazaSamochodow->dlugosc_+1);
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
        if(n!=bazaSamochodow->dlugosc_+1)
        {
            Katalog* katalog=zwrocNtyKatalog(bazaSamochodow,n);
            printf("%-15s|%-15s|%-5s|%-5s\n", "Dzial", "Nazwa samochodu", "Numer", "Przebieg");
            wyswietlKatalog(katalog);
            printf("\n");
        }
    }
    else
    {
        printf("Baza jest pusta. Musisz najpierw dodac katalog\n");
    }}
void wyswietlWszystkieSamochody(BazaSamochodow* bazaSamochodow)
{
    if(bazaSamochodow->iloscSamochodow_)
    {
        sortowanieListyKatalogow(bazaSamochodow);
        ElListyBaza* elem=bazaSamochodow->pierwszy_;
        printf("%-15s|%-15s|%-5s|%-5s\n", "Dzial", "Nazwa samochodu", "Numer", "Przebieg");
        while (elem)
        {
            if(elem->katalog_->dlugosc_)/*Nie wyswietla pustych katalogow*/
            wyswietlKatalog(elem->katalog_);
            elem=elem->nastepny_;
        }

    } else{
        printf("Baza jest pusta\n");
    }
}
void wyswietlSamochodyPrzebieg(BazaSamochodow* bazaSamochodow)
{
    sortowanieListyKatalogow(bazaSamochodow);
    /*TODO*/

}
void wyswietlSamochodyId(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/

}
void wyswietlSamochodNazwa(BazaSamochodow*bazaSamochodow)
{
   sortowanieListyKatalogow(bazaSamochodow);
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
        usunWszystko(bazaSamochodow);
        return;
    }
    menu(bazaSamochodow);
}

void sortowanieListyKatalogow(BazaSamochodow* bazaSamochodow)
{
    ElListyBaza* element=bazaSamochodow->pierwszy_;
    ElListyBaza* elementnast;
    int i,j;
    bool zamiana;

    for(i=0;i<bazaSamochodow->dlugosc_;i++)
    {
        zamiana=0;
        element=bazaSamochodow->pierwszy_;
        elementnast=element->nastepny_;
        for(j=0;j<bazaSamochodow->dlugosc_-1;j++)
        {
            if(strcmp(element->katalog_->nazwa_,elementnast->katalog_->nazwa_)>0)
             {
                 zamiana=1;
                 Katalog* pomoc;
                 pomoc=element->katalog_;
                 element->katalog_=elementnast->katalog_;
                 elementnast->katalog_=pomoc;

             }
            element=element->nastepny_;
            elementnast=elementnast->nastepny_;
        }
        if(!zamiana)
        {
            i=bazaSamochodow->dlugosc_;
        }
    }
}
void zapisDoPliku(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/
}
void odczytZPliku(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/

}
void zapisDoPlikuBin(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/

}
void odczytZPlikuBin(BazaSamochodow* bazaSamochodow)
{
    /*TODO*/

}


