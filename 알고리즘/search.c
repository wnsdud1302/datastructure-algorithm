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

int main(){
    int *ar;
    int max;
    int s;
    int num = 10;
    ar = calloc(num, sizeof(int));
    for(int i = 0; i < 10; i++){
        ar[i]  = rand() % 10;
    }
    for(int i = 0; i < 10; i++){
        printf("%d ", ar[i]);
    }
    printf("\n");
    max = FindMax(ar, 10);
    printf("%d\n", max);
    free(ar);
    return 0;
}
