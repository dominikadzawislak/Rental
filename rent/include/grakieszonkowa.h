//klasa GraKieszonkowa
#ifndef GRAKIESZONKOWA_H_
#define GRAKIESZONKOWA_H_
#include <iostream>
#include <string>
#include "gra.h"

using namespace std;

class GraKieszonkowa : public Gra
{
//nowe skladniki prywatne
private:
    int nr_kiesz;
    int dlugosc;
    int szerokosc;
public:
    static int licz_kiesz;
    GraKieszonkowa();
    GraKieszonkowa(const std::string & nazwa,  int & liczba_graczy, float & cen, int & dlugosc, int & szerokosc);
    ~GraKieszonkowa();
    //void pokazGra();
    virtual void dostepneGry();
    GraKieszonkowa & operator=(const GraKieszonkowa &wzor);
   // bool operator!();
    friend bool operator<(const GraKieszonkowa &g1, const GraKieszonkowa &g2);
    // void zmienStatusT(int nr_kli);
    //void zmienStatusF();
    friend ostream & operator<<(ostream & wyj, const GraKieszonkowa & g);
};

#endif // GRA_H_
