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
    elListyBaza->katalog_=katalog;
    if(bazaSamochodow->dlugosc_) {
        ElListyBaza *ostatni = bazaSamochodow->ostatni_;
        ostatni->nastepny_ = elListyBaza;
        elListyBaza->poprzedni_ = bazaSamochodow->ostatni_;
    }
    else
    {
        elListyBaza->poprzedni_=NULL;
        bazaSamochodow->pierwszy_=elListyBaza;

    }

    elListyBaza->nastepny_ = NULL;
    bazaSamochodow->ostatni_ = elListyBaza;
    bazaSamochodow->dlugosc_++;

}
void zmianaNazwyKatalogu2(BazaSamochodow* bazaSamochodow,int nrElementu)
{

    int i;
    ElListyBaza* element=bazaSamochodow->pierwszy_;
    for(i=1;i<nrElementu;i++)
    {
        element=element->nastepny_;
    }

    zminaNazwyKatalogu(bazaSamochodow,element->katalog_);

}
void zminaNazwyKatalogu(BazaSamochodow* bazaSamochodow,Katalog* katalog)
{

    printf("Podaj nazwe katalogu\n");
    char nazwa[DLUGOSC + 1] = "";
    int sn = 0;
    int c;
    while ((c = getchar()) != EOF && sn < DLUGOSC) {
        if (!(sn == 0 && c == '\n')) {
            if (c == '\n') {
                break;
            }
            nazwa[sn] = (char)c;
            sn++;
        }
    }
    if(!sprawdzKatalog(nazwa,sn))
    {
        printf("Bledna nazwa\n");
        zminaNazwyKatalogu(bazaSamochodow,katalog);
    }
    else
    {
        if(!czyUnikalnyKatalog(bazaSamochodow,nazwa))
        {
            printf("Nazwa nie jest unikalna\n");
            zminaNazwyKatalogu(bazaSamochodow,katalog);
        }
        else
        {
            strcpy(katalog->nazwa_,nazwa);
        }}
}
void usunWszystko(BazaSamochodow* bazaSamochodow)
{
    ElListyBaza* elem=bazaSamochodow->pierwszy_;
    while(elem)
    {
        bazaSamochodow->pierwszy_=elem->nastepny_;
        usunCalyKatalog(elem->katalog_);
        free(elem);
        elem=bazaSamochodow->pierwszy_;
    }
    free(bazaSamochodow);
}
void usuniecieKatalogu2(BazaSamochodow* bazaSamochodow,int nrElementu)
{
    int i;
    ElListyBaza* element=bazaSamochodow->pierwszy_;
    for(i=1;i<nrElementu;i++)
    {
        element=element->nastepny_;
    }
    usunCalyKatalog(element->katalog_);
    element->poprzedni_->nastepny_=element->nastepny_;
    element->nastepny_->poprzedni_=element->poprzedni_;
    free(element);
    bazaSamochodow->dlugosc_--;
}
Katalog* zwrocNtyKatalog(BazaSamochodow* bazaSamochodow, int nrElementu)
{
    int i;
    ElListyBaza* element=bazaSamochodow->pierwszy_;
    for(i=1;i<nrElementu;i++)
    {
        element=element->nastepny_;
    }
    return element->katalog_;
}
void wyswietlSamochodyPrzebieg2(BazaSamochodow* bazaSamochodow,int przebieg)
{
    Katalog* wynik=(Katalog*)malloc(sizeof(Katalog));
    wynik->dlugosc_=0;
    wynik->pierwszy_=NULL;
    wynik->ostatni_=NULL;
    ElListyBaza* katalog=bazaSamochodow->pierwszy_;
    while (katalog)
    {
        ElListyKatalog* samochod=katalog->katalog_->pierwszy_;
        while(samochod){
            if(samochod->samochod_->przebieg_==przebieg)
            {
                ElListyKatalog* elem=(ElListyKatalog*)malloc(sizeof(ElListyKatalog));
                elem->samochod_=samochod->samochod_;
                elem->nastepny_=NULL;
                if(!wynik->dlugosc_)
                {
                    wynik->pierwszy_=elem;
                    elem->poprzedni_=NULL;
                }
                else
                {
                    elem->poprzedni_=wynik->ostatni_;
                    elem->poprzedni_->nastepny_=elem;
                }

                wynik->ostatni_=elem;
                wynik->dlugosc_++;
            }
            samochod=samochod->nastepny_;
        }

        katalog=katalog->nastepny_;
    }
    if(wynik->dlugosc_)
    {
        printf("Samochody o przebiegu %d\n",przebieg);
        wyswietlSamochody(wynik);
    }
    ElListyKatalog* elem=wynik->pierwszy_;

    while(elem)
    {
        ElListyKatalog* pomoc=elem;
        elem=elem->nastepny_;
        free(pomoc);
    }
    free(wynik);
}
void wyswietlSamochody(Katalog* katalog)
{
    printf("%-15s|%-15s|%-5s|%-5s\n", "Dzial", "Nazwa samochodu", "Numer", "Przebieg");
    ElListyKatalog* elem=katalog->pierwszy_;
    while(elem){
        printf("%-15s", elem->samochod_->dzial_->nazwa_);
        printf("|%-15s|",elem->samochod_->nazwa_);
        wypiszId(elem->samochod_->id_);
        printf("%-5d\n",elem->samochod_->przebieg_);
        elem=elem->nastepny_;
    }

}
void wyswietlSamochodyNazwa2(BazaSamochodow* bazaSamochodow, char nazwa[])
{
    Katalog* wynik=(Katalog*)malloc(sizeof(Katalog));
    wynik->dlugosc_=0;
    wynik->pierwszy_=NULL;
    wynik->ostatni_=NULL;
    ElListyBaza* katalog=bazaSamochodow->pierwszy_;
    while (katalog)
    {
        ElListyKatalog* samochod=katalog->katalog_->pierwszy_;
        while(samochod){
            if(!strcmp(samochod->samochod_->nazwa_,nazwa))
            {
                ElListyKatalog* elem=(ElListyKatalog*)malloc(sizeof(ElListyKatalog));
                elem->samochod_=samochod->samochod_;
                elem->nastepny_=NULL;
                if(!wynik->dlugosc_)
                {
                    wynik->pierwszy_=elem;
                    elem->poprzedni_=NULL;
                }
                else
                {
                    elem->poprzedni_=wynik->ostatni_;
                    elem->poprzedni_->nastepny_=elem;
                }

                wynik->ostatni_=elem;
                wynik->dlugosc_++;
            }
            samochod=samochod->nastepny_;
        }

        katalog=katalog->nastepny_;
    }
    if(wynik->dlugosc_)
    {
        printf("Samochody o nazwie %s\n",nazwa);
        wyswietlSamochody(wynik);
    }
    ElListyKatalog* elem=wynik->pierwszy_;
    while(elem)
    {
        ElListyKatalog* pomoc=elem;
        elem=elem->nastepny_;
        free(pomoc);
    }
    free(wynik);
}
void wyswietlSamochodyID2(BazaSamochodow* bazaSamochodow, int id)
{
    ElListyBaza* katalog=bazaSamochodow->pierwszy_;
    while (katalog)
    {
        ElListyKatalog* samochod=katalog->katalog_->pierwszy_;
        while(samochod)
        {
            if(samochod->samochod_->id_==id)
            {
                printf("%-15s|%-15s|%-5s|%-5s\n", "Dzial", "Nazwa samochodu", "Numer", "Przebieg");
                printf("%-15s", samochod->samochod_->dzial_->nazwa_);
                printf("|%-15s|",samochod->samochod_->nazwa_);
                wypiszId(samochod->samochod_->id_);
                printf("%-5d\n",samochod->samochod_->przebieg_);
                return;
            }
            samochod=samochod->nastepny_;
        }
        katalog=katalog->nastepny_;
    }
    printf("Brak samochodow o podanym id\n");
}
