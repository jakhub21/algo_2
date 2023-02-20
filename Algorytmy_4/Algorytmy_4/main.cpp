//ALGO2 IS1 220A LAB04
//Hubert Jakubiak
//jh50985@zut.edu.pl

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
    bool kolor = true; //false - Black true - Red
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
            tmp -> kolor = false;
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
                        etykieta:
                        if(tmp2 -> kolor == true){
                            if(tmp2 -> rodzic -> l_obiekt == tmp2){
                                if(tmp2 -> rodzic -> p_obiekt != NULL && tmp2 -> rodzic -> p_obiekt -> kolor == true){
                                    recolor(tmp2);
                                    recolor(tmp2 -> rodzic);
                                    recolor(tmp2 -> rodzic -> p_obiekt);
                                    if(tmp2 -> rodzic -> kolor == true){
                                        tmp = tmp2 -> rodzic;
                                        if(tmp2 -> rodzic -> rodzic != NULL){
                                            tmp2 = tmp2 -> rodzic -> rodzic;
                                            goto etykieta;
                                        }
                                    }
                                    korzen -> kolor = false;
                                }
                                else{
                                    recolor(tmp2);
                                    recolor(tmp2 -> rodzic);
                                    rotacja_w_prawo(tmp2, tmp2 -> rodzic);
                                    if(tmp -> l_obiekt != NULL){
                                    recolor(tmp -> l_obiekt);
                                    }
                                    korzen -> kolor = false;
                                }
                            }
                            else{
                                if(tmp2 -> rodzic -> l_obiekt != NULL && tmp2 -> rodzic -> l_obiekt -> kolor == true){
                                    recolor(tmp2);
                                    recolor(tmp2 -> rodzic);
                                    recolor(tmp2 -> rodzic -> l_obiekt);
                                    if(tmp2 ->rodzic -> kolor == true ){
                                        tmp = tmp2 -> rodzic;
                                        if(tmp2 -> rodzic -> rodzic != NULL){
                                            tmp2 = tmp2 -> rodzic -> rodzic;
                                            goto etykieta;
                                        }
                                    }
                                    korzen -> kolor = false;
                                }
                                else{
                                    if(tmp2 -> rodzic -> l_obiekt == tmp2){
                                        rotacja_w_prawo(tmp, tmp2);
                                        recolor(tmp2);
                                        recolor(tmp2 -> p_obiekt);
                                        korzen -> kolor = false;
                                    }
                                    else{
                                        rotacja_w_prawo(tmp, tmp2);
                                        rotacja_w_lewo(tmp, tmp->rodzic);
                                        recolor(tmp);
                                        recolor(tmp -> l_obiekt);
                                        korzen -> kolor = false;
                                    }
                                    
                                }
                            }
                            
                        }
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
                        etykieta2:
                        if(tmp2 -> kolor == true){
                            if(tmp2 -> rodzic -> p_obiekt == tmp2){
                                if(tmp2 -> rodzic -> l_obiekt != NULL && tmp2 -> rodzic -> l_obiekt -> kolor == true){
                                    recolor(tmp2);
                                    recolor(tmp2 -> rodzic);
                                    recolor(tmp2 -> rodzic -> l_obiekt);
                                    if(tmp2 -> rodzic -> kolor == true){
                                        //powtorka = true;
                                        tmp = tmp2 -> rodzic;
                                        if(tmp2 -> rodzic -> rodzic != NULL){
                                            tmp2 = tmp2 -> rodzic -> rodzic;
                                            goto etykieta2;
                                        }
                                    }
                                    korzen -> kolor = false;
                                }
                                else{
                                    rotacja_w_lewo(tmp2, tmp2 -> rodzic);
                                    recolor(tmp2);
                                    recolor(tmp2 -> l_obiekt);
                                    korzen -> kolor = false;
                                }
                            }
                            else{
                                if(tmp2 -> rodzic -> p_obiekt != NULL && tmp2 -> rodzic -> p_obiekt -> kolor == true){
                                    recolor(tmp2);
                                    recolor(tmp2 -> rodzic);
                                    recolor(tmp2 -> rodzic -> p_obiekt);
                                    if(tmp2 -> rodzic -> kolor == true){
                                        
                                        tmp = tmp2 -> rodzic;
                                        if(tmp2 -> rodzic -> rodzic != NULL){
                                            tmp2 = tmp2 -> rodzic -> rodzic;
                                            goto etykieta2;
                                        }
                                    }
                                    korzen -> kolor = false;
                                }
                                else{
                                    if(tmp2 -> rodzic -> p_obiekt == tmp2){
                                        rotacja_w_lewo(tmp2, tmp2 -> rodzic);
                                        recolor(tmp2);
                                        recolor(tmp2 -> l_obiekt);
                                        korzen -> kolor = false;
                                    }
                                    else{
                                        rotacja_w_lewo(tmp, tmp2);
                                        rotacja_w_prawo(tmp, tmp->rodzic);
                                        recolor(tmp);
                                        recolor(tmp -> p_obiekt);
                                        korzen -> kolor = false;
                                    }
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    void recolor(Wezel<T>*tmp){
//        if(tmp -> rodzic == NULL){
//            tmp -> kolor = false;
//        }
//        else{
            if(tmp -> kolor == false){
                tmp -> kolor = true;
            }
            else{
                tmp -> kolor = false;
            }
//        }
    }
    
    void rotacja_w_prawo(Wezel<T>*O_dziecko,Wezel<T>*O_rodzic)
    {
        O_dziecko = O_rodzic -> l_obiekt;
        if(O_dziecko != NULL){
            
            O_rodzic -> l_obiekt = O_dziecko -> p_obiekt;
            if(O_dziecko -> p_obiekt != NULL){
                O_dziecko -> p_obiekt -> rodzic = O_rodzic;
            }
            O_dziecko -> rodzic = O_rodzic -> rodzic;
            if(O_rodzic -> rodzic == NULL){
                korzen = O_dziecko;
            }
            else if(O_rodzic == O_rodzic -> rodzic -> p_obiekt){
                O_rodzic -> rodzic -> p_obiekt = O_dziecko;
            }
            else{
                O_rodzic -> rodzic -> l_obiekt = O_dziecko;
            }
            O_dziecko -> p_obiekt = O_rodzic;
            O_rodzic -> rodzic = O_dziecko;
        }
        else{
            return;
        }
    }
    void rotacja_w_lewo(Wezel<T>*O_dziecko,Wezel<T>*O_rodzic)
    {
        O_dziecko = O_rodzic -> p_obiekt;
        if(O_dziecko != NULL){
           
            O_rodzic -> p_obiekt = O_dziecko -> l_obiekt;
            if(O_dziecko -> l_obiekt != NULL){
                O_dziecko -> l_obiekt -> rodzic = O_rodzic;
            }
            O_dziecko -> rodzic = O_rodzic -> rodzic;
            if(O_rodzic -> rodzic == NULL){
                korzen = O_dziecko;
            }
            else if(O_rodzic == O_rodzic -> rodzic -> l_obiekt){
                O_rodzic -> rodzic -> l_obiekt = O_dziecko;
            }
            else{
                O_rodzic -> rodzic -> p_obiekt = O_dziecko;
            }
            O_dziecko -> l_obiekt = O_rodzic;
            O_rodzic -> rodzic = O_dziecko;
        }
        else{
            return;
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
        korzen = NULL;
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
        if(tmp -> kolor != false)
        {
            dane = dane + std::to_string(tmp -> index);
            dane = dane + ": [czerwony" ;
        }
        else
        {
            dane = dane + std::to_string(tmp -> index) +": [czarny";
        }
        if(tmp -> rodzic != NULL)
        {
            dane = dane + std::to_string(tmp -> index);
            dane = dane + " ,r: " + std::to_string(tmp -> rodzic -> index);
        }
        else
        {
            dane = dane + std::to_string(tmp -> index) +" ,r: NULL";
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


template<typename T> std::string str(T dane)
{
    std::string tmp = std::to_string(dane)+"\n";
    return tmp;
}
int main() {
   
    Drzewo<int> drzewo;
    drzewo.dodanie_elementu(23);
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    drzewo.dodanie_elementu(40);
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    drzewo.dodanie_elementu(30);
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    drzewo.dodanie_elementu(50);
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    drzewo.dodanie_elementu(20);
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    drzewo.dodanie_elementu(10);
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    drzewo.dodanie_elementu(25);
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    drzewo.dodanie_elementu(70);
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    drzewo.dodanie_elementu(60);
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    drzewo.dodanie_elementu(72);
    drzewo.dodanie_elementu(24);
    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;
//    int n = 10;
//    std::cout<<"Stosunek wysokosci do logarytmu rozmiaru: "<< float(drzewo.wysokosc_drzewa(drzewo.korzen)/(log2(n+1)))<<std::endl;
//    drzewo.InOrder(drzewo.korzen);
//    drzewo.PreOrder(drzewo.korzen);
//    std::cout<<drzewo.wysokosc_drzewa(drzewo.korzen)<<std::endl;
//    drzewo.CzyszczenieDrzewa(drzewo.korzen);
//    std::cout<<drzewo.zwrocenie_napisowej(str, drzewo.korzen)<<std::endl;

    Drzewo<Ubrania> *cokolwiek = new Drzewo<Ubrania>();
    
    /*for(int j =0; j<4; j++)
    {
        int n = pow(10, j);
        std::cout<<n<<std::endl;
        clock_t t1 = clock () ;
        for(int i =0; i<n; i++)
        {
            if(i == 18)
            {
                std::cout<<i<<std::endl;
            }
            Ubrania tmp;
            tmp.marka = "nike";
            tmp.rozmiar = rand()%30+50;
            cokolwiek -> dodanie_elementu(tmp);
        }
        clock_t t2 = clock ();
        double t = (double)(t2 - t1)/CLOCKS_PER_SEC;
        std::cout<<"Czas: "+ std::to_string(t)+"s"<<std::endl;
        cokolwiek -> CzyszczenieDrzewa(cokolwiek-> korzen);
    }
    std::cout<<cokolwiek -> zwrocenie_napisowej(Ubrania_str,cokolwiek->korzen)<<std::endl;
    */
    
//
//   for ( int o = 1; o <= 5 ; o ++)
//    {
//        const int n = pow (10 , o ) ;
//        clock_t t1 = clock () ;
//
//        for ( int i = 0; i < n ; i ++)
//        {
//            Ubrania tmp;
//            int tmp_int = (rand()<<15)+rand();
//            tmp.marka = "nike";
//            tmp.rozmiar = tmp_int;//rand()%30+50;
//            cokolwiek -> dodanie_elementu(tmp);
//        }
//        int wysokosc = cokolwiek -> wysokosc_drzewa(cokolwiek->korzen);
//        std::cout<<"Wysokosc drzewa: "<<wysokosc<<std::endl;
//        clock_t t2 = clock () ;
//        double t = (double)(t2 - t1)/CLOCKS_PER_SEC;
//        std::cout<<"Czas dodawania: "+ std::to_string(t)+"s n= "<<n<<std::endl;
//        std::cout<<"Stosunek wysokosci do logarytmu rozmiaru: "<< float(wysokosc/(log2(n+1)))<<std::endl;
//        std::cout<<wysokosc<<" "<<2*log2(n+1)<<std::endl;
//
//        // wyszukiwanie
//        const int m = pow (10 , 4) ;
//        int hits = 0;
//        t1 = clock () ;
//        for ( int i = 0; i < m ; i ++)
//        {
//            Ubrania so;
//            int tmp_int = (rand()<<15)+rand();
//            so.marka = "nike";
//            so.rozmiar = tmp_int;//rand()%30+50;
//            Wezel<Ubrania>*result = cokolwiek -> szukanie_elementu(so) ;
//            if ( result != NULL )
//            {
//                hits++;
//            }
//        }
//        cokolwiek -> CzyszczenieDrzewa(cokolwiek->korzen);
//        t2 = clock () ;
//        t = (double)(t2 - t1)/CLOCKS_PER_SEC;
//        std::cout<<"Czas szukania: "+ std::to_string(t)+"s"<<std::endl;
//        std::cout<<"Liczba trafien: "<<hits<<"\n\n"<<std::endl;
//    }
//
//    delete cokolwiek;
    return 0;
}

