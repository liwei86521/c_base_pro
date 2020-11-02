#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void bubble_sort(int a[], int );

int main09(){
    int arr[10] = { 7,4,2,3,5,8,9,6,1,10 };
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, len);

    for (int i = 0; i < 10; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}

void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len-1; i++){
        for (int j = i+1; j < len; j++){
            if (arr[i] > arr[j]){
                //两个数据交换位置
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
