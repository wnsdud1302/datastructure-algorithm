#ifndef ARRAY_LINKED_LIST_H
#define ARRAY_LINKED_LIST_H

typedef int Index;
#define Null -1

class Node{
    public:
        void SetNode(const int *x, const Index nxt);
        int data;
        Index next;
        Index Dnext;
};

class Arraylinkedlist{
    public:
        Arraylinkedlist(int size);
        Index GetIndex();
        Index DeleteIndex(Index idx);
        Index Search(int *data);
        void InseartFront(int *data);
        void InseartBack(int *data);
        void RemoveFront();
        void RemoveBack();
        void RemoveCurrent();
        void Clear();
        void Printcurrent();
        void PrintIndex();
        void Print();
        ~Arraylinkedlist();
    private:
        Node *n;
        Index head;
        Index max;
        Index deleted;
        Index crnt;
};

#endif
