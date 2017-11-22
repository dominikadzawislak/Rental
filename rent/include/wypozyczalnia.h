//klasa Wypozyczalnia
#ifndef WYPOZYCZALNIA_H_
#define WYPOZYCZALNIA_H_
#include <string>
#include "gra.h"
#include "klient.h"
#include "grakieszonkowa.h"
#include <vector>

using namespace std;
class Klient;

class Wypozyczalnia
{
private:
    int i;
    int lgier; //ilosc obiektow (nowych gier)
    int lkl; //ilosc obiektow (nowych klientow)

public:
    vector <Gra> gry;
    vector <GraKieszonkowa> kieszonkowe;
    vector <Klient> klienci;
    static int licz_transakcji;
    Wypozyczalnia();
    ~Wypozyczalnia();
    //metody klasy
    void dodajGry();
    void przypiszGre();
    void dodajKlienta();
    void pozyczGre();
    void pozyczKieszonkowa();
    void oddajGre();
    void oddajKieszonkowa();
    void pokazKlientow();
    void pokazGry();
    void pokazDostepneGry();
    void najtanszaGra();
    void miniKieszonkowa();
};

#endif // WYPOZYCZALNIA_H_
