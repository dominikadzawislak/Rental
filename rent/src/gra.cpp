#include <string>
#include "gra.h"

using namespace std;

int Gra::licz_gry = 0;

//konstruktor domyslny
Gra::Gra()
{
    nr_gry=0; //numer katalogowy gry
    string nazwa="bez nazwy";
    stat=false; //status, czy jest wypo¿yczona czy nie
    liczba_graczy = 0; //na ile graczy jest gra
    cena = 0;
    nr_klient=0;   //numer klienta, ktory ma pozyczon¹ gre, O jak gra nie jest pozyczona
}

//konstruktor inicjujacy
Gra::Gra(const std::string & nazwa, int & liczba_graczy, float & cena)
{
    nr_gry=++licz_gry; //zwiekszanie licznika gier
	this->nazwa = nazwa;
	this->stat = false;
	this->liczba_graczy = liczba_graczy;
	this->cena = cena;
	this->nr_klient=0;
	cout <<"wpisano gre inna" <<endl;
}

//konstruktor kopiujacy
/*Gra::Gra(const Gra & g)
{
	nr_gry=++licz_gry;
	nazwa = g.nazwa;
	stat = g.stat;
	liczba_graczy = g.liczba_graczy;
	cena = g.cena;
    nr_klient=g.nr_klient;
}*/

//destruktor
Gra::~Gra ()
{
}

//operator przypisania
Gra & Gra::operator=(const Gra &wzor)
{
	nr_gry=wzor.nr_gry;
	nazwa = wzor.nazwa;
	stat = wzor.stat;
	liczba_graczy = wzor.liczba_graczy;
	cena = wzor.cena;
    nr_klient=wzor.nr_klient;
    return *this;
}

bool Gra::operator!()
{
    if (stat)
        return true;
    else
        return false;
}
bool Gra::operator<(const Gra &g)
{
   if(cena<g.cena)
        return true;
   else
        return false;
}

//przeciazony operator wyswietlajacy klientow
ostream & operator<<(ostream & wyj, const Gra & g)
{
     cout << "nr katalogowy: " << g.nr_gry <<endl
         << "gra: " << g.nazwa << endl<< "dla ilu graczy: "
         << g.liczba_graczy <<endl << "cena za wypozyczenie: "
         << g.cena <<endl ;

    if(g.stat)
    {
      cout << "czy wypozyczona: Tak" << endl;
      cout << " klientowi nr: "  <<g.nr_klient<<endl;
    }
    else cout << "czy wypozyczona: Nie" << endl;
}

//pozostale metody
//zmiana statusu w przypadku pozyczenia gry
void Gra::zmienStatusT(int nr_kli)
{
    this->stat = true;
    this->nr_klient=nr_kli;

}

//zmiana statusu w przypadku oddania gry
void Gra::zmienStatusF()
{
    this->stat = false;
    this->nr_klient=0;
}

void Gra::dostepneGry()
{
    if(!stat) //jesli status jest 0, gra niewypozyczona
    cout << "nr katalogowy: " << nr_gry <<endl
         << "gra: " << nazwa << endl<< "dla ilu graczy: "
         << liczba_graczy <<endl << "cena za wypozyczenie: "
         << cena <<endl ;
}

/*void Gra::pokazGra()
{
     cout << "nr katalogowy: " << nr_gry <<endl
         << "gra: " << nazwa << endl<< "dla ilu graczy: "
         << liczba_graczy <<endl << "cena za wypozyczenie: "
         << cena <<endl ;

    if(stat)
    {
      cout << "czy wypozyczona: Tak" << endl;
      cout << " klientowi nr: "  <<nr_klient<<endl;
    }
    else cout << "czy wypozyczona: Nie" << endl;
}*/

