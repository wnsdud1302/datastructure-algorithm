#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

static BinNode *AllocBinNode(){
    return malloc(sizeof(BinNode));
}
static void SetBinNode(BinNode *n, int d, BinNode *l, BinNode *r){
    n->data = d;
    n->left = l;
    n->right = r;
}

void Initialize(Tree *t){
    t->root = AllocBinNode();
}

void Add(Tree *t, int data){
    BinNode *new_node = AllocBinNode();
    SetBinNode(new_node, data, NULL, NULL);
    BinNode *start = t->root;
    while(1){
        if(start->data > data){
            if(start->left != NULL)
                start = start->left;
            else{
                start->left = new_node;
                break;
            }
        }
        else{
            if(start->right != NULL)
                start = start->right;
            else{
                start->right = new_node;
                break;
            }
        }
    }
}

void Remove(Tree *t, int data){
    BinNode *del_node = t->root;
    BinNode *parent_node = del_node;
    while(1){
        if(del_node->data == data) break;
        else if(del_node->data > data){
            parent_node = del_node;
            del_node = del_node->left;
        }
        else{
            parent_node = del_node;
            del_node = del_node-> right;
        }
    }

    if(del_node->left == NULL && del_node->right == NULL){
        if(parent_node->data > data){
            parent_node->left = NULL;
        }
        else{
            parent_node->right = NULL;
        }
        free(del_node);
    }
    else if(del_node->left != NULL && del_node->right == NULL){
        if(parent_node->data > data){
            parent_node->left = del_node->left;
        }
        else{
            parent_node->right = NULL;
        }
    free(del_node);
    }
    else if(del_node->left == NULL && del_node->right != NULL){
        if(parent_node->data > data)
            parent_node->left = del_node->right;
        else
            parent_node->right = parent_node->right;
        free(del_node);
    }
    else{
        BinNode *change_node = del_node;
        parent_node = del_node;
        del_node = del_node->left;
        while(del_node->left != NULL){
            parent_node = del_node;
            del_node = del_node->left;
        }
        change_node->data = del_node->data;
        if(del_node->right != NULL)
            parent_node->left = del_node->right;
        else
            parent_node->left = NULL;
        free(del_node);
    }

}

BinNode *Search(Tree *t, int data){
    BinNode *start = t->root;
    while (start != NULL){
        if(start->data == data)
            return start;
        else if(start->data > data){
            printf("%d ", start->data);
            start = start->left;
        }
        else{
            printf("%d ", start->data);
            start = start->right;
        }
    }
    return NULL;
}
void Print(const BinNode *start){
    if(start != NULL){
        Print(start->left);
        printf("%d ", start->data);
        Print(start->right);
    }
}

void PrintTree(const Tree *t){
    BinNode *start = t->root;
    Print(start);
}

void Free(BinNode *start){
    if(start != NULL){
        Free(start->left);
        Free(start->right);
        free(start);
    }
}

void FreeTree(Tree *t){
    BinNode *start = t->root;
    Free(start);
}