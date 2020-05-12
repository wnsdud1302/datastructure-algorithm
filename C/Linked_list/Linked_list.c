#include<stdio.h>
#include<stdlib.h>
#include"Linked_list.h"

static Node *AllocNode(){
    return calloc(1, sizeof(Node));
}

int Initialize(Linked_list *list){
    list->head = AllocNode();
}
int InserFront(Linked_list *list, int data){
    Node *tmpNode = AllocNode();
    tmpNode->data = data;
    tmpNode->next = list->head;
    list->head = tmpNode;
}
int Insertback(Linked_list *list, int data){
    Node *tmpNode = AllocNode();
    Node *start = list->head;
    while(start != NULL){
        start = start->next;
    }
    start->next = tmpNode;
}
void RemoveFront(Linked_list *list){
    Node *tmpNode = NULL;
    if(list-> head != NULL)
        tmpNode = list->head->next;
}
