#include "macierz.hpp"

GrafM::GrafM(int rozmiar) {  //konstruktor tworzy macierz zapelniona krawedziami o wadze -1
        this->n = rozmiar;
        tab = new int* [n]; //tablica o rozmiarze
        for (int i = 0; i < n; ++i)
            tab[i] = new int[n];    //zrobienie podtablicy
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                tab[i][j] = -1; //zapelnienie
}

int* GrafM::operator[](int i) {    //przeciazneie operatora by zwracac wszystkie polaczenia dla danego wierzcholka
        return tab[i];
}