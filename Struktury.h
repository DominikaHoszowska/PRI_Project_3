
#ifndef PRI_PROJECT_3_STRUKTURY_H
#define PRI_PROJECT_3_STRUKTURY_H
#define DLUGOSC 15

typedef struct ElListyBaza_t ElListyBaza;
typedef struct ElListyKatalog_t ElListyKatalog;
typedef struct BazaSamochodow_t BazaSamochodow;
typedef struct Katalog_t Katalog;
typedef struct
{
    char nazwa_[DLUGOSC+1];
    int przebieg_;
    int id_;
    Katalog* dzial_;
} Samochod;
struct ElListyKatalog_t
{
    Samochod* samochod_;
    struct ElListyKatalog_t* nastepny_;
    struct ElListyKatalog_t* poprzedni_;

};

struct Katalog_t
{
    char nazwa_[DLUGOSC+1];
    int dlugosc_;
    ElListyKatalog* pierwszy_;
    ElListyKatalog* ostatni_;
};

struct ElListyBaza_t
{
    Katalog* katalog_;
    struct ElListyBaza_t* nastepny_;
    struct ElListyBaza_t* poprzedni_;

};


struct BazaSamochodow_t
{
    int dlugosc_;
    int iloscSamochodow_;
    ElListyBaza* pierwszy_;
    ElListyBaza* ostatni_;
};
#endif /*PRI_PROJECT_3_STRUKTURY_H*/
