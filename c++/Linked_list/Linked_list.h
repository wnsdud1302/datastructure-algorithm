#pragma once

class Node{
public:
    int data;
    Node *next;
};

class Linked_list{
public:
    Linked_list();
    void InsertFront(int data);
    void InsertBack(int data);
    void RemoveFront();
    void RemoveBack();
    void RemoveCurrent();
    Node *Search(int data);
    void Clear();
    void Printcurrent();
    void Print();
    ~Linked_list(); 
private:
    Node *head;
    Node *crnt;
};