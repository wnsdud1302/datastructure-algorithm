#ifndef ARRAY_VECTOR_H
#define ARRAY_VECTOR_H
#include<iostream>
using namespace std;
typedef int Elem;
class ArrayVector{
public:
    ArrayVector();
    int size() const;
    bool isEmpty() const;
    Elem& Front() const;
    Elem& Back() const;
    Elem& operator[](int i);
    Elem& At(int i);
    void Insert(int i, const Elem& e);
    void Erase(int i);
    void Reserve(int N);
private:
    int n;
    int capacity;
    Elem *E;
};

#endif