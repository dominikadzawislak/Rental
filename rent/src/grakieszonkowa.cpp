#include <string>
#include "grakieszonkowa.h"

using namespace std;

int GraKieszonkowa::licz_kiesz = 0;

//konstruktor domyslny
GraKieszonkowa::GraKieszonkowa()
{
    nr_kiesz=0; //numer katalogowy gry
    string nazwa="bez nazwy";
    stat=false; //status, czy jest wypo¿yczona czy nie
    liczba_graczy = 0; //na ile graczy jest gra
    cena = 0;
    nr_klient=0;   //numer klienta, ktory ma pozyczon¹ gre, O jak gra nie jest pozyczona
    dlugosc=0;
    szerokosc=0;
}

//konstruktor inicjujacy
GraKieszonkowa::GraKieszonkowa(const std::string & nazwa, int & liczba_graczy, float & cena,int & dlugosc, int & szerokosc )
{
    nr_kiesz=++licz_kiesz; //zwiekszanie licznika gier
	this->nazwa = nazwa;
	this->stat = false;
	this->liczba_graczy = liczba_graczy;
	this->cena = cena;
	this->nr_klient=0;
	this->dlugosc=dlugosc;
	this->szerokosc=szerokosc;
	cout <<"wpisano gre kieszonkowa" <<endl;
}

//destruktor
GraKieszonkowa::~GraKieszonkowa ()
{
}

//operator przypisania
GraKieszonkowa & GraKieszonkowa::operator=(const GraKieszonkowa &wzor)
{
	nr_kiesz=wzor.nr_kiesz;
	nazwa = wzor.nazwa;
	stat = wzor.stat;
	liczba_graczy = wzor.liczba_graczy;
	cena = wzor.cena;
    nr_klient=wzor.nr_klient;
    dlugosc=wzor.dlugosc;
    szerokosc=wzor.szerokosc;
    return *this;
}

/*bool GraKieszonkowa::operator!()
{
    if (stat)
        return true;
    else
        return false;
}*/
bool operator<(const GraKieszonkowa &g1, const GraKieszonkowa &g2)
{  int pole1=g1.dlugosc*g1.szerokosc;
   int pole2=g2.dlugosc*g2.szerokosc;
   if(pole1<pole2)
        return true;
   else
        return false;
}

//przeciazony operator wyswietlajacy gier
ostream & operator<<(ostream & wyj, const GraKieszonkowa & g)
{
     cout <<  "gra kieszonkowa  "
         << "nr katalogowy-kieszonkowy: " << g.nr_kiesz <<endl
         << "gra: " << g.nazwa << endl<< "dla ilu graczy: "
         << g.liczba_graczy <<endl << "cena za wypozyczenie: "
         << g.cena <<endl <<"gra kieszonkowa dlugosc="
         << g.dlugosc << " szerokosc=" <<g.szerokosc <<endl ;

    if(g.stat)
    {
      cout << "czy wypozyczona: Tak" << endl;
      cout << " klientowi nr: "  <<g.nr_klient<<endl;
    }
    else cout << "czy wypozyczona: Nie" << endl;
}

//pozostale metody
//zmiana statusu w przypadku pozyczenia gry
/*void GraKieszonkowa::zmienStatusT(int nr_kli)
{
    this->stat = true;
    this->nr_klient=nr_kli;

}

//zmiana statusu w przypadku oddania gry
void GraKieszonkowa::zmienStatusF()
{
    this->stat = false;
    this->nr_klient=0;
}*/

void GraKieszonkowa::dostepneGry()
{
    if(!stat) //jesli status jest 0, gra niewypozyczona
    cout <<  "nr katalogowy-kieszonkowy: " << nr_kiesz <<endl
         << "gra: " << nazwa << endl<< "dla ilu graczy: "
         << liczba_graczy <<endl << "cena za wypozyczenie: "
         << cena <<endl << "gra kieszonkowa dlugosc="
         << dlugosc << " szerokosc=" <<szerokosc <<endl;

}
