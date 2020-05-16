#include<stdio.h>
#include<stdlib.h>
#include"Linked_list.h"

Node *AllocNode(){
    return calloc(1, sizeof(Node));
}

void Initialize(Linked_list *list){
    list->head = NULL;
    list->crnt = NULL;
}
void InsertFront(Linked_list *list, int *data){
    Node *tmpNode = AllocNode();
    tmpNode->data = *data;
    tmpNode->next = list->head;
    list->head = tmpNode;
    list->crnt = list->head;
}
void InsertBack(Linked_list *list, int *data){
    Node *tmpNode = AllocNode();
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

int Search(Linked_list *list, int *data){
    Node *start = list->head;
    int n = 1;
    while(start != NULL){
        if(start->data == *data){
            list->crnt = start;
            return 0;
        }
        start = start->next;
        n++;
    }
    printf("%d는 n번째에 있습니다\n", start->data);
    return -1;
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
        printf("%d 입니다.\n", list->crnt->data);
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