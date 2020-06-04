#include<stdio.h>

int factorial(int n){
    if(n > 0)
        return n*factorial(n-1);
    else
        return 1;
}
//n1 > n2
int great_common_divisior(int n1, int n2){
    if(n2 = 0) return n1;
    else return great_common_divisior(n2, n1 % n2);
}

void move(int n, int x, int y){
    if(n >1)
        move(n-1, x, 6-x-y);
    printf("원반 %d를 %d 기둥에서 %d 기둥으로 옮김\n", n, x, y);
    if(n >1)
        move(n-1, 6-x-y, y);
}

int pos[8];
int flag_a[8];
int flag_b[15];
int flag_c[15];

void print(){
    for(int i  = 0; i < 8; i++){
        printf("%2d", pos[i]);
    putchar('\n');
    }
}

void set(int i){
    for(int j = 0; j < 8; j++){
        if(!flag_a[j] && !flag_b[i+j] && !flag_c[i - j + 7]){
            pos[i] = j;
            if(i == 7)
                print();
        }
        else{
            flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
            set(i+1);
            flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
        }
    }
}