#ifndef DEQUE_H
#define DEQUE_H
#include<iostream>
#include<string>
#include"Double_linked_list.h"
using namespace std;

template<typename T>
class Deque{
public:
    Deque();
    int size() const;
    bool IsEmpty() const;
    const T& Front() const;
    const T& Back() const;
    const T& Data(int k) const;
    const T& operator[](int k) const;
    void InsertFront(const T& data);
    void InsertBack(const T& data);
    void RemoveFront();
    void RemoveBack();
    void Clear();
    void Print();
    void PrintReverse();
private:
    Double_linked_list<T> l;
    int n;
};

template<typename T>
Deque<T>::Deque(){ n = 0 ;}

template<typename T>
int Deque<T>::size() const{
    return n;
}

template<typename T>
bool Deque<T>::IsEmpty() const{
    return l.IsEmpty();
}

template<typename T>
const T& Deque<T>::Front() const{
    if(IsEmpty())
        cout << "데크가 비어있습니다." << endl;
    return l.Front();
}

template<typename T>
const T& Deque<T>::Back() const{
    if(IsEmpty())
        cout << "데크가 비어있습니다." << endl;
    return l.Back();
}

template<typename T>
const T& Deque<T>::Data(int k) const{
    if(IsEmpty())
        cout << "데크가 비어있습니다." << endl;
    return l.Data(k);
}

template<typename T>
const T& Deque<T>::operator[](int k) const{
    if(IsEmpty())
        cout << "데크가 비어있습니다." << endl;
    return Data(k);
}

template<typename T>
void Deque<T>::InsertFront(const T& data){
    l.InsertFront(data);
    n++;
}

template<typename T>
void Deque<T>::InsertBack(const T& data){
    l.InsertBack(data);
    n++;
}

template<typename T>
void Deque<T>::RemoveFront(){
    if(IsEmpty())
        cout << "데크가 비어있습니다." << endl;
    l.RemoveFront();
    n--;
}

template<typename T>
void Deque<T>::RemoveBack(){
    if(IsEmpty())
        cout << "데크가 비어있습니다." << endl;
    l.RemoveBack();
    n--;
}

template<typename T>
void Deque<T>::Clear(){
    if(IsEmpty())
        cout << "데크가 비어있습니다." << endl;
    while(!IsEmpty()){
        RemoveBack();
    }
}

template<typename T>
void Deque<T>::Print(){
    if(IsEmpty())
        cout << "데크가 비어있습니다." << endl;
    l.Print();
}

template<typename T>
void Deque<T>::PrintReverse(){
    if(IsEmpty())
        cout << "데크가 비어있습니다." << endl;
    l.PrintReverse();
}


#endif