
#include <iostream>
#include <string>
#include "time.h"
#include "math.h"
using namespace std;

template<typename T> class Obiekt_lista
{
public:
    Obiekt_lista<T> *poprzedni;
    Obiekt_lista<T> *nastepny;
    T dane;
    ~Obiekt_lista(){poprzedni = NULL; nastepny = NULL;}
};

template<typename T> class Lista
{
public:
    Obiekt_lista<T> *glowa;
    Obiekt_lista<T> *ogon;
    int rozmiar = 0;
    
    void dodanie_elementu_na_poczatku(T nowe_dane)
    {
        Obiekt_lista<T> *tmp;
        tmp = new Obiekt_lista<T>;
        tmp -> dane = nowe_dane;
        if(rozmiar == 0)
        {
            glowa = tmp;
            ogon = tmp;
            tmp -> nastepny = NULL;
            tmp -> poprzedni = NULL;
        }
        else
        {
            tmp -> nastepny = glowa;
            tmp -> poprzedni = NULL;
            glowa -> poprzedni = tmp;
            glowa = tmp;
        }
        rozmiar++;
    }
    void dodanie_elementu_na_koncu(T nowe_dane)
    {
        Obiekt_lista<T> *tmp;
        tmp = new Obiekt_lista<T>;
        tmp -> dane = nowe_dane;
        if(rozmiar == 0)
        {
            glowa = tmp;
            ogon = tmp;
            tmp -> poprzedni = NULL;
            tmp -> nastepny = NULL;
        }
        else
        {
            tmp -> poprzedni = ogon;
            tmp -> nastepny = NULL;
            ogon -> nastepny = tmp;
            ogon = tmp;
        }
        rozmiar++;
    }
    void usuniecie_elementu_na_koncu()
    {
        if(rozmiar == 0)
        {
            return;
        }
        else
        {
            Obiekt_lista<T> *tmp;
            tmp = ogon;
            
                ogon = tmp -> poprzedni;
                delete tmp;
        }
        rozmiar--;
    }
    void usuniecie_elementu_na_poczatku()
    {
        if(rozmiar == 0)
        {
            return;
        }
        else
        {
            Obiekt_lista<T> *tmp;
            tmp = glowa;
            glowa = tmp -> nastepny;
            delete tmp;
        }
        rozmiar--;
    }
    
    T zwrocenie_danych_i_elementu_listy(int szukana)
    {
        if(rozmiar == 0)
        {
            return NULL;
        }
        else
        {
            if(rozmiar/2 > szukana)
            {
                Obiekt_lista<T> *tmp;
                tmp = glowa;
                for(int i = 1; i<=szukana ;i++)
                {
                   
                    if(i == szukana)
                    {
                        return tmp -> dane;
                    }
                    tmp = tmp -> nastepny;
                }
            }
            else
            {
                Obiekt_lista<T> *tmp;
                tmp = ogon;
                for(int i = rozmiar - 1; i>=szukana ;i--)
                {
                    if(i == szukana)
                    {
                        return tmp -> dane;
                    }
                    tmp = tmp -> poprzedni;
                }
                
            }
                
        }
        return NULL;
    }
    
    void ustawienie_danych_i_elementu(int indeks, T nowe_dane)
    {
        if(rozmiar == 0)
        {
            return;
        }
        else
        {
            Obiekt_lista<T> *tmp;
            tmp = glowa;
            for(int i = 1; i<=indeks ;i++)
            {
                if(indeks>rozmiar)
                {
                    return;
                }
                else
                {
                    if(i == indeks)
                    {
                        tmp -> dane = nowe_dane ;
                    }
                    tmp = tmp -> nastepny;
                }
            }
        }
    }
    
    Obiekt_lista<T>* wyszukanie_elementu(T szukane_dane)
    {
        if(rozmiar == 0)
        {
            return NULL;
        }
        else
        {
            Obiekt_lista<T> *tmp;
            tmp = glowa;
            for(int i = 1; i<=rozmiar; i++)
            {
                if(tmp -> dane == szukane_dane)
                {
                    return tmp;
                }
                tmp = tmp -> nastepny;
            }
        }
        return NULL;
    }
    
    T wyszukanie_i_usuniecie_elementu(T szukane_dane)
    {
        bool flaga = false;
        if(rozmiar == 0)
        {
            return flaga;
        }
        else
        {
            Obiekt_lista<T> *tmp = wyszukanie_elementu(szukane_dane);
            if(tmp == glowa)
            {
                usuniecie_elementu_na_poczatku(true);
                flaga = true;
                return flaga;
                
            }
            else if(tmp == ogon)
            {
                usuniecie_elementu_na_koncu(true);
                flaga = true;
                return flaga;
            }
            else
            {
                tmp -> poprzedni -> nastepny = tmp -> nastepny;
                tmp -> nastepny -> poprzedni = tmp -> poprzedni;
                delete tmp;
                flaga = true;
                return flaga;

            }
            
        rozmiar--;
        }
    return flaga;
    }
    
    void dodanie_nowego_elementu_z_wymuszeniem_porzadku(T nowe_dane)
    {
       if(rozmiar == 0 || nowe_dane < glowa -> dane)
       {
           dodanie_elementu_na_poczatku(nowe_dane);
           return;
       }
        
        Obiekt_lista<T> *tmp;
        Obiekt_lista<T> *tmp2;
        tmp = glowa;
        for(int i = 0; i<rozmiar ;i++)
        {
            if(tmp -> dane < nowe_dane)
            {
                tmp = tmp -> nastepny;
            }
            else
            {
                tmp2 = new Obiekt_lista<T>;
                tmp2 -> dane = nowe_dane;
                if(rozmiar == 1)
                {
                    tmp -> nastepny = tmp2;
                }
                else
                {
                    tmp -> poprzedni -> nastepny = tmp2;
                    tmp2 -> poprzedni = tmp -> nastepny;
                    tmp -> poprzedni = tmp2;
                }
                tmp2 -> nastepny = tmp;
                rozmiar++;
                return;
            }
        }
    dodanie_elementu_na_koncu(nowe_dane);
    }
    
    void usuniecie_wszystkich_elementow()
    {
        if (rozmiar == 0)
        {
            return;
        }
        else
        {
            while(rozmiar != 0)
            {
                usuniecie_elementu_na_poczatku();
            }
        }
    }
    
    string zwrocenie_napisowej_reprezentacji_listy(string(*str)(T))
    {
        string dane = "";
        Obiekt_lista<T> *tmp;
        tmp = glowa;
        for(int i = 0; i<rozmiar; i++)
        {
            if(str != NULL)
            {
                dane = dane + str(tmp -> dane);
            }
            else
            {
                //tmp = tmp + tmp2;
            }
            tmp = tmp -> nastepny;
        }
        return dane;
    }
};

template<typename T> string str(T dane)
{
    string tmp = to_string(dane)+"\n";
    return tmp;
}

class Ubrania
{
public:
    string marka;
    int rozmiar;
    friend bool operator ==( Ubrania x, Ubrania y);
    friend bool operator <( Ubrania x, Ubrania y);
    friend bool operator >( Ubrania x, Ubrania y);
};

bool operator ==( Ubrania x, Ubrania y)
{
    return (x.rozmiar == y.rozmiar && x.marka == y.marka);
}

bool operator <( Ubrania x, Ubrania y)
{
    return (x.rozmiar < y.rozmiar);
}

bool operator >( Ubrania x, Ubrania y)
{
    return (x.rozmiar > y.rozmiar);
}

string Ubrania_str(Ubrania u)
{
   string tmp = u.marka + " " + to_string(u.rozmiar)+"\n";
   return tmp;
}

int main() {
    
    Lista<Ubrania> *cokolwiek = new Lista<Ubrania>();
    for(int j =0; j<3; j++)
    {
        int n = pow(10, j);
        clock_t t1 = clock () ;
        for(int i =0; i<n; i++)
        {
            Ubrania tmp;
            tmp.marka = "nike";
            tmp.rozmiar = rand()%30+50;
            cokolwiek -> dodanie_nowego_elementu_z_wymuszeniem_porzadku(tmp);
        }
        clock_t t2 = clock ();
        double t = (double)(t2 - t1)/CLOCKS_PER_SEC;
        cout<<"Czas: "+ to_string(t)+"s"<<endl;
    }
    cout<<cokolwiek -> zwrocenie_napisowej_reprezentacji_listy(Ubrania_str)<<endl;
   /* for(int i = 0; i<5; i++)
    {
        Ubrania tmp;
        tmp.marka = "addidas";
        tmp.rozmiar = rand()%30+50;
        cokolwiek -> dodanie_nowego_elementu_z_wymuszeniem_porzadku(tmp);
    }
    cout<<cokolwiek -> zwrocenie_napisowej_reprezentacji_listy(Ubrania_str)<<endl;
    /*clock_t t2 = clock ();
    clock_t t = (t2 - t1);
    cout<<"Czas: "+ to_string(t)<<endl;*/
    //cout<<cokolwiek -> zwrocenie_napisowej_reprezentacji_listy(Ubrania_str)<<endl;
    
    //Lista <int> lista;
    /*lista.dodanie_elementu_na_koncu(5);
    lista.dodanie_elementu_na_koncu(1);
    lista.dodanie_elementu_na_koncu(4);
    lista.dodanie_elementu_na_poczatku(1);
    lista.dodanie_elementu_na_poczatku(6);
    lista.dodanie_elementu_na_poczatku(8);
    lista.dodanie_elementu_na_poczatku(9);
    lista.dodanie_elementu_na_poczatku(0);
    lista.dodanie_elementu_na_poczatku(7);
    //lista.usuniecie_elementu_na_poczatku(true);
    //lista.usuniecie_elementu_na_koncu(false);
    cout<<lista.zwrocenie_danych_i_elementu_listy(2)<<endl;
    lista.wyszukanie_i_usuniecie_elementu(9);
    
    cout<<lista.wyszukanie_elementu(8) -> dane <<endl;*/
    /*lista.dodanie_nowego_elementu_z_wymuszeniem_porządku(2);
    lista.dodanie_nowego_elementu_z_wymuszeniem_porządku(5);
    lista.dodanie_nowego_elementu_z_wymuszeniem_porządku(6);
    lista.dodanie_nowego_elementu_z_wymuszeniem_porządku(1);
    lista.dodanie_nowego_elementu_z_wymuszeniem_porządku(8);
    lista.dodanie_nowego_elementu_z_wymuszeniem_porządku(0);
    lista.dodanie_nowego_elementu_z_wymuszeniem_porządku(3);
    lista.usuniecie_elementu_na_poczatku(true);
    lista.usuniecie_elementu_na_poczatku(true);
    cout<<lista.zwrocenie_napisowej_reprezentacji_listy(str)<<endl;
    //lista.usuniecie_wszystkich_elementow(true);
    lista.dodanie_elementu_na_poczatku(4);*/
    
    
    
    

    return 0;
}
