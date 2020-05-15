#include <stdio.h>
#include<stdlib.h>
#include"Index_Linked_list.h"

static Index GetIndex(list *l){
    if(l->deleted == NULL)
        return ++(l->max);
    else{
        Index rec = l->deleted;
        l->deleted = l->n[rec].next;
        return rec;
    }
}
static Index DeleteIndex(list *l, Index idx){
    if(l->deleted == NULL){
        l->deleted = idx;
        l->n[idx].next = NULL;
    }
    else{
        Index tmp = l->deleted;
        l->deleted = idx;
        l->n[idx].Dnext = tmp;
    }
}
static SetNode(Node *n, const int *data, Index next){
    n->data = *data;
    n->next = next;
}

void Initialize(list *l, int size){
    l->n = calloc(size, sizeof(Node));
    l->head = NULL;
    l->max = NULL;
    l->crnt = NULL;
    l->deleted = NULL;
}

int Search(list *l, int *data){
    Index start = l->head;
    int n = 1;
    while(start != NULL){
        if(&l->n[start] == data){
            l->crnt = start;
            return 0;
        }
        else
            return -1;
        
        start = l->n[start].next;
        n++;
    }
    printf("%d는 %d번째에 있습니다.\n", l->n[l->crnt].data, n);
    return 0;
}

void InsertFront(list *l, int *data){
    Index tmp = l->head;
    l->head = l->crnt = GetIndex(l);
    SetNode(&l->head, data, tmp);
}

void insertBack(list *l, int *data){
    if(l->head == NULL){
        InsertFront(l, data);
    }
    else{
        Index start = l->head;
        while(l->n[start].next != NULL){
            start = l->n[start].next;
        }
        l->n[start].next = l->crnt = GetIndex(l);
        SetNode(&l->n[start].next, data, NULL);
    }
}

void RemoveFront(list *l){
    if(l->head != NULL){
        Index tmp = l->n[l->head].next;
        DeleteIndex(l, l->head);
        l->head = l->crnt = tmp;
    }
}

void RemoveBack(list *l){
    if(l->head != NULL){
        if(l->n[l->head].next == NULL)
            DeleteIndex(l, l->head);
        else{
            Index tmp = l->head;
            Index pre;
            while(l->n[tmp].next != NULL){
                pre = tmp;
                tmp = l->n[tmp].next;
            }
            l->n[pre].next = NULL;
            DeleteIndex(l, tmp);
            l->crnt = pre;
        }
    }
}

void RemoveCurrent(list *l){
    if(l->head != NULL){
        if(l->crnt == l->head){
            RemoveFront(l);
        }
        else{
            Index start = l->head;
            while(l->n[start].next != l->crnt){
                start = l->n[start].next;
            }
            l->n[start].next = l->n[l->crnt].next;
            DeleteIndex(l, l->crnt);
            l->crnt = start;
        }
    }
}

void Clear(list *l){
    while(l->head != NULL)
        RemoveFront(l);
    l->crnt = NULL;
}

void PrintCurrent(list *l){
    if(l->crnt == NULL)
        printf("선택한 노드가 없습니다.\n");
    else
        printf("%d 입니다.\n", l->n[l->crnt].data);
    
}

void Print(list *l){
    if(l->head == NULL)
        puts("노드가 없습니다.");
    else{
        Index start = l->head;
        while(l->n[start].next != NULL){
            printf("%d ", l->n[start].data);
            start = l->n[start].next;
        }
    }
}
