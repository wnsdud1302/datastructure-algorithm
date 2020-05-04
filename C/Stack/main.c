#include "Stack.h"
#include <stdio.h>


int main(){
    Stack s;
    if(Initialize(&s,64) == -1){
        printf("스택생성에 실패하였습니다.\n");
        return 1;
    }

    while (1)
    {
        int menu, x;
        printf("현재 데이터수 %d / %d\n", size(&s), capacity(&s));
        printf("1: 푸시, 2: 팝, 3:피크, 4: 출력, 0: 종료 : ");
        scanf("%d", &menu);
        if (menu == 0) break;
        switch (menu)
        {
        case 1:
            printf("데이터 : ");
            scanf("%d", &x);
            if(Push(&s, x) == -1)
                puts("\a : 푸시에 실패하였습니다.\n");
            break;
        
        case 2:
            if (Pop(&s, &x) == -1)
                puts("\a : 푸시에 실패하였습니다.\n");
            else
                printf("팝 데이터는 %d 입니다.\n", x);
            break;
        
        case 3: 
            if (Peek(&s, &x) == -1)
                puts("\a : 피크에 실패하였습니다.\n");
            else
                printf("피크 데이터는 %d 입니다\n", x);
            break;
        case 4:
            print(&s);
            break;
        }

    }
    Terminate(&s);
    return 0;
    
}

