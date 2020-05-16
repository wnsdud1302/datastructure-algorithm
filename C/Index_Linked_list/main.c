#include<stdio.h>
#include"Index_Linked_list.h"

int main(){
    list l;
    Initialize(&l, 64);
    while(1){
        int menu, x;
        printf("1: 앞쪽노드 삽입 2: 뒷쪽노드 삽입 3: 앞쪽노드 삭제 4: 뒤쪽노드 삭제 \n");
        printf("5: 현재노드 삭제 6: 검색 7: 현재노드 출력 8: 모든 노드 출력 \n");
        printf("9: 모든 노드 삭제 0:종료\n");
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
                break;

            case 3:
                RemoveFront(&l);
                break;

            case 4:
                RemoveBack(&l);
                break;
            
            case 5:
                RemoveCurrent(&l);
                break;

            case 6:
                printf("데이터 : ");
                scanf("%d", &x);
                Search(&l, &x);
                if(Search(&l, &x) == Null);
                    printf("찾는 숫자가 없습니다.\n");
                break;

            case 7:
                PrintCurrent(&l);
                break;

            case 8:
                Print(&l);
                putchar('\n');
                break;

            case 9:
                Clear(&l);
                break;      
        }
    }
    Terminate(&l);
    return 0;

}