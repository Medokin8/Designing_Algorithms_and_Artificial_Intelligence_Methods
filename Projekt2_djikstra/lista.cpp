#include "lista.hpp"

GrafL::GrafL(int n) {  //konstruktor
    tab = vector<vector<Pair>>(n); //tworzy n wektorow z parami intow
    this->n = n;    //przypisanie dlugosci
}


vector<Pair>* GrafL::operator[](int i) { //przeciazneie operatora by zwracac krawedzie (wektor) dla pojedynczego wierzcholka
    return &tab[i];
}