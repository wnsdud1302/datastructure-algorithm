#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(){
    Stack s;
    if(Initialize(&s,64) == -1){
        printf("스택생성에 실패하였습니다.\n");
        return 1;
    }

    while (1)
    {
        int menu, x;
        prinf("현재 데이터수 %d / %d\n", size(&s), capacity(&s));
        prinf("1: 푸시, 2: 팝, 3:피크, 4: 출력, 0: 종료 : ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1 :
            printf("데이터 : ");
            scanf("%d", &x);
            Push(&s, x);
            if(Push(&s, x) == -1)
                puts("\a : 푸시에 실패하였습니다.\n");
            break;
        
        case 2:
            
            break;
        }
    }
    
}
