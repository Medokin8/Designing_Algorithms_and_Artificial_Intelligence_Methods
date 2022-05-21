#ifndef KONTENERY_HPP

#define KONTENERY_HPP
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

class Pair{
    public:
    int first, second;
    Pair();
    Pair(int first, int second);
    int operator[](int i);
};

// template<class D>
// class Node{
//     public:
//     D val;
//     Node *next;
//     Node(D val){
//         this->val=val;
//         next=nullptr;
//     }
//     Node(){
//         this->val = D();
//         next=nullptr;
//     }
// };

// template<class T>
// class Vector
// {
// public:
//     Node<T> *first;
//     int l;

//     int size(){
//         return l;
//     }

//     Vector(int j){
//         l=j;
//         first = new Node<T>();
//         Node<T> *curr = first;
//         for (int i = 1; i < l; i++)
//         {
//             curr->next = new Node<T>();
//             curr = curr->next;
//         }
//     }
//     Vector(){
//         l=0;
//         first = nullptr;
//     }
//     T operator[](int l){
//         Node<T> *curr = first;
//         for (int i = 0; i < l; i++)
//         {
//            curr = curr->next;
//         }
//         return (curr->val);
//     }
//     void push_back(T val){
//         Node<T> *curr = first;
//         if (first == nullptr)
//         {
//             first = new Node<T>(val);
//             l++;
//             return;
//         }
        
//         while (curr->next != nullptr)
//         {
//             curr = curr->next;
//         }
//         curr->next = new Node<T>(val);
//         l++;
//     }
// };

#endif 