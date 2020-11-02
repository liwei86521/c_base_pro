/*
-------------------------------------------------
   Author :       F7687778
   date:          2020/10/15 下午 04:10
-------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

void printBiArray(int(*parr)[3], int len1, int len2){
    for (int i = 0; i < len1; ++i){
        for (int j = 0; j < len2; ++j){
            //printf("%d ", *(*(parr + i) + j) );
            printf("%d ", parr[i][j]);
        }
    }
}

void printBiArray2(int parr[3][3], int len1, int len2)
{
    for (int i = 0; i < len1; ++i)
    {
        for (int j = 0; j < len2; ++j)
        {
            //printf("%d ", *(*(parr + i) + j) );
            printf("%d ", parr[i][j]);
        }
    }
}

void printBiArray3(int parr[][3], int len1, int len2)
{
    for (int i = 0; i < len1; ++i)
    {
        for (int j = 0; j < len2; ++j)
        {
            //printf("%d ", *(*(parr + i) + j) );
            printf("%d ", parr[i][j]);
        }
    }
}

void test08_12(){
    int arr[3][3] =
            {
                    { 1, 2, 3 },
                    { 4, 5, 6 },
                    { 7, 8, 9 }
            };

    printBiArray(arr,3,3);

}

int main082() {

    test08_12();
    return 0;
}
