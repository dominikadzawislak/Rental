#include <iostream>
#include <string>
#include "status.h"
#include "klient.h"

using namespace std;

int Klient::licz_kl = 0;

//konstruktor domyslny
Klient::Klient()
{
    nr_klient=0;  //numer karty klienta, nadawany statycznie przy tworzeniu kolejnych realnych obiektow
    imie="";
    nazwisko="";
    stat=false; //jesli klient nie ma wypozyczonej gry, to status klienta false
    poz_gra=0;  //gra, ktora wypozyczyl klient, 0 oznacza brak wypozyczenia

}

//konstruktor inicjujacy
Klient::Klient(string  imie, string  nazwisko)
{ cout << "konstruktor inicjujacy" << endl;
    this->imie = imie;
	this->nazwisko = nazwisko;
	this->nr_klient = ++licz_kl;
	this->stat=false;
	this->poz_gra=0;
}

//konstruktor kopiujacy
/*Klient::Klient(const Klient & k)
{ cout << "konstruktor kopiujacy" << endl;
    imie = k.imie;
	nazwisko = k.nazwisko;
	nr_klient = ++licz_kl;;
	stat=k.stat;
	poz_gra=k.poz_gra;
}*/

//destruktor
Klient::~Klient ()
{
}

//przeciazony operator
bool Klient::operator==(bool)
{
    if (stat)
        return true;
    else return false;
}

//metody
//zmiana statusu w przypadku, gdy klient ma pozyczona gre
void Klient::zmienStatusT(int gra_poz)
{
    this->stat = true;
    this->poz_gra=gra_poz;
}

//zmiana statusu w przypadku, gdy klient nie ma pozyczonej gry
void Klient::zmienStatusF()
{
    this->stat = false;
    this->poz_gra=0;
}

//przeciazony operator wyswietlajacy klientow
ostream & operator<<(ostream & wyj, const Klient & k)
{
    wyj << "imie: " << k.imie << endl;
    wyj << "nazwisko: " << k.nazwisko << endl;
    wyj << "nr karty: " << k.nr_klient << endl;
    if(k.stat)
    {
      wyj << "czy pozyczyl gre: Tak" << endl;
      wyj << " numer pozyczonej gry: "  <<k.poz_gra<<endl;
    }
    else wyj <<  "czy pozyczyl gre: Nie" << endl;
    return wyj;
}
