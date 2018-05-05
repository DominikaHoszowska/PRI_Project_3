/*Created by Dominika Hoszowska on 17.04.18.*/
#include <memory.h>
#include "ObslugaPlikow.h"
#include "Struktury.h"
#include <crypt.h>
#define DLUGOSC 15

int sprawdzNazwePilku(char nazwa[], int dlugosc)/* 0-bledna nazwa, 1- txt 2-bin*/
{

    if (nazwa[dlugosc - 3] == 't' && nazwa[dlugosc - 2] == 'x' && nazwa[dlugosc - 1] == 't') {
        return 1;
    }
    if (nazwa[dlugosc - 3] == 'u' && nazwa[dlugosc - 2] == 'l' && nazwa[dlugosc - 1] == 'a') {
        return 2;
    }
    return 0;
}

void zapisDoPlikuTxt(char nazwa[], BazaSamochodow *bazaSamochodow) {
    FILE *file;
    file = fopen(nazwa, "w");
    if (file == NULL) {
        printf("Nie mozna otworzyc pliku %s\n", nazwa);
        return;
    }
    sortowanieListyKatalogow(bazaSamochodow);
    ElListyBaza *katalog = bazaSamochodow->pierwszy_;
    while (katalog) {
        sortujKatalog(katalog->katalog_);
        ElListyKatalog *samochod = katalog->katalog_->pierwszy_;
        while (samochod) {
            wypiszSamochod(file, samochod->samochod_);
            samochod = samochod->nastepny_;
        }
        katalog = katalog->nastepny_;
    }
    fclose(file);
}
 int ustawHaslo(char haslo[])
 {

     printf("Podaj haslo\n");
     int sn = 0;
     int c;
     while ((c = getchar()) != EOF && c != ' ' && sn < DLUGOSC) {
         if (!(sn == 0 && c == '\n')) {
             if (c == '\n') {
                 break;
             }
             haslo[sn] = (char) c;
             sn++;
         }
     }
     char hasloPotwierdzenie[DLUGOSC+1]="";
     int i=0;
     sn=0;
     while(i<3)
     {
         printf("Potwierdz haslo\n");
         while ((c = getchar()) != EOF && c != ' ' && sn < DLUGOSC) {
             if (!(sn == 0 && c == '\n')) {
                 if (c == '\n') {
                     break;
                 }
                 hasloPotwierdzenie[sn] = (char) c;
                 sn++;
             }
         }
         if(!strcmp(haslo,hasloPotwierdzenie))
         {
             return sn;
         }
         i++;
     }
     return 0;
 }
void zapisDoPlikuBin(char nazwa[], BazaSamochodow *bazaSamochodow) {

    FILE *file;
    file = fopen(nazwa, "wb");
    if (file == NULL) {
        printf("Nie mozna otworzyc pliku %s\n", nazwa);
        return;
    }
    char haslo[DLUGOSC + 1] = "";
    int rozmiar=ustawHaslo(haslo);
    while(!rozmiar)
    {
        rozmiar=ustawHaslo(haslo);
    };
    char wynik[DLUGOSC+1]="";
    szyfruj(wynik,haslo,rozmiar,"a",1);
    fwrite(wynik, sizeof(char), rozmiar,file);
    fwrite("\n", sizeof(char),1,file);

    sortowanieListyKatalogow(bazaSamochodow);
    ElListyBaza *katalog = bazaSamochodow->pierwszy_;
    while (katalog) {
        sortujKatalog(katalog->katalog_);
        ElListyKatalog *samochod = katalog->katalog_->pierwszy_;
        while (samochod) {
            wypiszSamochodB(file, samochod->samochod_,haslo,rozmiar);
            samochod = samochod->nastepny_;
        }
        katalog = katalog->nastepny_;
    }
    fclose(file);
}

void wypiszSamochod(FILE *file, Samochod *samochod) {
    fprintf(file, "%s ", samochod->nazwa_);
    wypiszIdF(file, samochod->id_);
    fprintf(file, " %d %s\n", samochod->przebieg_, samochod->dzial_->nazwa_);
}

void wypiszIdF(FILE *file, int id) {
    if (id < 10) {
        fprintf(file, "0000%-1d", id);
        return;
    }
    if (id < 100) {
        fprintf(file, "000%-2d", id);
        return;
    }
    if (id < 1000) {
        fprintf(file, "00%-3d", id);
        return;
    }
    if (id < 10000) {
        fprintf(file, "0%-4d", id);
        return;
    }
    fprintf(file, "%-5d", id);

}
void szyfruj(char wynik[],char dane[], int rozmiar, char haslo[], int rozmiarHasla)
{
    int i;
    for(i=0;i<rozmiar;i++)
    {
        char j=haslo[i%rozmiarHasla];
        wynik[i]=dane[i]^j;
    }
    wynik[rozmiar]='\n';
}
int zwrocRozmiar(char nazwa[])
{
    int rozmiar=0;
    while(nazwa[rozmiar]!='\0')
    {
        ++rozmiar;
    }
    return rozmiar;
}
int zamienNaCharPrzebieg(int liczba,char wynik[])
{
    zamienNaCharID(liczba,wynik);
    int i;
    int licznik=0;
    while(wynik[0]!=0 && wynik[0]!='\n')
    {
        i=0;
        licznik++;
        while (wynik[i]!='\0')
        {
            wynik[i]=wynik[i+1];
            ++i;
        }
    }
    return 5-licznik;
}
int zamienNaCharID(int liczba,char wynik[])
{
    int i=4;
    while(i>=0)
    {
        wynik[i]=(char)(liczba%10+'0');
        liczba/=10;
        --i;
    }
    wynik[5]='\0';
    return 5;
}

void wypiszSamochodB(FILE *file, Samochod *samochod, char haslo[], int rozmiarHasla) {

    int rozmiar=zwrocRozmiar(samochod->nazwa_);
    char nazwa[DLUGOSC+1] ="";
    char wynik[DLUGOSC+1]="";
    szyfruj(wynik,samochod->nazwa_,rozmiar,haslo,rozmiarHasla);
    strcpy(nazwa,wynik);
    fwrite(nazwa, sizeof(char), rozmiar, file);
    fwrite(" ", sizeof(char), 1, file);

    char pomoc[DLUGOSC+1];
    rozmiar=zamienNaCharID(samochod->id_,pomoc);

    szyfruj(wynik,pomoc,rozmiar,haslo,rozmiarHasla);
    strcpy(nazwa,wynik);
    fwrite(nazwa, sizeof(char), rozmiar, file);
    fwrite(" ", sizeof(char), 1, file);

    rozmiar=zamienNaCharPrzebieg(samochod->przebieg_,pomoc);
    szyfruj(wynik,pomoc,rozmiar,haslo,rozmiarHasla);
    strcpy(nazwa,wynik);
    fwrite(nazwa, sizeof(char), rozmiar, file);
    fwrite(" ", sizeof(char), 1, file);

    rozmiar=zwrocRozmiar(samochod->dzial_->nazwa_);
    szyfruj(wynik,samochod->dzial_->nazwa_,rozmiar,haslo,rozmiarHasla);
    strcpy(nazwa,wynik);
    fwrite(nazwa, sizeof(char), rozmiar, file);
    fwrite("\n", sizeof(char), 1, file);

}

void odczytZPlikuT(char nazwa[], BazaSamochodow *bazaSamochodow) {
    FILE *file;
    file = fopen(nazwa, "r");
    if (file == NULL) {
        printf("Nie mozna otworzyc pliku %s\n", nazwa);
        return;
    }
    char samochod[4 * DLUGOSC];
    while (!feof(file)) {
        fgets(samochod, 4 * DLUGOSC, file);
        int r = rozmiar(samochod);
        dodajSamochodf(bazaSamochodow, samochod, r);
    }
    fclose(file);


}

void odczytZPlikuBin(char nazwa[], BazaSamochodow *bazaSamochodow) {
    FILE *file;
    file = fopen(nazwa, "r");
    if (file == NULL) {
        printf("Nie mozna otworzyc pliku %s\n", nazwa);
        return;
    }
    char tekst[DLUGOSC+1]="";
    char haslo[DLUGOSC+1]="";
    if(!feof(file))
    fgets(tekst,DLUGOSC+1, file);
    int i=0;
    int rozmiarhasla=odczytajhaslo(haslo,tekst);
    while(!wczytajhaslo(haslo,rozmiarhasla));
    char samochod[4 * DLUGOSC];
    while (!feof(file)) {
        fgets(samochod, 4 * DLUGOSC, file);
        int r = rozmiar(samochod);
        dodajSamochodfb(bazaSamochodow, samochod, r);
    }
    fclose(file);
}
bool wczytajhaslo(char haslo[],int rozmiarhasla)
{
    printf("Podaj haslo\n");
    int sn = 0;
    int c;
    char sprhaslo[DLUGOSC+1]="";
    while ((c = getchar()) != EOF && c != ' ' && sn < DLUGOSC) {
        if (!(sn == 0 && c == '\n')) {
            if (c == '\n') {
                break;
            }
            sprhaslo[sn] = (char) c;
            sn++;
        }
    }
    sprhaslo[sn]='\n';
    if(sn!=rozmiarhasla) {
        printf("Bledne haslo\n");
        return 0;
    }
    if(!strcmp(sprhaslo,haslo)) return 1;
    printf("Bledne haslo\n");
    return 0;
}

int odczytajhaslo(char haslo[],char tekst[])
{
    int i=0;
    while(tekst[i]!='\n')
    {
        ++i;
    }
    szyfruj(haslo,tekst,i,"a",1);
    return i;
}


int rozmiar(char napis[]) {
    int r = 0;
    while (napis[r] != '\n' && napis[r] != '\0') {
        ++r;
    }
    napis[r] = '\0';
    return r + 1;
}

void dodajSamochodf(BazaSamochodow *bazaSamochodow, char napis[], int rozmiar) {
    int i = rozmiar - 1;
    napis[i] = '\000';
    while (napis[i] != ' ') {
        i--;
    }
    int dlugoscKat = rozmiar - i - 2;
    if (dlugoscKat > DLUGOSC) {
        return;
    }
    char katalog[DLUGOSC + 1];
    strcpy(katalog, (napis + i + 1));
    int j = i;
    napis[i] = '\0';
    i--;
    while (napis[i] != ' ') {
        i--;
    }
    int przebieg = zamienNaLiczbe(&napis[i + 1], j - i - 1);
    if (przebieg < 0) {
        return;
    }
    for (; j > i; j--) {
        napis[j] = '\000';
    }
    i--;
    while (napis[i] != 32) {
        i--;
    }
    int id = zamienNaLiczbe(&napis[i + 1], j - i - 1);
    if (id < 0 || !czyUnikalneId(id, bazaSamochodow)) {
        return;
    }
    for (; j >= i; j--) {
        napis[j] = '\000';
    }
    if (!sprawdzNazwe(napis, i)) {
        return;
    }
    if (!czyIstniejeKatalog(bazaSamochodow, katalog, rozmiar)) {
        stworzKatalog(bazaSamochodow, katalog);
    }
    stworzSamochod(bazaSamochodow, katalog, napis, id, przebieg);
}

int zamienNaLiczbe(char liczba[], int rozmiar) {
    int wynik = 0;
    int d = 1;
    rozmiar--;
    for (; rozmiar >= 0; rozmiar--) {
        if (liczba[rozmiar] < '0' || liczba[rozmiar] > '9') {
            return -1;
        }
        wynik += (liczba[rozmiar] - '0') * d;
        d *= 10;
    }
    return wynik;
}