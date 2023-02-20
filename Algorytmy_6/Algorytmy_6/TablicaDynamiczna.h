#pragma one
#include <iostream>
#include <string>
#include "time.h"
#include "math.h"
#include <iomanip>

template<typename T> class TablicaDynamiczna
{
public:
    int rozmiar = 0;
    int maks_rozmiar = 1;
    T* tablica;
    
    TablicaDynamiczna()
    {
        tablica = new T[maks_rozmiar];
    }
    
    void dodanie_elementu_na_koncu(T nowe_dane)
    {
        if(rozmiar == maks_rozmiar)
        {
            maks_rozmiar = maks_rozmiar * 2;
            T* tmp;
            tmp = new T[maks_rozmiar];
            for(int i=0; i<rozmiar; i++)
            {
                tmp[i] = tablica[i];
            }
            tmp[rozmiar] = nowe_dane;
            delete [] tablica;
            tablica = tmp;
            rozmiar++;
        }
        else
        {
            tablica[rozmiar] = nowe_dane;
            rozmiar++;
        }
        
    }
    
    T zwrocenie_danych_i_elementu(int indeks)
    {
        if(rozmiar == 0)
        {
            return NULL;
        }
        else
        {
            return tablica[indeks];
        }
    }
    
    void ustawienie_danych_i_elementu(int indeks,T nowe_dane)
    {
        if(rozmiar == 0)
        {
            return;
        }
        else
        {
            for(int i = 0;i<rozmiar;i++)
            {
                if(i == indeks)
                {
                    tablica[i] = nowe_dane;
                }
            }
        }
    }
    void usuniecie_wszystkich_elementow()
    {
        delete [] tablica;
        rozmiar = 0;
    }
    
    std::string zwrocenie_napisowej_reprezentacji_listy(std::string(*str)(T))
    {
        std::string dane = "";
        for(int i = 0; i<rozmiar; i++)
        {
            if(str != NULL)
            {
                dane = dane + str(tablica[i]);
            }
        }
        return dane;
    }
    
    void sortowanie_babelkowe()
    {
        T tmp;
        for(int i = 0; i < rozmiar; i++)
        {
            for(int j = 1; j < rozmiar; j++)
            {
                if(tablica[j-1] > tablica[j])
                {
                    tmp = tablica[j];
                    tablica[j] = tablica[j-1];
                    tablica[j-1] = tmp;
                }
            }
        }
    }
    
    T operator[](int);

};


template<typename T> T TablicaDynamiczna<T>::operator[](int indeks)
{
    return *(tablica + indeks);
}

template<typename T> std::string str(T obiekt)
{
        std::string tmp = std::to_string(obiekt)+" ";
        return tmp;
}
