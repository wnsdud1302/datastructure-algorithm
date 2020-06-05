#include<stdio.h>

//버블 정렬
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = n-1; j > i; j--){
            if(a[j-1] > a[j])
                swap(&a[j-1], &a[j]);
        }
    }
}

void BubbleSort1(int a[], int n){
    for(int i = 0; i < n; i++){
        int exg = 0;
        for(int j = n-1; j > i; j--){
            if(a[j-1] > a[j])
                swap(&a[j-1], &a[j]);
            exg++;
        }
        if(exg == 0) break;
    }
}

int is_sorted(int a[], int n){
    for(int i = 0; i < n; i++){
        int exg = 0;
        for(int j = n-1; j > i; j--){
            if(a[j-1] > a[j])
                exg++;
        }
        if(exg == 0) return 1;
    }
    return 0;
}

void BubbleSort2(int a[], int n){
    int k = 0;
    for(int i = 0; i < n; i++){
        int last = n-1;
        for(int j = n-1; j > i; j--){
            if(a[j-1] > a[j])
                swap(&a[j-1], &a[j]);
            last = j;
        }
        k = last;
    }
}

void BubbleSort3(int a[], int n){
    int left = 0;
    int right = n-1;
    int last = right;
    while(left < right){
        for(int i = left; i < right-1; i++){
            if(a[i] > a[i+1])
                swap(&a[i] , &a[i+1]);
            last = i;
        }
        right = last;
        for(int i = right; i > left; i--){
            if(a[i-1] > a[i])
                swap(&a[i-1], &a[i]);
            last = i;
        }
        left = last;
    }
}

//단순 선택 정렬
