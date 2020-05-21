#include<stdio.h>
#include"Double_Linked_list.h"

int main(){
    list l;
    Initialize(&l);
    while (1){
        int menu, x;
        printf("1. 앞쪽에 노드 삽입 2. 뒤쪽에 노드 삽입 3. 앞쪽 노드 삭제 4. 뒤쪽 노드 삭제\n");
        printf("5. 노드 검색 6. 현재노드 출력 7. 앞에서부터 출력 8. 뒤에서부터 출력 9. 모든 노드 삭제\n");
        printf("0. 종료 : ");
        scanf("%d", &menu);
        if(menu == 0) break;
        switch(menu){
            case 1: 
                printf("데이터 : ");
                scanf("%d", &x);
                InsertFront(&l, &x);
                break;
            case 2:
                printf("데이터 : ");
                scanf("%d", &x);
                InsertBack(&l, &x);
            case 3:
               RemoveFront(&l);
                break;
            case 4:
                RemoveBack(&l);
                break;
            case 5:{
                printf("데이터 : ");
                scanf("%d", &x);
                Dnode *srch = Search(&l, &x);
                printf("%d\n", srch->data);
                break;
            }
            case 6:
                PrintCurrent(&l);
                break;
            case 7:
                Print(&l);
                break;
            case 8:
                PrintReverse(&l);
                break;
            case 9:
                Clear(&l);
                break;
        }
    }
    Terminate(&l);
    return 0;
}