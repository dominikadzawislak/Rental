// Wypozyczalnia gier planszowych
//Dominika Zawiœlak
#include <string>
#include "wypozyczalnia.h"
#include "gra.h"
#include "grakieszonkowa.h"
#include "klient.h"

void pmenu();
using namespace std;

int main()
{
    //c1, c6, c8 zmienne ktore blokuja wywolanie funkcji,np. gdy nie dodano zadnych gier lub klientow
    bool c1=false;
    bool c6=false;
    bool c8=false;
    bool c9=false;
    Wypozyczalnia wyp;

    pmenu();
    int wybor;
    cin >> wybor;
    while (wybor)
    {
    //sprawdzenie poprawnosci implementacji
    //wywolanie metod i funkcji skladowch klasy wypozyczalnia
     switch(wybor)
    {
        case 1:
          {
            wyp.dodajGry();
            c1=true; //oznacza, ze dodano nowa gre (wiec mozna wywolac metody na kopiowanie, przypisanie itd. dla gier)
          }
          break;

        case 2:
          { if (c1)
                wyp.miniKieszonkowa();
            else
                cout<< "Nie dodano zadnej gry kieszonkowej" <<endl;
          }
          break;
        case 3:
          {
            if(c1) wyp.najtanszaGra();
            else cout <<"Nie dodano zadnych gier " <<endl;
          }
          break;
        case 4:
          {
            if(c1) wyp.pokazDostepneGry();
            else cout <<"Nie dodano zadnych gier " <<endl;
          }
          break;

        case 5:
          {
            if(c1) wyp.pokazGry();
            else cout <<"Nie dodano zadnych gier " <<endl;
          }
          break;

        case 6:
          {
            wyp.dodajKlienta();
            c6 =true; //oznacza, ze dodano nowego klienta
          }
          break;

        case 7:
          {
            if(c6) wyp.pokazKlientow();
            else cout <<"Nie dodano klientow " <<endl;
          }
          break;

        case 8:
          {
            if(!c1 || !c6) //jesli nie dodano wczesniej gry lub klienta
                cout <<"brak klientow lub gier "<< endl;
            else
            {
                wyp.pozyczGre();
                c8=true; //oznacza, ze wypozyczono gre (wiec mozna wywolac metode oddajGre)
            }
          }
          break;
         case 9:
          {
            if(!c1 || !c6) //jesli nie dodano wczesniej gry lub klienta
                cout <<"brak klientow lub gier "<< endl;
            else
            {
                wyp.pozyczKieszonkowa();
                c9=true; //oznacza, ze wypozyczono gre (wiec mozna wywolac metode oddajGre)
            }
          }
          break;

        case 10:
          {
            if(!c8)
                cout <<"brak pozyczonych gier "<< endl;
            else
                wyp.oddajGre();
          }
          break;
         case 11:
          {
            if(!c9)
                cout <<"brak pozyczonych gier kieszonkowych "<< endl;
            else
                wyp.oddajKieszonkowa();
          }
          break;


        default: cout << "Nie ma takiej opcji" <<endl;
       }

        pmenu();
        cin >> wybor;
}
        cout <<"Do widzenia    Zapraszamy ponownie";
        return 0;
}

//wyswietlane menu
void pmenu()
{
   cout<<"Podaj numer dzialania ktore chcesz wykonac" <<endl
    <<"1. Dodaj nowa gre"<<endl
    <<"2. Najmniejsza gra - wszedzie sie zmiesci"<<endl
    <<"3. Promocja dnia!!! (najtansza gra)"<<endl
    <<"4. Pokaz dostepne gry"<<endl
    <<"5. Pokaz wszystkie gry"<<endl
    <<"6. Dodaj nowego klienta"<<endl
    <<"7. Wyswietl liste klientow"<<endl
    <<"8. Wypozycz normalna gre"<<endl
    <<"9. Wypozycz gre kieszonkowa"<<endl
    <<"10. Oddaj normalna gre"<<endl
    <<"11. Oddaj gre kieszonkowa"<<endl
    <<"0. Koniec"<<endl;
}
