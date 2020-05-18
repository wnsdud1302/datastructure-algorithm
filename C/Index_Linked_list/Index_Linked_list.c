#include <stdio.h>
#include<stdlib.h>
#include"Index_Linked_list.h"

static Index GetIndex(list *l){
    if(l->deleted == Null)
        return ++(l->max);
    else{
        Index rec = l->deleted;
        l->deleted = l->n[rec].next;
        return rec;
    }
}
static Index DeleteIndex(list *l, Index idx){
    if(l->deleted == Null){
        l->deleted = idx;
        l->n[idx].next = Null;
    }
    else{
        Index tmp = l->deleted;
        l->deleted = idx;
        l->n[idx].Dnext = tmp;
    }
}
static void SetNode(Node *n, const int *data, Index next){
    n->data = *data;
    n->next = next;
}

void Initialize(list *l, int size){
    l->n = calloc(size, sizeof(Node));
    l->head = Null;
    l->max = Null;
    l->crnt = Null;
    l->deleted = Null;
}
Index Search(list *l, int *data){
    Index start = l->head;
    int n = 1;
    while(start != Null){
        if(l->n[start].data == *data){
            l->crnt = start;
            return start;
        }
        start = l->n[start].next;
        n++;
    }
    printf("%d는 %d번째에 있습니다.\n", l->n[start].data, n);
    return Null;
}

void InsertFront(list *l, int *data){
    Index tmp = l->head;
    l->head = l->crnt = GetIndex(l);
    SetNode(&l->n[l->head], data, tmp);
}

void InsertBack(list *l, int *data){
    if(l->head == Null){
        InsertFront(l, data);
    }
    else{
        Index start = l->head;
        while(l->n[start].next != Null){
            start = l->n[start].next;
        }
        l->n[start].next = l->crnt = GetIndex(l);
        SetNode(&l->n[l->n[start].next], data, Null);
    }
}

void RemoveFront(list *l){
    if(l->head != Null){
        Index tmp = l->n[l->head].next;
        DeleteIndex(l, l->head);
        l->head = l->crnt = tmp;
    }
}

void RemoveBack(list *l){
    if(l->head != Null){
        if(l->n[l->head].next == Null)
            DeleteIndex(l, l->head);
        else{
            Index tmp = l->head;
            Index pre;
            while(l->n[tmp].next != Null){
                pre = tmp;
                tmp = l->n[tmp].next;
            }
            l->n[pre].next = Null;
            DeleteIndex(l, tmp);
            l->crnt = pre;
        }
    }
}

void RemoveCurrent(list *l){
    if(l->head != Null){
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
    Index start = l->head;
    while(start != Null){
        RemoveFront(l);
    }
    l->crnt = Null;
}

void PrintCurrent(const list *l){
    if(l->crnt == Null)
        printf("선택한 노드가 없습니다.\n");
    else
        printf("%d 입니다.\n", l->n[l->crnt].data);
    
}

void Print(const list *l){
    if(l->head == Null)
        puts("노드가 없습니다.");
    else{
        Index start = l->head;
        while(l->n[start].next != Null){
            printf("%d ", l->n[start].data);
            start = l->n[start].next;
        }
    putchar('\n');
    }
}

void Terminate(list *l){
    Clear(l);
    free(l->n);
}
