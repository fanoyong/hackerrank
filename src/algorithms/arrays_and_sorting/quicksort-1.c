#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void printAr(int ar_size, int * ar) {
    int i;
    for(i=0;i<ar_size;i++) {
        printf("%d ",ar[i]);
    }
    printf("\n");
}

void partition(int ar_size, int *  ar, int lo, int hi) {
    int pivotIndex = lo;
    int pivotValue = ar[pivotIndex];
    int ar2[ar_size];
    int i;
    int count=0;
    for (i=0; i<ar_size; i++) {
        if(ar[i] < pivotValue) {
            ar2[count++] = ar[i];
        }
    }
    for (i=0; i<ar_size; i++) {
        if(ar[i] >= pivotValue) {
            ar2[count++] = ar[i];
        }
    }
    printAr(ar_size, ar2);
}

int main(void) {
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        scanf("%d", &_ar[_ar_i]);
    }
    partition(_ar_size, _ar, 0, _ar_size-1);

    return 0;
}

