#include <iostream>
#include <string>
#include <algorithm>
#include "wypozyczalnia.h"
#include "gra.h"
#include "klient.h"
#include "grakieszonkowa.h"

using namespace std;
int Wypozyczalnia::licz_transakcji = 0;
//Gra *wsk_gra; //wskaznik do tablicy obiektow nowych gier
//Klient *wsk_kli; //wskaznik do tablicy obiektow nowych klientow

//konstruktor domyslny
Wypozyczalnia::Wypozyczalnia()
{
}
//destruktor
Wypozyczalnia::~Wypozyczalnia ()
{
}

//metody
//dodawanie nowej gry do bazy
void Wypozyczalnia::dodajGry()
{   int rodzaj;
    string nazwa;
    int liczba_graczy;
    float cena;
    int dlug , szer;
    cout << "Podaj liczbe nowych gier" <<endl;
    cin >> lgier;

    for (i=0;i<lgier;i++)
    {
        cout << "Podaj nazwe gry" <<endl;
        cin.get();
        getline(cin, nazwa); //uzycie getline pozwala na wprowadzenie wieloczlonowej nazwy gry
        cout << "Podaj liczbe graczy" <<endl;
        cin >> liczba_graczy;
        cout << "Podaj cene wypozyczenia" <<endl;
        cin >> cena;
        cout << "Wpisz 1 dla gier kieszonkowych, wpisz 0 dla pozostalych: ";
        while (cin >> rodzaj && (rodzaj != 1 && rodzaj != 0))
            cout << "Wpisz 1 dla gier kieszonkowych, wpisz 0 dla pozostalych: ";
        if (rodzaj == 0)
            gry.push_back(Gra(nazwa,liczba_graczy,cena)); //wywolanie konstruktora gra
        else
        {
          cout << "Podaj dlugosc gry" <<endl;
          cin >> dlug;
          cout << "Podaj szerokosc gry" <<endl;
          cin >> szer;
          kieszonkowe.push_back(GraKieszonkowa(nazwa,liczba_graczy,cena,dlug,szer)); //wywolanie konstruktora grakieszonkowa
        }
    }
 }

//przypisanie danych z jednej gry na druga
void Wypozyczalnia::przypiszGre()
{
    int nowa, wzor;
    cout << "Przyklad przypisanie gier" <<endl;
    if (Gra::licz_gry<2)
        cout << "Za malo gier ";
    else
    {
        cout <<"Podaj numer gry wzoru od 1 do " << Gra::licz_gry <<endl;
        cin >> wzor;
        cout <<"Podaj numer gry do zmiany od 1 do "<< Gra::licz_gry <<endl;
        cin >> nowa;
        gry[nowa-1]=gry[wzor-1]; //wykorzystanie przeciazonego operatora przypisania
        cout << "Pokaz dane gier" <<endl;
        for (i=0;i<Gra::licz_gry;i++)
        cout << gry[i];
    }
}

//dodawanie nowego klienta do bazy
void Wypozyczalnia::dodajKlienta()
{
    string imie,nazwisko;
    cout << "Podaj liczbe nowych klientow" <<endl;
    cin >> lkl;

    for (i=0;i<lkl;i++)
    {
        cout << "Podaj imie klienta" <<endl;
        cin >> imie;
        cout << "Podaj nazwisko klienta" <<endl;
        cin >> nazwisko;
        klienci.push_back(Klient(imie,nazwisko)); //wywolanie konstruktora z parametrami
    }
}

//pozyczanie gier
void Wypozyczalnia::pozyczGre()
{
    if (!Gra::licz_gry)
        cout << "Nie dodano zadnych gier ";
    else
    {
        int nr_kli, nr_gra;
        cout <<"Podaj nr klienta " << endl;
        cin >> nr_kli;
        cout <<"Podaj nr gry " << endl;
        cin >> nr_gra;
        if (klienci[nr_kli-1]==true) //-1, bo numery klientow zaczynaja sie od 1, a tablica od 0
        //klient moze pozyczyc jedna gre, aby doszlo do tranzakcji status klienta musi byc 0, wykorzystanie przeladowania operatorow
            cout <<"ten klient juz ma gre na koncie"<<endl;
        else if (!gry[nr_gra-1])
        //jesli gra jest wypozyczona, nie mozna jej juz wypozyczyc
            cout <<"ta gra jest juz wypozyczona"<<endl;
        else
        {
            gry[nr_gra-1].zmienStatusT(nr_kli); //zmiana obu statusow na true
            klienci[nr_kli-1].zmienStatusT(nr_gra);
            cout <<"transakcja nr " <<++licz_transakcji <<"  klient nr: "
                 <<nr_kli << " pozycza gre o numerze: " <<nr_gra <<endl;
        }
    }
}
//pozyczanie gier
void Wypozyczalnia::pozyczKieszonkowa()
{
    if (!GraKieszonkowa::licz_kiesz)
        cout << "Nie dodano zadnych gier kieszonkowych";
    else
    {
        int nr_kli, nr_gra;
        cout <<"Podaj nr klienta " << endl;
        cin >> nr_kli;
        cout <<"Podaj nr gry " << endl;
        cin >> nr_gra;
        if (klienci[nr_kli-1]==true) //-1, bo numery klientow zaczynaja sie od 1, a tablica od 0
        //klient moze pozyczyc jedna gre, aby doszlo do tranzakcji status klienta musi byc 0, wykorzystanie przeladowania operatorow
            cout <<"ten klient juz ma gre na koncie"<<endl;
        else if (!kieszonkowe[nr_gra-1])
        //jesli gra jest wypozyczona, nie mozna jej juz wypozyczyc
            cout <<"ta gra jest juz wypozyczona"<<endl;
        else
        {
            kieszonkowe[nr_gra-1].zmienStatusT(nr_kli); //zmiana obu statusow na true
            klienci[nr_kli-1].zmienStatusT(nr_gra);
            cout <<"transakcja nr " <<++licz_transakcji <<"  klient nr: "
                 <<nr_kli << " pozycza gre o numerze: " <<nr_gra <<endl;
        }
    }
}

//oddawanie gier
void Wypozyczalnia::oddajGre()
{
    int nr_kli, nr_gra;
    cout <<"Podaj nr klienta " << endl;
    cin >> nr_kli;

    if (klienci[nr_kli-1]==true) //sprawdzenie czy klient ma gre, jesli tak to oddanie i zmiana stausow na 0
    {
        nr_gra=klienci[nr_kli-1].poz_gra; //numer gry otrzymany poprzez klienta
        gry[nr_gra-1].zmienStatusF();
        klienci[nr_kli-1].zmienStatusF();
        cout <<"transakcja nr " <<++licz_transakcji <<" klient nr: "
             <<nr_kli << " oddaje gre o numerze: " <<nr_gra <<endl;
    }
    else
        cout <<"ten klient nie ma gry na koncie"<<endl;
 }
//oddawanie gier
void Wypozyczalnia::oddajKieszonkowa()
{
    int nr_kli, nr_gra;
    cout <<"Podaj nr klienta " << endl;
    cin >> nr_kli;

    if (klienci[nr_kli-1]==true) //sprawdzenie czy klient ma gre, jesli tak to oddanie i zmiana stausow na 0
    {
        nr_gra=klienci[nr_kli-1].poz_gra; //numer gry otrzymany poprzez klienta
        kieszonkowe[nr_gra-1].zmienStatusF();
        klienci[nr_kli-1].zmienStatusF();
        cout <<"transakcja nr " <<++licz_transakcji <<" klient nr: "
             <<nr_kli << " oddaje gre o numerze: " <<nr_gra <<endl;
    }
    else
        cout <<"ten klient nie ma gry na koncie"<<endl;
 }

//wyswietlanie listy dodanych klientow
void Wypozyczalnia::pokazKlientow()
{
    cout << "Pokaz dane klientow " <<endl;
    for (i=0;i<lkl;i++)
    cout << klienci[i];
}

//wyswietlanie listy dodanych gier
void Wypozyczalnia::pokazDostepneGry()
{
    cout << "Mozesz wypozyczyc gry: " <<endl; //lista dostepnych gier (niewypozyczonych)
    for (i=0;i<Gra::licz_gry;i++)
        gry[i].dostepneGry();
    cout << "Mozesz wypozyczyc gry kieszonkowe: " <<endl; //lista dostepnych gier (niewypozyczonych)
    for (i=0;i<GraKieszonkowa::licz_kiesz;i++)
        kieszonkowe[i].dostepneGry();
  }
//wyswietlanie listy dodanych gier
void Wypozyczalnia::pokazGry()
{
    cout << "Pokaz wszystkie duze gry  " <<endl;
    for (i=0;i<Gra::licz_gry;i++)
        cout << gry[i];
    cout << "Pokaz wszystkie kieszonkowe-podrozne gry  " <<endl;
    for (i=0;i<GraKieszonkowa::licz_kiesz;i++)
        cout << kieszonkowe[i];
    cout << "Serdecznie Zapraszamy! Promocyjne ceny!" <<endl;
}
//znajduje najtansza gre
void Wypozyczalnia::najtanszaGra()
{
    if (!Gra::licz_gry)
        cout << "Nie dodano zadnych gier ";
    else
    {
        vector<Gra>::iterator tania;
         tania = min_element(gry.begin(),gry.end());
         cout <<"Najtansza gra , okazja dnia to: " <<endl;
         cout << *tania;
    }

}
void Wypozyczalnia::miniKieszonkowa()
{
    if (!GraKieszonkowa::licz_kiesz)
        cout << "Nie dodano zadnych gier kieszonkowych";
    else
    {
        vector <GraKieszonkowa> posortowane(GraKieszonkowa::licz_kiesz);
        copy(kieszonkowe.begin(),kieszonkowe.end(),posortowane.begin());
        sort(posortowane.begin(),posortowane.end());
        cout << "Najmniejsza gra w naszej wypozyczalni to: " << endl;
        cout << posortowane[0];
    }

}
