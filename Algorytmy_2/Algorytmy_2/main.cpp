
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
 
class Ubrania
{
public:
    std::string marka;
    int rozmiar;
};

std::string Ubrania_str(Ubrania u)
{
   std::string tmp = u.marka + " " + std::to_string(u.rozmiar)+" ";
   return tmp;
}

std::string Ubrania_str_wskaznik(Ubrania *u)
{
   std::string tmp = u -> marka + " " + std::to_string(u -> rozmiar)+" ";
   return tmp;
}

int main() {

    TablicaDynamiczna<int>tablica;
    tablica.dodanie_elementu_na_koncu(5);
    tablica.dodanie_elementu_na_koncu(3);
    tablica.dodanie_elementu_na_koncu(7);
    tablica.dodanie_elementu_na_koncu(4);
    tablica.dodanie_elementu_na_koncu(1);
    //std::cout<<tablica.zwrocenie_danych_i_elementu(2)<<std::endl;
    tablica.ustawienie_danych_i_elementu(2,5);
    //tablica.usuniecie_wszystkich_elementow();
//    for(int i = 0; i<4; i++)
//    {
//        std::cout<<tablica[i]<<std::endl;
//    }
//    tablica.dodanie_elementu_na_koncu(3);
//    tablica.sortowanie_babelkowe();

    std::cout<<tablica.zwrocenie_napisowej_reprezentacji_listy(str)<<std::endl;
    /*TablicaDynamiczna<Ubrania> *cokolwiek = new TablicaDynamiczna<Ubrania>();
    for(int j =0; j<8; j++)
    {
        int n = pow(10, j);
        clock_t t1 = clock () ;
        for(int i =0; i<n; i++)
        {
            Ubrania tmp;
            tmp.marka = "nike";
            tmp.rozmiar = rand()%30+50;
            cokolwiek -> dodanie_elementu_na_koncu(tmp);
        }
        clock_t t2 = clock ();
        double t = (double)(t2 - t1)/CLOCKS_PER_SEC;
        std::cout<<"Czas: "+ std::to_string(t)+"s"<<std::endl;
    }*/
    /*for(int i = 0; i<10; i++)
    {
        Ubrania tmp;
        tmp.marka = "addidas";
        tmp.rozmiar = rand()%30+50;
        cokolwiek -> dodanie_elementu_na_koncu(tmp);
    }
    std::cout<<cokolwiek -> zwrocenie_napisowej_reprezentacji_listy(Ubrania_str)<<std::endl;
*/
//
//    TablicaDynamiczna< Ubrania* >* da = new TablicaDynamiczna< Ubrania* >();
//    const int order = 7;
//    const int n = pow (10 , order );
//    // dodawanie do tablicy
//    clock_t t1 = clock ();
//    double max_time_per_element = 0.0; // najgorszy zaobserwowany czas operacji dodawania
//    for ( int i = 0; i < n ; i ++)
//    {
//        Ubrania *tmp = new Ubrania;
//        tmp -> marka = "nike";
//        tmp -> rozmiar = rand()%30+50;
//        clock_t t1_element = clock ();
//        da -> dodanie_elementu_na_koncu(tmp);
//        clock_t t2_element = clock ();
//        double time_per_element = (double)(t2_element-t1_element)/CLOCKS_PER_SEC;
//        if ( time_per_element > max_time_per_element )
//            {
//                max_time_per_element = time_per_element;
//                std::cout<<"Odnotowanie nowego najgorszego czasu: "<< max_time_per_element * 1000000 << " mikrosekund mialo to miejsce przy indeksie: " << i << std:: endl;
//            }
//    }
//    clock_t t2 = clock ();
//    double time_per_element = (double)(t2 - t1)/CLOCKS_PER_SEC;
//    std::cout<<"Czas: "+ std::to_string(time_per_element)+"s"<<std::endl;
//    std::cout<< da -> zwrocenie_napisowej_reprezentacji_listy(Ubrania_str_wskaznik)<<std::endl;
//    da -> usuniecie_wszystkich_elementow();
//    delete da;
    return 0;
}
