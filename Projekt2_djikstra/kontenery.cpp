#include "kontenery.hpp"

Pair::Pair(){   //konstruktor domyslny
    first = 0;
    second = 0;
}

Pair::Pair(int first, int second){  //konstruktor
        this->first = first;
        this->second = second;
}

int Pair::operator[](int i){
    if (i = 0)
    {
        return first;
    }
    else
    {
        return second;
    }
}