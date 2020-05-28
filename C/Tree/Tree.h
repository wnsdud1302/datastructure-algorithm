#ifndef TREE_H
#define TREE_H

typedef struct BinNode{
    int data;
    struct BinNode *left;
    struct BinNode *right;
}BinNode;

typedef struct Tree{
    BinNode *root;
}Tree;

void Initialize(Tree *t);
void Add(Tree *t, int data);
void Remove(Tree *t, int data);
BinNode *Search(Tree *t, int data);
void Print(const BinNode *start);
void PrintTree(const Tree *t);
void Free(BinNode *start);
void FreeTree(Tree *t);

#endif
