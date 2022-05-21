#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <fstream>
#include <chrono>
#include "macierz.hpp"
#include "lista.hpp"
#include "djikstra.hpp"
#include "kontenery.hpp"

//dla losowania
std::random_device rd;
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed1);

using namespace std;

//nie zdazylem
GrafL czytanie(FILE * dane, int n, int kr)
{
    // int** h = new int* [n]; //tablcie dla pamietania ktore krawedzie sie pojawily
    // for (int i = 0; i < n; ++i)
    //     h[i] = new int[n];
    // for (int i = 0; i < n; ++i)
    //     for (int j = 0; j < n; ++j)
    //         h[i][j] = 0;

    // GrafL g = GrafL(n); //konstruktor grafu

    // int wierzcholek1;
    // int wierzcholek2;
    // int waga;

    // for(int i=0; i<kr; i++)
    // {   
    //     fscanf(dane, "%d", "%d", "%d", &wierzcholek1, &wierzcholek2, &waga);
       
    //     h[wierzcholek1][wierzcholek2] = 1;  //usatw ze krawedz wykorzystana
    //     h[wierzcholek2][wierzcholek1] = 1;  //usatw ze krawedz wykorzystana
        
    //     Pair p = Pair(waga, wierzcholek2);   //para  czyli reprezentacja wierzcholka (waga,wierzcholek)

    //     vector<Pair>* v = g[wierzcholek1]; //wskaznik na odpowiedni wierzcholek

    //     //usatwianie wierzcholka w grafie
    //     (*v).push_back(p);
    //     v = g[wierzcholek2];
    //     p = Pair(waga, wierzcholek1);
    //     (*v).push_back(p);
    // }
    // return g; //zwroc graf
}

//nie zdazylem
void wczytaj_plik(){
    // int rozmiar;
    // int gestosc;
    // int poczatek = 0;
    // int koniec = 0;
    // string zrodlo;
    // FILE * dane;

    // cout<<"podaj nazwe pliku"<<endl;
    // cin>>zrodlo;
    
    // dane = fopen(zrodlo.c_str(),"r");

    // fscanf(dane, "%d", "%d", "%d", &rozmiar, &gestosc, &poczatek);
    // cout<< rozmiar <<endl;
    // cout<< gestosc <<endl;

    // GrafL lista = czytanie(dane, rozmiar, gestosc);
    
    // fclose(dane);

    // uniform_int_distribution<int> distribution(0, rozmiar - 1);
    // koniec = distribution(generator);
    // while(poczatek==koniec)
    //    koniec = distribution(generator);

    // cout<<djikstra(lista, poczatek, koniec);
    
}

GrafL losujL(int n, int p) { //losowanie dla listy (wielkosc,  gestosc)
    
    double procent=(double)p/100.0;

    int** h = new int* [n]; //tablcie dla pamietania ktore krawedzie sie pojawily
    for (int i = 0; i < n; ++i)
        h[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            h[i][j] = 0;

    double kr = procent * n * (n - 1) / 2; //wyliczenie ilosci krawedzi do rozdzielenia

    GrafL g = GrafL(n); //konstruktor grafu

    //losowanie z rozkladu uniform
    uniform_int_distribution<int> distribution(0, n - 1);

      // losowanie i zpaelnienie spojnosci
    for(int i = 0; i<n; i++)
    {
        int wierzcholek1 = distribution(generator); //los dla wierzcholka1

        while (wierzcholek1 == i|| h[wierzcholek1][i] != 0)  //jezeli te same wierzcholki lub krawedz wykorzystana to losuj nowe wierzcholki
        {
            wierzcholek1 = distribution(generator); //los dla wierzcholka1
        }

        h[wierzcholek1][i] = 1;  //usatw ze krawedz wykorzystana
        h[i][wierzcholek1] = 1;  //usatw ze krawedz wykorzystana

        int val=distribution(generator)+1; //losowanie wagi wierzcholka, +1 by krawedz nie mogla byc 0

        Pair p = Pair(val, i);   //para  czyli reprezentacja wierzcholka (waga,wierzcholek)

        vector<Pair>* v = g[wierzcholek1]; //wskaznik na odpowiedni wierzcholek
        
        //usatwianie wierzcholka w grafie
        (*v).push_back(p);
        v = g[i];
        p = Pair(val, wierzcholek1);
        (*v).push_back(p);
    }

    for (int i = n; i < kr; i++)
    {
        int wierzcholek1 = distribution(generator); //los dla wierzcholka1
        int wierzcholek2 = distribution(generator); //los dla wierzcholka2

        while (wierzcholek1 == wierzcholek2 || h[wierzcholek1][wierzcholek2] != 0) //jezeli te same wierzcholki lub krawedz wykorzystana to losuj nowe wierzcholki
        {
            wierzcholek1 = distribution(generator); //los dla wierzcholka1
            wierzcholek2 = distribution(generator); //los dla wierzcholka2
        }

        h[wierzcholek1][wierzcholek2] = 1;  //usatw ze krawedz wykorzystana
        h[wierzcholek2][wierzcholek1] = 1;  //usatw ze krawedz wykorzystana

        int val=distribution(generator)+1; //losowanie wagi wierzcholka, +1 by krawedz nie mogla byc 0

        Pair p = Pair(val, wierzcholek2);   //para  czyli reprezentacja wierzcholka (waga,wierzcholek)

        vector<Pair>* v = g[wierzcholek1]; //wskaznik na odpowiedni wierzcholek

        //usatwianie wierzcholka w grafie
        (*v).push_back(p);
        v = g[wierzcholek2];
        p = Pair(val, wierzcholek1);
        (*v).push_back(p);
    }

    return g; //zwroc graf
}

GrafM losujM(int n, int p) { //losowanie dla macierzy (wielkosc,  gestosc)
    
    double procent=(double)p/100.0;

    int** h = new int* [n]; //tablcie dla pamietania ktore krawedzie sie pojawily
    for (int i = 0; i < n; ++i)
        h[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            h[i][j] = 0;

    double kr = procent * n * (n - 1) / 2;    //wyliczenie ilosci krawedzi do rozdzielenia

    GrafM g = GrafM(n); //konstruktor grafu

    //losowanie z rozkladu uniform
    uniform_int_distribution<int> distribution(0, n - 1);

    // losowanie i zpaelnienie spojnosci
    for(int i = 0; i<n; i++)
    {
        int wierzcholek1 = distribution(generator); //los dla wierzcholka1

        while (wierzcholek1 == i|| h[wierzcholek1][i] != 0)  //jezeli te same wierzcholki lub krawedz wykorzystana to losuj nowe wierzcholki
        {
            wierzcholek1 = distribution(generator); //los dla wierzcholka1
        }

        int val=distribution(generator)+1;        //losuj wage, +1 by krawedz nie mogla byc 0
        h[wierzcholek1][i] = 1;      //ustaw odcinek ab jako sprawdzony
        h[i][wierzcholek1] = 1;      //ustaw odcinek ba jako sprawdzony
        g[wierzcholek1][i] = val;    //ustaw wage krawedzi odcinka ab
        g[i][wierzcholek1] = val;    //ustaw wage krawedzi odcinka ba
    }

    //losowanie z rozkladu uniform, zapelnieni grafu
    for (int i = n; i < kr; i++)
    {
        int wierzcholek1 = distribution(generator); //los dla wierzcholka1
        int wierzcholek2 = distribution(generator); //los dla wierzcholka2

        while (wierzcholek1 == wierzcholek2 || h[wierzcholek1][wierzcholek2] != 0)  //jezeli te same wierzcholki lub krawedz wykorzystana to losuj nowe wierzcholki
        {
            wierzcholek1 = distribution(generator); //los dla wierzcholka1
            wierzcholek2 = distribution(generator); //los dla wierzcholka2
        }

        int val=distribution(generator)+1;        //losuj wage, +1 by krawedz nie mogla byc 0
        h[wierzcholek1][wierzcholek2] = 1;      //ustaw odcinek ab jako sprawdzony
        h[wierzcholek2][wierzcholek1] = 1;      //ustaw odcinek ba jako sprawdzony
        g[wierzcholek1][wierzcholek2] = val;    //ustaw wage krawedzi odcinka ab
        g[wierzcholek2][wierzcholek1] = val;    //ustaw wage krawedzi odcinka ba
    }

    return g;
}

//menu wielkosci
int menu_wielkosc(int rozmiar){

    cout << "Wybiez wielkosc:" << endl;
    cout << "10" << endl;
    cout << "50" << endl;
    cout << "100" << endl;
    cout << "500" << endl;
    cout << "1000" <<endl;
    cin >> rozmiar;
    cout << endl;
    
    return rozmiar;
}

//menu gestosci
int menu_gestosc(int gestosc){

    cout << "Wybiez gestosc:" << endl;
    cout << "25 = 25%" << endl;
    cout << "50 = 50%" << endl;
    cout << "75 = 75%" << endl;
    cout << "100 = 100%" << endl;
    cin >> gestosc;
    cout << endl;

    return gestosc;
}


int main(int argc, char const *argv[])
{
    //wartosci wyboru dla grafu na inicjacji
    int rozmiar = 0;
    int gestosc = 0;

    int suma_lt = 0;//suma czasow dla listy
    int suma_mt = 0;//suma czasow dla macierzy

    // int poczatek = 0;
    // int koniec = 0;
    // string zrodlo; //dla czytnaia pliku
    // FILE * dane;

    int wybor = 2;
    cout << "Dadne podane z pliku czy generowane?" << endl;
    cout << "1 = generowane" << endl;
    cout << "2 = plik" << endl;
    cin >> wybor;
    cout << endl;

    //menu wyboru czytania danych
    switch (wybor)
    {
    case 1:
        rozmiar = menu_wielkosc(rozmiar);
        gestosc = menu_gestosc(gestosc);
        break;

    case 2:
        wczytaj_plik();
        return 0;
        break;

    default:
        break;
    }

     // wielkosc grafu
    switch(rozmiar)
        {
            case 10:
                rozmiar=10;
            break;
   
            case 50:
                rozmiar=50; 
            break;
   
            case 100:
                rozmiar=100; 
            break;
   
            case 500:
                rozmiar=500;
            break;

            case 1000:
                rozmiar=1000;
            break;

            default:
            cout << "zly rozmiar" << endl;
            return 0;
    }

    // gestosc grafu
    switch(gestosc)
        {
            case 25:
                gestosc=25;
            break;
   
            case 50:
                gestosc=50; 
            break;
   
            case 75:
                gestosc=75; 
            break;
   
            case 100:
                gestosc=100;
            break;

            default:
            cout << "zla gestosc" << endl;
            return 0;
    }

    //nazwy plikow wynikowych
    int rozmiar_plik=rozmiar;   //pomocniczy
    int gestosc_plik=gestosc;   //pomocniczy

    string nazwa_lista = "lista_" + to_string(rozmiar_plik) + "_" + to_string(gestosc_plik) + ".txt";
    string nazwa_macierz = "macierz_" + to_string(rozmiar_plik) + "_" + to_string(gestosc_plik) + ".txt";

    ofstream zapis_lista(nazwa_lista);
    ofstream zapis_macierz(nazwa_macierz);
    
    //100 instancji = 100 losowych grafow 
    int instancja = 0;
    //if(wybor==1)
    while(instancja<100){

        //lsoowanie wartosci grafow
        GrafL lista = losujL(rozmiar, gestosc);
        GrafM macierz = losujM(rozmiar, gestosc);

        //lsoowanie poczatka i konca do drogi
        uniform_int_distribution<int> distribution(0, rozmiar - 1);
        int poczatek = distribution(generator);
        int koniec = distribution(generator);
        while(poczatek==koniec)
        {
            poczatek = distribution(generator);
            koniec = distribution(generator);
        }

        //DJISkTRA lista
        //liczenie czasu i zapis do pliku lista
        auto start_l = chrono::high_resolution_clock::now();//czas start

        string wynik_l = djikstra(lista, poczatek, koniec);

        auto stop_l = chrono::high_resolution_clock::now(); //czas stop
        auto duration_l = chrono::duration_cast<chrono::microseconds>(stop_l - start_l); //ile minelo od start do stop
        int czas_l = duration_l.count(); //sumowanie czasow trwania djikstry
        suma_lt = suma_lt + czas_l;

        string  czas_string_l = to_string(czas_l);

        zapis_lista << instancja+1 << ".    (waga : droga)  " << wynik_l << "                       czas[us]:   " << czas_string_l << "\n";

        //DJISkTRA macierz
        //liczenie czasu lista
        auto start_m = chrono::high_resolution_clock::now();//czas start

        string wynik_m = djikstra(macierz, poczatek, koniec);

        auto stop_m = chrono::high_resolution_clock::now(); //czas stop
        auto duration_m = chrono::duration_cast<chrono::microseconds>(stop_m - start_m); //ile minelo od start do stop
        int czas_m = duration_m.count(); //sumowanie czasow trwania djikstry
        suma_mt = suma_mt + czas_m;

        string  czas_string_m = to_string(czas_m);

        zapis_macierz << instancja+1 << ".    (waga : droga)  " << wynik_m <<"                       czas[us]:   "<< czas_string_m <<"\n";
        
        //kolejny pomiar
        instancja++;
        cout<<instancja<<endl;  //dla siebie by siedzic proces
    }

    int czas_sr_l=suma_lt/100;
    int czas_sr_m=suma_mt/100; 

    //testowe dla kontroli
    /*cout << "Czas sredni: "   << czas_sr_l/(60*1000000) << " minut, "
                                << czas_sr_l/1000000 << " sekund, " 
                                << czas_sr_l/1000 << " milisekund, "
                                << czas_sr_l << " mikrosekund, " << endl;
    cout << endl;*/

    //testowe dla kontroli
    /*cout << "Czas sredni: "   << czas_sr_m/(60*1000000) << " minut, "
                                << czas_sr_m/1000000 << " sekund, " 
                                << czas_sr_m/1000 << " milisekund, "
                                << czas_sr_m << " mikrosekund, " << endl;
*/
    
    //dopis sredniego czasu i zmainkiecie pliku
    zapis_lista << "\n    sredni czas[us]:   " << to_string(czas_sr_l);
    zapis_lista.close();

    //dopis sredniego czasu i zmainkiecie pliku
    zapis_macierz << "\n    sredni czas[us]:   " << to_string(czas_sr_m);
    zapis_macierz.close();

    return 0;
}