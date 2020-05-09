#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

int FindMax(const int ar[], int len){
    int max = ar[0];
    for(int i = 0; i < len; i++){
        if(ar[i] > max) 
            max = ar[i];
    }
    return max;
}

int search(const int ar[], int key, int len){
    for(int i = 0; i < len; i++){
        if(ar[i] == key){
            return i;
        }
    }
}

int bin_search1(const int ar[], int key, int len){
    int pl = 0;
    int pr = len - 1;
    int pc;
    do{
        pc = (pl+pr) / 2;
        if (ar[pc] == key)
            return pc;
        else if (ar[pc] < key)
            pl = pc + 1;
        else if (ar[pc] > key)
            pr = pc - 1;
    } while(pl <= pr);
    return -1;
}

int bin_search2(const int ar[], int key, int len){
    int pl = 0;
    int pc = 0;
    int pr = len - 1;
    int i = 1;
    do{
        pc = (pl + pr) / 2;
        if(ar[pc] == key){
            do{
                if(ar[pc-i] != key)
                    return pc - i + 1;
                i++;
            } while( pc- i >= pl);
        }
        else if (ar[pc] < key)
            pl = pc + 1;
        else if ( ar[pc] > key)
            pr = pc - 1;
    } while(pl <= pr);
    return -1;
}

int main(){
    int *ar;
    int max;
    int num = 10;
    ar = calloc(num, sizeof(int));
    for(int i = 0; i < num; i++){
        printf("ar[%d]: ", i);
        scanf("%d", &ar[i]);
    }
    for(int i = 0; i < num; i++)
        printf("%d ", ar[i]);
    while (1){
        int menu, x, print;

        
        puts("\n");
        printf("(1: search, 2: bin search1, 3: bin search2, 0: 종료)\n 선택하세요 : ");
        scanf("%d", &menu);
        if(menu == 0){
            free(ar);
            break;
        }
        switch (menu)
        {
        case 1:
            printf("데이터 :");
            scanf("%d", &x);
            print = search(ar, x, num);
            printf("%d \n", print);
            break;
        
        case 2:
         printf("데이터 :");
            scanf("%d", &x);
            print = bin_search1(ar, x, num);
            printf("%d\n", print);
            break;

        case 3:
            printf("데이터 :"); 
            scanf("%d", &x);
            print = bin_search2(ar, x, num);
            printf("%d\n", print);
            break;
        }
    }

    return 0;
}

