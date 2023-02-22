
#include <iostream>
#include <string>
#include <math.h>


template<typename T> class Wezel
{
public:
    Wezel<T> *rodzic = NULL;
    Wezel<T> *l_obiekt = NULL;
    Wezel<T> *p_obiekt = NULL;
    int index;
    T dane;
};

template<typename T> class Drzewo
{
public:
    Wezel<T> *korzen;
    int rozmiar = 0;
    
    
    
    void dodanie_elementu(T nowe_dane)
    {
        Wezel<T> *tmp;
        tmp = new Wezel<T>;
        tmp -> dane = nowe_dane;
        if(rozmiar == 0)
        {
            korzen  = tmp;
            tmp -> index = rozmiar;
            rozmiar++;
        }
        else
        {
            bool sprawdzenie = false;
            Wezel<T> *tmp2;
            tmp2 = korzen;
            while (sprawdzenie != true){
                if(nowe_dane <= tmp2 -> dane)
                {
                    if (tmp2 -> l_obiekt != NULL)
                    {
                        tmp2 = tmp2 -> l_obiekt;
                        
                    }
                    else
                    {
                        tmp -> rodzic = tmp2;
                        tmp2 -> l_obiekt = tmp;
                        tmp -> index = rozmiar;
                        sprawdzenie = true;
                        rozmiar++;
                    }
                    
                }
                else
                {
                    if (tmp2 -> p_obiekt != NULL)
                    {
                        tmp2 = tmp2 -> p_obiekt;
                    }
                    else
                    {
                        tmp -> rodzic = tmp2;
                        tmp2 -> p_obiekt = tmp;
                        tmp -> index = rozmiar;
                        sprawdzenie = true;
                        rozmiar++;
                    }
                }
            }
        }
    }
    
    Wezel<T>* szukanie_elementu(T szukana)
    {
        if(rozmiar == 0)
        {
            return NULL;
        }
        else
        {
            if(korzen -> dane == szukana)
            {
                return korzen;
            }
            else
            {
                bool sprawdzenie = false;
                Wezel<T> *tmp2;
                tmp2 = korzen;
                while (!sprawdzenie){
                    if(szukana < tmp2 -> dane)
                    {
                        if (tmp2 -> l_obiekt != NULL)
                        {
                            tmp2 = tmp2 -> l_obiekt;
                        }
                        else
                        {
                            sprawdzenie = true;
                        }
                    }
                    else if (szukana > tmp2 ->dane)
                    {
                        if (tmp2 -> p_obiekt != NULL)
                        {
                            tmp2 = tmp2 -> p_obiekt;
                        }
                        else
                        {
                            sprawdzenie = true;
                        }
                    }
                    else
                    {
                        return tmp2;
                    }
                }
            }
        }
        return NULL;
    }
    
    void UsuwanieElementu(Wezel<T>* szukana)
    {
        if(szukana == NULL)
        {
            return;
        }
        else
        {
            if(szukana -> l_obiekt == NULL && szukana -> p_obiekt == NULL)
            {
                if(szukana == korzen)
                {
                    delete korzen;
                    korzen = NULL;
                    rozmiar--;
                }
                else
                {
                    if(szukana -> rodzic -> p_obiekt == szukana)
                    {
                        szukana -> rodzic -> p_obiekt = NULL;
                    }
                    else
                    {
                        szukana -> rodzic -> l_obiekt = NULL;
                    }
                    delete szukana;
                    rozmiar--;
                }
            }
            else if (szukana -> l_obiekt != NULL && szukana -> p_obiekt == NULL)
            {
                if(szukana == korzen)
                {
                    korzen = szukana -> l_obiekt;
                }
                else
                {
                    if(szukana -> rodzic -> p_obiekt == szukana)
                    {
                        szukana -> rodzic -> p_obiekt = szukana -> l_obiekt;
                    }
                    else
                    {
                        szukana -> rodzic -> l_obiekt = szukana -> l_obiekt;
                    }
                }
                delete szukana;
                rozmiar--;
            }
            else if (szukana -> l_obiekt == NULL && szukana -> p_obiekt != NULL)
            {
                if(szukana == korzen)
                {
                    korzen = szukana -> p_obiekt;
                }
                else
                {
                    if(szukana -> rodzic -> p_obiekt == szukana)
                    {
                        szukana -> rodzic -> p_obiekt = szukana -> l_obiekt;
                    }
                    else
                    {
                        szukana -> rodzic -> l_obiekt = szukana -> l_obiekt;
                    }
                }
                delete szukana;
                rozmiar--;
            }
            else
            {
                Wezel<T>*tmp;
                tmp = szukana -> l_obiekt;
                while(tmp -> p_obiekt != NULL)
                {
                    tmp = tmp -> p_obiekt;
                }
                
                szukana -> dane = tmp -> dane;
                if(tmp -> l_obiekt == NULL)
                {
                    tmp -> rodzic -> p_obiekt = NULL;
                }
                else
                {
                    tmp -> rodzic -> p_obiekt = tmp -> l_obiekt;
                    tmp -> l_obiekt -> rodzic = tmp -> rodzic;
                }
                delete tmp;
                rozmiar--;
            }
        }
    }
    
    void InOrder(Wezel<T>*wezel)
    {
        if(wezel == NULL)
        {
            return;
        }
        else
        {
            InOrder(wezel -> l_obiekt);
            std::cout<<wezel->dane<<std::endl;
            InOrder(wezel -> p_obiekt);
        }
    }
    
    void PreOrder(Wezel<T>*wezel)
    {
        if(wezel == NULL)
        {
            return;
        }
        else
        {
            std::cout<<wezel->dane<<std::endl;
            PreOrder(wezel -> l_obiekt);
            PreOrder(wezel -> p_obiekt);
        }
    }
   
    void CzyszczenieDrzewa(Wezel<T>*wezel)
    {
       if(wezel == NULL)
       {
           return;
       }
        CzyszczenieDrzewa(wezel->l_obiekt);
        CzyszczenieDrzewa(wezel->p_obiekt);
        delete wezel;
        rozmiar = 0;
    }
    
    
    int wysokosc_drzewa(Wezel<T>*wezel)
    {
        if(wezel == NULL)
        {
            return 0;
        }
        else
        {
            int l_wysokosc = wysokosc_drzewa(wezel -> l_obiekt);
            int p_wysokosc = wysokosc_drzewa(wezel -> p_obiekt);
            
            if(l_wysokosc > p_wysokosc)
            {
                return (l_wysokosc + 1);
            }
            else
            {
                return (p_wysokosc + 1);
            }

        }
    }
    
    
    std::string zwrocenie_napisowej(std::string(*str)(T),Wezel<T>*tmp)
    {
        if(tmp == NULL)
        {
            return "";
        }
        std::string dane ="";
        if(tmp -> rodzic != NULL)
        {
            dane = dane + std::to_string(tmp -> index);
            dane = dane + ": [r: " + std::to_string(tmp -> rodzic -> index);
        }
        else
        {
            dane = dane + std::to_string(tmp -> index) +": [r: NULL";
        }
        if(tmp -> p_obiekt != NULL)
        {
            dane = dane + ", p: " +std::to_string(tmp -> p_obiekt -> index);
        }
        else
        {
            dane = dane + ", p: NULL";
        }
        if(tmp -> l_obiekt != NULL)
        {
            dane = dane + ", l: " +std::to_string(tmp -> l_obiekt -> index);
        }
        else
        {
            dane = dane + ", l: NULL";
        }
        
        dane = dane +"], dane: " + str(tmp -> dane) ;
        dane = dane + zwrocenie_napisowej(str, tmp -> l_obiekt);
        dane = dane + zwrocenie_napisowej(str, tmp -> p_obiekt);

        return dane;
    }
};
template<typename T> std::string str(T dane)
{
    std::string tmp = std::to_string(dane)+"\n";
    return tmp;
}

class Ubrania
{
public:
    std::string marka;
    int rozmiar;
    friend bool operator ==( Ubrania x, Ubrania y);
    friend bool operator <( Ubrania x, Ubrania y);
    friend bool operator >( Ubrania x, Ubrania y);
    friend bool operator <=( Ubrania x, Ubrania y);
};

bool operator ==( Ubrania x, Ubrania y)
{
    return (x.rozmiar == y.rozmiar && x.marka == y.marka);
}

bool operator <( Ubrania x, Ubrania y)
{
    return (x.rozmiar < y.rozmiar );
}

bool operator >( Ubrania x, Ubrania y)
{
    return (x.rozmiar > y.rozmiar);
}

bool operator <=( Ubrania x, Ubrania y)
{
    return (x.rozmiar <= y.rozmiar );
}


std::string Ubrania_str(Ubrania u)
{
   std::string tmp = u.marka + " " + std::to_string(u.rozmiar)+"\n";
   return tmp;
}

int main() {
    Drzewo<int> drzewo;
    drzewo.dodanie_elementu(50);
    drzewo.dodanie_elementu(20);
    drzewo.dodanie_elementu(66);
    drzewo.dodanie_elementu(10);
    drzewo.dodanie_elementu(35);
    drzewo.dodanie_elementu(5);
    drzewo.dodanie_elementu(2);
    drzewo.dodanie_elementu(7);
    drzewo.dodanie_elementu(52);
    drzewo.dodanie_elementu(55);
    drzewo.dodanie_elementu(57);
    drzewo.dodanie_elementu(53);
    drzewo.dodanie_elementu(56);
    drzewo.dodanie_elementu(70);
    drzewo.dodanie_elementu(69);
    drzewo.dodanie_elementu(75);
    drzewo.dodanie_elementu(80);
    //drzewo.InOrder(drzewo.korzen);
    //drzewo.PreOrder(drzewo.korzen);
    //drzewo.CzyszczenieDrzewa();
    //drzewo.UsuwanieElementu(drzewo.szukanie_elementu(50));
    //std::cout<<drzewo.wysokosc_drzewa(drzewo.korzen)<<std::endl;
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;
    
    
    Drzewo<Ubrania> *cokolwiek = new Drzewo<Ubrania>();
    /*for(int j =0; j<3; j++)
    {
        int n = pow(10, j);
        clock_t t1 = clock () ;
        for(int i =0; i<n; i++)
        {
            Ubrania tmp;
            tmp.marka = "nike";
            tmp.rozmiar = rand()%30+50;
            cokolwiek -> dodanie_elementu(tmp);
        }
        clock_t t2 = clock ();
        double t = (double)(t2 - t1)/CLOCKS_PER_SEC;
        std::cout<<"Czas: "+ std::to_string(t)+"s"<<std::endl;
    }
    std::cout<<cokolwiek -> zwrocenie_napisowej(Ubrania_str,cokolwiek->korzen)<<std::endl;*/
    
    /*std::cout<<RAND_MAX<<std::endl;;
    for ( int o = 1; o <= 6 ; o ++)
    {
        const int n = pow (10 , o ) ;
        clock_t t1 = clock () ;
        
        for ( int i = 0; i < n ; i ++)
        {
            Ubrania tmp;
            tmp.marka = "nike";
            tmp.rozmiar = rand()%1000000;//rand()%30+50;
            cokolwiek -> dodanie_elementu(tmp);
        }
        int wysokosc = cokolwiek -> wysokosc_drzewa(cokolwiek->korzen);
        std::cout<<"Wysokosc drzewa: "<<wysokosc<<std::endl;
        clock_t t2 = clock () ;
        double t = (double)(t2 - t1)/CLOCKS_PER_SEC;
        std::cout<<"Czas dodawania: "+ std::to_string(t)+"s n= "<<n<<std::endl;
        std::cout<<"Stosunek wysokosci do rozmiaru: "<< float(wysokosc)/n<<std::endl;
        std::cout<<"Stosunek wysokosci do logarytmu 2: "<< float(wysokosc/log2(n))<<std::endl;
        std::cout<<"Stosunek wysokosci do logarytmu rozmiaru: "<< float(wysokosc/log2(n))<<std::endl;
        
        // wyszukiwanie
        const int m = pow (10 , 4) ;
        int hits = 0;
        t1 = clock () ;
        for ( int i = 0; i < m ; i ++)
        {
            Ubrania so;
            so.marka = "nike";
            so.rozmiar = rand()%1000000;//rand()%30+50;
            Wezel<Ubrania>*result = cokolwiek -> szukanie_elementu(so) ;
            if ( result != NULL )
            {
                hits++;
            }
        }
        cokolwiek -> CzyszczenieDrzewa(cokolwiek->korzen);
        t2 = clock () ;
        t = (double)(t2 - t1)/CLOCKS_PER_SEC;
        std::cout<<"Czas szukania: "+ std::to_string(t)+"s"<<std::endl;
        std::cout<<"Liczba trafien: "<<hits<<"\n\n"<<std::endl;
    }
    
    delete cokolwiek;*/
    return 0;
}
