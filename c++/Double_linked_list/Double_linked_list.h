#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

class Node{
    public:
        void SetNode(int *x,Node *nxt,Node *prv);
        int data;
        Node *next;
        Node *prev;

};

class Double_linked_list{
    public:
        Double_linked_list();
        void Insert(Node *n,int *data);
        void InsertFront(int *data);
        void InsertBack(int *data);
        void Remove(Node *n);
        void RemoveFront();
        void RemoveBack();
        Node *Search(int *data);
        bool IsEmpty();
        bool next();
        bool prev();
        void PrintCurrent();
        void Print();
        void PrintReverse();
        void Clear();
        ~Double_linked_list();
    private:
        Node *head;
        Node *tail;
        Node *crnt;
};
#endif
