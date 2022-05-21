#ifndef LISTA_HPP

#define LISTA_HPP
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include "kontenery.hpp"

using namespace std;

class GrafL {
public:
    int n;  //rozmiar
    vector<vector<Pair>> tab; //wektor wektorow bo kazda miejsce w grafie to taka mniejsza lista (int1=dlugosc krawedzi, int2=wierzcholek)
    
    GrafL(int n);  //konstruktor
    
    vector<Pair>* operator[](int i); //przeciazneie operatora by zwracac krawedzie (wektor) dla pojedynczego wierzcholka
};

#endif 