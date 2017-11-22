//klasa Gra
#ifndef GRA_H_
#define GRA_H_
#include <iostream>
#include <string>

using namespace std;

class Gra
{
//skladniki prywatne
protected:
    int nr_gry;
    std::string nazwa;
    bool stat;
    int liczba_graczy;
    float cena;
    int nr_klient;

//skladniki prywatne
public:
    static int licz_gry;
    Gra();
    Gra(const std::string & nazwa,  int & liczba_graczy, float & cen);
   // Gra (const Gra & g);
    ~Gra();
    //void pokazGra();
    virtual void dostepneGry();
    Gra & operator=(const Gra &wzor);
    bool operator!();
    bool operator<(const Gra &g);
    void zmienStatusT(int nr_kli);
    void zmienStatusF();
    friend ostream & operator<<(ostream & wyj, const Gra & g);
};

#endif // GRA_H_
