#include <stdio.h>
#include "Samochod.h"
#include "Struktury.h"

/*Created by Dominika Hoszowska on 17.04.18.*/


void wyswietlSamochod(Samochod* samochod)
{
    printf("|%-15s|",samochod->nazwa_);
    wypiszId(samochod->id_);
    printf("%-5d\n%-15s",samochod->przebieg_," ");
}
void wypiszId(int id)
{
    if(id<10)
    {
        printf("0000%-1d|",id);
        return;
    }
    if(id<100)
    {
        printf("000%-2d|",id);
        return;
    }
    if(id<1000)
    {
        printf("00%-3d|",id);
        return;
    }
    if(id<10000)
    {
        printf("0%-4d|",id);
        return;
    }
    printf("%-5d|",id);

}