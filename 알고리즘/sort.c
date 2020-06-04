#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = n-1; j > 0; j--){
            if(a[j-1] > a[j])
                swap(&a[j-1], &a[j]);
        }
    }
}

void BubbleSort1(int a[], int n){
    int exg
}