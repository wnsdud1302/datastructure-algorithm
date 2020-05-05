#include <stdio.h>
#include "DoubleStack.h"

int main(){
    DoubleStack ds;
    if(Initialize(&ds, 64) == -1){
        printf("스택생성에 실패하였습니다.\n");
        return -1;
    }
    while (1)
    {
            int menu, x;
        printf("현재 데이터수 %d / %d\n", size(&ds), capacity(&ds));
        printf("1: 앞쪽 푸시, 2:뒤쪽 푸시, 3:앞 팝, 4: 뒤팝, 5: 앞쪽피크, 6:뒤쪽피크, 7: 앞쪽검색, 8: 뒤쪽검색, 9: 출력, 0: 종료 : " );
        scanf("%d", &menu);
        if (menu == 0) break;
        switch (menu)
        {
        case 1:
            printf("data : ");
            scanf("%d", &x);
            if(FrontPush(&ds, x) == -1)
                puts("\a오류 : 푸시에 실패하였습니다.");
            break;
        case 2:
            printf("data : ");
            scanf("%d", &x);
            if(RearPush(&ds, x) == -1)
                puts("\a오류 : 푸시에 실패하였습니다.");
            break;
        case 3:
            if(FrontPop(&ds, &x) == -1)
                puts("\a오류 팝에 실패하였습니다.");
            else
                printf("팝 데이터는 %d 입니다.\n", x);
            break;
        case 4:
            if(RearPop(&ds, &x) == -1)
                puts("\a오류 팝에 실패하였습니다.");
            else
                printf("팝 데이터는 %d 입니다.\n", x);
            break;
        case 5:
            if(FrontPeek(&ds, &x) == -1)
                puts("\a오류 피크에 실패하였습니다.");
            else
                printf("피크 데이터는 %d 입니다. \n", x);
            break;
        case 6:
            if(RearPeek(&ds, &x) == -1)
                puts("\a오류 피크에 실패하였습니다.");
            else
                printf("피크 데이터는 %d 입니다. \n", x);
            break;
        case 7:
            if(FrontSearch(&ds, x) == -1)
                puts("\a오류 검색에 실패하였습니다.");
            else
                printf("%d는 %d번째에 있습니다. \n",x, FrontSearch(&ds, x));
            break;
        case 8:
            if(RearSearch(&ds, x) == -1)
                puts("\a오류 검색에 실패하였습니다.");
            else
                printf("%d는 %d번째에 있습니다. \n",x, RearSearch(&ds, x));
            break;
        case 9:
            printf("앞쪽 : ");
            FrontPrint(&ds);
            printf("뒤쪽 : ");
            RearPrint(&ds);
            break;

        }        
    }

    Terminate(&ds);
    return 0;
}