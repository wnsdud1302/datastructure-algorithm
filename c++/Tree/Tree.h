#ifndef TREE_H
#define TREE_H
#include<iostream>
using namespace std;

template<typename T> class Tree;

template<typename T>
class Tree{
public:
    template<typename T>
    class BinNode{
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
Tree<T>::Tree():root(NULL), parent(NULL), child(NULL) {}

template<typename T>
Tree<T>::~Tree(){
    cout << "종료합니다"<< endl;
}

template<typename T>
int Tree<T>::Size() const {return n; }

template<typename T>
Tree<T>::BinNode<T> *Tree<T>::Parent() const {return parent; }

template<typename T>
Tree<T>::BinNode<T> *Tree<T>::Child() const {return child; };

template<typename T>
void Tree<T>::Add(T& elem){
    BinNode<T> *new_node = new BinNode<T>(elem, NULL, NULL);
    BinNode<T> *start = root;
    if(root == NULL)
        root = new_node;
    while(1){
        if(start->elem > elem){
            if(start->left != NULL){
                parent = start;
                start = start->left;
            }
            else{
                start->left = child = new_node;
                n++;
                break;
            }
        }
        else{
            if(start->right != NULL){
                parent = start;
                start = start->right;
            }
            else{
                start->right = child = new_node;
                n++;
            }
        }     
    }
}

template<typename T>
void Tree<T>::Remove(T& elem){
    BinNode<T> *del = root;
    parent = del;
    while(1){
        if(del->elem == elem) break;
        else if(del->elem > elem){
            parent = del;
            del = child = del->left;
        }
        else{
            parent = del;
            del = child = del->right;
        }
    }
    if(del->left == NULL && del->right == NULL){
        if(parent->elem > elem)
            parent->left = NULL;
        else
            parent->right = NULL:
        delete del;
    }
    else if(del->left != NULL && del->right == NULL){
        if(parent->elem > elem)
            parent->left = del->left;
        else
            parent->right = del->left;
        delete del;
    }
    else if(del->left == NULL && del->right != NULL){
        if(parent->elem > elem)
            parent->left = del->right;
        else
            parent->right = del->right;
        delete del;
    }




}
