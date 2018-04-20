
#ifndef PRI_PROJECT_3_STRUKTURY_H
#define PRI_PROJECT_3_STRUKTURY_H
#define DLUGOSC 15

typedef struct ElListyBaza_t ElListyBaza;
typedef struct BazaSamochodow_t BazaSamochodow;
typedef struct
{
    char nazwa_[DLUGOSC+1];
    int przebieg_;
    int id_;
    struct Katalog* dzial_;
} Samochod;
typedef struct
{
    Samochod* samochod_;
    struct ElListyKatalog* nastepny_;
    struct ElListyKatalog* poprzedni_;

}ElListyKatalog;

typedef struct
{
    char nazwa_[DLUGOSC+1];
    int dlugosc_;
    ElListyKatalog* pierwszy_;
    ElListyKatalog* ostatni_;
}Katalog;

struct ElListyBaza_t
{
    Katalog* katalog_;
    struct ElListyBaza_t* nastepny_;
    struct ElListyBaza_t* poprzedni_;

};


struct BazaSamochodow_t
{
    int dlugosc_;
    ElListyBaza* pierwszy_;
    ElListyBaza* ostatni_;
};
#endif /*PRI_PROJECT_3_STRUKTURY_H*/
