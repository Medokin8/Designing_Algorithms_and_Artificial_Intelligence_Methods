#include "djikstra.hpp"

using namespace std;

Que::Que(int n) {    //konstruktor,inicjalizacja kolejki
    this->n = n;
    tab = new int* [n];
    for (int i = 0; i < n; ++i)
        tab[i] = new int[2]; //stworznie dwuwymiarowej jak wyzej
}

int* Que::operator[](int i) { //przeciazenie do zwracania bezposrednio wartosci
    return tab[i];
}

int* Que::smallest() {   //funkcja zwracajaca najmniejsza wage i jej wierzcholek z kolejki
    int minval = INT32_MAX, minw = -1; //pomocnicze
    for (int i = 0; i < n; i++)
    {
        if (tab[i][1] == 0 && tab[i][0] < minval) //czy wierzcholek byl sprawdzany i czy jego waga jest mniejsza od nieskonczonosci
        {
            minval = tab[i][0]; //waga na wage wierzcholka
            minw = i;   //wierzcholek
        }
    }
    return new int[2]{ minval,minw }; //zwroc (waga, numer wierzcholka)
}

bool Que::empty() {  //czy pusto
    for (int i = 0; i < n; i++)
    {
        if (tab[i][1] == 0) //jezeli wierzcholek nie sprawdzony to 0, czyli cos jescze trzeba sprawdzic
        {
            return false;
        }
    }
    return true;
}

int findin(Que que, int v) {    //kolejka, szukany wierzcholek 
    for (int i = 0; i < que.n; i++) //dopki nie przejdzie calej kolejki
    {
        if (i == v && que[i][1] != 1) //jezeli jest wierzcholek i jest nie sprawdzony
        {
            return que[i][0]; //zwraca wage wierzcholka
        }
    }
    return -1;
}

int findin(vector<Pair>* que, int v) { //wektor, szukany wierzcholek 
    for (int i = 0; i < que->size(); i++)
    {
        if (que[0][i].second == v)//jezeli jest wierzcholek i jest nie sprawdzony
        {
            return que[0][i].first; //zwraca wage wierzcholka
        }
    }
    return -1;
}

void setin(Que que, int v, int n) { //kolejka, wierzcholek, waga
    for (int i = 0; i < que.n; i++)
    {
        if (i == v) //jezeli jesst wierzcholek 
        {
            que[i][0] = n;  //podstaw nowa wage dla wierzcholka
            return;
        }
    }
}

string djikstra(GrafM G, int v, int k) { //algorytm dla (graf, start, stop)
    int* p = new int[G.n];  //tablica przodkow, oddaje droge jaka trzeba przejsc
    Que que = Que(G.n); //kolejka na bazie grafu
    
    for (int i = 0; i < G.n; i++)   
    {
        p[i] = -1;  //zapelnienie przodkow wartoscia drogi -1 na start
        que[i][0] = INT32_MAX;  //ustawienie elementu kolejki - waga na nieskonczonosc
        que[i][1] = 0;  //ustawienie eleemntu kolejki - czy sprawdzony na 0 (czyli ze nie sprawdzony)
    }

    for (int i = 0; i < G.n; i++)
    {
        if (i == v) //jezeli indeks jest startowym
        {
            que[i][0] = 0; //ustawienie startu, waga = 0
            break;
        }
    }

    while (!que.empty())    //dopoki cos jest w kolejce
    {
        int* u = que.smallest(); //zwraca wierzchlek o njamniejszej wadze w kolejce
        
        que[u[1]][1] = 1;   //ustawienie elementowi w kolejce (o numerze najmniejszego) czy sprawdzony na sprawdzony
        if (u[1] == -1){
            return "graf nie spójny";
        }
        for (int i = 0; i < G.n; i++)
        {
            if (G[u[1]][i] != -1) //czy jest krawedz, jak jest to dalej, jak nie to nie wchodz
            {
                int c = findin(que, i); //przypisanie wagi wierzcholka 
                if (c != -1)    //jezeli mamy krawedz
                {
                    if (c > u[0] + G[u[1]][i])  //jezeli droga do znalezionego wierzcholka jest wieksza od  wagi aktualnie najmniejszego + wagi kolejnego polaczonego z aktualniie najmnijeszym
                    {
                        setin(que, i, u[0] + G[u[1]][i]); //jezeli jest dluzsze to ustaw nowa wage dla wierzcholka (te mniejsza)
                        p[i] = u[1]; //zapisz krok posredni do nowej wagi
                    }
                }

            }

        }

    }

    string s;   //do zwrocenia drogi

    int waga = que.tab[k][0]; //zapmietanie wagi dla drogi

    if (p[k] != -1) //czy to nie poczatek, bo jak nie ma poprzednika to =-1
    {
        while (k != v) //dpoki koniecjest rozny od startu
        {
            s = to_string(k) + " " + s; //dopisz droge
            k = p[k];   //ustaw nowy koniec
        }
    }

    s = to_string(waga) + " : " + to_string(k) + " " + s; //dopisz ostani krok

    return s;
    
}

string djikstra(GrafL G, int v, int k) { //fraf, start, stop
    int* p = new int[G.n]; //przodki - droga od poczatku do konca
    Que que = Que(G.n); //kolejka

    for (int i = 0; i < G.n; i++)
    {
        p[i] = -1; //zapelnienie przodkow wartoscia drogi -1 na start
        que[i][0] = INT32_MAX; //ustawienie elementu kolejki - waga na nieskonczonosc
        que[i][1] = 0;  //ustawienie eleemntu kolejki - czy sprawdzony na 0 (czyli ze nie sprawdzony)
    }

    for (int i = 0; i < G.n; i++)   
    {
        
        if (i == v) //jezeli indeks jest startowym
        {
            que[i][0] = 0;  //ustawienie startu, waga = 0
            break;
        }
    }

    while (!que.empty())    //dopoki cos jest w kolejce
    {
        int* u = que.smallest();    //zwraca wierzchlek o njamniejszej wadze w kolejce
        if (u[1] == -1){
            return "graf nie spójny";
        }
        que[u[1]][1] = 1;   //ustawienie elementowi w kolejce (o numerze najmniejszego) czy sprawdzony na sprawdzony
        for (int i = 0; i < G.n; i++)   //!!!!jakby tu był for each to by bylo szybciej!!!
        {
            int g = findin(que, i); //czy jest krawedz, jak jest to dalej, jak nie to nie wchodz
            if (g != -1)
            {
                int c = findin(G[u[1]], i); //przypisanie wagi wierzcholka
                if (c != -1)    //jezeli mamy krawedz
                {
                    if (g > u[0] + c)   //jezeli waga krawedzi wieksza od wagi aktualnie najmnijszego + wagi krawedzi kolejnego
                    {
                        setin(que, i, u[0] + c); //ustaw nowa mniejsza wage
                        p[i] = u[1];    //zapisz krok
                    }
                }
            }
        }
    }
    
    string s;   //pomocniczy do drogi

    int waga = que.tab[k][0];   //zapamietanie wagi dla drogi

    if (p[k] != -1) //dopoki nie bedzie start, bo ten nie ma poprzednika
    {
        while (k != v)  //dopki koniec jest rozny od start
        {
            s = to_string(k) + " " + s; //zapisz przejscie
            k = p[k];   //usatw nowy koniec
        }
    }
    

    s = to_string(waga) + " : " + to_string(k) + " " + s; //usatw ostantie przejscie
    
    return s; //zwroc dorge
}

