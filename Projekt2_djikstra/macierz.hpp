#ifndef MACIERZ_HPP

#define MACIERZ_HPP
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>
#include "kontenery.hpp"

using namespace std;

class GrafM {
public:
    int n; //rozmiar
    int** tab;  //wskaznik na podwojna tablice ([wierzcholek][wierzcholek]=waga krawedzi miedzy nimi)
   
    GrafM(int n); //konstruktor tworzy macierz zapelniona krawedziami o wadze -1

    int* operator[](int i);    //przeciazneie operatora by zwracac wszystkie polaczenia dla danego wierzcholka
};

#endif 