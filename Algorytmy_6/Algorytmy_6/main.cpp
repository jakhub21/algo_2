
#include <iostream>
#include<cmath>
template<typename T> class Kopiec{
public:
    int rozmiar = 0;
    int maks_rozmiar = 1;
    T* kopiec;
    
    Kopiec()
    {
        kopiec = new T[maks_rozmiar];
    }
    
    void swap_gora(int index){
        if(index != 0){
            int rodzic =floor((index-1)/2);
            if(kopiec[index]>kopiec[rodzic]){
                T tmp = kopiec[rodzic];
                kopiec[rodzic] = kopiec[index];
                kopiec[index] = tmp;
                swap_gora(rodzic);
            }
        }
    }
    
    void swap_dol(int index){
        if(index<rozmiar-1){
            int l_dziecko = 2*index+1;
            int p_dziecko = 2*index+2;
            if(l_dziecko <= rozmiar-1 || p_dziecko < rozmiar-1){
                if(kopiec[l_dziecko]>=kopiec[p_dziecko]){
                    if(kopiec[index]<kopiec[l_dziecko]){
                        T tmp = kopiec[index];
                        kopiec[index] = kopiec[l_dziecko];
                        kopiec[l_dziecko] = tmp;
                        swap_dol(l_dziecko);
                    }
                }
                else{
                    if(kopiec[index]<kopiec[p_dziecko]){
                        T tmp = kopiec[index];
                        kopiec[index] = kopiec[p_dziecko];
                        kopiec[p_dziecko] = tmp;
                        swap_dol(p_dziecko);
                    }
                }
            }
        }
    }
    
    void dodawanie(T nowe_dane){
        if(rozmiar == maks_rozmiar)
        {
            maks_rozmiar = maks_rozmiar * 2;
            T* tmp;
            tmp = new T[maks_rozmiar];
            for(int i=0; i<rozmiar; i++)
            {
                tmp[i] = kopiec[i];
            }
            delete[] kopiec;
            kopiec = tmp;
            tmp[rozmiar] = nowe_dane;
            swap_gora(rozmiar);
            rozmiar++;
        }
        else
        {
            kopiec[rozmiar] = nowe_dane;
            swap_gora(rozmiar);
            rozmiar++;
        }
    }
    
    T usuwanie(){
        if(rozmiar != 0)
        {
            T tmp = kopiec[0];
            kopiec[0] = kopiec[rozmiar-1];
            rozmiar--;
            swap_dol(0);
            return tmp;
        }
        return NULL;
    }
    
    
    void usuniecie_wszystkich_elementow(){
        delete [] kopiec;
        rozmiar = 0;
        maks_rozmiar = 1;
        kopiec = new T[maks_rozmiar];
    }
    
    std::string zwrocenie_napisowej_reprezentacji_listy(std::string(*str)(T))
    {
        std::string dane = "";
        for(int i = 0; i<rozmiar; i++)
        {
            if(str != NULL)
            {
                dane = dane + str(kopiec[i]);
            }
        }
        return dane;
    }
    T& operator[](int);
};

template<typename T> T& Kopiec<T>::operator[](int indeks)
{
    return *(kopiec + indeks);
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
    friend bool operator ==( Ubrania x, Ubrania y);
    friend bool operator <( Ubrania x, Ubrania y);
    friend bool operator >( Ubrania x, Ubrania y);
    friend bool operator >=( Ubrania x, Ubrania y);
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

bool operator >=( Ubrania x, Ubrania y)
{
    return (x.rozmiar >= y.rozmiar );
}


std::string Ubrania_str(Ubrania u)
{
   std::string tmp = u.marka + " " + std::to_string(u.rozmiar)+"\n";
   return tmp;
}


int main() {
    
//    Kopiec<int>kopiec;
//    kopiec.dodawanie(50);
//    kopiec.dodawanie(300);
//    kopiec.dodawanie(7);
//    kopiec.dodawanie(4);
//    kopiec.dodawanie(6);
//    kopiec.dodawanie(20);
//    kopiec.dodawanie(1);
//    std::cout<<kopiec.zwrocenie_napisowej_reprezentacji_listy(str)<<std::endl;
//    std::cout<<kopiec.usuwanie()<<std::endl;
//    std::cout<<kopiec.zwrocenie_napisowej_reprezentacji_listy(str)<<std::endl;
    
//    for(int i = 0; i< 1000;i++){
//        kopiec.dodawanie();
    //}
//    for(int i = 0; i< 7;i++){
//        std::cout<<kopiec.usuwanie()<<std::endl;
//    }
    
    
    Kopiec<Ubrania*> *cokolwiek = new Kopiec<Ubrania*>();
    for ( int o = 1; o <= 7 ; o++)
        {
            const int n = pow (10 , o ) ;
            clock_t t1 = clock () ;

            for ( int i = 0; i < n ; i ++)
            {
                Ubrania *tmp = new Ubrania;
                int tmp_int = (rand()<<15)+rand();
                tmp -> marka = "nike";
                tmp -> rozmiar = tmp_int;//rand()%30+50;
                cokolwiek -> dodawanie(tmp);
            }
            clock_t t2 = clock () ;
            double t = (double)(t2 - t1)/CLOCKS_PER_SEC;
            std::cout<<"Czas dodawania: "+ std::to_string(t)+"s n= "<<n<<std::endl;
            // pobiranie i usuwanie
            t1 = clock () ;
            for ( int i = 0; i < n ; i ++)
            {
                Ubrania *polled = cokolwiek -> usuwanie();
                delete polled;
            }
            t2 = clock () ;
            t = (double)(t2 - t1)/CLOCKS_PER_SEC;
            std::cout<<"Czas szukania: "+ std::to_string(t)+"s"<<std::endl;
            cokolwiek -> usuniecie_wszystkich_elementow();
        }

        delete cokolwiek;
    return 0;
}
