#ifndef TREE_H
#define TREE_H
#include<iostream>
using namespace std;

template<typename T> class Tree;
template<typename T> class BinNode;

template<typename T>
class Tree{
public:
    template<typename T>
    class BinNode{
public:
    class leftRight{
    public:
        bool operator()(const BinNode<T> &p, const BinNode<T> &q) const { return p.elem < q.elem; }
    };
public:
    BinNode();
    BinNode(E &e, BinNode<T> *l, BinNode<T> *r): elem(e), left(l), right(r) {}
    void Print();
private:
    T& elem;
    BinNode<T> *left;
    BinNode<T> *right;
    friend class Tree<T>;
};
public:
    Tree();
    ~Tree();
    int Size() const;
    BinNode<T> *Parent() const;
    BinNode<T> *Child() const;
    void Add(T& elem);
    void Remove(T& elem);
    void PrintTree();
private:
    int n = 0;
    BinNode<T> *root;
    BinNode<T> *parent;
    BinNode<T> *child;
};


template<typename T>
Tree<T>::Tree(){
    root = new BinNode;
    parent = NULL;
    child = NULL;
}

template<typename T>
Tree<T>::~Tree(){
    cout << "종료합니다"<< endl;
}

template<typename T>
BinNode<T> *Tree<T>::Parent() const {return parent; }
