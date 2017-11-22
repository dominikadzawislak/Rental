//klasa Klient
#ifndef KLIENT_H_
#define KLIENT_H_
#include "status.h"
#include <iostream>
#include <string>

using namespace std;

class Klient : public Status
{
private:
    static int licz_kl;
    string imie;
    string nazwisko;
    int nr_klient;
    bool stat;

public:
    int poz_gra;
    Klient();
    Klient (string imie, string nazwisko);
   // Klient (const Klient & k);
    ~Klient();
    void zmienStatusT(int nr_gra);
    void zmienStatusF();
    bool operator==(bool);
    friend ostream & operator<<(ostream & wyj, const Klient & k);
    //musi byæ zaprzyjazniona, aby moc siê odwolywac do prywatnych w³asciwosci klasy klient
};

#endif // KLIENT_H_
