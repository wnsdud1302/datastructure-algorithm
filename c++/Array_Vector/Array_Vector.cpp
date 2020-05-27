#include"Array_Vector.h"

ArrayVector::ArrayVector() : n(0), capacity(0), E(NULL) {}

int ArrayVector::size() const{
    return n;
}

bool ArrayVector::isEmpty() const{
    return (size() == 0);
}

Elem& ArrayVector::Front() const{
    return E[0];
}

Elem& ArrayVector::Back() const{
    return E[n];
}

Elem& ArrayVector::operator[](int i){
    return E[i];
}

Elem& ArrayVector::At(int i){
    if(i < 0 || i >= n)
        cout << " illegal index in function at()" <<endl;
    return E[i];
}

void ArrayVector::Insert(int i, const Elem& e){
    if(n >= capacity)
        Reserve(max(1,2*capacity));
    for(int j = n-1; j>= i; j--)
        E[j+1] = E[j];
    E[i] = e;
    n++;
}

void ArrayVector::Erase(int i){
    for(int j = i+1; j < n; j++)
        E[j-1] = E[j];
    n--;
}

void ArrayVector::Reserve(int N){
    if(capacity >= N) return;
    Elem *B = new Elem[N];
    for(int j = 0; j < n; j++)
        B[j] = E[j];
    if(E != NULL) delete [] E;
    E = B;
    capacity = N;
}
