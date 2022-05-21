#ifndef DJIKSTRA_HPP

#define DJIKSTRA_HPP
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>
#include "macierz.hpp"
#include "lista.hpp"
#include "kontenery.hpp"

using namespace std;

class Que { //kolejka
public:
    int** tab;  //tablica wierzcholkow ([wierzcholek][sprawdzanie: 1= czy zsotal sprawdzony, 0=waga])
    int n;  //rozmiar grafu czyli kolejki
    
    Que(int n);    //konstruktor,inicjalizacja kolejki

    int* operator[](int i); //przeciazenie do zwracania bezposrednio wartosci

    int* smallest();   //funkcja zwracajaca najmniejsza wage i jej wierzcholek z kolejki

    bool empty();  //czy pusto
};

int findin(Que que, int v);   //kolejka, szukany wierzcholek 

int findin(vector<Pair>* que, int v); //wektor, szukany wierzcholek 

void setin(Que que, int v, int n);  //kolejka, wierzcholek, waga

string djikstra(GrafM G, int v, int k); //algorytm dla (graf, start, stop)

string djikstra(GrafL G, int v, int k); //fraf, start, stop

#endif 