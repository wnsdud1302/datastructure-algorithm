#include<stdio.h>
#include"Deque.h"

int main(){
    Deque *d;
    Dinitialize(d);
    while(1){
        int menu, x;
        printf("%d\n", size(d));
        printf("1) InsertFront 2) InsertBack 3) RemoveFront 4) RemoveBack\n");
        printf(" 5) nth data 6) Print 7) PrintReverse 8) Clear 0) Terminate\n");
        printf("enter : ");
        scanf("%d", &menu);
        if(menu == 0) break;
                switch(menu){
            case 1:
                printf("data : ");
                scanf("%d", &x);
                insertFront(d, &x);
                break;
            case 2:
                printf("data : ");
                scanf("%d", &x);
                insertBack(d, &x);
                break;
            case 3:
                removeFront(d);
                break;
            case 4:
                removeBack(d);
                break;
            case 5:
                printf("data : ");
                scanf("%d", &x);
                printf("%d\n", data(d, x));
                break;
            case 6:
                print(d);
                break;
            case 7:
                printReverse(d);
                break;
            case 8:
                clear(d);
                break;
        }
    }
    terminate(d);
    return 0;
}