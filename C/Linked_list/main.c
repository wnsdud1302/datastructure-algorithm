#include<stdio.h>
#include"Linked_list.h"

typedef enum Menu{
    TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_BACK,
    RMV_CRNT, SCRH, CRNT_PRINT, ALL_PRINT, CLEAR
} Menu;

Menu SelectMenu(){
    int ch;
    char *mstring[] = {
        "머리에 노드를 삽입", "꼬리에 노드를 삽입", "머리에 노드삽입"
        "꼬리노드를 삭제", "선택한 노드를 삭제", "검색", "선택한 노드를 출력",
        "모든 노드를 출력", "모든 노드를 삭제",
    };
    do{
        for(int i = TERMINATE; i < CLEAR; i++){
            printf("(%2d) %-18.18s", i+1, mstring[i]);
            if((i % 3) == 2)
                putchar('\n');
        }
        printf("(0) 종료 : ");
        scanf("%d", ch);
    }while(ch < TERMINATE || ch > CLEAR);
    return(Menu)ch;
}

int main(){
    Linked_list l;
    Initialize(&l);

    return 0;
}