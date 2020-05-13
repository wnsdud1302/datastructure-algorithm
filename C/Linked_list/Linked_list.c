#include<stdio.h>
#include<stdlib.h>
#include"Linked_list.h"


int Initialize(Linked_list *list){
    list->head = NULL;
    list->crnt = NULL;
}
int InsertFront(Linked_list *list, int data){
    Node *tmpNode;
    tmpNode->data = data;
    tmpNode->next = list->head;
    list->head = tmpNode;
    list->crnt = list->head;
}
int Insertback(Linked_list *list, int data){
    Node *tmpNode;
    Node *start = list->head;
    while(start != NULL){
        start = start->next;
    }
    start->next = tmpNode;
    list->crnt = start->next;
}
void RemoveFront(Linked_list *list){
    Node *tmpNode;
    if(list-> head != NULL){
        tmpNode = list->head->next;
        free(list->head);
    }
    list->head = list->crnt = tmpNode;
}

void RemoveBack(Linked_list *list){
    Node *tmpNode;
    Node *start = list->head;
    if(start != NULL){
        if(start->next == NULL)
            RemoveFront(list);
        else{
            while(start->next != NULL){
                tmpNode = start;
                start = start->next;
            }
            free(start->next);
            list->crnt = tmpNode;
        }
    }
}
void RemoveCurrent(Linked_list *list){
    Node *start = list->head;
    if(start != NULL){
        if(start == list->crnt){
            RemoveFront(list);
        }
        else{
            while(start->next != list->crnt){
                start = start->next;
            }
            start->next = list->crnt->next;
            free(list->crnt);
            list->crnt = start;
        }
    }
}

void Search(Linked_list *list, int data){
    Node *start = list->head;
    while(start->next != NULL){
        if(start->data == data){
            list->crnt = start;
        }
        start = start->next;
    }
}

void Clear(Linked_list *list){
    while(list->head != NULL){
        RemoveFront(list);
    }
}

void PrintCurrent(const Linked_list *list){
    if(list->crnt == NULL)
        printf("선택한 노드가 없습니다.");
    else
        printf("%d 입니다.", list->crnt->data);
}

void Print(const Linked_list *list){
    Node *start = list->head;
    while (start != NULL){
        printf("%d ", start->data);
        start = start->next;
    }
    putchar('\n');
}

void Terminate(Linked_list *list){
    Clear(list);
}