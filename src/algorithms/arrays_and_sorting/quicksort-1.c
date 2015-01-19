#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int count_l, count_r;

void printSolution (int pivot, int * ar_l, int * ar_r) {
    int i;
    for (i=0; i<count_l; i++) {
        printf("%d ", ar_l[i]);
    }
    printf("%d ", pivot);
    for (i=0; i<count_r; i++) {
        printf("%d ", ar_r[i]);
    }
}

void partition(int ar_size, int *  ar, int * ar_l, int * ar_r) {
    int pivotIndex = 0;
    int pivotValue = ar[pivotIndex];
    int i;
    count_l=0;
    for (i=0; i<ar_size; i++) {
        if(ar[i] < pivotValue) {
            ar_l[count_l++] = ar[i];
        }
    }
    count_r=0;
    for (i=0; i<ar_size; i++) {
        if(ar[i] > pivotValue) {
            ar_r[count_r++] = ar[i];
        }
    }
}

int main(void) {
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    int _ar_l[_ar_size], _ar_r[_ar_size];
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        scanf("%d", &_ar[_ar_i]);
    }
    partition(_ar_size, _ar, _ar_l, _ar_r);
    printSolution(_ar[0], _ar_l, _ar_r);
    return 0;
}

